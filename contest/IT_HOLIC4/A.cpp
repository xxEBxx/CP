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

bool comp(ii a, ii b){
    if(a.f != b.f){
        return a.f<b.f;
    }
    return a.s<b.s;
}

int main(){fast();
    int n,q;cin>>n>>q;
    vector<ii> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].f>>arr[i].s;
    }
    vi sheeps(q);
    for(int i=0;i<q;i++){
        cin>>sheeps[i];
    }
    sort(all(arr),comp);
    sort(all(sheeps));
    //for(auto elem : arr)cout<<elem.f<<" "<<elem.s<<endl;
    //for(auto elem : sheeps)cout<<elem<<" ";
    int i=0,j=0;
    int res=0;
    while(i<n && j<q){
        if(arr[i].f <= sheeps[j] && sheeps[j]<=arr[i].s){
            res++;
            i++;
            j++;
        }
        else if(sheeps[j] < arr[i].f){
            j++;
        }
        else{
            i++;
        }
    }
    cout<<res<<endl;
    return 0;
}
