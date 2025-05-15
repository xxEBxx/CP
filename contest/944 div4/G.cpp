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

bool comp(int a,int b){
    return to_string(a)<to_string(b);
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, priority_queue<int>> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]>>2].push(-a[i]);
        }
        for(int i = 0; i < n; i++)
        {
            cout << -mp[a[i]>>2].top() << " ";
            mp[a[i]>>2].pop();
        }
        cout << endl;
    }
    return 0;
}