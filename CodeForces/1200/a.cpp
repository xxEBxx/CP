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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n),price(n-1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i =0;i < n-1;i++){
        cin>>price[i];
    }

    vi to_take;
    int current = arr[0];
    to_take.push_back(arr[0]);
    for(int i =0;i<n-1;i++){
        if(current < 0)break;
        to_take.push_back(arr[i]);
        current += arr[i+1];
        current -= price[i+1];
    }
    int res=0;
    sort(all(to_take));
    reverse(all(to_take));
    for(int i=0;i<k+1;i++)
        res += to_take[i];
    cout<<res<<endl;

    return 0;
}