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
        vector<ll> arr(n);
        map <ll,set<ll>> m;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            m[arr[i]%k].insert(arr[i]);
        }
        ll res=0;bool done=false;int count_impaire=0;
        for(auto elem : m){
            if(elem.second.size() & 1 ){
                count_impaire++;
            }
            if(count_impaire > 1){
                cout<<-1<<endl;
                done=true;
                break;
            }
            if(elem.second.size() > 1){
                vector<ll> arr_;
                for (ll num : elem.second) {
                    arr_.push_back(num);
                }

                if(elem.second.size() & 1){
                    vector<ll> distances;
                    for(int i=0;i<n-1;i++){
                        distances.push_back(arr_[i+1]-arr_[i]);
                    }
                    //we find the edge with max;
                    int index_max=max(all(distances))-distances.begin();
                    bool add=false;int to_add1=0,to_add2=0;
                    for(int i=0;i<n;i++){
                        if(index_max==i)continue;
                        if(add)to_add1 += arr_[i];
                        else to_add1 -= arr_[i];
                        add=!add;
                    }
                    for(int i=0;i<n;i++){
                        if(index_max+1==i)continue;
                        if(add)to_add2 += arr_[i];
                        else to_add2 -= arr_[i];
                        add=!add;
                    }
                    res+=min(to_add1,to_add2);
                }

                else{
                    for (int i = 0; i < arr_.size(); i += 2) {
                        res += (arr_[i + 1] - arr_[i]) / k;
                    }
                }
            }

        }
        if(!done)cout<<res<<endl;
    }
    return 0;
}