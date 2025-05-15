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
    int t;cin>>t;
    while(t--){
        int n,k,q;cin>>n>>k>>q;
        vector<ll> position(k+1),time(1+k);
        position[0]=0;time[0]=0;
        for(int i=1;i<=k;i++)cin>>position[i];
        for(int i=1;i<=k;i++)cin>>time[i];
        for(int i=0;i<q;i++){
            ll val;cin>>val;
            //cout<<val<<endl;
            if(val==n){
                cout<<time[k]<<" ";
                continue;
            }
            ll index= prev(upper_bound(all(position),val))-position.begin();
            ll time_all=time[index+1]-time[index],pos_all=position[index+1]-position[index],pos_rel=val-position[index];
            cout<<time[index]+time_all*pos_rel/pos_all<<" ";
        }
        cout<<endl;
    }
    return 0;
}