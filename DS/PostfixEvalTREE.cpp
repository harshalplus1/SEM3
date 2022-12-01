#include <iostream>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;

    Node(char ele){
        data=ele;
        left=NULL;
        right=NULL;
    }
};
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'){
        return true;
    }
    return false;
}
class Stack{
    Node* arr[20];
    int top;
    int size;
public:
    Stack(){
        top=-1;
        size=20;
    }
    void push(Node* s){
        if(top==size-1){
            return;
        }
        top++;
        arr[top]=s;
    }
    Node* pop(){
        if(top==-1){
            return NULL;
        }
        return arr[top--];
    }
    bool isFull(){
        if(top==size-1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    Node* peek() {
        if (!isEmpty()){
             return arr[top];
        }
        return NULL;
    }
};

Node* createBT(string s){
    Stack s1;
    for(int i=0;s[i]!='\0';i++){
        if(!isOperator(s[i])){
            Node* temp=new Node((s[i]));
            s1.push(temp);
        }
        else {
            Node *temp = new Node(s[i]);
            temp->right = s1.pop();
            temp->left = s1.pop();
            s1.push(temp);
        }
    }
    return s1.peek();
}
int operate(int a,int b,char c){
    switch(c){
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;
    }
}
int eval(Node* root){
    Node* temp=root;
    if(isOperator(root->data)){
        int l=eval(root->left);
        int r=eval(root->right);
        return operate(l,r,root->data);
    }
    else{
        int num=(int) root->data-'0';
        return num;
    }
}

void infix(Node* root){
    if(root==NULL){
        return;
    }
    infix(root->left);
    cout<<root->data;
    infix(root->right);
}

int main(){
    string s;
    cout<<"Enter a postfix expression";
    cin>>s;
    Node *root=createBT(s);
    infix(root);
    cout<<endl<<eval(root);
}
