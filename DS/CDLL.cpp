#include <iostream>
using namespace std;
class Node{
public:
    Node* prev;
    int data;
    Node* next;
    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};
void deleteanode(Node* &head,int loc){
    Node* temp=head;
    int i=1;
    if(loc==1){
        Node* y=temp->next;
        y->prev=head->prev;
        do{
            temp=temp->next;
        }while(temp->next!=head);
        temp->next=y;
        head=y;
        return;
    }
    while(i<loc-1){
        temp=temp->next;
        i++;
    }
    if(temp->next==head){
        Node* y=temp->prev;
        y->next=head;
        head->prev=y;
        return;
    }
    Node* y=temp->next;
    temp->next=y->next;
    y=y->next;
    y->prev=temp;
    return;
}
void insertathead(Node* &head,int val){
    Node* n=new Node(val);
    Node* temp=head;
    if(head==NULL){
        n->next=n;
        n->prev=n;
        head=n;
        return;
    }
    do{
        temp=temp->next;
    }while(temp->next!=head);
    temp->next=n;
    n->next=head;
    head->prev=n;
    head=n;
    return;
}
void insertattail(Node* &head,int val){
    Node* temp=head;
    Node* n= new Node(val);
    if(head==NULL){
        n->next=n;
        n->prev=n;
        head=n;
        return;
    }
    do{
        temp=temp->next;
    }while(temp->next!=head);
    n->prev=temp;
    n->next=head;
    temp->next=n;
    head->prev=n;
    return;
}
void insertanode(Node* &head,int val,int loc){
    Node* temp=head;
    int i=1;
    if(loc==1){
        insertathead(head,val);
        return;
    }
    Node* n=new Node(val);
    while(i<loc-1){
        temp=temp->next;
        i++;
    }
    if(temp->next==head){
        insertattail(head,val);
        return;
    }
    Node*y=temp->next;
    temp->next=n;
    n->prev=temp;
    n->next=y;
    y->prev=n;
    return;
}
void display(Node* head){
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    return;
}
int main(){
    Node* head;
    insertanode(head,1,1);
    insertanode(head,2,2);
    insertanode(head,3,3);
    insertanode(head,4,4);
    insertanode(head,5,5);
    insertathead(head,3);
    insertattail(head,2);
    deleteanode(head,7);
    display(head);
}
