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
        int n,q;cin>>n>>q;
        vector<string> portals(n);
        map<string,vi> m;
        for(int i=0;i<n;i++){
            cin>>portals[i];
            m[portals[i]].push_back(i);
        }

        for(int i=0;i<q;i++){
            int from,to;cin>>from>>to;
            from--;to--;
            if(from>to) swap(to,from);
            if(portals[from][0]==portals[to][0] || portals[from][1]==portals[to][0] || portals[from][0]==portals[to][1] || portals[from][1]==portals[to][1]){
                cout<<to-from<<endl;
                continue;
            }
//now we know there is no common element aka we need one of the 4 others
//we need to binary search for the 4 other elements
            int bs=1e9;
            for(auto &[k,v] : m){
                if(k==portals[from] || k==portals[to])continue;
                auto it= lower_bound(all(v),to);
                if(it!=v.end())bs=min(bs,*it-from);
                if(it!=v.begin()){
                    it--;
                    bs=min(bs,to-*it);
                }
            }
            if(bs>to-from && bs<1e7 ){
                bs=2*(bs-(to-from))+to-from;
            }
            bs=max(bs,to-from);
            if(bs>1e7)bs=-1;
            cout<<bs<<endl;
        }
    }
    return 0;
}