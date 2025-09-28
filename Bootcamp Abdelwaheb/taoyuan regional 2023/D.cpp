
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
    int cnt=0;
    while (t--) {
        cnt++;
        cout<<"Airplane #"<<cnt<<":"<<endl;
        int n,m;
        cin>>n>>m;
        char d1,d2;
        cin>>d1>>d2;
        vector<vector<char>> arr(n,vector<char> (m));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                char val ;cin>>val;
                if (val=='.')
                    arr[i][j]='0';
                else
                    arr[i][j]=val;
            }
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (arr[i][j]=='V') {
                    if (i>0 && arr[i-1][j]!='V')arr[i-1][j] = d1;
                    if (j>0 && arr[i][j-1]!='V')arr[i][j-1] = d1;
                    if (i+1<n && arr[i+1][j]!='V')arr[i+1][j] = d1;
                    if (j+1<m && arr[i][j+1]!='V')arr[i][j+1] = d1;

                    if (i>0 && j>0 && arr[i-1][j-1]!='V')arr[i-1][j-1] = max(arr[i-1][j-1],d2);
                    if (i>0 && j+1<m && arr[i-1][j+1]!='V')arr[i-1][j+1] = max(arr[i-1][j+1],d2);
                    if (i+1<n && j>0 && arr[i+1][j-1]!='V')arr[i+1][j-1] = max(arr[i+1][j-1],d2);
                    if (i+1<n && j+1<m && arr[i+1][j+1]!='V')arr[i+1][j+1] = max(arr[i+1][j+1],d2);
                }
            }
        }
        for (int i=0;i<n;i++) {
            for (int j = 0; j < m; j++)
                cout << arr[i][j];
            cout<<endl;
        }
    }
    return 0;
}
