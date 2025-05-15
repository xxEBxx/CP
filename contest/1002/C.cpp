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
        int n;
        cin>>n;
        vi visited;
        vvi useful;
        visited.assign(n+1,0);
        useful.assign(n+1,vi(0));
        vvi arr(n+1,vi(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=n;j>=1;j--){
                cin >> arr[i][j];
            }
        }
        vector<int> s;
        for(int i=1;i<=n;i++){
            int j;
            for(j=1;j<=n;j++){
                if(arr[i][j] != 1)break;
            }
            s.push_back(j-1);
        }
        sort(all(s));
        //for(auto elem : s)cout<<elem<<" ";
        int res=1,index=1;

        while(index < n){
            if(s[index]>=res){
                res++;
            }
            index++;
        }

        cout<<res<<endl;


    }
    return 0;
}