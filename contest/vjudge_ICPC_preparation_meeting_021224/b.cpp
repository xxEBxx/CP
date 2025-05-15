#include<iostream>
#include<string>
using namespace std;

char find_char(string s){
    if(s[0]!='A' && s[1]!='A' && s[2]!='A'){
        return 'A';
    }
    if(s[0]!='B' && s[1]!='B' && s[2]!='B'){
        return 'B';
    }
    return 'C';
}

int main(){
    char a,b,c;
    string arr[3];
    int t;
    cin>>t;
    cin.ignore();
    for (int kk=0;kk<t;kk++){
        int row;
        for(int i=0;i<3;i++){
            getline(cin,arr[i]);
            if (arr[i][0]=='?'|| arr[i][1]=='?'|| arr[i][2]=='?'){
                row=i;
            }
        }
        cout<<find_char(arr[row])<<endl;
    }

}