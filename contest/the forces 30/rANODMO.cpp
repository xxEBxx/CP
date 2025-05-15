#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int before=k,after=(k/n) + k ;
        while(before < after){
            before=after;
            after=(after/n)+k;
        }
        cout<<after<<endl;
    }
}