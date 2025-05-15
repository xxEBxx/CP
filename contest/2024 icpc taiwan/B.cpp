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

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

struct three{
    ll f;
    ll s;
    ll summation;
};

int main(){fast();
    ll n;
    cin >> n;
    vector<three> v;

    vector<ll> arr(n+3,0),ps(3+n,0);
    ps[0]=0;
    for(ll i=1;i<=n;i++) {
        cin >> arr[i];
        if(arr[i] < 0) v.push_back({i,i,arr[i]});

        ps[i] = abs(arr[i]) + ps[i-1];
    }


    ll current=0,start=1;
    for(ll i =1;i<=n;i++){
        current += arr[i];
        if(current < 0){
            start = i+1;
            current = 0;
        }
        else{
            v.push_back({start,i,current});
        }
    }

    //for(auto elem:v){
    //    cout<<elem.f<<" "<<elem.s<<" "<<elem.summation<<endl;
    //}


    ll res=ps[n];
    for(auto elem:v){
        ll i=elem.f,j=elem.s;
        res=max(res,
                elem.summation*2 + ps[i-1] + ps[n]-ps[j]);
    }

    cout<<res<<endl;


    return 0;
}

/*
 ll k,j;
    for(k=0;k<n;k++){
        if(arr[k] <0)
            out += (-1)*arr[k];
        else
            break;
    }
    for(j=n-1;j>k;k++){
        if(arr[j] <0)
            out += (-1)*arr[j];
        else
            break;
    }
    ll m=0,count=0;
    ll a=k,b;
    for(ll i=k;i<=j;i++){
        if(arr[i] > 0) {
            count += arr[i];
        }
        else{
            if(count > m)
        }
    }*/