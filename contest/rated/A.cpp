#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if(a==b){
            for(int i=0;i<a;i++){
                cout<<1<<" ";
            }
        }
        else if(b==1){
            for(int i=0;i<a;i++){
                cout<<i+1<<" ";
            }
        }
        else{
            cout<<-1;
        }
        cout<<endl;
    }
}