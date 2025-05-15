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
        int n,m;cin>>n>>m;
        vector<pair<int,int>> pairat(1+m),to_st_on(1+n,{0,-1});
        for(int i=1;i<=m;i++)
            cin>>pairat[i].f>>pairat[i].s;
        int q;cin>>q;
        for(int i=1;i<=q;i++){
            int index;cin>>index;
            to_st_on[index].f = 1;
            to_st_on[index].s = i;
        }

        vector<vector<pair<int,int>>> st(n+1,vector<pair<int,int>> (20,{0,-1}));

        for(int i=1;i<=n;i++){
            st[i][0]=to_st_on[i];
        }

        for(int j=1;j<20;j++){
            for(int i=1;i+(1<<j) <= n ;i++){
                st[i][j] = {
                        st[i][j-1].f + st[i+(1<<j)][j-1].f,
                        max(st[i][j-1].s , st[i+(1<<j)][j-1].s)};
            }
        }
        int res=-1,best_time=1e9;
        for(int i=1;i<m;i++){
            int r=pairat[i].s,l=pairat[i].f;
            int diff = l-r;
            int last_added=-1,generated=0;
            for(int j=20;j>=0;j--){
                if((1<<j) <= diff){
                    diff -= (1<<j);
                    l += (1<<j);
                    generated += st[l][j].f ;
                    last_added = max(last_added,st[l][j].s);
                }
            }
            if(generated > ((l-r)/2) && ){

            }

        }

    }
    return 0;
}