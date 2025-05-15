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
        ll n,m,k;cin>>n>>m>>k;
        vector<vector<ll>> arr(n,vector<ll>(m,0));
        ll w;cin>>w;
        vi weights(w);
        for(int i=0;i<w;i++)cin>>weights[i];

        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                ll dis_hor=min(i+1,n-i),dis_vert=min(j+1,m-j);
                dis_hor=min(dis_hor,n-k+1);
                dis_vert=min(dis_vert,m-k+1);
                if(dis_hor>k)dis_hor=k;
                if(dis_vert>k)dis_vert=k;
                arr[i][j]=dis_vert*dis_hor;
                //cout<<arr[i][j]<<" ";
            }
            //cout<<endl;
        }
        vector<ll> res(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i*m+j]=arr[i][j];
            }
        }
        sort(all(res));
        reverse(all(res));
        sort(all(weights));
        reverse(all(weights));
        ll ans=0;
        for(int i=0;i<w;i++){
            //cout<<res[i]<<" ";
            ans += res[i] * weights[i];
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}