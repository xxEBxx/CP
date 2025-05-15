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
        ll n;cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool poss=true;
        for(int i=0;i<n-1;i++){
           if(arr[i] > 1 && arr[i+1] == 1 )poss=false;
        }
        if(!poss) { cout << -1 << endl;continue; }
        vector<ll> relation(n,0),puiss(n,0);
        for(int i=1;i<n;i++){
//relation of i says how much power i give to i to surpass i-1 (may be negative)
            ll prev=arr[i-1],curr=arr[i];
            if(prev==1 || curr==1)continue;
            if(prev > curr){
                while (prev > curr) {
                    curr *= curr;
                    relation[i]++;
                }
            }

            else if( prev<curr){
                prev = arr[i - 1];
                curr = arr[i];
                while (prev < curr) {
                    prev *= prev;
                    relation[i]--;
                }
                if (prev > curr)relation[i]++;
            }
        }
        //for(int k:relation)cout<<k<<" ";cout<<endl;
        ll res=0;
        for(int i=1;i<n;i++){
//relation of i is what we need
//puiss i-1 is where we are , there difference should be
            puiss[i]=max((ll)0,relation[i]+puiss[i-1]);
            res+=puiss[i];
        }
        //for(int k:puiss)cout<<k<<" ";cout<<endl;
        cout<<res<<endl;
    }
    return 0;
}
