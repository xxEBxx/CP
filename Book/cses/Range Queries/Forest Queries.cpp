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
        int n,m;cin>>n>>m;
        vvi arr(n+1,vi(n+1,0)),ps(1+n,vi(n+1,0));
        for(int i=1;i<=n;i++){
            string s;cin>>s;
            for(int j=0;j<n;j++){
                if(s[j]=='*')
                    arr[i][j+1]++;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ps[i][j] = arr[i][j] + ps[i][j-1] + ps[i-1][j]-ps[i-1][j-1];
            }
        }

        for(int i=0;i<m;i++){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            int res= ps[x2][y2] - ps[x2][y1-1] - ps[x1-1][y2] + ps[x1-1][y1-1];
            cout<<res<<endl;
        }

    return 0;
}