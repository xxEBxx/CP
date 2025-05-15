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

const int maxn=(int)1e5*2+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    int t;cin>>t;
    vi count;
    while(t--){
        int n,k;cin>>n>>k;
        count.clear();
        count.resize(2*n+1,0);
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            count[val]++;
        }
        //for(auto elem:count)cout<<elem<<" ";cout<<endl;
        int res=0;
        for(int i=1;i<k/2;i++){
            res += min(count[i],count[max(0,k-i)]);
        }
        if(k%2==0){
            res+=count[k/2]/2;
        }
        else{
            res += min(count[k/2],count[max(0,k-k/2)]);
        }
        cout<<res<<endl;
    }
    return 0;
}