
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

int ask(int i) {
    cout<<"? 1 "<<i<<endl;
    int res;
    cin>>res;
    return res;
}

int main() {
    fast();
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int curr = 0,cnt_z=1;
        int start=2;
        while (start<=n && curr == 0) {
            curr = ask(start);
            start++;
        }
        if (start==n) {
            cout<<"! IMPOSSIBLE"<<endl;
            continue;
        }
        start--;
        string s = "";
        for (int i=0;i<start-1;i++)
            s+='0';
        s[start-1]='1';
        for (int i=0;i<start-1-curr;i++)
            s[i]='1';

        for (int i=start+1;i<=n;i++ ) {
            int loc = ask(i);
            if (loc==curr) {
                s += '0';
                cnt_z++;
            }
            else {
                s += '1';
            }
            curr = loc;
        }
        cout<<"! "<<s<<endl;


    }
    return 0;
}
