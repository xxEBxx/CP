
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
    int cnt =0,index=-1,sz=0;
    string s="";
    for (int i = 0; i < n; i++) {
        int val;cin>>val;
        if (val==1) {
            char c;cin>>c;
            sz++;

            if (c=='(')cnt++;
            else cnt--;
            if (cnt<0 && index==-1)  index = sz;
            if (index != -1 || cnt != 0) {
                cout<<"NO"<<endl;
            }
            else {
                cout<<"YES"<<endl;
            }
            s+=c;
        }
        else {
            if (index == sz) {
                index = -1;
            }

            if (s[sz-1] == ')')cnt++;
            else cnt--;
            if (index != -1 || cnt != 0) {
                cout<<"NO"<<endl;
            }
            else {
                cout<<"YES"<<endl;
            }
            sz--;
            s.pop_back();
        }
    }

    return 0;
}
