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

const int maxn=(int)1e5*2+7;
const int mod=(int)1e9+7;

int main(){fast();
    int n;
    cin>>n;
    if(n==2) {
        cout << 1 << endl;
        return 0;
    }
    ll upper=2;
    for(int i=2;i<maxn;i++){
        upper+=i;
        if(upper >= n){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}