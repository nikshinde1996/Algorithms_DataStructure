#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
	int data;
	struct node *next;
} *start = NULL;

struct node* create_node(int num) 
{
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = num;
	temp->next = NULL;

	return temp;
}

void insert_node()
{
	int num;
	struct node *head = start, *new_node;

	printf("Enter number to enter: ");
	scanf("%d", &num);
	new_node = create_node(num);

	if(start==NULL)
	{
		start = new_node;
	}
	else 
	{
		while(head->next!=NULL) 
		{
			head = head->next;
		}

		head->next = new_node;
	}

	printf("Node Inserted ...\n\n");
}

/* Deletes the given node of 
 * Singly Linked List using 
 * double pointers
 */
void delete_node()
{
	int num, flag = 0;
	struct node **p_to_head = &start, *to_delete = start;

	printf("Enter the node to delete: ");
	scanf("%d", &num);

	while(to_delete)
	{
		if(to_delete->data==num)
		{
			*p_to_head = to_delete->next;
			flag=1;
		}

		p_to_head = &to_delete->next;
		to_delete = to_delete->next;
	}

	if(flag==0)
		printf("Node not found ...\n\n");

	else 
		printf("Node deleted ...\n\n");	

}

void get_size()
{
	int size = 0;
	struct node *head = start;

	while(head!=NULL) 
	{
		head = head->next;
		size++;
	}

	printf("Size of current linked list: %d \n\n", size);
}

void display_list()
{
	struct node *head = start;

	printf("Current List: ");
	
	if(start==NULL) 
	{
		printf("< Empty >\n\n");
		return;
	}

	while(head->next!=NULL) 
	{
		printf(" %d ->",head->data);
		head = head->next;
	}
	printf(" %d", head->data);
	printf("\n\n");
}

int main() 
{
	int choice;

	while(1) 
	{
		printf("Singly Linked List: \n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Size\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice) 
		{
			case 1:
				insert_node();
				break;

			case 2:
				delete_node();
				break;

			case 3:
				get_size();
				break;

			case 4:
				display_list();
				break;

			case 5:
				exit(0);

			default:
				printf("Enter a valid choice\n\n");
		}
	}

	return 0;
}