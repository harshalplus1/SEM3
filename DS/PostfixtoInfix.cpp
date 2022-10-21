#include <iostream>
using namespace std;
class PosttoIn{
    string* arr;
    int top;
public:
    PosttoIn(){
        arr=new string[100];
        top=-1;
    }
    bool Push(string s){
        if(top==20){
            return false;
        }
        arr[++top]=s;
    }
    string Pop(){
        if(top==-1) {
            return "no";
        }
        string x=arr[top];
        top--;
        return x;
    }
    string Peek(){
        return arr[top];
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else {
            return false;
        }
    }
};
void conIn(string str){
    PosttoIn p;
    string r="";
    int i=0;
    while(str[i]!='\0'){
        if(isalpha(str[i])|| isdigit(str[i])){
            p.Push(string(1,str[i]));
            i++;
        }
        else{
            string a=p.Pop();
            string b=p.Pop();
            r+='('+b+str[i]+a+')';
            p.Push(r);
            i++;
        }
    }
    string output=p.Peek();
    cout<<output;
}
int main(){
    cout<<"Enter a Postfix Expression: ";
    string s;
    cin>>s;
    conIn(s);
}