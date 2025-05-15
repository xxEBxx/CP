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
        int n;cin>>n;
        string a,b;cin>>a>>b;
        int count=0;
        for(int i=1;i<n-1;i++){
            if(a[i]=='.' && a[i+1]=='.' && a[i-1]=='.' && b[i]=='.' && b[i+1]=='x' && b[i-1]=='x')count++;

            if(b[i]=='.' && b[i+1]=='.' && b[i-1]=='.' && a[i]=='.' && a[i+1]=='x' && a[i-1]=='x')count++;
        }
        cout<<count<<endl;
    }
    return 0;
}