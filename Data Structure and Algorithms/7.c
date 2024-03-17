#include<stdio.h>
#include<stdlib.h>

int choice,Insertingnodevalue;
struct TR
{
int data;
struct TR *left;
struct TR *right;
};

struct TR *insert(struct TR *root,int Insertingnodevalueue);
void inorderTraversal(struct TR *);
struct TR *createTR(int);
void preorderTraversal (struct TR*);
void postorderTraversal (struct TR* );
int Height(struct TR* );
void traversal(struct TR *);
void printLeafnodes(struct TR *);

void main() {int rv;
    printf("---------->Enter Root Value:>");
    scanf("%d",&rv);
  struct TR* root = createTR(rv);
  asd:
  printf("\n\t**1.Insertion of element\n\t**2.Traversal\n\t**3.Height\n\t**4.Print Leafnodes\n\t**5.Exit\n\t");
  scanf("%d",&choice);
if(choice==1){
      printf("\n---------->Enter value:>");
  scanf("%d",&Insertingnodevalue);
  insert(root,Insertingnodevalue);
}
else if(choice == 2){
    traversal(root);
}
else if(choice == 3){
    printf("\n---------->Height :> %d\n",(Height(root))-1);
}
else if(choice == 4){
    printLeafnodes(root);
printf("\n---------->");

}
else if(choice == 5)
{printf("---------->Exit from program");
 exit(0);}
else {
    printf("---------->Invalid Value");}
  goto asd;
}
/*Building Tree*/

struct TR *insert(struct TR *root, int Insertingnodevalueue){
    int lor;
printf("---------->Insert-->Left(1)---Right(2) of %d:",root->data);
scanf("%d",&lor);

if(lor == 2){
    if(root->right == NULL){
        root->right = createTR(Insertingnodevalueue);
        return root->right;
    }
    else{insert(root->right,Insertingnodevalueue);}
}
else if(lor == 1){
    if(root->left == NULL){
        root->left = createTR(Insertingnodevalueue);
        return root->left;
        }
    else{insert(root->left,Insertingnodevalueue);}
}
else
{
    printf("---------->Invalid Input");
}
}

struct TR *createTR( int Insertingnodevalueue){
    struct TR* newTR = malloc(sizeof(struct TR));
    newTR->data = Insertingnodevalueue;
     newTR->right = NULL;
newTR->left = NULL;
return newTR;
}

/*Traversal of TREE*/

void traversal(struct TR *root){
printf("---------->Inorder traversal: \n");
inorderTraversal(root);


printf("\n---------->Preorder traversal: \n");
preorderTraversal(root);

printf("\n---------->InPostorder traversal: \n");
postorderTraversal(root);
}

void inorderTraversal(struct TR *root)
{
    if (root == NULL) return;
    inorderTraversal(root->left) ;
    printf("%d\t", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal (struct TR* root)
{
    if (root == NULL) return;
    printf("%d\t", root->data);
    preorderTraversal (root->left);
    preorderTraversal (root->right);
     }

void postorderTraversal (struct TR* root)
{
    if (root == NULL) return;
postorderTraversal (root->left);
postorderTraversal(root->right);
printf("%d\t", root->data);
}
/*Height Find*/
int Height(struct TR* root)
{
if (root == NULL)
 return 0;

else {

int lDepth = Height(root->left);
int rDepth = Height(root->right);

if (lDepth> rDepth)
   return (lDepth+1);
else
  return(rDepth+1);
}
}

/*Printing Leaf TRs*/
void printLeafnodes(struct TR *root)
{
    if (!root)
        return;

 if (!root->left && !root->right)
    {
      printf("%d\t",root->data);
     return;
    }
if (root->left)
  printLeafnodes(root->left);

if (root->right)
  printLeafnodes(root->right);
}
