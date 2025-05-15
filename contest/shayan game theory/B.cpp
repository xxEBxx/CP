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
    int n,m;cin>>n>>m;
    unordered_map<string,int> g;

    for(int i=0;i<n+m;i++){
        string a;cin>>a;
        g[a]++;
    }
    int doubled=0;
    for(auto elem :g){
        if(elem.s==2){
            doubled++;
        }
    }

    if(doubled%2==1){
        m--;
    }
    if(n>m)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}