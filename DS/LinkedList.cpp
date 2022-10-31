#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
void insertattail(Node* &head,int data){
    Node* temp=head;
    Node* n = new Node(data);
    if(temp==NULL){
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
void insertnode(Node* &head, int val, int loc) {
    Node *temp = head;
    Node *y = head;
    Node *n = new Node(val);
    int i = 1;
    //insertathead bhi yahi hai
    if (loc == 1) {
        n->next = head;
        head = n;
        return;
    }
    while (i < loc - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp != NULL) {
        y = temp->next;
        n->next = y;
        temp->next = n;
    } else {
        cout << endl;
        cout << "Wrong Index. Did not insert";
        return;
    }
}

    void deletenode(Node* &head,int loc) {
        Node *temp = head;
        int i = 1;
        if (loc == 1) {
            Node *x = temp;
            temp = x->next;
            head=temp;
            return;
        }
        else{
            while (i < loc - 1 && temp != NULL) {
                temp = temp->next;
                i++;
            }
            Node *y = temp->next;
            temp->next = y->next;
        }
    }
    int lengthLL(Node* head){
         int cnt=1;
         Node* temp=head;
         while(temp->next!=NULL){
             temp=temp->next;
             cnt++;
         }
         return cnt;
    }
int main() {
    Node* head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    display(head);
    insertnode(head->next,3,3);//4th location
    cout<<endl;
    display(head);
    deletenode(head,1);
    cout<<endl;
    display(head);

}
