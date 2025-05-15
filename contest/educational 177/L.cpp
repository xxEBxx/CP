#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;

int main(){fast();
        ll n,m,k;cin>>n>>m>>k;
        vector<ll> a(n);
        map<ll,ll> start,end;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<m;i++){
            ll val;cin>>val;
            start[val]++;
        }
        for(ll i=0;i<k;i++){
            ll val;cin>>val;
            end[val]++;
        }

        ll av_start=0,res=0;
        for(ll i=0;i<n;i++){
            if(end[a[i]] > 0){
                res+=av_start;
            }
            else if(start[a[i]] > 0){
                av_start++;
            }
        }
        cout<<res<<endl;


    return 0;
}