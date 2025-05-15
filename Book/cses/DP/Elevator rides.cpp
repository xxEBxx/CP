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

const int maxn=20;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,x,dp[(1<<20)+1],arr[maxn];

int solve(int bitmask){
    if(bitmask == ((1<<n)-1))
        return 0;
//try every subset
    for(int i=0;i<n;i++){
        if(((bitmask>>i)&1) == 1)continue;

    }

}

int main(){fast();
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    return 0;
}