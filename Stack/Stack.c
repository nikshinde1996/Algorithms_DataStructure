#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node *next;
} *start = NULL;

struct node* create_node(int n) 
{
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = n;
	temp->next = NULL;

	return temp;
}

void insert_x() 
{
	struct node *new_node;
	int num;

	printf("Enter the number: ");
	scanf("%d", &num);
	new_node = create_node(num);

	if(start==NULL) 
	{
		start = new_node;
	}
	else 
	{
		new_node->next = start;
		start = new_node;
	}

	printf("Node inserted ...\n\n");
}

void delete_x()
{
	struct node *head = start;
	if(start!=NULL)
	{
		start = head->next;
		printf("Node deleted ...\n\n");
	}
	else
	{
		printf("Stack Empty\n\n");
	}
}

void print_max()
{
	struct node *head = start;
	int max = INT_MIN;

	//printf("Max Element: ");
	if(start==NULL)
	{
		printf("Stack Empty\n\n");
		return;
	}

	while(head!=NULL)
	{
		if(head->data > max) max = head->data;
		head = head->next;
	}

	printf(" %d \n", max);
}

void display()
{
	struct node *head = start;

	if(start==NULL)
	{
		printf("Stack Empty\n\n");
		return;
	}

	printf("Current Stack: ");
	while(head!=NULL)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
	printf("\n\n");
}

int main()
{
	int choice;

	while(1)
	{
		printf("Stack: \n");
		printf("1. Insert [Input: 1 x]\n");
		printf("2. Delete\n");
		printf("3. Print maximum element in the stack\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_x();
				break;
			case 2:
				delete_x();
				break;
			case 3:
				print_max();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid Entry\n\n");
		}
	}
}