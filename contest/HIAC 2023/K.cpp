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
    vector<string> elem(n+1,"");
    for(int i=1;i<=n;i++){
        cin>>elem[i];
    }
    vector<vector<pair<int,int>>> arr(n+1,vector<pair<int,int>>(26,{1e9,-1}));
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            arr[i][elem[i][j]-'a'].f = min(arr[i][elem[i][j]-'a'].f,j);
            arr[i][elem[i][j]-'a'].s = max(arr[i][elem[i][j]-'a'].s,j);
        }
    }
    //cout<<arr[1][0].f<<" "<<arr[1][0].s<<endl;
    int q;cin>>q;
    for(int ii=0;ii<q;ii++){
        int a,b;cin>>a>>b;
        int res=0;
        for(int i=0;i<26;i++){
            pair<int,int> c1=arr[a][i],c2=arr[b][i];
            if(c1.s==-1 || c2.s==-1)continue;
            int to_add=min(c1.s,c2.s)-max(c1.f,c2.f)+1;
            if(to_add<=0)continue;
            res+=to_add;
        }
        cout<<res<<endl;
    }


    return 0;
}