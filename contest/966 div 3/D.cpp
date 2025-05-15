#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e5*2+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> arr(n);
        string s;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>s;
        vector<ll> ls(n,0),rs(n,0);

        if(s[0]=='L')ls[0]=1;
        if(s[n-1]=='R')rs[n-1]=1;

        for(int i=1;i<n;i++){
            ls[i]=ls[i-1];
            if(s[i]=='L')ls[i]++;
        }
        for(int i=n-2;i>=0;i--){
            rs[i]=rs[i+1];
            if(s[i]=='R')rs[i]++;
        }
        ll res=0;
        for(int i=0;i<n;i++){
            ll a=min(rs[i],ls[i]);
            res+=arr[i]*a;
        }
        //for(int i=0;i<n;i++)cout<<rs[i]<<" ";cout<<endl;
        //for(int i=0;i<n;i++)cout<<ls[i]<<" ";cout<<endl;
        cout<<res<<endl;

    }
    return 0;
}