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

const int maxn=(int)1e5+3;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}


int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,d,k;cin>>n>>d>>k;
        vi ps_s(n+1,0),ps_e(n+1,0);

        for(int i=0;i<k;i++){
            int a,b;cin>>a>>b;
            ps_s[a]++;
            ps_e[b]++;
        }
        int curr=0,res1,index1=1,index2=1,res2;
        for(int i=1;i<=d;i++)curr+=ps_s[i];
        res1=curr;
        res2=curr;
        for(int i=2;i<=n-d+1;i++){
            curr += -ps_e[i-1] + ps_s[i+d-1];
            if(curr > res1){
                res1=curr;
                index1=i;
            }
            if(curr < res2){
                res2=curr;
                index2=i;
            }
        }
        cout<<index1<<" "<<index2<<endl;

    }
    return 0;
}
