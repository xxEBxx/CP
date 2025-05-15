#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
const int maxn=(int)2002;


int main(){
    int tt;cin>>tt;
    while(tt--){
        int n,f,h;
        cin>>n>>h>>f;
        vi dp(h+1,0);
        vvi arr(n+1,vi(h+1,0));
        for(int i=0;i<n;i++){
            int m;cin>>m;
            for(int j=0;j<m;j++){
                int v;cin>>v;
                arr[i][v-1]++;
            }
        }

//our dp is basically only caring about the best acorn when we are on a certain height
        for(int tree=0;tree<n;tree++){
            dp[0]=max(dp[0],arr[tree][0]);
        }

        for(int height=1;height<h;height++){
            for(int tree=0;tree<n;tree++){
                arr[tree][height] += max(
                        arr[tree][height-1],
                        (height-f >= 0)?dp[height-f]:0
                        );
                dp[height]=max(dp[height],arr[tree][height]);
            }

        }
        cout<<dp[h-1]<<endl;
    }
    return 0;
}