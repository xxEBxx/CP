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

const ll maxn=(ll)1e5*2+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
string s,res;
ll arr[maxn],dp[maxn][30],n,m;

ll solve(ll i,ll j){
    if(j==m)
        return 0;
    if(i==n)
        return -1e18;

    if(dp[i][j]!=-1)
        return dp[i][j];
    ll ress=solve(i+1,j);
    if(s[i] == res[j] ){
        ress=max(ress,arr[i]+solve(i+1,j+1));
    }
    return dp[i][j]=ress;
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        cin>>s;

        stack<char> st;
        ll count[30]={0},exist[30]={0};
        for(ll i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        for(ll i=0;i<n;i++){
            count[s[i]-'a']--;
            if(exist[s[i]-'a']==1)continue;
            while(!st.empty() && s[i] < st.top() && count[st.top()-'a']>0 ){
                char c=st.top();
                st.pop();
                exist[c-'a']=0;
            }
            st.push(s[i]);
            exist[s[i]-'a']=1;
        }
        res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(all(res));
        //now we find maximum subarray with res and maximize score
        m=res.size();
        cout<<res<<endl;
        cout<<solve(0,0)<<endl;
    }
    return 0;
}