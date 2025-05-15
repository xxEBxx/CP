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

const int maxn=2*(int)1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}


int main(){fast();
    vi prime(maxn,1);
    int count=0;
    for(int i=2;i<maxn;i++){
        if(prime[i])count++;
        for(int j=2*i;j<maxn;j+=i){
            prime[j]=0;
        }
    }
    cout<<count;

    return 0;
}