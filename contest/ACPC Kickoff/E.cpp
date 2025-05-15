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
        int n;cin>>n;
        string s;cin>>s;
        unordered_map<char,int> m1;
        bool first=true;
        int res = 0;

        for(int i=0;i<n;i++){
            int score=1;
            while (i < n - 1 && s[i] == s[i + 1]) {
                score++;
                i++;
            }

            if(!first) { m1[s[i]]  = max(m1[s[i]],score); }
            else res=score;

            first=false;
        }
        res += m1[s[0]];
        for(auto elem : m1){
            res = max(res,elem.s);

        }
        cout<<res<<endl;
    }
    return 0;
}