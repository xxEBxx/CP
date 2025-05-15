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
        int x,y,k;cin>>x>>y>>k;

        while(k > 0 && x>=y){
            cout<<"here is k"<<k<<endl;
            int a=min(k,(x/y + 1) * y - x);
            x+=a;
            k-=a;
            while(x%y == 0)x /= y;
        }
        if(k){
            int a=min(k,y-x);
            x+=a;
            k-=a;
            while(x%y == 0)x /= y;
        }

        cout<<x<<endl;
    }
    return 0;
}