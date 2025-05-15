#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef unsigned long long ll;
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
    while(t--) {
        ll n,nn;
        cin >> n;nn=n;
        vector<ll> res;int number[61];
        int c=0;
        for(int i=0;i<61;i++){
            number[i]=nn%2;
            nn/=2;
            c+=number[i];
        }
        if(c==1)cout<<1<<endl<<n<<endl;
        else{
            cout<<c+1<<endl;
            for(int i=60;i>-1;i--){
                if(number[i]==1)cout<<n-(1ll<<i)<<" ";
            }
            cout<<n<<endl;
        }
    }
    return 0;
}