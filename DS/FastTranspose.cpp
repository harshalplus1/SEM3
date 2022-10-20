//Fast Transpose
#include<iostream>
using namespace std;
class Sparse{
private:
    int row,col,val;
public:
    void createSMT(int r, int c, int v){
        row=r;
        col=c;
        val=v;
    }
    void display(){
        cout<<row<<" "<<col<<" "<<val<<" "<<endl;
    }
    void Ftrans(Sparse s[]){
        int trans[100][3];
        int total[s[0].col];
        int index[s[0].col+1];
        int loc;
        int colno;
        for(int i=0;i<s[0].col;i++){
            total[i]=0;
        }
        for(int i=1;i<s[0].val;i++){
            colno=s[i].col;
            total[colno]++;
        }
        index[0]=1;
        for(int i=1;i<s[0].col;i++){
            index[i]=index[i-1]+total[i-1];
        }
        trans[0][0]=s[0].col;
        trans[0][1]=s[0].row;
        trans[0][2]=s[0].val;
        for(int i=1;i<s[0].val;i++){
            colno=s[i].col;
            loc=index[colno];
            trans[loc][0]=s[i].col;
            trans[loc][1]=s[i].row;
            trans[loc][2]=s[i].val;
            index[colno]++;
        }
        for(int i=0;i<s[0].val;i++){
            for(int j=0;j<3;j++){
                cout<<trans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Sparse s[100];
    int r=3;
    int c=3;
    int arr[r][c];
    int cnt=1;
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    for(int i =0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!=0) {
                s[cnt].createSMT(i, j, arr[i][j]);
                cnt++;
            }
        }
    }
    s[0].createSMT(r,c,cnt);
    cout<<"Sparse Matrix:"<<endl;
    for(int i=0;i<cnt;i++){
        s[i].display();
    }
    cout<<"Fast Transpose of Sparse Matrix:"<<endl;
    s[23].Ftrans(s);
}