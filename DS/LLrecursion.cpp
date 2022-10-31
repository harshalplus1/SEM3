#include <iostream>
using namespace std;
struct Node {
    Node *next;
    int data;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
        void insert(Node* &head,int loc,int val){
            Node* y=new Node(val);
            Node* temp=head;
            if(loc==1){
                y->next=head;
                head=y;
                return;
            }
            else if(loc==2){
                y->next=temp->next;
                temp->next=y;
                return;
            }
            else {
                Node *temp2 = head;
                insert(temp2->next, loc - 1, val);
            }
        }
        void insertattail(Node* &head, int val){
            Node* temp=head;
            Node* y=new Node(val);
            if(temp==NULL){
                head=y;
                return;
            }
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=y;
        }
        void display(Node* head){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
int main(){
    Node* head;
    insertattail(head,3);
    insertattail(head,3);
    insertattail(head,3);
    insertattail(head,3);
    insert(head,1,4);
    display(head);
}