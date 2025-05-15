#include<iostream>
using namespace std;

char no_elem(char e1,char e2){
    if ('A'!=e1 && 'A'!=e2){
        return 'A';
    }
    if ('B'!=e1 && 'B'!=e2){
        return 'B';
    }
    return 'C';
}

int main(){
    int t,r,c;
    char arr[3][3];
    char res,e1,e2;
    cin>>t;
    for (int k=0;k<t;k++){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                cin>>arr[i][j];
                if (arr[i][j]=='?'){
                    r=i;
                    c=j;
                }
            }
    }
    if (c==0){
        e1=arr[r][1];
        e2=arr[r][2];
    }
    else if (c==1){
    e1=arr[r][0];
    e2=arr[r][2];     
    }
    else{
    e1=arr[r][1];
    e2=arr[r][0];
    }
    cout<<no_elem(e1,e2)<<"\n";
    }
}