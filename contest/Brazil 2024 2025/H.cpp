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
    int n,m;
    while(cin>>n>>m){
        int res=0;
        for(int i=0;i<n;i++){
            int count=1;
            for(int j=0;j<m;j++){
                int val;cin>>val;
                if(val==0)
                    count=0;
            }
            res+=count;
        }
        cout<<res<<endl;
    }
    return 0;
}