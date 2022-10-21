#include <iostream>
using namespace std;
//infixTOpostfix
#define max 10
class Postfix {
    int top;
    int MAX;
    int *a;

public:

    Postfix() {
        top = -1;
        MAX = max;
        a = new int[MAX];
    }

    bool isEmpty(){
        if(top==-1)
            return true;
        return false;
    }
    bool Push(int val){
        if(top==10){
            return false;
        }
        a[++top]=val;
    }
    int Pop(){
        if(top==-1){
            return -1;
        }
        return a[top--];
    }
    int Peek(){
        return a[top];
    }

};
int getPriority (char alpha)
{
    if(alpha == '+' || alpha =='-')
        return 1;
    if(alpha == '*' || alpha =='/')
        return 2;
    if(alpha == '^')
        return 3;

    return 0;
}
void convert(string str1){
    string res=" ";
    Postfix p;
    int c;
    int i=0;
    string str='('+str1+')';
    while(str[i]!='\0'){
        if(isalpha(str[i])|| isdigit(str[i])){
            res+=str[i];
            i++;
        }
        else if(str[i]=='('){
            p.Push(str[i]);
            i++;
        }
        else if(str[i]==')'){
            while(p.Peek()!='('){
                res+=(char)p.Pop();
            }
            p.Pop();
            i++;
        }
        else{
            //top of the stack should have lower precedence value than str[i]
            while(!p.isEmpty() && getPriority(str[i])<= getPriority((char)p.Peek())){
                res+=(char)p.Pop();
            }
            p.Push(str[i]);
            i++;
        }
    }
    while(!p.isEmpty()){
        res+=(char)p.Pop();
    }
    cout<<res;
}
int main(){
    Postfix i;
    string s="a+b*c/d";
    convert(s);

}