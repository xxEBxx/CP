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
    for(int i=0;i<n;i++)cin>>arr[i];
    vi count(1e5+2,0);
    int max_elem=0,res=0;
    for(int i=0;i<n;i++) { count[arr[i]]++;
        if(count[arr[i]] > res)res=count[arr[i]];
        if(arr[i] > max_elem)max_elem=arr[i];
    }
    for(int i=2;i<=max_elem;i++){
        if(count[i] > count[i-1]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<res<<endl;
    for(int i=0;i<n;i++){
        cout<<count[arr[i]]<<" ";
        count[arr[i]]--;
    }
    return 0;
}