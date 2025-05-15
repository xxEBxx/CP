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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;

ll solve(vvi mat,vi p){
    ll n=(ll)p.size();
    vector<ll> less(n,0),eq(n,0),great(n,0);

    for(ll j=0;j<n-1;j++){
        for(ll i=0;i<n;i++){
            if(mat[i][j] == mat[i][j+1])
                eq[j]=1;
            if(mat[i][j] == (1+mat[i][j+1]))
                great[j]=1;
            if((mat[i][j]+1) == mat[i][j+1])
                less[j]=1;
        }
    }
    //for(auto elem : eq)cout<<elem<<" ";cout<<endl;    for(auto elem : great)cout<<elem<<" ";cout<<endl;    for(auto elem : less)cout<<elem<<" ";cout<<endl;

    vector<vi> dp(n,vi(2,0));
    dp[0][1] = p[0];
    for(ll i=1;i<n;i++){
        //i wont add to myself aka dp[i][0]
        dp[i][0]=1e18;
        if(eq[i-1] == 0){
            dp[i][0] = min(dp[i][0],dp[i-1][0]);
        }
        if(less[i-1] == 0){
            dp[i][0] = min(dp[i][0],dp[i-1][1]);
        }

        //i will add to myselef
        dp[i][1]=1e18;
        if(great[i-1] == 0){
            dp[i][1] = min(dp[i][1],dp[i-1][0]);
        }
        if(eq[i-1] == 0){
            dp[i][1] = min(dp[i][1],dp[i-1][1]);
        }
        dp[i][1] += p[i];
    }
    return min(dp[n-1][0],dp[n-1][1]);

}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> a(n),b(n);

        vvi mat1(n,vi(n,0)),mat2(n,vi(n,0));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>mat1[i][j];
                mat2[j][i]=mat1[i][j];
            }
        }
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        ll res = solve(mat1,b) + solve(mat2,a);
        if(res>=(ll)1e18)
            cout<<-1<<endl;
        else
            cout<<res<<endl;


    }
    return 0;
}