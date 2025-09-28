#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;
//variables to store are
//places available on iron , maximum already in stone
//sum of people in stones , number of stone houses
vvi child;
vi card,type;

ll n,c;
array<ll,5> dfs(ll i) {
    ll av_iron=0, max_stone=0, p_stone=0, stone_houses=0,dead=0;
    if (child[i].empty()){
        if (type[i] == 3) {
            av_iron += c - card[i];
        } else if (type[i] == 2) {
            max_stone = card[i];
            p_stone = card[i];
            stone_houses = 1;
        }
    }
    else {

        for (ll c : child[i]) {
            auto res = dfs(c);
            av_iron += res[0];
            max_stone = max(max_stone,res[1]);
            p_stone += res[2];
            stone_houses += res[3];
            dead += res[4];
        }

        ll go_iron = min(av_iron,card[i]);
        av_iron-=go_iron;
        card[i]-=go_iron;
        if (card[i]==0)
            return {av_iron,max_stone,p_stone,stone_houses,dead};

        if (stone_houses==0)
            return {av_iron,max_stone,p_stone,stone_houses,dead+card[i]};

        p_stone += card[i];
        if (p_stone > max_stone*stone_houses) {
            max_stone = p_stone/stone_houses;
            if (p_stone%stone_houses != 0)
                max_stone++;
        }
    }


    return {av_iron,max_stone,p_stone,stone_houses,dead};
}


int main() {
    fast();
    cin>>n>>c;
    child.resize(n+1);
    card.resize(n+1);
    type.resize(n+1);
    for (ll i=1;i<=n;i++) {
        ll p;cin>>p;
        if (i==1)continue;
        child[p].push_back(i);
    }
    for (ll i=1;i<=n;i++) {
        cin >> card[i];
    }
    for (ll i=1;i<=n;i++) {
        cin>>type[i];
    }
    auto res = dfs(1);
    cout<<res[4] + res[1]<<endl;

    return 0;
}
