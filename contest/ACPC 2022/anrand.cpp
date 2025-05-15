#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair< ll, ll> ii;
typedef pair<ll,ll> pl;
typedef vector< ll> vi;
typedef vector<vector< ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const  ll maxn=( ll)1e6+7;
const  ll mod=( ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

unordered_map< ll, ll> know,dp,counter;
set<ll> elems;

 ll solve( ll mex){
    if(mex==0)
        return 0;
    if(know[mex]==1)
        return dp[mex];
    ll res=1e18;
    for(auto elem : elems){
        if(elem >= mex)break;
        res=min(res, (counter[elem]-1) * mex +elem+ solve(elem));
    }
    know[mex]=1;
    return dp[mex]=res;
}

 int main(){fast();
     ll t;cin>>t;
    while(t--){
        elems.clear();
        know.clear();
        dp.clear();
        counter.clear();
         ll n;cin>>n;
        for( ll i=0;i<n;i++){
            ll val;cin>>val;
            elems.insert(val);
            counter[val]++;}

        ll first_mex=0;
        for( ll elem : elems){
            if(first_mex != elem)break;
            first_mex++;
        }

         ll res=1e18;
        for(ll elem :elems){
            if(elem > first_mex)break;
            res=min(res,solve(elem));
        }
        cout<<solve(first_mex)<<endl;
    }
    return 0;
}