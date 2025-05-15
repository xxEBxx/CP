#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

int main(){
    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        if(n/k==1 && n!=k){
            cout<<"NO"<<endl;
        }
        else{
            ll rep=n/k;
            cout<<"YES"<<endl<<1<<endl;
            cout<<rep<<endl;
        };
    }

}