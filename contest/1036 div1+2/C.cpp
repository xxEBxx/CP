
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


struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1,0) {}
    void add(int i, int v) { for (; i<=n; i+=i&-i) f[i]+=v; }
    int sum(int i)      { int s=0; for (; i>0; i-=i&-i) s+=f[i]; return s; }
};


Fenwick fw(0);
vi arr;
int n,k;

bool removable(int i) {
    return (fw.sum(arr[i]-1) < k && fw.sum(arr[i]) >= k);
}
int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {

        cin >> n>>k;
        arr.resize(n+1,0);
        Fenwick fw1(n+1);
        fw = fw1;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            fw.add(arr[i],1);
        }

        int i =1,j=n;
        bool valid =true;
        while (i<j && (j-i+1) >= k) {
            if (arr[i] == arr[j]) {
                fw.add(arr[i], -1);
                fw.add(arr[j], -1);
                i++;
                j--;
            } else if (removable(i)) {
                fw.add(arr[i], -1);
                i++;
            } else if (removable(j)) {
                fw.add(arr[j], -1);
                j--;
            } else {
                valid = false;
                break;
            }
        }
            if (valid)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
