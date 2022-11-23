#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* insert(Node* &root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left= insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void findparent(Node* root, int val,int par){
    if(root==NULL){
        return;
    }
    if(root->data==val){
        cout<<"Parent of the Current Node is: "<<par;
    }
    else{
        findparent(root->left,val,root->data);
        findparent(root->right,val,root->data);
    }
}
void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1) {
        cout << root->data << " ";
    }
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void levelorder(Node* root)
{
    int h = 4;
    int i;
    for (i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
        cout<<endl;
    }
}
int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int ln=count(root->left);
    int rn=count(root->right);
    return ln+rn+1;
}
int main() {
    Node* root=NULL;
    root=insert(root,5);
    insert(root,2);
    insert(root,3);
    insert(root,1);
    insert(root,6);
    insert(root,0);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    findparent(root,7,-1);
    cout<<endl;
    int cn=count(root);
    cout<<cn<<endl;
    levelorder(root);
}
