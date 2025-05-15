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
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int res=n;
    for(int i=1;i<n-1;i++){
        if(arr[i]>=k)res--;
        else{
            if(arr[i+1]<k && arr[i+1]+arr[i]>=k)res--;
            else if(arr[i-1]<k && arr[i-1]+arr[i]>=k)res--;
        }
    }
    if(arr[0]>=k)res--;
    else if(arr[1]<k && arr[1]+arr[0]>=k)res--;

    if(arr[n-1]>=k)res--;
    else if(arr[n-1]<k && arr[n-1]+arr[n-2]>=k)res--;

    cout<<res<<endl;
    return 0;
}