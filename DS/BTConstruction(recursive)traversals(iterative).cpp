#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data=0){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    Node* insert(int data,Node* root){
        Node* temp=new Node(data);
        if(root==NULL){
            root=temp;
            return root;
        }
        char direction[20];
        cout<<"Enter the direction: "<<endl;
        cin>>direction;
        Node* current;
        Node* prev;
        prev=NULL;
        current=root;
        int i=0;
        for(i=0;direction[i]!='\0'&&current!=NULL;i++){
            prev=current;
            if(direction[i]=='l'){
                current=current->left;
            }
            else{
                current=current->right;
            }
        }
        if(direction[i-1]=='l')
            prev->left=temp;
        else
            prev->right=temp;
        return root;
    };
};
class Stack{
private:
    Node* arr[20];
    int top;
    int size;
public:
    Stack(){
        top=-1;
        size=10;
    }
    void push(Node *root){
        if(isFull()){
            return;
        }
        arr[++top]=root;
        return;
    }
    Node* pop(){
        if(isEmpty()) {
            return NULL;
        }
        return arr[top--];
    }
    Node* peek(){
        if(isEmpty()) {
            return NULL;
        }
        return arr[top];
    }
    bool isFull(){
        if(top==size-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void preorderdisplay(Node* root){
            if(root==NULL){
                return;
            }
            Node* curr=root;
            Stack S;
            S.push(curr);
            for(;;){
                curr=S.pop();
                if(curr==NULL){
                    break;
                }
                cout<<curr->data<<" ";
                if(curr->right!=NULL){
                    S.push(curr->right);
                }
                if(curr->left!=NULL){
                    S.push(curr->left);
                }
            }

        }
        void inorderdisplay(Node* root){
        if(root==NULL){
            return;
        }
        Node* curr=root;
        Stack S;
        while(curr!=NULL || !S.isEmpty()){
            while(curr){
                S.push(curr);
                curr=curr->left;
            }
                curr=S.pop();
                if(curr==NULL){
                    return;
                }
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
        void postorderdisplay(Node* root){
        if(root==NULL){
            return;
        }
        Node* curr=root;
        Node* prev=NULL;
        Stack S;
        while(curr!=NULL ||!S.isEmpty()) {
            while(curr != NULL) {
                S.push(curr);
                curr = curr->left;
            }
                prev=S.peek()->right;
                if(prev==NULL){
                    prev=S.pop();
                    cout<<prev->data<<" ";
                    while(!S.isEmpty() and prev == S.peek()->right) {
                        prev = S.peek();
                        S.pop();
                        cout<<prev->data<<" ";
                    }
                }
                else{
                    curr=prev;
                }
            }
        }

};
    int height(Node *root) {
        int h = 0;
        if (root != NULL) {
            int lHeight = height(root->left);
            int rHeight = height(root->right);
            int maxHeight = max(lHeight, rHeight);
            h = maxHeight + 1;
        }
        return h;
    }
Node* createBT(){
    Node* p;
    int x;
    cout<<"Enter data(-1 for no data): "<<endl;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    p=new Node();
    p->data=x;
    cout<<"Enter the left child"<<x<<" "<<endl;
    p->left=createBT();
    cout<<"Enter the right child"<<x<<" "<<endl;
    p->right=createBT();
    return p;
}
int main(){
    Node* root;
    root=createBT();
    Stack s;
    s.preorderdisplay(root);
    cout<<endl;
    s.inorderdisplay(root);
    cout<<endl;
    s.postorderdisplay(root);
    cout<<height(root);
}
