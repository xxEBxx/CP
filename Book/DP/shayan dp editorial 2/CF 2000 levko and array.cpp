#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)2001;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll n,k,arr[maxn];

bool work(ll x){
//here we try to compute the maximum elements that stay at their place
//to know minimum numbers to change
    vi dp(n,1);
    for(ll i=1;i<n;i++){
        for(ll j=0;j<i;j++){
            if(abs(arr[i]-arr[j]) <= (i-j)*x){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++)ans=max(ans,dp[i]);

    return n-ans <= k;
}

int main(){fast();
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    //binary search on answer
    ll a=0,b=1e18,middle;
//if 5 works then 6 7 8 900 works as well cause it is a bigger llervalle

    while(b-a > 1){

        middle=(a+b)/2;
        if(work(middle))
            b=middle;
        else
            a=middle+1;

    }
    //cout<<a<<" "<<b<<endl;
    if(work(a))cout<<a;
    else cout<<b;


    return 0;
}