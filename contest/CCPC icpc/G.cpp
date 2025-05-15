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
struct triple{
    int l;int r;int y;
};



int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,x,y;cin>>n;
        vector<triple> arr(n);
        for(int i=0,l,r,yy;i<n;i++){
            cin >> l >> r >> yy;
            arr[i] = {l,r,yy};
        }
        cin >> x >> y;

        sort(all(arr),[](triple q,triple a){
            return q.y < a.y;
        });
        while(!arr.empty()){
            triple p = arr.back();
            arr.pop_back();
            if(p.y <= y){
                y = p.y;
                if (x <= p.r && x > p.l){
                    x = p.r;
                }
            }
        }
        cout << x << "\n";
    }
    return 0;
}