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

vi arr;
inline int crush(int mask, int p) {
    int low  = mask & ((1 << p) - 1);
    int high = mask >> (p + 1);
    return low | (high << p);
}



int main() {
    fast();
    //assert(crush(3,0)==crush(3,1));
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n>>m>>k;
        arr.resize(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        if (m==1) {
            cout<<1<<endl;
            continue;
        }

        vvi dp(1<<n,vi(2,0));//0 is loosing state aka ends with one
        //dp[1] = 0;
        //dp[i][0] means can first win
        for (int i=2;i<(1<<n);i++) {
            for (int j =0;j<k;j++) {
                int nxt = crush(i,arr[j]-1);

                if (i==nxt)break;//we went higher
                if (dp[nxt][0]==0) {//if next cant lose
                    dp[i] = 1;//i cant win 
                    break;
                }
            }
        }

        int res=0;
        for (int i=0;i < (1<<n);i++) {
            res++;
            if (dp[i]==1)
                res ++;
        }
        cout<<res<<endl;

    }
    return 0;
}
