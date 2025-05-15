#include<bits/stdc++.h>



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
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        map<pair<ll,ll>,ll> f,s,t;
        map<pair<ll,pair<ll,ll>>,ll> same;
        for(int i=0;i<n-2;i++){
            f[{arr[i+1],arr[i+2]}]++;
            s[{arr[i],arr[i+2]}]++;
            t[{arr[i],arr[i+1]}]++;
            same[{arr[i],{arr[i+1],arr[i+2]}}]++;
        }
        ll res=0;
        for(auto elem : f){
            ll k=elem.second;
            res+=k*(k-1)/2;
        }
        for(auto elem : s){
            ll k=elem.second;
            res+=k*(k-1)/2;
        }
        for(auto elem : t){
            ll k=elem.second;
            res+=k*(k-1)/2;
        }
        for(auto elem : same){
            ll k=elem.second;
            res-=k*(k-1)/2*3;
        }
        cout<<res<<endl;

    }
    return 0;
}