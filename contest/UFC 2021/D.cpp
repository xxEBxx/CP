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

struct node {
    int ss;
    int w;
    int h;
};
bool op(node a,node b){
    return a.ss < b.ss;
}
int main(){fast();
    int n;
    cin >> n;
    vector<node> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i].ss >> arr[i].w >> arr[i].h;
    sort(arr.begin(),arr.end(),op);
    ll out = arr[0].ss + arr[0].h + arr[0].w;
    for(int i=1;i<n;i++){
        out += (arr[i].ss - (arr[i-1].ss + arr[i-1].w));
        if(arr[i-1].ss + arr[i-1].w == arr[i].ss)
            out += abs(arr[i].h -arr[i-1].h);
        else
            out += arr[i-1].h + arr[i].h;
        out += arr[i].w;
    }
    out += arr[n-1].h + 100-(arr[n-1].ss + arr[n-1].w);
    cout << out << endl;
    return 0;
}