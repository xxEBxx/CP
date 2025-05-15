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

struct node{
    int l,r,index;
};

bool comp(node a,node b){
    if(a.l != b.l)return a.l<b.l;
    return a.index<b.index;
}

int main(){fast();
    int n;cin>>n;
    vector<node> arr;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++) {
        cin>>arr[i].l>>arr[i].r;
        arr[i].index=i;
    }
    sort(all(arr),comp);
    int container=-1,contained=-1;
    for(int i=0;i<n;i++){
//to not be taken it should be bigger than all
        s.insert({arr[i].s,arr[i].index});
    }

    return 0;
}