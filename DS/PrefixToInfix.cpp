#include <iostream>
using namespace std;
class PretoIn{
private:
    int top;
    string* arr;
public:
    PretoIn(){
        top=-1;
        arr=new string[100];
    }
    bool Push(string s){
        if(top==20){
            return false;
        }
        arr[++top]=s;
    }
    string Pop(){
        if(top==-1){
            return 0;
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
        return false;
    }
};
void PreIn(string s){
    PretoIn p;
    string res;
    int i=0;
    while(s[i]!='\0'){
        if(isalpha(s[i])||isdigit(s[i])){
            p.Push(string(1,s[i]));
            i++;
        }
        else{
            string a=p.Pop();
            string b=p.Pop();
            res="("+a+s[i]+b+")";
            p.Push(res);
            i++;
        }
    }
    cout<<p.Peek();
}
string rev(string &s){
    int l=s.length();
    for(int i=0;i<l/2;i++){
        char temp=s[i];
        s[i]=s[l-i-1];
        s[l-i-1]=temp;
    }
    return s;
}
int main(){
    string s;
    cout<<"Enter a Prefix String: "<<endl;
    cin>>s;
    string str=rev(s);
    PreIn(str);
}