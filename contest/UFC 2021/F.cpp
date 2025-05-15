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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
    int arr[maxn];
    arr[1]=0;arr[2]=1;
    for(int i=3;i<maxn;i++){
        arr[i] = max(arr[i/2],arr[i-i/2]);
    }
    int n,m;
    cin>>n>>m;
    int res=0;
    while(true){
        if(m==1 || n==1)break;
        //worst luck is that he gets sick each time
        n = n/2;
        m--;
        res++;
    }
    cout<<res+n-1;
    return 0;
}