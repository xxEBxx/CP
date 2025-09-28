
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

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        if (abs(n-k)%2==0) {
            //we will have k-2 1
            for (int i=0;i<k-2;i++)
                cout<<1<<" ";
            cout<<(n-k+2)/2<<" "<<(n-k+2)/2<<endl;
        }
        else {
            //now we have n reduced by k-3;
            for (int i=0;i<k-3;i++)
                cout<<1<<" ";
            n -= k-3;
            //and k is 3
            if (n%4==0) {
                cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
            }
            else {
                cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<endl;
            }
        }
    }
    return 0;
}
