
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
int n,m;
ii s,e;
string dir;
struct node {
    ii pos;
    int d;
    string dir;
};
int res=0;
pair<ii,string> nxt(ii s,string dir) {
    int add=0;
    if (dir == "UL") {
        if (s.f==1) {
            s.f = 2;
            dir[0]='D';
            add=1;
        }
        else s.f--;
        if (s.s==1) {
            s.s=2;add=1;
            dir[1]='R';
        }
        else s.s--;
    }
    else if (dir == "UR"){
        if (s.f==1) {
            s.f = 2;add=1;
            dir[0]='D';
        }
        else s.f--;
        if (s.s == m) {
            s.s--;add=1;
            dir[1]='L';
        }
        else s.s++;
    }
    else if (dir == "DL"){
        if (s.f==n) {add=1;
            s.f--;
            dir[0]='U';
        }
        else s.f++;
        if (s.s==1) {add=1;
            s.s=2;
            dir[1]='R';
        }
        else s.s--;
    }
    else {
        if (s.f==n) {add=1;
            s.f --;
            dir[0]='U';
        }
        else
            s.f++;
        if (s.s==m) {add=1;
            s.s--;
            dir[1]='L';
        }
        else
            s.s++;
    }
    res += add;
    return {s,dir};
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {

        cin>>n>>m>>s.f>>s.s>>e.f>>e.s;
        cin>>dir;
        if (s.f==e.f && s.s==e.s) {
            cout<<0<<endl;
            continue;
        }
        ii curr =s;
        string init_dir=dir;
        res=0;
        vector<vvi> vis(n+1,vvi(m+1,vi(4,0)));
        unordered_map<string,int> m;
        m["DL"]=0;
        m["UL"]=1;
        m["UR"]=2;
        m["DR"]=3;
        vis[curr.f][curr.s][m[dir]]=1;

        while (true) {

            auto nx = nxt(curr,dir);

            if (vis[nx.f.f][nx.f.s][m[nx.s]] == 1) {
                cout<<-1<<endl;break;
            }
            if (nx.f == e) {
                cout<<res<<endl;break;
            }
            vis[nx.f.f][nx.f.s][m[nx.s]] = 1;
            curr= nx.f;
            dir=nx.s;
        }

    }
    return 0;
}
