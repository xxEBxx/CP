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
    int n,m,d;
    cin >> n >> m >> d;
    vector<int> arr(n);
    vector<int> brr(m);
    for(int i=0;i<n;i++)cin >> arr[i];
    for(int i=0;i<m;i++)cin >> brr[i];

    int count = 0;
    int time = 0;
    int final = arr[n-1] - d;
    int j=0;
    while(true){
        if(j >= m){
            cout << "B " << count;
            break;
        }
        int elem = brr[j];
        if(elem + d >= final){
            cout << "B " << count;
            break;
        }
        count++;
        elem += d+1;
        int a = lower_bound(arr.begin(),arr.end(),elem+d) - arr.begin();
        if(a >= n){
            cout << "A " << count;
            break;
        }
        if(arr[a] >= final){
            cout << "A " << count;
            break;
        }
        count++;
        elem = arr[a] +1;
        j = lower_bound(brr.begin(),brr.end(),elem) - brr.begin();
    }
    return 0;
}