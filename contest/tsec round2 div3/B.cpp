#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        int type;
        ll l,r;
        cin >> type >> l >> r;
        ll total = r-l+1;
        r = sqrt(r);
        l = ceil(sqrt(l));
        if(type == 1)
            cout << r -l +1 << endl;
        else
            cout << total - (r-l+1) << endl;
    }
    return 0;
}//
// Created by benje on 10/23/2024.
//
