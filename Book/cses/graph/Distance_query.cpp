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

const int maxn=(int)1e5*2+7;
const int logg=19;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

vi parent(maxn,-1),depth(maxn,-1);
vvi up(maxn,vi (maxn,-1));

int solve(int a, int b){
//the idea is that if the k-th parent is not the same
//we should go up to that element
    int count =0;
    if(depth[a] < depth[b]){
        swap(a,b);
    }
//now a is the more deep element , we make them the same depth and start
int k=depth[b]-depth[a];
for(int i=logg;i>=0;i--){
    if(k && (1<<i)){
        a=up[a][i];
        count+=(1<<i);
    }
}

for(int j=logg;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
            count+=(1<<(j+1));
            //because we add to the distance
            // 2 times 2^j
        }
    }
    //now we are sure they are sons of the same parent that is lca
    return count+2;
}

int main(){fast();
    cout<<"l9lawu";
    int n,q;cin>>n>>q;
    depth[1]=0;
    for(int i=1;i<n;i++){
        cout<<"hi";
        int a,b;cin>>a>>b;
        parent[max(a,b)]=min(a,b);
    }
    cout<<"parent" ;
    for(int i=2;i<1+n;i++){
        depth[i]=depth[parent[i]]+1;
    }
    cout<<"depth done";
    for(int i=1;i<1+n;i++)up[i][0]=parent[i];

    for(int j=1;j<logg;j++){
        for(int i=1;i<n+1;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    cout<<"hello";
    for(int i=0;i<q;i++){
        cout<<"query : "<<i+1<<endl;
        int a,b;cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
    return 0;
}