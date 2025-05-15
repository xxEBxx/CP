#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,kk=0,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        kk++;
        cout<<"Case #"<<kk<<": ";
        if((k+1)%(1<<n)==0){
            cout<<"ON"<<endl;
        }
        else{
            cout<<"OFF"<<endl;
        }
    }
}