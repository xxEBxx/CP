#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore();
    string real,guess;
    cin>>real>>guess;
    //cout<<real<<"  "<<guess;
    int r=0,s=0;
    string real_copy="",guess_copy="";
    for(int i=0;i<t;i++){
        if(real[i]==guess[i]){
            //cout<<"worked in "<<i<<endl;
            r++;
        }
        else{
            real_copy+=real[i];
            guess_copy+=guess[i];
        }
    }
    int n=real_copy.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (real_copy[i]==guess_copy[j]){
                s++;
                guess_copy[j]='@';
                real_copy[i]='#';
            }
        }
    }
    cout<<r<<" "<<s;

}