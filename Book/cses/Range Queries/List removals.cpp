#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v) v.begin(), v.end()
#define f first
#define s second

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
        int n;cin>>n;
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            int val;cin>>val;
            s.insert(make_pair(i,val));
        }

        for(int i=0;i<n;i++){
            if(i==2){
                for(auto elem : s){
                    cout<<elem.f<<" "<<elem.s<<endl;
                }
            }
            int index;cin>>index;
            pair<int,int> elem = (*s.lower_bound({index-1,-1}));
            cout<< elem.s <<" ";
            s.erase(elem);
        }
    return 0;
}