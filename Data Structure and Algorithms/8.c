#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* temp = NULL;
void insert(struct node *root,struct node *New){
    char ch;
        if(New->data>root->data)
            ch='r';
        else if(New->data<root->data)
            ch='l';
        else
        {
            printf("\n:::Please don't repeat the node Value:::");
            return;
        }
    if(ch=='r')
    {
        if(root->right==NULL){
            root->right=New;
        }
        else
            insert(root->right,New);
    }
    else
    {
        if(root->left==NULL){
            root->left=New;
        }
        else
            insert(root->left,New);
    }
}
void inorder(struct node* node){
	if (node == NULL)
		return;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}
void preorder(struct node* node){
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preorder(node->left);
	preorder(node->right);
}
void postorder(struct node* node){
	if (node == NULL)
		return;
	postorder(node->left);
    postorder(node->right);
	printf("%d ", node->data);
}
int tree_height(struct node* node){
    if (node == NULL)
        return 0;
    else{
        int left_height = tree_height(node->left);
        int right_height = tree_height(node->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}
int getLeaf(struct node *node){
if(node == NULL)
	return 0;
if(node->left == NULL && node->right==NULL)
	printf("%d ",node->data);
else
	return getLeaf(node->left)+
		getLeaf(node->right);
}
struct node *get_node(){
    struct node *temp = malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void notcreated(){

    printf("\n\t:::Tree is not Created!!:::");
 
}
struct node * minValueNode(struct node* node){
   struct node* current = node;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}
struct node* deleteNode(struct node* root, int dele_data){
   if (root == NULL) return root;
      if (dele_data < root->data)
         root->left = deleteNode(root->left, dele_data);
      else if (dele_data > root->data)
         root->right = deleteNode(root->right, dele_data);
   else{
      if (root->left == NULL){
         struct node *temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL){
         struct node *temp = root->left;
         free(root);
         return temp;
      }
      struct node* temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
   }
   return root;
}
int search(struct node* node,int search_data){
    if(node == NULL)
    {
        printf("\n\t:::No,%d is not in Binary Search Tree:::",search_data);
        return 0;
    }
    if(node->data == search_data)
        printf("\n\t:::Yes,%d is in Binary Search Tree:::",search_data);
    else
    {
        if(search_data > node->data)
            search(node->right,search_data);
        else
            search(node->left,search_data);
    }
}

void main(){
    int choice;
    int height=0,level = 0,data=0,del_data=0;
    char ans='n';
    struct node *New,*root;
    root = NULL;
    do{
        printf("\n////////////////////////////////////////////////");
        printf("\n\tProgram For Implementing Simple Binary Tree");
        printf("\n\t1\t---->\tInsert");
        printf("\n\t2\t---->\tInorder");
        printf("\n\t3\t---->\tPreorder");
        printf("\n\t4\t---->\tPostorder");
        printf("\n\t5\t---->\tHeight of Binary Tree");
        printf("\n\t6\t---->\tValues of Leaf Nodes");
        printf("\n\t7\t---->\tSearch Node value");
        printf("\n\t8\t---->\tDelete");
        printf("\n\t9\t---->\tExit");
        printf("\n\n\tEnter your choice:");
        scanf("%d",&choice);
        printf("\n////////////////////////////////////////////////");
        switch(choice){
        case 1:{
                do{
                    New = get_node();
                    printf("\n\t--->Enter the new node value:");
                    scanf("%d",&New->data);
                    if(root==NULL)
                        root=New;
                    else{
                        printf("\n");
                        insert(root,New);
                        printf("\n");
                    }
                    check_moreelement:
                    printf("\tDo you want To Enter More Element?(Y/N):");
                    ans = getchar();
                    if(ans=='y'||ans=='Y'||ans=='n'||ans=='N'){}
                    else{
                       
                        printf("\n\t:::Please Enter (y/Y) or (n/N) only!:::");
                       
                        goto check_moreelement;
                    }
                }
                while(ans=='y'||ans=='Y');
                break;
            }
        case 2:{
                if(root==NULL)
                    notcreated();
                else{
                    printf("\n\t--->InOrder Traversal of tree is : ");
                    inorder(root);
                }
                break;
            }
        case 3:{
                if(root==NULL)
                    notcreated();
                else{
                    printf("\n\t--->PreOrder Traversal of tree is : ");
                    preorder(root);
                }
                break;
            }
        case 4:{
                if(root==NULL)
                    notcreated();
                else{
                    printf("\n\t--->PostOrder Traversal of tree is : ");
                    postorder(root);
                }
                break;
            }
        case 5:{
                if(root==NULL)
                    notcreated();
                else{
                    height = tree_height(root);
                    printf("\n\t\t--->Height of Tree is : %d",height-1);
                }
                break;
            }
        case 6:{
                if(root==NULL)
                    notcreated();
                else{
                    printf("\n\t--->Value of leaf Nodes is/are:");
                    getLeaf(root);
                }
                break;
            }
        case 7:{
                printf("\n\t--->Enter the data value to be Search:");
                scanf("%d",&data);
                search(root,data);
                break;
            }
        case 8:{
                printf("\n\t--->Enter the data value to be Deleted:");
                scanf("%d",&del_data);
                deleteNode(root,del_data);
                break;
            }
        case 9:
             exit(1);
             break;
        default :
            printf("\n\n:::Invalid Choice!:::\n");
        }
    }
    while(1);
}
