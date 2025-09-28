#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return  a.first < b.first;
}
int main() {
    fast();
    int n;
    cin >> n;
    vector<pair<ll,ll>> arr(n);
    for (int i=0;i<n;i++)
        cin >> arr[i].first;
    for (int i=0;i<n;i++)
        cin >> arr[i].second;
    sort(arr.begin(),arr.end(),cmp);
    ll time = 0;
    for (int i=0;i<n;i++) {
        if (time <= arr[i].second)
            time = arr[i].second;
        time++;
    }
    cout << time;
    return 0;
}
