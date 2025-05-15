#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef __int128 ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef unsigned long long ull;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
vector<vector<ll>> dp(61,vector<ll>(61,-1));

ll solve(ll n,ll back){
    if(n<=1)return 0;
    if(dp[n][back]!=-1)return dp[n][back];
    ll res=0;
    for(int i=1;i<=back;i++){
        res+=solve(n-i,back)+1;
    }
    return dp[n][back]=res;
}

void printInt128(__int128 num) {
    if (num == 0) {
        std::cout << '0';
        return;
    }
    if (num < 0) {
        std::cout << '-';
        num = -num;
    }
    char buffer[40];
    int i = 39;
    buffer[i] = '\0';
    while (num != 0) {
        buffer[--i] = (num % 10) + '0';
        num /= 10;
    }
    std::cout << &buffer[i];
}

int main(){
    int n,k;int cc=0;
    while(cin>>n>>k){cc++;
        if(n==61 && k==61)break;
        cout<<"Case "<<cc<<": ";
        printInt128(solve(n,k)+1);
        cout<<endl;
    }
    return 0;
}


