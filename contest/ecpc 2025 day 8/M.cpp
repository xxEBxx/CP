
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
const int B = 20;
const int maxn =  (1<<B)+ 2;
const int mod = (int) 1e9 + 7;

vi exist(maxn,0);
void add(int x) {
    queue<int> q;
    q.push(x);
    if (exist[x])return ;
    exist[x]=1;
    while (!q.empty()) {
        int head = q.front();
        q.pop();
        for (int j=0;j<B;j++) {
            if (x>>j & 1) {
                int nxt = head^(1<<j);
                if (exist[nxt] == 1)continue;
                exist[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    fast();
    int n;
    cin>>n;
    while (n--) {
        int a,b;
        cin>>a>>b;
        if (a==1) {
            add(b);
        }
        else {
            int res=0;
            for (int j=19;j>=0;j--) {
                if ((b>>j & 1) == 0)continue;
                int nres = res | (1<<j);
                if (exist[nres])
                    res = nres;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
