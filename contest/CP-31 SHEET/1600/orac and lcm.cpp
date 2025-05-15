#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

vector<unordered_map<int,int>> m;

void pre(){
    vvi divisors(maxn);
    for(int i=2;i<maxn;i++){
        for(int j=i*2;j<maxn;j+=i){
            divisors[j].push_back(i);
        }
    }

    m[1][1]=1;
    m[2][2]=1;
    for(int i=3;i<maxn;i++){
        if(divisors[i].empty()) {
            m[i][i] = 1;
            continue;
        }
        m[i] = m[i / divisors[i][0]];
        m[i][(int)divisors[i][0]]++;
    }
}


int main(){fast();
    pre();
    ll n;cin>>n;
    vector<ll> arr(n),gcd_suff(n),gcd_pre(n);

    unordered_map<int,int> res;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        for(auto div : m[arr[i]]){
            res[div] = min(res[div.f],m[arr[i]][div]);
        }
    }


    return 0;
}