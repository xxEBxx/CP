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

const int maxn=(int)1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

bool work(vector<int> arr,int k){
    unsigned long long  n=arr.size();
    //cout<<"here is k n"<<k<<" "<<n<<endl;
    if(k==0 || k==n || n==1)return true;
    int ora=0;
    vector<int> bit(20,0);
    for(int i=0;i<k;i++){
        ora= ora | arr[i];
        for(int j=0;j<20;j++){
            if(1<<j & arr[i]) bit[j] ++;
        }
    }
    //cout<<"initialized bit";
    for(int i=k;i<n;i++){
        //we remove bits from i-k
        for(int j=0;j<20;j++){
            if((1<<j) & arr[i-k]) bit[j] --;
        }
        //we add elements from i
        for(int j=0;j<20;j++){
            if((1<<j) & arr[i]) bit[j] ++;
        }
        //we check if it is like beginning
        int ori=0;
        for(int j=0;j<20;j++){
            if(bit[j] > 0) ori |= (1<<j);
        }
        if(ori!=ora) return false;
    }
    return true;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int a=1,b=n,mid=(a+b)/2;
        while(a < b){
            mid=(a+b)/2;
            //cout<<"here is mid"<<mid;
            if(work(arr,mid)){
                b=mid;
            }
            else{
                a=mid+1;
            }
        }
        cout<<b<<endl;

    }
    return 0;
}
/*
 * */