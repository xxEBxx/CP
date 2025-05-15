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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
        cin >> arr[i];
    ll m=0;
    ll a,b,c;

    for(ll i=0;i<n-1;i++){
        if(arr[i] >= arr[i+1])
            continue;
        else {
            a = i;
            while(arr[i+1] >= arr[i]){
                if(i >= n-1)
                    break;
                i++;
            }
            b = i;
            if(i==n-1)
                break;
            while( arr[i+1] <= arr[i] ){
                if(i >=n-1)
                    break;
                i++;
            }
            c = i;
            if(i >= n)
                break;
            m = max(m,min(arr[b]-arr[a],arr[b]-arr[c]));
            i--;
        }
    }
    cout << m;
    return 0;
}