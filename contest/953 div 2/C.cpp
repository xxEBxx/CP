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
        int n,k;cin>>n>>k;
        if(k&1){
            cout<<"No"<<endl;
            continue;
        }
        vector<int> arr(n);
        for(int j=0;j<n;j++){
            arr[j]=j+1;
        }
        int i=0,x=n-1;
        while(i < n/2 && k>0 && x>=0){
            //cout<<"here is k"<<k;
            if(2*x <= k ){
                k = k - x*2;
                arr[i]=n-i;
                arr[n-i-1]=i+1;
            }
            i++;
            x-=2;
        }
        if(k==0){
            cout<<"Yes"<<endl;
            for(int z:arr){
                cout<<z<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}