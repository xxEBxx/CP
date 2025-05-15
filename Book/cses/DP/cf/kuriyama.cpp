#include<bits/stdc++.h>
//link : https://codeforces.com/problemset/problem/433/B

using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    vector<ll> v(n);
    for(ll &a:v)cin>>a;
    vector<ll> ps(n),sortps(n);
    ps[0]=v[0];
    for(int i=1;i<n;i++){
        ps[i]=ps[i-1]+v[i];
    }
    sort(v.begin(),v.end());
    sortps[0]=v[0];
    for(int i=1;i<n;i++){
        sortps[i]=sortps[i-1]+v[i];
    }
    int t;cin>>t;
    while(t--){
        int a,b,c;cin>>a>>b>>c;
        b--;c--;
        if(a==1) {
            if(b!=0)cout << ps[c] - ps[b - 1] << endl;
            else cout << ps[c]<< endl;
        }
        else {
            if(b!=0)cout << sortps[c] - sortps[b - 1] << endl;
            else cout<<sortps[c]<<endl;
        }
    }
    return 0;
}