#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create_node(int value1)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value1;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
struct node *creation_end(struct node *root, int key)
{
    if (root->next == NULL)
    {
        struct node *new = create_node(key);
        root->next = new;
        new->prev = root;
        return new;
    }
}
struct node *insertion_begin(struct node *root, int key)
{
    struct node *new = create_node(key);
    new->next = root;
    root->prev = new;
    new->prev = NULL;
    return new;
    printf("::Inserted::\n");
}
struct node *insertion_position(struct node *root, int key, int key1)
{
    int i = 1;
    struct node *prev1;
    while (i < key1)
    {
        root = root->next;
        i++;
    }

    struct node *new = create_node(key);
    prev1 = root->prev;
    new->next = root;
    new->prev = prev1;
    prev1->next = new;
    root->prev = new;
    printf("::Inserted::\n");
}
void deletion_end(struct node *root)
{
    struct node *prev1;
    while (root->next != NULL)
    {
        prev1 = root;
        root = root->next;
    }
    prev1->next = NULL;
    root->prev = NULL;
    printf("::Deleted::\n");
    free(root);
}
struct node *deletion_begin(struct node *root)
{
    struct node *prev1 = root->next;
    root->next = NULL;
    prev1->prev = NULL;
    free(root);
    printf("::Deleted::\n");
    return prev1;
}
void deletion_position(struct node *root, int key1)
{
    int i = 1;
    while (i <= key1)
    {
        root = root->next;
        i++;
    }
    struct node *prev1 = root->prev;
    struct node *prev2 = root->next;
    prev1->next = prev2;
    prev2->prev = prev1;
    root->next = NULL;
    root->prev = NULL;
    printf("::Deleted::\n");
}
void Traversal(struct node *root)
{
    struct node *prev1;
    printf("Traversal in froward : ");
    while (root != NULL)
    {
        prev1 = root;
        printf("%d ", root->data);
        root = root->next;
    }
    printf("Traversal in backward : ");
    while (prev1 != NULL)
    {
        printf("%d ", prev1->data);
        prev1 = prev1->prev;
    }
}
int main()
{
    struct node *root = NULL;
    struct node *root2;
    int node_no, root_value, pos_no;
    printf("\n");
    printf("Enter the no. of nodes for implementation of linklist = ");
    scanf("%d", &node_no);
    int value;
    for (int i = 0; i < node_no; i++)
    {
        printf("Enter the value of node %d = ", i + 1);
        scanf("%d", &value);
        if (i == 0 && root == NULL)
        {
            root = create_node(value);
            root2 = root;
        }
        else
        {
            root = creation_end(root, value);
        }
    }
    int choice;
cont:
    printf("\n:://:://:://:://:://:://:://:://:://:://:://:://:://:://");
    printf("\n1.insertion_end\n2.deletion_end\n3.Traversal\n4.insertion_begin\n5.insertion_position\n6.deletion_begin\n7.deletion_position\n8.Exit\n");
    printf("Enter the choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Insertion process at the end: ");
        printf("Enter value of node to be insert : ");
        scanf("%d", &root_value);
        root = creation_end(root, root_value);
        goto cont;
        break;
    case 2:
        printf("Deletion process at the end: ");
        deletion_end(root2);
        goto cont;
        break;
    case 3:
        printf("Traversal process: ");
        Traversal(root2);
        goto cont;
        break;

    case 4:
        printf("Insertion process at the begin: ");
        printf("Enter value of node to be insert : ");
        scanf("%d", &root_value);
        root2 = insertion_begin(root2, root_value);
        goto cont;
        break;
    case 5:
        printf("Insertion process at the position: ");
        scanf("%d", &pos_no);
        printf("Enter value of node to be insert : ");
        scanf("%d", &root_value);
        insertion_position(root2, root_value, pos_no);
        goto cont;
        break;
    case 6:
        printf("Deletion process at the begin: ");
        root2 = deletion_begin(root2);
        goto cont;
        break;
    case 7:
        printf("Deletion process at the position: ");
        scanf("%d", &pos_no);
        deletion_position(root2, pos_no);
        goto cont;
        break;
    case 8:
        printf("Exit All Operations\n");
        break;
    }

    return 0;
}