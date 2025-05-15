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

int main(){fast();
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        int i=0;
        while(n-m > 1<<i){
            i++;
        }
        if(m>n){
            int max_i=0;

        }
        if(i==0) { cout << n << endl;continue; }

        int to_or=0;
        for(int j=0;j<i;j++){
            to_or=to_or | (1<<j);
        }
        n=to_or | n;
        cout<< n<<endl;

    }
    return 0;
}