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
    vi isprime(301,1);
    for(int i=2;i<301;i++){
        if(isprime[i]){
            for(int j=2;j*i<301;j++){
                isprime[j*i]=0;
            }
        }
    }
    int count =0;
    for(int i=2;i<301;i++){
        if(isprime[i]){
            count++;
        }
    }
    cout<<count;

    return 0;
}