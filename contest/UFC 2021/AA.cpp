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
        int n;n=s.size();
        int res=0;
        for(int distance=1;distance <= n/2;distance++){
            int count=0;
            for(int i=0;i<distance;i++){
                if(s[i]==s[i+distance] || s[i]=='?' || s[i+distance]=='?')
                    count++;
            }
            if(count == distance) {
                res = distance;
                continue;
            }
            for(int i=1;i <= n-2*distance;i++){
                if(s[i-1] == s[i-1+distance] || s[i-1]=='?' || s[i-1+distance]=='?')
                    count--;
                if(s[i+distance*2-1] == s[i+distance-1] || s[2*distance+i-1]=='?'|| s[i+distance-1]=='?')
                    count++;
                if(count==distance) {
                    res = distance;
                    break;
                }
            }
        }
        cout<<res*2<<endl;

    }
    return 0;
}