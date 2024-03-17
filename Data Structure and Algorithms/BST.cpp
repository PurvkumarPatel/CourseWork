#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* InsertintoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }
    if (d > root->data) {
        root->right = InsertintoBST(root->right, d);
    } else {
        root->left = InsertintoBST(root->left, d);
    }
    return root;
}

void takeinput(Node* &root) { 
    int d;
    cin >> d;
    while (d != -1) {
        root = InsertintoBST(root, d);
        cin >> d;
    }
}

void levelor(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) { 
                q.push(temp->left); 
            }
            if (temp->right) { 
                q.push(temp->right); 
            }
        }
    }
}

int minvalue(Node* root){
    if(root->left == NULL){
        return root->data;
    }
    return minvalue(root->left);
}
int maxvalue(Node* root){
    if(root->right == NULL){
        return root->data;
    }
    return maxvalue(root->right);
}
Node* deletenode(Node* root,int val){
    if(root == NULL){
        return root;
    }
    if(root->data == val){
        //delete operation
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right != NULL){
            int min = minvalue(root->right);
            root->data = min;
            root->right = deletenode(root->right,min);
        }
        
    }
    else if(val > root->data){
        root->right = deletenode(root->right,val);
        return root;
    } else{
        root->left = deletenode(root->left,val);
        return root;
    }
    return root;
}
void findpresuc(Node* root,int key,Node*& pre,Node*& suc){
    while(root){
        if(root->data == key){
            if(root->left){
                pre = root->left;
                while(pre->right){
                    pre = pre->right;
                }
            }
            if(root->right){
                suc = root->right;
                while(suc->left){
                    suc = suc->left;
                }
            }
            return;
        } else if(root->data > key){
            suc = root;
            root = root->left;
        } else{
            pre = root;
            root = root->right;
        }
    }
}
int main() {
    Node* root = NULL;
    cout << "Enter data to create BST" << endl;
    takeinput(root);
    cout << "Print BST" << endl;
    levelor(root);
    cout<<"Max value "<< maxvalue(root) <<endl;
    cout<<"Min value "<< minvalue(root) <<endl;
    deletenode(root,2);
    cout << "Print BST" << endl;
    levelor(root);
    Node* pre = NULL;
    Node* suc = NULL;
    findpresuc(root,7,pre,suc);
    if(pre){
        cout<<"Predecessor "<<pre->data<<endl;    
    } else{ cout<<"No pre"<<endl;}
    if(suc){
        cout<<"Successor "<<suc->data<<endl;
    } else{ cout<<"No suc"<<endl;}
    
}
