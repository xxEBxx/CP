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

const int maxn = (int) 1e6 + 7;
const int mod = (int) 1e9 + 7;

int spf[maxn];
void estratos() {
    memset(spf,-1,sizeof(spf));
    for (int i=2;i<maxn;i++) {
        if(spf[i]==-1) {
            for (int j =i;j<maxn;j+=i) {
                spf[j]=i;
            }
        }
    }
}
vi masks;
int b,n,cnt;
/*
int dp[(int)1e5+2][520],vis[(int)1e5+2][520];
int solve(int i,int mask) {
    if (mask == (1<<b)-1) {
        return 0;
    }
    if (i==n)
        return n;
    if (vis[i][mask]==cnt)
        return dp[i][mask];

    int res = min(solve(i+1,mask|masks[i])+1,
        solve(i+1,mask));
    vis[i][mask] = cnt;
    return dp[i][mask] = res;
}
*/
int main() {
    fast();
    estratos();
    int t;
    cin >> t;
    //memset(vis,-1,sizeof(vis));
    cnt=0;
    while (t--) {
        cnt++;
        cin >> n;
        vi arr(n);
        unordered_map<int,int> decomp;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            unordered_map<int,int> loc;
            int cp=arr[i];
            while (cp > 1) {
                loc[spf[cp]]++;
                cp/=spf[cp];
            }
            for (auto elem : loc) {
                decomp[elem.f] = max(decomp[elem.f],elem.s);
            }
        }
        b=decomp.size();
        if (b==0){
            cout << 1 << endl;
            continue;
        }

        unordered_map<int,int> prime_to_id;
        int id = 0;
        for (auto elem: decomp) {
            prime_to_id[elem.f] = id;//
            id++;
        }
        masks.resize(n);
        for (int i=0;i<n;i++) {
            unordered_map<int,int> loc;
            int cp = arr[i];
            while (cp > 1) {
                loc[spf[cp]]++;
                cp/=spf[cp];
            }
            int res=0;
            for (auto elem : decomp) {
                if (elem.s == loc[elem.f]) {
                    res |= (1<<prime_to_id[elem.f]);
                }
            }
            masks[i]=res;
        }


        //cout<<solve(0,0)<<endl;
        b=20;
        vi dp(1050,1e9);
        dp[0]=0;
        for (int i=0;i<n;i++) {
            for (int mask=0;mask<520;mask++) {
                if ((mask|masks[i]) >= 1050)continue;
                    dp[mask | masks[i]] = min(dp[mask | masks[i]] , dp[mask]+1);
            }
        }
        cout<<dp[(1<<b)-1]<<endl;

    }
    cout<<3<<endl<<2<<endl;

    return 0;
}
