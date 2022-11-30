#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
int FindIndex(int inorder[],int val,int size){
    int index=-1;
    for(int i=0;i<size;i++){
        if(inorder[i]==val){
            index=i;
            return index;
        }
    }
    return -1;
}
Node* constructBin(int inorder[],int preorder[],int start,int end,int *prein,int size){
    if(start>end || (*prein)>>size){
        return NULL;
    }
    int rootindex= FindIndex(inorder,preorder[*prein],size);
    Node* root=new Node(inorder[rootindex]);
    *prein=*prein+1;
    root->left= constructBin(inorder,preorder,start,rootindex-1,prein,size);
    root->right= constructBin(inorder,preorder,rootindex+1,end,prein,size);
    return root;
}
Node* inorderTraversal(Node* root){
    if(root==NULL){
        return NULL;
    }
    inorderTraversal(root->left);
    cout<<root->data<<endl;
    inorderTraversal(root->right);

}
Node* preorderTraversal(Node* root){
    if(root==NULL){
        return NULL;
    }
    cout<<root->data<<endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);

}
int main() {

    int size = 6;                        // size of the array
    int inOrder[] = {4, 2, 5, 1, 6, 3};  // inOrderTraversal sequence
    int preOrder[] = {1, 2, 4, 5, 3, 6}; // preOrderTraversal sequence
    int preIndex = 0;                    // pre order traversal index to keep track of subtree root nodes
    Node *root = constructBin(inOrder, preOrder, 0, size - 1, &preIndex, size);
    cout << "The inOrderTraversal of the binary tree  is: ";
    preorderTraversal(root);
    return 0;
}
