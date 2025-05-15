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
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n=s.size();
        vector<int> b(n+1,0),r(n+1,0);
        for(int i=1;i<=n;i++) {
            b[i] = b[i - 1];
            r[i] = r[i - 1];
            if (s[i-1] == 'B')
                b[i]++;
            else
                r[i]++;
        }
        //for(auto elem :r)cout<<elem<<" ";cout<<endl;
        //for(auto elem :b)cout<<elem<<" ";cout<<endl;
        int res = min(b[n],r[n]);//red all or blue all
        for(int i=0;i<=n;i++){
            int v1 = b[i] + r[n]-r[i];
            res=min(res,v1);
            v1 = r[i] + b[n]-b[i];
            res=min(res,v1);
        }
        cout<<res<<endl;
    }
    return 0;
}