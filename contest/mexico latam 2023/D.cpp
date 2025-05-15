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
    int r,c,k;cin>>r>>c>>k;
    map<int,int> count;
    for(int i=0;i<c;i++){
        int val;cin>>val;
        count[val]++;
    }
    vector<int> arr;
    for(auto elem : count){
        arr.push_back(elem.s);
    }
    sort(all(arr));
    reverse(all(arr));
    int res=0;
    for(int i=0;i<min((int)arr.size(),k);i++)
        res+=arr[i];
    cout<<res<<endl;
    return 0;
}