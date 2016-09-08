/* Datastructure:    Trie
 * Time Complexity:  O(key_length)    
 * Space Complexity: O(NO_OF_ALPHABETS * key_length* N) where N = no of keys in trie.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include<conio.h>

#define NO_OF_ALPHABETS (26)

struct node 
{
    bool isLeaf;
    struct node *next_char[NO_OF_ALPHABETS];
} *root;

/*
 * Create, initialise and return a new node
 */
struct node *create_node() 
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node) 
    {
        int i;
        new_node->isLeaf = false;

        for(i=0;i<NO_OF_ALPHABETS;i++)
            new_node->next_char[i] = NULL;
    }
    return new_node;
}

/* 
 * Initialise the root of the trie to NULL
 */
void init_root()
{
    root = create_node();
}

/*
 * Insert string key into the trie
 */
void insert_string()
{    
    struct node *temp = root;
    int i, str_length, char_index;
    char string[50];
    printf("String: ");
    scanf("%s", string);

    str_length = strlen(string);

    for(i=0;i<str_length;i++)
    {
        char_index = ((int)string[i] - (int)'a');
        if(!temp->next_char[char_index])
            temp->next_char[char_index] = create_node();
        
        temp = temp->next_char[char_index];
    }
    temp->isLeaf = true;
}

/*
 * Searches string and returns true if found
 */
bool search_string()
{
    struct node *temp = root;
    int i, char_index, str_length;
    char string[100];
    printf("Search String: ");
    scanf("%s", string);

    str_length = strlen(string);
    
    for(i=0;i<str_length;i++)
    {
        char_index = ((int)string[i] - (int)'a');

        if(!temp->next_char[char_index]) 
            return false;
        temp = temp->next_char[char_index];
    }

    return (temp!=NULL && temp->isLeaf);
}

bool isItFreeNode(struct node *temp) {
	int i;
	for(i=0;i<NO_OF_ALPHABETS;i++) {
		if(temp->next_char[i]) {
			return false;
		}
	}
	return true;
}

bool deletehelper(struct node *temp,char key[],int level,int len) {
	if(temp) {
		if(level == len) {
			if(temp->isLeaf) {
				temp->isLeaf = false;
				if(isItFreeNode(temp)) {
					return true;
				}
				return false;
			}
		}else {
			int index = ((int)key[level]-(int)'a');
			
			if(deleteHelper(temp->next_char[index],key,level+1,len)) {
				free(temp->next_char[index]);
				return (!temp->isLeaf && isItFreeNode(temp));
			}
		}
	}
}

void delete_string() {
	struct node *temp = root;
	int i,char_index,str_length;
	char string[100];
	printf("Delete String : ");
	scanf("%s",&string);
	str_length = strlen(string);
	
	if(str_length > 0) {
	   deleteHelper(temp,string,0,str_length);	
	}
}

int main()
{
    int choice;

    init_root();

    while(1)
    {
        printf("Trie: \n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("3. Exit\n");
        printf("Enter: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_string();
                printf("String inserted ...\n\n");
                break;

            case 2:
                if(search_string())
                    printf("String present in trie ...\n\n");

                else 
                    printf("String not present in trie ...\n\n");
                break;

            case 3: 
                delete_string();
                printf("String deleted ...\n\n");
                break;
                
            case 4:
                exit(0);

            default:
                printf("Invalid choice\n\n");
        }
    }
}
