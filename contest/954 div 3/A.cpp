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
        int a,b,c;cin>>a>>b>>c;
        float number=a+b+c;number/=3;
        int mean;
        if(number-(int)number > 0.5){
            mean=(int)number +1;
        }
        else{
            mean =(int) number;
        }
        int res=abs(mean-max(a,max(c,b)))+abs(mean-min(min(a,b),c));
        cout<<res<<endl;
    }
    return 0;
}