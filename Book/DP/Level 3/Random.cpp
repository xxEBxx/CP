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

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,k,arr[maxn];

int work(int x){
    vi count(n);
//the question here : Is there a subarray of size >=k such that its sum is >=0;
    for(int index=0;index<n;index++){
        if(arr[index]>=x)count[index]=1;
        else count[index]=-1;
        if(index>0)count[index]+=count[index-1];
    }
    int mn=0,mx=count[n-1];
    for(int index=k;index<n;index++){
        mn=min(mn,count[index-k]);
        mx=max(mx,count[index]-mn);
    }
    return mx > 0;
}

int main(){fast();
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>arr[i];
    int a=1,b=n-1;
    while(b-a>1){
        int middle=(a+b)/2;
        if(work(middle)){
            //we can have a higher middle
            a=middle;
        }
        else {
            b=middle-1;
        }
    }
    if(work(b))cout<<b;
    else cout<<a;
    return 0;
}