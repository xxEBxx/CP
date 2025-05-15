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

bool op(pair<int,int>a , pair<int,int> b){
    return a.s < b.s;
}
int main(){fast();
    int n,c;cin >> n >>c;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i].f >> arr[i].s;
    sort(arr.begin(),arr.end(),op);
    vector<int> visited(24,0);
    int tot = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        if(visited[arr[i].f] == 1)
            continue;
        tot += arr[i].s;
        visited[arr[i].f] = 1;
        if(tot > c)
            break;
        count++;
    }
    cout << count;
    return 0;
}