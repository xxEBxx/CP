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
vi B(maxn,0);
int n,m;

int get_b(int i){
    int res=0;
    while(i>0){
        res+=B[i];
        i-=  i & -i;
    }
    return res;
}
void set_b(int i,int v){
    while(i <= n){
        B[i]+=v;
        i+=  i & -i;
    }
}
int main(){fast();
    cin>>n;
    vi arr(n+1);
    for(int i=1;i<1+n;i++){
        cin>>arr[i];
        if(arr[i]&1){
            set_b(i,1);
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int q,a,b;cin>>q>>a>>b;
        if(q==2){
            cout<<get_b(b)-get_b(a-1)<<endl;
        }
        else if(q==1){
            cout<<b-a+1-get_b(b)+get_b(a-1)<<endl;
        }
        else{
            if(arr[a] %2 ==1)set_b(a,-1);
            arr[a]=b;
            if(arr[a]%2 == 1)set_b(a,1);
        }
    }
    return 0;
}