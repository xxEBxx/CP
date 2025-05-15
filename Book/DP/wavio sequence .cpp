//link:https://vjudge.net/problem/UVA-10534
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
    int n;
    while(cin>>n){
        vector<int> arr(n),L(n, 0),dp_inc(n),dp_dec(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            //cout<<"here is arr[i]"<<arr[i]<<endl;
            int pos = lower_bound(L.begin(), L.begin()+k, arr[i]) - L.begin();
            //cout<<"here is pos"<<pos<<" "<<L.size()-1<<" "<<k<<endl;
            L[pos] = arr[i];
            if (pos == k && (pos==0 || L[pos-1] != L[pos])) {
                k = pos+1;
            }
            dp_inc[i]=pos+1;
        }

        //reverse(all(arr));
        k = 0;
        for (int i = n-1; i > -1; i--) {
            //cout<<"here is arr[i]"<<arr[i]<<endl;
            int pos = lower_bound(L.begin(), L.begin()+k, arr[i]) - L.begin();
            //cout<<"here is pos"<<pos<<" "<<L.size()-1<<" "<<k<<endl;
            L[pos] = arr[i];
            if (pos == k && (pos==0 || L[pos-1] != L[pos]) ) {
                k = pos+1;
            }
            dp_dec[i]=pos+1;
        }
        int res=1;
        for(int i=0;i<n;i++){
            int len=min(dp_inc[i],dp_dec[i]);
            res=max(res,2*len-1);
        }

        //cout<<"LIS "<<endl;for(int i:dp_inc)cout<<i<<" ";cout<<endl;cout<<"LDS "<<endl;for(int i:dp_dec)cout<<i<<" ";cout<<endl;
        cout<<res<<endl;

    }
    return 0;
}