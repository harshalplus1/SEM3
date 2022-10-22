#include <iostream>
using namespace std;
class IntoPre{
private:
    int* arr;
    int top;
public:
    IntoPre() {
        arr = new int[100];
        top = -1;
    }
    bool Push(int s){
        if(top==20){
            return false;
        }
        arr[++top]=s;
        return true;
    }
    int Pop(){
        if(top==-1){
            return 0;
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
int Priority(char s){
    switch(s){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
        case '$':
            return 3;
    }
    return 0;
}

void IntoPrefix(string res){
    IntoPre l;
    string result;
    int i=0;
    while(res[i]!='\0'){
        if(isalpha(res[i])||isdigit(res[i])){
            result+=res[i];
            i++;
        }
        else if(res[i]=='('){
            l.Push(res[i]);
            i++;
        }
        else if(res[i]==')'){
            while(l.Peek()!='('){
                result+=(char)l.Pop();
            }
            l.Pop();
            i++;
        }
        else{
            while(!l.isEmpty() && Priority(res[i])<= Priority((char)l.Peek())){
                result+=(char)l.Pop();
            }
            l.Push(res[i]);
            i++;
        }
    }
    int x=result.length();
    for(int z=0;z<x/2;z++){
        char temp=result[z];
        result[z]=result[x-z-1];
        result[x-z-1]=temp;
    }
    cout<<result;


}
string rev(string &str){
    char temp;
    int l=str.length();
    for(int i=0;i<l/2;i++){
        temp=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=temp;
    }
    for(int i=0;i<l;i++){
        if(str[i]==')'){
            str[i]='(';
        }
        else if(str[i]=='('){
            str[i]=')';
        }
    }
    return str;
}
int main(){
    string s="(a*b+c)";
    string res=rev(s);
    IntoPrefix(res);
}