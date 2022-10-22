#include <iostream>
using namespace std;
class PrefixEval{
private:
    int* arr;
    int top;
public:
    PrefixEval(){
        arr = new int[100];
        top = -1;
    }
    bool Push(int ele){
        if(top==20) {
            return false;
        }
        arr[++top]=ele;
        return true;
    }
    int Pop(){
        if(top==-1){
            return -1;
        }
        int x=arr[top];
        top--;
        return x;
    }
    int Peek(){
        return arr[top];
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};
int getEval(char s, int a, int b){
    switch(s){
        case '+': return (b+a);
        case '-': return (a-b);
        case '*': return (a*b);
        case '/': return (a/b);
    }
    return 0;
}
void Eval(string str){
    PrefixEval p;
    string res;
    int i=0;
    while(str[i]!='\0'){
        if(isalpha(str[i])|| isdigit(str[i])){
            p.Push((int)str[i]-'0');
            i++;
        }
        else{
            int ress=getEval(str[i], p.Pop(), p.Pop());
            p.Push(ress);
            i++;
        }
    }
    cout<<p.Peek();
}
string Rev(string &str){
    int l=str.length();
    for(int i=0;i<l/2;i++){
        char temp=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=temp;
    }
    return str;
}
int main(){
    string s;
    cout<<"Enter a Prefix Expression to be evaluated: "<<endl;
    cin>>s;
    s=Rev(s);
    Eval(s);
}