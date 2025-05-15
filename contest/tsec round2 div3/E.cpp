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
    int t;cin>>t;
    while(t--){
        int n,q;
        cin >> n >> q;
        vector<ll> arr(n);
        ll sum = 0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            sum += arr[i]*(i+1);
        }
        for(int i=0;i<q;i++){
            int type;
            ll l,r;
            cin >> type >> l >> r;
            if(type == 2)
                cout << sum << endl;
            else{
                sum += l*(r - arr[l-1]);
                arr[l-1] = r;
            }
        }
    }
    return 0;
}//
// Created by benje on 10/23/2024.
//
