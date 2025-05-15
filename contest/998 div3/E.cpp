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

vector<int> parent_G,rankg,rankf,parent_F;

int find_set_G(int v) {
    if (v == parent_G[v])
        return v;
    return parent_G[v] = find_set_G(parent_G[v]);
}

void union_sets_G(int a, int b) {
    a = find_set_G(a);
    b = find_set_G(b);
    if (a != b) {
        if (rankg[a] < rankg[b])
            swap(a, b);
        parent_G[b] = a;
        if (rankg[a] == rankg[b])
            rankg[a]++;
    }
}

int find_set_F(int v) {
    if (v == parent_F[v])
        return v;
    return parent_F[v] = find_set_F(parent_F[v]);
}

void union_sets_F(int a, int b) {
    a = find_set_F(a);
    b = find_set_F(b);
    if (a != b) {
        if (rankf[a] < rankf[b])
            swap(a, b);
        parent_F[b] = a;
        if (rankf[a] == rankf[b])
            rankf[a]++;
    }
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,m1,m2;cin>>n>>m1>>m2;
        parent_G.clear();
        rankg.clear();
        rankg.resize(n+1,0);
        parent_G.resize(n+1,0);

        parent_F.clear();
        rankf.clear();
        rankf.resize(n+1,0);
        parent_F.resize(n+1,0);

        vector<pair<int,int>> temp(m1);
        for(int i=0;i<m1;i++){
            cin>>temp[i].f;
            cin>>temp[i].s;
        }
        for(int i=1;i<=n;i++){
            rankg[i]=1;
            parent_G[i]=i;
            rankf[i]=1;
            parent_F[i]=i;
        }

        for(int i=0;i<m2;i++){
            int a,b;cin>>a>>b;
            union_sets_G(a,b);
        }
        int res=0;
        for(auto elem:temp){
            if(find_set_G(elem.f)==find_set_G(elem.s)){
                union_sets_F(elem.f,elem.s);
            }
            else{
                res++;
            }
        }

        set<int> comp_G,comp_F;
        for(int i=1;i<=n;i++){
            comp_G.insert(find_set_G(i));
            comp_F.insert(find_set_F(i));
        }
        int add=comp_G.size()-comp_F.size();
        if(add<0)add=-add;
        cout<<res+add<<endl;

    }
    return 0;
}