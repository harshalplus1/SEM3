#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int ele){
        data=ele;
        right=NULL;
        left=NULL;
    }
};
void Search(Node* &curr,int key,Node* &par){
    while(curr!=NULL && curr->data!=key){
        par=curr;
        if(key<curr->data){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}
Node* getmin(Node* curr){
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* insert(Node* &root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(key);
    }

    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }

        // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }

    return root;
}
void delete1(Node* &root,int key){
    Node* parent=NULL;
    Node* curr=root;
    Search(curr,key,parent);
    if(curr==NULL){
        return;
    }
    if(curr->left==NULL&&curr->right==NULL){
        if(curr!=root){
            if(parent->left==curr){
                parent->left=NULL;
            }
            else{
                parent->right=NULL;
            }
        }
        else{
            root=NULL;
        }
    }
    else if(curr->left &&curr->right){
        Node* succ=getmin(curr->right);
        int val=succ->data;
        delete1(root,succ->data);
        curr->data=val;
    }
    else{
        Node* child=(curr->left)?curr->left:curr->right;
        if(curr!=root){
            if(curr==parent->left){
                parent->left=child;
            }else{
                parent->right=child;
            }
        }else{
            root=child;
        }
    }
}
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    int keys[] = { 15, 10, 20, 8, 12, 16 };

    Node* root = NULL;
    for (int key: keys) {
        root = insert(root, key);
    }
    inorder(root);
    cout<<endl;
    delete1(root, 16);
    inorder(root);
    return 0;
}
