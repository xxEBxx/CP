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
vector<pair<int,int>> arr;
int n;
bool work(int k){
    int x=0,y=0;

    for(int i=0;i<n;i++){
        //from min reached before we want to rach this min
        int l=arr[i].f,r=arr[i].s;

        //max reachable
        x = max(0,x-k);
        y = y+k;

        if(l>y || x>r)return false;
        x=max(x,l);
        y=min(y,r);
    }
    return true;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n;
        arr.assign(n,{0,0});
        for(int i=0;i<n;i++){
            cin>>arr[i].f>>arr[i].s;
        }
        int a=0,b=1e9,m;
        while(a+1 < b){
            m=(a+b)/2;
            if(work(m)){
                b=m;
            }
            else{
                a=m+1;
            }
        }
        if(work(a))cout<<a<<endl;
        else cout<<b<<endl;
    }
    return 0;
}