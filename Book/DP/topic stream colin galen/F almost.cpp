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

int n ,k;

int main(){fast();
    cin>>n>>k;
    ll res;
    if(k==1){
        res=1;
    }
    else if(k==2){
        res=1+n*(n-1)/2;
    }
    else if(k==3){
        res=1+n*(n-1)/2+n*(n-1)*(n-2)/3;
    }
    else {
        res=1+n*(n-1)/2+n*(n-1)*(n-2)/3 ;
        ll add= n*(n-1);
        add*=(n-2)*(n-3)*3;
        add/=8;
        res+=add;
    }
    cout<<res<<endl;

    return 0;
}