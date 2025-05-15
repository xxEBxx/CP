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


int main(){fast();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        ll sum = 0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr.begin(),arr.end());
        ll a1 = arr[n/2 -1];
        ll a2 = arr[n/2];
        ll a = 1e18 + 18,b=1e18 + 18,c=1e18 + 18;

        ll x = a1*(n+1) - sum;
        if(x <= a1){
            a = x;
        }
        if(sum%x ==0){
            x = sum/n;
            if(x>= a1 && x <= a2)
                b = x;
        }

        x = a2*(n+1) - sum;
        if(x >= a2){
            c = x;
        }
        x = min({a,b,c});
        cout << x << endl;
    }
    return 0;
}