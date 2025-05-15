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

const ll N=(ll)1e5+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    //preprocess all divisors;
    vector<vi> divisors(N);
    for(ll i=2;i<N;i++){
        for(ll j=i;j<N;j+=i){
            divisors[j].push_back(i);
        }
    }
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        int freq[N];
        vector<ll> pref(n,0),suff(n,0);
        memset(freq,0,sizeof freq);
        for(ll i=0;i<n;i++){
            for(ll elem:divisors[arr[i]]){
                pref[i]+=freq[elem];
            }
            freq[arr[i]]++;
        }
//pref is just how many elements are before me and i am divisble by them
//similar to s2
        memset(freq,0,sizeof freq);
        for(ll i=n-1;i>=0;i--){
            for(ll elem:divisors[arr[i]]){
                suff[i] += freq[elem];
            }
            freq[arr[i]]++;
        }
        //for(auto elem :pref)cout<<elem<<" ";cout<<endl;
        //for(auto elem :suff)cout<<elem<<" ";cout<<endl;

        //now we should combine the two to solve the problem
        //lets think of how to make the elements of s3
        ll res=0;
        vector<ll> repeat(N, 0);
        for(ll i=0;i<n;i++){
            res += 1ll * repeat[arr[i]] * suff[i];
            repeat[arr[i]] += pref[i];
        }
        cout<<res<<endl;
    }
    return 0;
}