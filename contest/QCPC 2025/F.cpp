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
        int n,m;
        cin >> n>>m;
        string x,y;
        cin>>x>>y;
        vvi nxt(n,vi(26,-1));
        vvi ss(n,vi(26,0));

        vi curr(26,-1);
        vi curr_sum(26,0);
        for (int i=n-1;i>=0;i--) {
            curr[x[i]-'a']=i;
            nxt[i] = curr;

            curr_sum[x[i]-'a']++;
            ss[i] = curr_sum;
        }

        vi freq(26);
        for (int i=0;i<m;i++) {
            freq[y[i]-'a']++;
        }
        bool sol=true;
        for (int k=0;k<26;k++) {
            if (freq[k] > ss[0][k]) {
                sol=false;
                break;
            }
        }
        if (!sol) {
            cout<<-1<<endl;
            continue;
        }
        string res="";
        for (int i=0;i<n;i++) {
            //we try to push our best letter
            for (int j=25;j>=0;j--) {
                //we see if this letter can be there
                if (freq[j]==0)continue;
                bool val=true;
                int index = nxt[i][j];
                //if (index==-1)continue;

                for (int k=0;k<26;k++) {
                    if (freq[k] > ss[index][k]) {
                        val=false;
                        break;
                    }
                }
                if (val) {
                    res += static_cast<char>('a' + j);
                    i = index;
                    freq[j]--;
                    break;
                }
            }
        }
        cout<<res<<endl;

    }
    return 0;
}
