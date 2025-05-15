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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> x(n),r(n);
        for(int i=0;i<n;i++)
            cin>>x[i]>>r[i];

        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            for(int j=0 ;j <= r[i];j++){
                int distance = floor(sqrt(r[i]*r[i]-j*j));
                m[x[i]+j] = max(m[x[i]+j],distance*2 + 1);
                m[x[i]-j] = max(m[x[i]-j],distance*2 + 1);
            }
        }
        int res=0;
        for(auto elem : m) {
            cout<<elem.f<<" "<<elem.s<<endl;
            res += elem.s;
        }
        cout<<res<<endl;

    }
    return 0;
}