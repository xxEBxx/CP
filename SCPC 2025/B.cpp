#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)x

typedef long long ll;
typedef vector<ll> vi;

int main(){
    ll n,k;
    cin>>n>>k;

    vi arr(n);
    ll res = -1;
    for (ll i=0;i<n;i++){
        cin >> arr[i];
        ll poss = arr[i]-i-i;
        if (poss >= k) {
            if (res == -1)
                res = poss;
            else
                res = min(res,poss);
        }
    }
    cout<<res<<endl;

}
