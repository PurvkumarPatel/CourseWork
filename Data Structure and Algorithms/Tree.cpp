#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* right;
    node* left;
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* Buildtree(node* root) {
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new node(data);
    cout << "Enter left data of " << data << endl;
    root->left = Buildtree(root->left);
    cout << "Enter right data of " << data << endl;
    root->right = Buildtree(root->right);
    return root;
}

void levelor(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* temp = q.front();
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

void revror(node* root) {
    queue<node*> q;
    stack<int> ans; // Using a stack to reverse the output
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            ans.push(-1);
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            ans.push(temp->data);
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }

    while (!ans.empty()) {
        int temp = ans.top();
        ans.pop();
        temp == -1 ? cout << endl : cout << temp << " ";
    }
}

void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelbuild(node* &root) {
    queue<node*> q;
    cout << "Enter data of root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Left " << temp->data << endl;
        int l;
        cin >> l;
        if (l != -1) {
            temp->left = new node(l);
            q.push(temp->left);
        }
        cout << "Right " << temp->data << endl;
        int r;
        cin >> r;
        if (r != -1) {
            temp->right = new node(r);
            q.push(temp->right);
        }
    }
}

int nodecount(node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftCount = nodecount(root->left);
    int rightCount = nodecount(root->right);
    return (leftCount + rightCount + 1);
}

int heightofbtree(node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = heightofbtree(root->left);
    int right = heightofbtree(root->right);
    return max(left, right) + 1;
}

int diameterofbtree(node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = diameterofbtree(root->left);
    int right = diameterofbtree(root->right);
    int combo = heightofbtree(root->left) + heightofbtree(root->right) + 1;
    return max(max(left, right), combo);
}

pair<int, int> bothDianHeight(node* root) {
    if (root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = bothDianHeight(root->left);
    pair<int, int> right = bothDianHeight(root->right);

    int l = left.first;
    int r = right.first;
    int combo = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(max(l, r), combo); // diameter of tree
    ans.second = max(left.second, right.second) + 1; // height of tree
    return ans;
}

bool isBalaced(node* root) {
    if (root == NULL) {
        return 1;
    }
    bool left = isBalaced(root->left);
    bool right = isBalaced(root->right);
    bool diff = abs(heightofbtree(root->left) - heightofbtree(root->right)) <= 1;

    if (left && right && diff) {
        return 1;
    } else {
        return 0;
    }
}

pair<bool, int> BalacenHeight(node* root) {
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = BalacenHeight(root->left);
    pair<bool, int> right = BalacenHeight(root->right);
    bool diff = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    if (left.first && right.first && diff) {
        return ans = make_pair(true, max(left.second, right.second) + 1);
    } else {
        return ans = make_pair(false, max(left.second, right.second) + 1);
    }
}

bool isSameTree(node* p, node* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p != nullptr && q == nullptr || p == nullptr && q != nullptr) {
        return false;
    }
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    bool val = p->data == q->data;
    if (left && right && val) {
        return true;
    } else {
        return false;
    }
}

pair<bool, int> isSumBTree(node* root) {
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL) {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftpart = isSumBTree(root->left);
    pair<bool, int> rightpart = isSumBTree(root->right);

    int leftsum = leftpart.second;
    int rightsum = rightpart.second;
    bool con = root->data == leftsum + rightsum;

    pair<bool, int> ans;
    if (con && leftpart.first && rightpart.first) {
        ans.first = true;
        ans.second = 2 * (root->data);
    } else {
        ans.first = false;
    }
    return ans;
}

int main() {
    node* root = NULL;
    // root = Buildtree(root);
    levelbuild(root);
    cout << "level order" << endl;
    levelor(root);
    cout << "reverse order" << endl;
    revror(root);
    cout << endl << "inorder" << endl;
    inorder(root);
    cout << "preorder" << endl;
    preorder(root);
    cout << "postorder" << endl;
    postorder(root);
    cout << endl << "Total Nodes" << endl;
    cout << nodecount(root) << endl;
    cout << "Height of b tree" << endl;
    cout << heightofbtree(root) << endl;
    cout << "Diameter of b tree" << endl;
    cout << diameterofbtree(root) << endl;
    cout << "Both diameter and Height" << endl;
    cout << bothDianHeight(root).first << " " << bothDianHeight(root).second << endl;
    cout << "Tree is Balanced or not" << endl;
    cout << isBalaced(root) << endl;
    cout << "Tree is Balanced or its Height" << endl;
    cout << BalacenHeight(root).first << " " << BalacenHeight(root).second << endl;
    cout << "Tree is Sum Tree or not" << endl;
    cout << isSumBTree(root).first << endl;
    isSumBTree(root).first ? cout << "Sum of tree nodes " << isSumBTree(root).second << endl : cout << "not a sum tree";
    return 0;
}
