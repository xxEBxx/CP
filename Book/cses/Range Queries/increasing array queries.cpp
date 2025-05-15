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

struct obj{
    int l,r,index;
};
int b;
bool comp(obj x,obj y){
    if(x.l/b == y.l/b)
        return x.l/b < y.l/b;
    return x.r<y.r;
}

int main(){fast();
    int n,m;cin>>n>>m;
    b=(int)sqrt(n);

    vi arr(n+1),pay(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=2;i<=n;i++){
        pay[i]=max(0,arr[i]-arr[i-1]);
    }

    vector<obj> queries;
    for(int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        queries[i]={l,r,i};
    }

    sort(all(queries),comp);
    int i=1,j=1;
    int res=0;
    for(auto elem:queries){
        int l=elem.l,r=elem.r;
        while(i>l){
            res+=pay[i]
        }
        while(i<l){
            res-=pay[i];
            i++;
        }
    }

    return 0;
}



