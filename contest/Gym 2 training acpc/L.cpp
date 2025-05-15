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
        int n;cin>>n;
        vi arr(n);
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        int res,to_inc;
        res=0;
        to_inc=0;
        for(int i=1;i<=n;i++){
            if(i==arr[arr[i]]) {
                to_inc++;
                swap(arr[i],arr[arr[i]]);
            }
        }
    res = to_inc + max(0,res-to_inc*2-1) ;
    for(int i=1;i<=n;i++)
        cin>>arr[i];

    to_inc=0;
    for(int i=1;i<=n;i++){
        if(i==arr[arr[i]]) {
            res++;
            swap(arr[i],arr[arr[i]]);
        }
    }

    for(int i=1;i<=n;i++){
        if(arr[i]!=i)
            to_inc++;
    }
    res+=to_inc;

    cout<<res<<endl;


    return 0;
}