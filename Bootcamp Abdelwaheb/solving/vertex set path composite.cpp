#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod  = 998244353;

struct node{ ll a,b; };
constexpr node base = {1,0};            // identity

/* --------------- iterative seg-tree ------------- */
struct Tree{
    using T = node;
    static constexpr T unit = base;
    ll n; bool rev;
    vector<T> s;

    Tree(ll N=0,T def=unit,bool _rev=0):n(N),rev(_rev),s(2*N,def){}

    static T compose(const T& g,const T& f){
        return { (g.a*f.a)%mod , ( (g.a*f.b)%mod + g.b )%mod };
    }
    T merge(const T& L,const T& R)const{
        return rev? compose(L,R):compose(R,L);
    }
    void update(ll p,T v){
        for(s[p+=n]=v;p>>=1;) s[p]=merge(s[p<<1],s[p<<1|1]);
    }
    T query(ll l,ll r)const{
        T L=unit,R=unit;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) L=merge(L,s[l++]);
            if(r&1) R=merge(s[--r],R);
        }
        return merge(L,R);
    }
};

/* --------------- HLD ------------- */
const int MAXN = 2e5+7;
vector<vector<int>> adj;
vector<int> parent_,depth_,sz,heavy,head,tin,inv;
int timer_=0;

int dfs(int v,int p){
    parent_[v]=p; sz[v]=1; heavy[v]=-1;
    for(int to:adj[v]) if(to!=p){
        depth_[to]=depth_[v]+1;
        int sub=dfs(to,v); sz[v]+=sub;
        if(heavy[v]==-1||sz[to]>sz[heavy[v]]) heavy[v]=to;
    }
    return sz[v];
}
void decomp(int v,int h){
    head[v]=h; tin[v]=timer_; inv[timer_]=v; ++timer_;
    if(heavy[v]!=-1) decomp(heavy[v],h);
    for(int to:adj[v]) if(to!=parent_[v]&&to!=heavy[v]) decomp(to,to);
}

/* --------------- path query ------------- */
node query_path(int u,int v,int x,const Tree& st1,const Tree& st2){
    node pref={1,0};
    vector<node> stk;
    while(head[u]!=head[v]){
        if(depth_[head[u]]>=depth_[head[v]]){
            pref = Tree::compose( st2.query(tin[head[u]], tin[u]+1), pref );
            u    = parent_[head[u]];
        }else{
            stk.push_back( st1.query(tin[head[v]], tin[v]+1) );
            v = parent_[head[v]];
        }
    }
    if(tin[u]<=tin[v]) stk.push_back( st1.query(tin[u], tin[v]+1) );
    else               pref = Tree::compose( st2.query(tin[v], tin[u]+1), pref );

    while(!stk.empty()){
        pref = Tree::compose( stk.back(), pref );
        stk.pop_back();
    }
    return { (pref.a*x + pref.b)%mod , 0 };
}

/* --------------- main ------------- */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; if(!(cin>>n>>q)) return 0;

    vector<node> val(n);
    for(auto& t:val){ cin>>t.a>>t.b; t.a%=mod; t.b%=mod; }

    adj.assign(n,{});
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    parent_.resize(n); depth_.resize(n); sz.resize(n);
    heavy.resize(n); head.resize(n); tin.resize(n); inv.resize(n);

    dfs(0,-1); decomp(0,0);

    Tree stF(n,base,0), stR(n,base,1);
    for(int i=0;i<n;i++){
        stF.update(tin[i], val[i]);
        stR.update(tin[i], val[i]);
    }

    while(q--){
        int type; cin>>type;
        if(type==0){
            int p,c,d; cin>>p>>c>>d;
            val[p]={c%mod,d%mod};
            stF.update(tin[p], val[p]);
            stR.update(tin[p], val[p]);
        }else{
            int u,v,x; cin>>u>>v>>x;
            cout<< query_path(u,v,x,stF,stR).a <<'\n';
        }
    }
    return 0;
}
