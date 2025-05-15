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

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
    int n,m;cin>>n>>m;

    vvi mat(n,vi(m));
    vector<int> dec;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]==1){
                dec.push_back(j);
            }
        }
    }
    //for(auto elem : dec)cout<<elem<<" ";
    //we now need to find longest decreasing subsequence
    reverse(all(dec));
    n = (int)dec.size();
    vi L(n),L_id(n),arr=dec;
    int k = 0, lis_end = 0;
    for (int i = 0; i < n; i++) {
        //cout<<"here is arr[i]"<<arr[i]<<endl;
        int pos = lower_bound(L.begin(), L.begin()+k, arr[i]) - L.begin();
        //cout<<"here is pos"<<pos<<" "<<L.size()-1<<" "<<k<<endl;
        L[pos] = arr[i];
        L_id[pos] = i;
        if (pos == k ) {
            k = pos+1;
            lis_end = i;
        }
        else if (pos==k-1)lis_end=i;
    }
    cout<<k<<endl;

    return 0;
}