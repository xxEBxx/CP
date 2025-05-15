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
    vi arr(n),next_high(n),next_low(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    next_low[n-1]=n-1;
    next_high[n-1]=n-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i] > arr[i+1]){
            next_low[i]=next_low[i+1];
            next_high[i]=i;
        }
        else if(arr[i] < arr[i+1]){
            next_high[i]=next_high[i+1];
            next_low[i]=i;
        }
        else {
            next_low[i]=next_low[i+1];
            next_high[i]=next_high[i+1];
        }
    }

    //for(int i=0;i<n;i++)cout<<next_high[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++)cout<<next_low[i]<<" ";cout<<endl;

    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;a--;b--;
        if( b <= next_low[next_high[a]] ){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}


