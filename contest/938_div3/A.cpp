

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        if (a*2 < b){
            cout<<n*a<<endl;
        }
        else{
            int res=n/2 *b;
            if(n & 1)res+=a;
            cout<<res<<endl;
        }
    }
}