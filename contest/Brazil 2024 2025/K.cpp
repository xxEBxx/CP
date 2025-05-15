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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    int n,k;
    while(cin>>n>>k){
        vector<int> arr(k);
        string res="S";
        for(int i=0;i<k;i++){
            cin>>arr[i];
            if(i>0 && arr[i]-arr[i-1] < (2*n/k))
                res="N";
        }
        int lower=0,upper=n/k,mod=n/k;
        //modulo is the number of slices
        for(int i=0;i<k-1;i++){
            //we check from i to i+1
            int dist=arr[i+1]-arr[i];
            if(dist >= mod)continue;
            int min_local=arr[i]%mod,max_local=arr[i+1]%mod;

            if(min_local < max_local && lower < upper){
                //it is a continuous segment
                lower = max(lower,min_local);
                upper = min(upper,max_local);
            }
            else if(min_local < max_local || lower < upper){
                //here one of them cony an other divided
                lower = max(lower,min_local);

            }

        }
        int min_local=arr[k-1]%mod,max_local=arr[0]%mod;
        if(lower >= max_local && upper <= min_local) {
            res="N";
        }
        cout<<res<<endl;
    }
    return 0;
}