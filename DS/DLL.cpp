#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertathead(Node* &head, int data){
    Node* n=new Node(data);
    n->next=head;
    head->prev=n;
    head=n;
    return;
}
void insertattail(Node* &head, int data) {
    Node *temp = head;
    Node *n = new Node(data);
    if (temp == NULL) {
        n->next = head;
        head=n;
        return;
    }
    while(temp->next!=0){
        temp=temp->next;
    }
    n->prev=temp;
    temp->next=n;
    return;
}
void display(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insertanode(Node* &head,int data,int loc){
    Node* temp=head;
    int i=1;
    if(loc==1){
        insertathead(head,data);
        return;
    }
    while(i<loc-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    Node* n=new Node(data);
    Node* y=temp->next;
    temp->next=n;
    n->prev=temp;
    y->prev=n;
    n->next=y;
    return;
}
void deleteanode(Node* &head,int loc){
    Node* temp=head;
    int i=1;
    if(loc==1){
        temp=temp->next;
        temp->prev=NULL;
        head=temp;
        return;
    }
    while(i<loc-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    Node* y =temp->next;
    temp->next=y->next;
    Node* n=y->next;
    n->prev=temp;
    return;
}
int main(){
    Node* head;
    insertattail(head,3);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,3);
    insertattail(head,3);
    deleteanode(head,1);
    insertathead(head,3);
    insertathead(head,1);
    insertanode(head,2,1);
    display(head);
}