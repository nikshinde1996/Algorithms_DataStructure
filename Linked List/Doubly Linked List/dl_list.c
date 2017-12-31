#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  struct list_node *prev;
  struct list_node *next;
  int data;
} list_node;

typedef struct list {
  struct list_node *head;
  unsigned int length;
} list;

list *new_list() {
  list *l = (list *)malloc(sizeof(list));
  l->head = NULL;
  l->length = 0;
  return l;
}

list_node *new_node(int data) {
  list_node *node = (list_node *)malloc(sizeof(list_node));
  node->prev = NULL;
  node->data = data;
  node->next = NULL;
  return node;
}

void insert_node(list *l, int data) {
  if (l == NULL) return;
  list_node *node = new_node(data);
  if (l->head == NULL) {
    l->head = node;
  } else {
    list_node *temp = l->head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
  }
  l->length++;
}

void remove_node(list *l, int data) {
  if (l->head == NULL) return;
  if (l->head->data == data) {
    list_node *temp = l->head;
    l->head = temp->next;
    if (l->head != NULL) {
      l->head->prev = NULL;
    }
    free(temp);
    l->length--;
  } else {
    list_node *temp = l->head;
    while (temp != NULL) {
      if (temp->data == data) {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
          temp->next->prev = temp->prev;
        }
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
        l->length--;
        return;
      }
      temp = temp->next;
    }

    printf("node %d not found, skipping ...\n", data);
  }
}

void push(list *l, int data) {
  list_node *node = new_node(data);
  if (l->head == NULL) {
    l->head = node;
  } else {
    node->next = l->head;
    l->head->prev = node;
    l->head = node;
  }
  l->length++;
}

void pop(list *l) {
  if (l->head != NULL) {
    list_node *node = l->head;
    l->head = l->head->next;
    if (l->head != NULL) {
      l->head->prev = NULL;
    }
    free(node);
    l->length--;
  }
}

int peek(list *l) {
  if (l->head != NULL) {
    return l->head->data;
  } else {
    return -1;
  }
}

bool is_empty(list *l) { return l->length == 0; }

static void delete_node(list *l, list_node *node) {
  if (node == l->head) {
    l->head = l->head->next;
    if (l->head != NULL) {
      l->head->prev = NULL;
    }
  } else {
    node->prev->next = node->next;
    if (node->next != NULL) {
      node->next->prev = node->prev;
    }
  }
  free(node);
  l->length--;
}

void remove_dups(list *l) {
  list_node *temp = l->head;
  while (temp != NULL) {
    list_node *inner = temp->next;
    while (inner != NULL) {
      if (inner->data == temp->data) {
        delete_node(l, inner);
      }
      inner = inner->next;
    }
    temp = temp->next;
  }
}

int kth_last(list *l, int k) {
  list_node *fast, *slow;
  int count = 0;

  fast = l->head;
  while (fast != NULL && count < k) {
    fast = fast->next;
    count++;
  }

  slow = l->head;
  while (fast != NULL) {
    fast = fast->next;
    slow = slow->next;
  }

  return count < k ? -1 : slow->data;
}

void remove_middle(list *l) {
  list_node *fast, *slow;

  fast = slow = l->head;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }

  if (slow != NULL) delete_node(l, slow);
}

void print_list(list *l) {
  if (l != NULL) {
    int i, len = l->length;
    list_node *temp = l->head;

    printf("[");
    for (i = 0; i < len - 1; i++) {
      printf("%d, ", temp->data);
      temp = temp->next;
    }
    if (temp != NULL) printf("%d", temp->data);
    printf("]\n");
  }
}

list *partition(list *l, int x) {
  list *small = new_list();
  list *big = new_list();
  list_node *temp = l->head;

  while (temp != NULL) {
    if (temp->data < x) {
      insert_node(small, temp->data);
    } else if (temp->data > x) {
      insert_node(big, temp->data);
    }
    temp = temp->next;
  }

  insert_node(small, x);
  list_node *h_temp = big->head;
  while (h_temp != NULL) {
    insert_node(small, h_temp->data);
    h_temp = h_temp->next;
  }

  return small;
}

bool is_palindrome(list *l) {
  if (l == NULL) return false;
  list_node *front, *back;

  front = l->head;
  while (front->next != NULL) {
    front = front->next;
  }

  back = front;
  front = l->head;

  while (front != back && front->next != back) {
    if (front->data != back->data) {
      return false;
    }
    front = front->next;
    back = back->prev;
  }

  if (l->length % 2 == 0)
    return front->data == front->next->data;
  else
    return true;
}

list *sum_lists(list *a, list *b) {
  int sum, carry = 0;
  list *l = new_list();
  list_node *one, *two;

  one = a->head;
  two = b->head;
  while (one && two) {
    sum = (one->data + two->data + carry);
    carry = sum / 10;
    insert_node(l, sum % 10);
    one = one->next;
    two = two->next;
  }

  while (one) {
    sum = (one->data + carry);
    carry = sum / 10;
    insert_node(l, sum % 10);
    one = one->next;
  }

  while (two) {
    sum = (two->data + carry);
    carry = sum / 10;
    insert_node(l, sum % 10);
    two = two->next;
  }

  if (carry != 0) insert_node(l, carry);

  return l;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: ./list <elements>\n");
  } else {
    int i, n = argc - 1;
    list *l = new_list();
    list *m = new_list();

    for (i = 1; i <= n; i++) {
      push(l, atoi(argv[i]));
      push(m, atoi(argv[i]));
    }

    if (is_palindrome(l))
      printf("palindromic list\n");
    else
      printf("not a palindromic list\n");
    print_list(l);
    remove_dups(l);
    print_list(l);
    printf("4th last element is %d\n", kth_last(l, 4));
    remove_middle(l);
    print_list(partition(l, 3));
    print_list(l);
    print_list(m);
    list *sum = sum_lists(l, m);
    print_list(sum);
  }
  return 0;
}