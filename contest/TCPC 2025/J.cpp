#include<bits/stdc++.h>

#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;
vi arr;
int n;
vvi all;

void generate(int i,vi curr) {
    if (i==n) {
        all.push_back(curr);
        return ;
    }
    generate(i+1,curr);
    curr.push_back(arr[i]);
    generate(i+1,curr);
}


int main() {
    fast();
    cin>>n;
    arr.resize(n);
    unordered_map<int,int> inverse;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        inverse[arr[i]]=i;
    }

    vvi change((1<<n)+2,vi(n,0));
    int q;
    cin>>q;
    for (int i=0;i<q;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        int j = inverse[c];
        change[a][j]^=1;
        change[b+1][j]^=1;
    }

    for (int i=1;i < change.size();i++) {
        for (int j=0;j<n;j++) {
            change[i][j] ^= change[i-1][j];
        }
    }

    generate(0,{});
    sort(all.begin(),all.end());

    for (int i=1;i<(1<<n);i++) {
        vi loc(n,0);
        for (auto elem : all[i]) {
            loc[inverse[elem]]=1;
        }
        ll res=1;
        for (int j=0;j<n;j++) {
            if (loc[j] != change[i][j]) {
                res *= arr[j];
                res %= mod;
            }
        }
        cout<<res<<" ";
    }

    return 0;
}
