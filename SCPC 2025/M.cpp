#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)x

typedef long long ll;
typedef vector<ll> vi;

int main(){
    ll n,m;
    cin>>n>>m;
    vi curr(n);
    for (ll i=0;i<n;i++)
            cin>>curr[i];

    vi all;
    while(curr.size() > 1) {
        vi nxt;
        for (ll i=0;i<curr.size();i++) {
            all.push_back(curr[i]);
            if (i%2 == 0)
                nxt.push_back(curr[i]);
        }
        curr = nxt;
    }
    all.push_back(curr[0]);

    n = all.size();
    for (ll i=1;i<n;i++) {
        all[i] += all[i-1];
    }

    for (ll i=0;i<m;i++) {
        ll a;
        cin>>a;
        auto it  = upper_bound(all.begin(),all.end(),a);
        cout<<it-all.begin()<<endl;;
    }


}