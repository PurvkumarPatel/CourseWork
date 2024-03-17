#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* link;
};
struct node* start = NULL;
void createList()
{
	if (start == NULL) {
		int n;
		printf("\n--->Enter the number of nodes: ");
		scanf("%d", &n);
		if (n != 0) {
			int data;
			struct node* newnode;
			struct node* temp;
			newnode = malloc(sizeof(struct node));
			start = newnode;
			temp = start;
			printf("\n--->Enter number to be inserted : ");
			scanf("%d", &data);
			start->info = data;

			for (int i = 2; i <= n; i++) {
				newnode = malloc(sizeof(struct node));
				temp->link = newnode;
				printf("\n--->Enter number to be inserted : ");
				scanf("%d", &data);
				newnode->info = data;
				temp = temp->link;
			}
		}
		printf("\nThe list is created\n");
	}
	else
		printf("\nThe list is already created\n");
}
void traverse()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		while (temp != NULL) {
			printf("%d\t", temp->info);
			temp = temp->link;
		}
	}
}
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);
	printf("::Inserted::");
	temp->info = data;
	temp->link = start;
	start = temp;
}
void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);
	printf("::Inserted::");
	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}
void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));
	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &data);
	printf("::Inserted::");
	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}
void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		printf("\n::List is empty::\n");
	else {
		temp = start;
		start = start->link;
		free(temp);
	}
	printf("::Deleted::");
}
void deleteEnd()
{
	struct node *temp, *prevnode;
	if (start == NULL)
		printf("\n::List is Empty::\n");
	else {
		temp = start;
		while (temp->link != 0) {
			prevnode = temp;
			temp = temp->link;
		}
		free(temp);
		prevnode->link = 0;
	}
	 printf("::Deleted::");
}
void deletePosition()
{
	struct node *temp, *position;
	int i = 1, pos;
	if (start == NULL)
		printf("\n::List is empty::\n");
	else {
		printf("\n-->Enter Position : ");
		scanf("%d", &pos);
	    printf("::Deleted::");
		position = malloc(sizeof(struct node));
		temp = start;

		while (i < pos - 1) {
			temp = temp->link;
			i++;
		}
		position = temp->link;
		temp->link = position->link;
		free(position);
	}
}

int main()
{
	int choice;
	while (1) {
        printf(":://:://:://:://:://:://:://:://:://:://:://:://:://:://");
		printf("\n\t-->Enter 1 to see list\n");
		printf("\t-->Enter 2 for insert at starting\n");
		printf("\t-->Enter 3 for insert at end\n");
		printf("\t-->Enter 4 for insert at any position\n");
		printf("\t-->Enter 5 for delete first element\n");
		printf("\t-->Enter 6 for delete last element\n");
		printf("\t-->Enter 7 for delete element at any position\n");
		printf("\t-->Enter 8 to exit program\n");
		printf("\n---->Enter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;
		case 8:
			exit(1);
			 printf("::Exited from program::");
			break;
		default:
			printf("::Incorrect Choice::\n");
		}
	}
	return 0;
}
