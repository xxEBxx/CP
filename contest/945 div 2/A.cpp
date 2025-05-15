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
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) & 1) { cout << -1 << endl;continue; }
        int res=0;
        while(a>0){
            if(c>b){
                c--;
            }
            else{
                b--;
            }
            a--;
            res++;
        }
        cout<<res+min(b,c)<<endl;
    }
    return 0;
}