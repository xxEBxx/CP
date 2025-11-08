
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
        int n;
        cin >> n;
        vector<string> arr(n);
        int min_n=1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            reverse(all(arr[i]));
            min_n=min(min_n,(int)arr[i].size());
        }
        string s="";
        for (int i=0;i<min_n;i++) {
            bool stop=false;
            for (int j=1;j<n;j++) {
                if (arr[j-1][i] != arr[j][i]) {
                    stop=true;
                    break;
                }
            }
            if (stop)break;
            s += arr[0][i];
        }
        reverse(all(s));
        if (s=="")cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }

    return 0;
}
