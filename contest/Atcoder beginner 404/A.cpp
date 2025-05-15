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
    string s;cin>>s;
    vi exist(26,0);
    for(char c : s){
        exist[c-'a']=1;
    }
    for(int i=0;i<26;i++){
        if(exist[i]==0){
            cout<<(char)('a'+i)<<endl;
            return 0;
        }
    }
    return 0;
}