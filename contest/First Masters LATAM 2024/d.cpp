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
    int h,m;cin>>h>>m;
    int n;cin>>n;
    vi price(n),time(n);
    int k=60*h+m,res=0;
    for(int i =0;i<n;i++){
        cin>>time[i]>>price[i];
        if(k==0)break;
        if(k < time[i]){
            res += k*price[i];
            k=0;
        }
        else{
            res+=time[i]*price[i];
            k-=time[i];
        }
    }
    cout<<res<<endl;
    return 0;
}