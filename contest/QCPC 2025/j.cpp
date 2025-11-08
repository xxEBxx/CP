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
        int n;
        cin >> n;
        vi arr(n);
        int a=0,b=0,c=0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i]==1)a++;
            else if (arr[i]==2)b++;
            else c++;
        }
        if (a != 0) {
            cout << -1 << endl;
            continue;
        }
        if (n >= 4) {
            cout<<-1<<endl;
            continue;
        }
       if (n == 1) {
           cout << arr[0] <<endl;
           continue;
       }
        if (n == 2 && b != 2 && c != 2) {
            cout << arr[0] << " " << arr[1]<<endl;
            continue;
        }

        if (n == 3 && (b == 2 && c == 1)) {
            cout << "2 3 2" << endl;
            continue;
        }

        cout << -1 << endl;


    }
    return 0;
}
