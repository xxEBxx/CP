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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
        int n,m;cin>>n>>m;
        map<int,int> counter;
        vi arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            counter[arr[i]]++;
        }
        for(int i=1;i<=m;i++){
            if(counter[i]==0){
                cout<<0<<endl;
                return 0;
            }
        }

        for(int i=n-1;i>=0;i--){
            counter[arr[i]]--;
            if(arr[i] <= m && counter[arr[i]]==0){
                cout<<n-i<<endl;
                return 0;
            }
        }

    return 0;
}