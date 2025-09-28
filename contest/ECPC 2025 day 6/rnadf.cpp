
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

const int mod = (int) 1e9 + 7;

vvi dp;
vector<ii> a;
int n;vi av;

int main() {
    fast();
    int n,k;
    cin>>n>>k;
    vi arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int curr=0;
    for (int i=0;i<n;i++) {
        if (arr[i] != 0) {
            if (curr!=0) {
                a.push_back({curr,1});
                curr=0;
            }
            a.push_back({arr[i],0});
        }
        else {
            curr++;
        }
    }
    if (curr != 0)
        a.push_back({curr,1});

    n=a.size();
    dp.resize(n,vi(n,-1));
    av.resize(n,0);
    if (a[0].s == 1)
        av[0] = a[0].f;
    for (int i=1;i<n;i++) {
        av[i] = av[i-1];
        if (a[i].s==1) {
            av[i] += a[i].f;
        }
    }

    for (int i=0;i<n;i++) {
        for (int str = 0;str<)
    }


    return 0;
}
