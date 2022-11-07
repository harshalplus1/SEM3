#include <iostream>
//polynomial
using namespace std;
class Node{
public:
    int coeff;
    int exp;
    Node* next;
    Node(int num1,int num2){
        coeff=num1;
        exp=num2;
        next=NULL;
    }
};
void insert(Node* &head, int num1,int num2) {
    Node *temp = head;
    Node *n = new Node(num1, num2);
    if (temp == NULL) {
        head = n;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
    return;
}
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<"+"<<temp->coeff<<"x^"<<temp->exp;
        temp=temp->next;
    }

}
void add(Node* one,Node* two){
    Node* poly=NULL;
    Node* ptr1=one;
    Node* ptr2=two;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->exp==ptr2->exp){
            insert(poly,ptr1->coeff+ptr2->coeff,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->exp>ptr2->exp){
            insert(poly,ptr1->coeff,ptr1->exp);
            ptr1=ptr1->next;
        }
        else if(ptr1->exp<ptr2->exp){
            insert(poly,ptr2->coeff,ptr2->exp);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        insert(poly,ptr1->coeff,ptr1->exp);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        insert(poly,ptr2->coeff,ptr2->exp);
        ptr2=ptr2->next;
    }
    cout<<endl;
    cout<<"Result: "<<endl;
    display(poly);
}
int main(){
    Node* head=NULL;
    int n,c,e;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the coefficients Polynomial 1: "<<endl;
        cin>>c;
        cout<<"Enter the exponents of the Polynomial 1: "<<endl;
        cin>>e;
        insert(head,c,e);
    }
    cout<<endl;
    Node* head1= NULL;
    int n1,c1,e1;
    cout<<"Enter the number of terms of Polynomial 2: "<<endl;
    cin>>n1;
    for(int i=0;i<n1;i++){
        cout<<"Enter the coefficients Polynomial 1: "<<endl;
        cin>>c1;
        cout<<"Enter the exponents of the Polynomial 1: "<<endl;
        cin>>e1;
        insert(head1,c1,e1);
    }
    cout<<"Polynomial 1 is: "<<endl;
    display(head);
    cout<<endl;
    cout<<"Polynomial 2 is: "<<endl;
    display(head1);
    add(head,head1);
    cout<<endl;
}
