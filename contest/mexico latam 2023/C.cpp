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


int main(){fast();
    ll n,k,lsize;cin>>n>>k>>lsize;
    string a,l;
    cin>>a>>l;
    a="a"+a;
    vi arr(27,0);
    for(ll i=0;i<lsize;i++){
        arr[l[i]-'a']=1;
    }
    vi ps(n+1,0);
    for(ll i=1;i<=n;i++){
        ps[i] = ps[i-1]+arr[a[i]-'a'];
    }
    vi uu(n+1,0),vv(n+1,0);
//uu[i]means just the next closest element that has a valid number
//uu[i] can't be i
    uu[n] = n+1 ;
    for(ll i=n-1;i>0;i--){
        uu[i] =  uu[i+1];
        if (arr[a[i +1]-'a'])uu[i] = i + 1;
    }
    vv[1]=0;
    for(ll i=2;i<=n;i++){
        vv[i] = vv[i-1];
        if(arr[a[i-1] - 'a'])vv[i] = i-1;
    }
    //for(ll elem : uu)cout<<elem<<" ";cout<<endl;for(ll elem : vv)cout<<elem<<" ";cout<<endl;
    ll i=1,j=1,res=0;
    while(j<=n){
        //cout<<i<<" "<<j<<endl;
        if(ps[j]-ps[i-1] < k){
            j++;
        }
        else if(ps[j]-ps[i-1] > k){
            i++;
        }
        else{
            while(ps[j]-ps[i-1]==k) {
                i++;
            }
            i--;
            res += (uu[j]-j) * (i-vv[i]);
            i++;
            j=max(i,j);
            //cout<<res<<endl;
        }
    }
    cout<<res<<endl;

    return 0;
}//
// Created by benje on 10/24/2024.
//
