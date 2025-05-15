#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
vector<pair<ll,ll>> brute;
vi fact;
void generate(ll index,ll num,ll combined){
    if(index==fact.size()){
        brute.emplace_back(num,combined);
        return;
    }

    generate(index+1,num+fact[index],combined+1);
    generate(index+1,num,combined);
}

ll countset(ll num){
    ll res=0;
    while(num>0){
        if((num/2)*2 != num)res++;
        num/=2;
    }
    return res;
}

int main(){fast();
    ll fact_num=6;
    fact.push_back(6);
    for(ll i=4;;i++){
        fact_num*=i;
        if(fact_num > (ll)1e12)break;
        fact.push_back(fact_num);
    }

    generate(0ll,0ll,0ll);
    sort(all(brute));
    //for(auto elem : brute)cout<<elem.f<<" "<<elem.s<<endl;
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll res=1000;
        for(auto elem : brute){
            if(elem.f > n)break;
            res=min(res, countset(n-elem.f)+elem.s);
        }
        cout<<res<<endl;
    }
    return 0;
}