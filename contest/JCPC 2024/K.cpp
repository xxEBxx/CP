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

int dist(char a,char b) {
    if (a>b)swap(a,b);
    return min(b-a,'z'-b+a-'a'+1);
}

int main() {
    fast();
    int n,q;
    cin>>n>>q;
    string s;cin>>s;
    vi ps3(n+1,0),ps1(n+1,0),ps2(n+1,0);
    for (int i=1;i<=n-2;i++) {
        if (i%3==0)
            ps1[i] = dist(s[i],'d')+dist(s[i+1],'o')+dist(s[i+2],'z');
        if (i%3==1)
            ps2[i] = dist(s[i],'d')+dist(s[i+1],'o')+dist(s[i+2],'z');
        if (i%3==2)
            ps3[i] = dist(s[i],'d')+dist(s[i+1],'o')+dist(s[i+2],'z');
    }
    for (int i=1;i<n;i++) {
        ps3[i]+=ps3[i-1];
        ps2[i]+=ps2[i-1];
        ps1[i]+=ps1[i-1];
    }
    for (int i=0;i<q;i++) {
        int a,b;
        cin>>a>>b;
        if(b-a+1 %3==0) {
            cout<<ps1[b]-ps1[a-1]<<endl;
        }
        else if (b-a+1 %3==1) {
            cout<<min(ps1[b]-ps1[a-1],ps1[b]-ps1[a-1])<<endl;

        }

    }

    return 0;
}
