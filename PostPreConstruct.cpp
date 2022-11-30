#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node*right;
    Node(int ele){
        data=ele;
        left=NULL;
        right=NULL;
    }
};
int findIndex(int inorder[],int val,int size){
    int index=-1;
    for(int i=0;i<size;i++){
        if(inorder[i]==val){
            index=i;
            return index;
        }
    }
    return index;
}

Node* constructBin(int inorder[],int postorder[],int start,int end,int *post,int size){
    if(start>end||(*post)<0){
        return NULL;
    }
    int rootindex=findIndex(inorder,postorder[*post],size);
    Node* root=new Node(inorder[rootindex]);
    *post=*post-1;
    root->right= constructBin(inorder,postorder,rootindex+1,end,post,size);
    root->left= constructBin(inorder,postorder,start,rootindex-1,post,size);
    return root;
}
void inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
    return;

}
int main(){
    Node* root;
    Node* hel;
    int size = 6;
    int post=size-1;// size of the array
    int inorder[] = {4, 2, 5, 1, 6, 3};   // inOrderTraversal sequence
    int postorder[] = {4, 5, 2, 6, 3, 1};
    root= constructBin(inorder,postorder,0,size-1,&post,size);
    inorderTraversal(root);
}
