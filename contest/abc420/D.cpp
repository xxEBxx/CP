


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

struct node {
    int i,j,d,s;
};

int main() {
    fast();
    int n,m;cin>>n>>m;
    vector<string> arr(n);
    int si=0,sj=0,ei=0,ej=0;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
        for (int j=0;j<m;j++) {
            if (arr[i][j] == 'S') {
                si=i;sj=j;
            }
            if (arr[i][j] == 'G') {
                ei=i;ej=j;
            }
        }
    }

    vector<vvi> vis(n,vvi (m,vi(2)));
    queue<node> q;
    q.push({si,sj,0,0});
    vis[si][sj][0]=1;
    while (!q.empty()) {
        node head = q.front();
        if (head.i==ei && head.j==ej) {
            cout<<head.d;
            return 0;
        }
        q.pop();
        int i=head.i,j=head.j,d=head.d,s=head.s;
        int ns=s;
        if (arr[i][j]=='?')ns=1-s;

        if (i>0 && vis[i-1][j][ns]==0 && arr[i-1][j]!='#' && (arr[i-1][j]!='o' || ns==0) && (arr[i-1][j]!='x' || ns==1)) {
            vis[i-1][j][ns]=1;
            q.push({i - 1, j, d + 1, ns});
        }
        if (i<n-1 && vis[i+1][j][ns]==0 && arr[i+1][j]!='#' && (arr[i+1][j]!='o' || ns==0) && (arr[i+1][j]!='x' || ns==1)) {
            vis[i+1][j][ns]=1;
            q.push({i + 1, j, d + 1, ns});
        }
        if (j>0 && vis[i][j-1][ns]==0 && arr[i][j-1]!='#' && (arr[i][j-1]!='o' || ns==0) && (arr[i][j-1]!='x' || ns==1)) {
            vis[i][j-1][ns]=1;
            q.push({i , j-1, d + 1, ns});
        }
        if (j<m-1 && vis[i][j+1][ns]==0 && arr[i][j+1]!='#' && (arr[i][j+1]!='o' || ns==0) && (arr[i][j+1]!='x' || ns==1)) {
            vis[i][j+1][ns]=1;
            q.push({i, j+1, d + 1, ns});
        }
    }
    cout<<-1;
    return 0;
}
