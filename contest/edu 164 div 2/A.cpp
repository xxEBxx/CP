#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(v) v.begin(),v.end()

int main(){
    int t;cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;
        int biggest=n/m + (1-(n%m==0));
        if(n-biggest <= k )cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}