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
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int top1=0,top2=0,res=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=top1 && arr[i]<=top2){
                if(top1>top2)
                    top2=arr[i];
                else
                    top1=arr[i];
            }
            else if(arr[i]<=top1)
                top1=arr[i];
            else if(arr[i]<=top2)
                top2=arr[i];
            else{
                if(top1>0 && top2>0)res++;
                if(top1<top2)
                    top1=arr[i];
                else
                    top2=arr[i];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}