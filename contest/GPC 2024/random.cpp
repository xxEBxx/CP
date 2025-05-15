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
    int n;cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i].f>>arr[i].s;

    sort(all(arr));
    int res=1;
    int tv1=-2,tv2=-2;
    for(int i=0;i<n;i++){
        //cout<<arr[i].f<<endl;
        if(tv1 < arr[i].f)
            tv1 = arr[i].s;
        else if(tv2 < arr[i].f)
            tv2 = arr[i].s;
        else {
            res = -1;
            break; }
    }
    if(res==-1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}