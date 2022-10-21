#include <iostream>
using namespace std;
class PostEval{
    int* arr;
    int top;
public:
    PostEval(){
        top =-1;
        arr = new int[100];
    }
    bool Push(int val){
        if(top==20){
            return false;
        }
        arr[++top]=val;
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
};
int Eval(char s, int a, int b){
    switch(s){
        case '+': return (a+b);
        case '-': return (b-a);
        case '*': return (b*a);
        case '/': return (b/a);
    }
    return 0;
}
void Eval(string s){
    PostEval p;
    int i=0;
    int x;
    int ret;
    while(s[i]!='\0'){
        if(isdigit(s[i])||isalpha(s[i])){
            x= (int)s[i]-48;
            p.Push(x);
            i++;
        }
        else{
            ret= Eval(s[i], (int)p.Pop(),(int)p.Pop());
            p.Push(ret);
            i++;
        }
    }
    cout<<p.Peek();
}
int main(){
    string s;
    cout<<"Enter the Post Evaluated Expression:"<<endl;
    cin>>s;
    Eval(s);
}