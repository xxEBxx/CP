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
ll pre[18];
void preprocess(){
    pre[0]=0;
    pre[1]=9;
    for(ll i=2;i<18;i++){
        pre[i]=pre[i-1];
        pre[i]+=i*(ll)(pow(10,i)-pow(10,i-1));
        //cout<<pre[i]<<" ";
    }
}

ll solve(ll i){
    string a=to_string(i);
    ll res = pre[a.size()-1];
    //cout<<res<<endl;
    res += (i - (ll)pow(10,a.size()-1)+1) * (ll)a.size();
    //cout<<res<<endl;
    return res;
}

int main(){fast();
    preprocess();
    int t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        //cout<<solve(b)<<" "<<solve(a-1)<<endl;
        cout<<solve(b)-solve(a-1)<<endl;
    }
    return 0;
}