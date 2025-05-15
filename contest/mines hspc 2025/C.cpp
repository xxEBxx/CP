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

struct node{
    int x,a,b;
};

bool comp(vi a,vi b){
    __int128 aa = (__int128)a[0] / (__int128)a[1];
    __int128 bb = (__int128)b[0] / (__int128)b[1];
    return aa < bb;
}

int main(){fast();
    int n;cin>>n;
    vector<node> arr(n);
    vector<vector<int>> s;
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].a>>arr[i].b;
        s.push_back({arr[i].a ,arr[i].x,+1});
        s.push_back({arr[i].b ,arr[i].x,-1});

    }
    sort(all(s),comp);
    int curr =0,res=0;
    for(auto elem : s){
        curr += elem[2];
        res=max(res,curr);
    }
    cout<<res<<endl;


    return 0;
}