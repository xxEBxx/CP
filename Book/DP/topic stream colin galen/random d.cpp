#include<bits/stdc++.h>

using namespace std;

const int mod=998244353;

int main(){
    int n;cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<string> vv=v ;
    sort(v.begin(),v.end());
    string x=v[0];

    if(v[0]==vv[0])
        x=v[1];

    int sum=0;
    for(int i=0 ; i < x.size() ; i++){
        sum *= 10 ;
        sum += x[i]-'0';
        sum %= mod;
    }
    cout<<(sum*n)%mod<<endl;

    return 0;
}