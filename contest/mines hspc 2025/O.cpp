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
    int n;
    cin>>n;
    vi visited(n+1,0);
    int res=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(visited[i] || visited[a])continue;
        visited[i]=1;
        visited[a]=1;
        res+=2;
    }
    cout<<n-res<<endl;
    return 0;
}