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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
    int r,c,n,p;
    cin>>r>>c>>n>>p;
    vvi arr(r,vi(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    set<int> res;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==0)continue;
            if(arr[i][j]>p)continue;
            if(j<c-1 && arr[i][j+1] + p-arr[i][j] <= n && 0<arr[i][j+1] + p-arr[i][j])
                res.insert(arr[i][j+1] + p-arr[i][j]);
            if(j>0  && arr[i][j-1] + p-arr[i][j] <= n && 0<arr[i][j-1] + p-arr[i][j])
                res.insert(arr[i][j-1] + p-arr[i][j]);
            if(i<r-1 && arr[i+1][j] + p-arr[i][j] <= n && 0<arr[i+1][j] + p-arr[i][j])
                res.insert(arr[i+1][j] + p-arr[i][j]);
            if(i>0 && arr[i-1][j] + p-arr[i][j] <= n && 0<arr[i-1][j] + p-arr[i][j])
                res.insert(arr[i-1][j] + p-arr[i][j]);
            }

    }
    for(auto elem:res)cout<<elem<<" ";
    res.erase(p);
    cout<<res.size()<<"/"<<n-1<<endl;
    return 0;
}