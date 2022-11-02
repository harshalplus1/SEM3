#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void insertattail(Node* &head, int val){
    Node* temp=head;
    Node* n=new Node(val);
    if (temp==NULL){
        n->next=n;
        head=n;
        return;
    }
    do{
        temp=temp->next;
    }while(temp->next!=head);
    temp->next=n;
    n->next=head;
    return;
}
void insertathead(Node* &head,int val){
    Node* temp=head;
    Node* n=new Node(val);
    if(temp==NULL){
        n->next=n;
        head=n;
        return;
    }
    do{
        temp=temp->next;
    }while(temp->next!=head);
    temp->next=n;
    n->next=head;
    head=n;
    return;
}
void insertanode(Node* &head,int loc,int val){
    Node* temp=head;
    Node*n =new Node(val);
    int i=1;
    while(i<loc-1){
        temp=temp->next;
        i++;
    }
    if(temp->next==head){
        insertattail(head,val);
    }
    else if(loc==1){
        insertathead(head,val);
    }
    else {
        n->next = temp->next;
        temp->next = n;
    }
}
void display(Node* &head){
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}
void deleteathead(Node* &head){
    Node* temp=head;
    do{
        temp=temp->next;
    }while(temp->next!=head);
    Node* y=head;
    temp->next=y->next;
    head=y->next;
    return;
}
void deletenode(Node* &head,int loc){
    Node* temp=head;
    int i=1;
    if(loc==1){
        deleteathead(head);
        return;
    }
    while(i<loc){
        temp=temp->next;
        i++;
    }
    if(temp->next==head){
        Node* y=temp;
        do{
            temp=temp->next;
        }while(temp->next!=y);
        temp->next=head;
        return;
    }
    else{
        Node *y = temp->next;
        temp->next = y->next;
        return;
    }

}
int main(){
    Node* head;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertathead(head,0);
    insertanode(head,5,4);
    deletenode(head,1);
    display(head);
}

