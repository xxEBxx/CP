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

typedef string String;
const ll maxn=(ll)101;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
ll pw3


ll dp[maxn][1<<9][1<<9],n,arr[maxn];

bool isvalid(int& nmask,int& nmask2, int i){
    String number = to_string(arr[i]);
    vi count(10,0);
    for(ll index=0;index<(ll)number.size();index++){
        count[number[index]-'0']++;
    }
    for(int bit=0;bit<10;bit++){
        if(count[bit] > 2){
            return false;
        }
        if(count[bit]==2){
            if(nmask>>bit &1)
                return false;
            nmask|=(1<<bit);
            nmask2|=(1<<bit);
        }
        if(count[bit]==1){
            if(nmask2>>bit & 1)
                return false;
            if(nmask>>bit &1)
                nmask2|=(1<<bit);
            else
                nmask|=(1<<bit);
        }
    }
    return true;
}

ll solve(ll i,int mask,int mask2){
    if(i==n)
        return 0;
    if(dp[i][mask][mask2]!=-1)
        return dp[i][mask][mask2];

    ll res=solve(i+1,mask,mask2);

    int nmask=mask,nmask2=mask2;

    if(isvalid(nmask,nmask2,i))
        res=max(res,arr[i]+solve(i+1,nmask,nmask2));

    return dp[i][mask][mask2]=res;

}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solve(0,0,0)<<endl;
    }
    return 0;
}