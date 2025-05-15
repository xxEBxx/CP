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
    ll t;cin>>t;
    while(t--){
        ll k,x,y;cin>>k>>x>>y;
        ll res=0;
        if(k==1){
            cout<<x+y<<endl;
            continue;
        }
        if(k%2==0){
            // k/2 amount of y's needed
            res=y/(k/2);
            ll reste_y=y%(k/2);
            x-= k-reste_y*2;
            if(x<0) {
                cout<<res<<endl;
                continue;
            }
            res++;
            res+=x/k;
            cout<<res<<endl;
        }
        else{
            res = min(x,y/(k/2));
            x -= res;
            y -= res*(k/2);
            if(x==0){
                k++;
                res+=y/(k/2);
            }
            else{
                x -= k-y*2;
                if(x<0){
                    cout<<res<<endl;
                    continue;
                }
                else{
                    res++;
                    res += x/k;
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}