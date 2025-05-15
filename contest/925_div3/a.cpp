#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int kk=0;kk<t;kk++){
        int n;
        cin>>n;
        //cout<<n;
        if (n>52){
            char a=(char) (n-52+96);
            cout<<a<<"zz"<<endl;
            continue;
        }
        else if (n>26){
            if(n==27){
                cout<<"aay"<<endl;
            }
            else{
            char a=(char) (n-1-26+96); //The -1 is for having a in the begining
            cout<<"a"<<a<<"z"<<endl;
            }
        }
        else{
            char a=(char) (n-2+96);
            cout<<"aa"<<a<<endl;
        }

    }
}

