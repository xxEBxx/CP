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
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        int n_copy=x,best_mex=0;
        while(n_copy > 0){
            if(n_copy%2==0){
                break;
            }
            best_mex++;
            n_copy/=2;
        }

        vi res;
        cout<<best_mex<<endl;
        int counter=0;
        for(int i=0;i<n;i++){
            if(counter == (1<<best_mex)){
                res.push_back(x);
            }
            else{
                res.push_back(counter);
                counter++;
            }
        }
        int or_arr=0;
        for(auto elem : res) {
            or_arr |= elem;
        }
        //cout<<or_arr<<endl;
        if(x == or_arr){
            for(int i=0;i<n;i++){
                cout<<res[i]<<" ";
            }
        }
        else{
            sort(all(res));
            for(int i=0;i<n-1;i++){
                cout<<res[i]<<" ";
            }
            cout<<x;
        }

        cout<<endl;
    }
    return 0;
}