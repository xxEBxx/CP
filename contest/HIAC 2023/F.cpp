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
        int n;cin>>n;
        vector<vi> arr(n,vi(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        }
        vector<int> vert(n),hor(n);
        unordered_map<int,int> cnt;
        for(int i=1;i<=n;i++){
            cnt[i]=1;
        }
        for(int i=0;i<n;i++){
            //we check each comlumn
            unordered_map<int,int> curr;
            for(int j=0;j<n;j++){
                curr[arr[i][j]]++;
            }
            if(curr!=cnt){
                cout<<"NO";
                return 0;
            }
        }
        for(int j=0;j<n;j++){
            //we check each comlumn
            unordered_map<int,int> curr;
            for(int i=0;i<n;i++){
                curr[arr[i][j]]++;
            }
            if(curr!=cnt){
                cout<<"NO";
                return 0;
            }
        }
        cout<<"YES"<<endl;

    return 0;
}