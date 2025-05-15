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
    vvi arr(n,vi(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    set<int> s_hor,s_vert;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i-1][j]==1 && arr[i][j-1]==1){
                s_hor.insert(i);
                s_vert.insert(j);
            }
        }
    }

    cout<<min(s_hor.size(),s_vert.size())+1<<endl;

    return 0;
}