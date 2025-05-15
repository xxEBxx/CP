#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,a,b,c,d;
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        c=d=0;
        cin>>a;
        for(int i=1;i<n;i++){
            cin>>b;
            if(2*b>a) c++;
            else c=0;
            d+=(c>=k);
            a=b;}
        cout<<d<<endl;}
}