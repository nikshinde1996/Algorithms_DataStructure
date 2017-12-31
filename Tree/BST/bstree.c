#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
  struct tree_node *left;
  struct tree_node *right;
  int data;
} tree_node;

typedef struct bstree {
  struct tree_node *root;  // root of the bstree
  unsigned int n;          // no. of nodes in bstree
} bstree;

typedef enum traversal { INORDER, PREORDER, POSTORDER, LEVELORDER } traversal;

static char *name(traversal method) {
  switch (method) {
    case INORDER:
      return "inorder";
    case PREORDER:
      return "preorder";
    case POSTORDER:
      return "postorder";
    case LEVELORDER:
      return "levelorder";
    default:
      exit(0);  // unreachable
  }
}

static tree_node *new_node(int data) {
  tree_node *node = (tree_node *)malloc(sizeof(tree_node));
  node->left = NULL;
  node->right = NULL;
  node->data = data;
  return node;
}

static tree_node *insert_node(tree_node *node, int data) {
  if (node == NULL) return new_node(data);

  if (data < node->data) {
    node->left = insert_node(node->left, data);
  } else if (data > node->data) {
    node->right = insert_node(node->right, data);
  }

  return node;
}

void add_node(bstree *tree, int data) {
  tree->root = insert_node(tree->root, data);
}

static tree_node *successor(tree_node *node) {
  tree_node *current = node;
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

static tree_node *delete_node(tree_node *node, int data) {
  if (node == NULL) return node;

  if (data < node->data) {
    node->left = delete_node(node->left, data);
  } else if (data > node->data) {
    node->right = delete_node(node->right, data);
  } else {
    if (node->left == NULL) {
      tree_node *temp = node->right;
      free(node);
      return temp;
    } else if (node->right == NULL) {
      tree_node *temp = node->left;
      free(node);
      return temp;
    }

    tree_node *temp = successor(node->right);
    node->data = temp->data;
    node->right = delete_node(node->right, temp->data);
  }
}

void remove_node(bstree *tree, int data) {
  tree->root = delete_node(tree->root, data);
}

static tree_node *search(tree_node *node, int data) {
  if (node == NULL || node->data == data) return node;
  if (node->data > data) return search(node->left, data);
  return search(node->right, data);
}

bool has_node(bstree *tree, int data) {
  tree_node *node = search(tree->root, data);
  return node == NULL ? false : node->data == data;
}

static void preorder(tree_node *node) {
  if (node != NULL) {
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}

static void postorder(tree_node *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
  }
}

static void inorder(tree_node *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
  }
}

static int height(tree_node *node) {
  if (node == NULL) return 0;
  int left_height = height(node->left);
  int right_height = height(node->right);
  return left_height > right_height ? left_height + 1 : right_height + 1;
}

static void print_level(tree_node *node, int level) {
  if (node == NULL) return;
  if (level == 1) {
    printf("%d ", node->data);
  } else if (level > 1) {
    print_level(node->left, level - 1);
    print_level(node->right, level - 1);
  }
}

static void levelorder(tree_node *node) {
  int i, h = height(node);

  for (i = 1; i <= h; i++) {
    print_level(node, i);
  }
}

void traverse(bstree *tree, traversal method) {
  printf("%s: ", name(method));
  switch (method) {
    case INORDER:
      inorder(tree->root);
      break;
    case POSTORDER:
      postorder(tree->root);
      break;
    case PREORDER:
      preorder(tree->root);
      break;
    case LEVELORDER:
      levelorder(tree->root);
      break;
    default:
      printf("Invalid traversal method!\n");
      exit(0);
  }
  printf("\n");
}

/*
 * Example:
 *
 *        5
 *      /   \
 *     3     7
 *    / \   / \
 *   2   4 6   8
 *
 */
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: ./bstree <no. of nodes>\n");
  } else {
    int i, v, n = atoi(argv[1]);
    bstree *tree = (bstree *)malloc(sizeof(bstree));

    for (i = 0; i < n; i++) {
      printf("node %d: ", (i + 1));
      scanf("%d", &v);
      add_node(tree, v);
    }

    traverse(tree, INORDER);
    traverse(tree, POSTORDER);
    traverse(tree, PREORDER);
    traverse(tree, LEVELORDER);

    if (has_node(tree, 8))
      printf("tree contains node with value 8\n");
    else
      printf("node with value 8 not found\n");

    remove_node(tree, 5);
    traverse(tree, INORDER);
  }
  return 0;
}
