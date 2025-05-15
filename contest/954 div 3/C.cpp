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
        int n,m;cin>>n>>m;
        string word;cin>>word;
        set<int> indexes;
        for(int i=0;i<m;i++){
            int val;cin>>val;
            indexes.insert(val-1);
        }
        string to_sort;
        cin>>to_sort;int i=0;
        sort(all(to_sort));
        for(auto elem:indexes){
            word[elem]=to_sort[i];
            i++;
        }
        cout<<word<<endl;
    }
    return 0;
}