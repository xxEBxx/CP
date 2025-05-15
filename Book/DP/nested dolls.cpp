// https://vjudge.net/problem/UVA-11368
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

bool comp (ii a, ii b){
    if(a.f==b.f) return a.s > b.s;
    // to not have elements with same first
    //if we didn't do that we can have 10 20 and then 10 30 on top of it
    return a.f < b.f;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ii> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].f>>arr[i].second;
        }
        sort(all(arr),comp);
        deque<int> lows;
        for(int i=0;i<n;i++){
            int index= lower_bound(all(lows),arr[i].s)-lows.begin();
//if the height is smaller bwtween everyone you need to make a new place for him
//else you need to find the element strictly smaller than him and he will englobe it
            if(index==0)lows.push_front(arr[i].second);
            else lows[index-1]=arr[i].second;//to not overlap second
        }
        cout<<lows.size()<<endl;
    }
    return 0;
}