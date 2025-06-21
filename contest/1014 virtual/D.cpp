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
        string s;cin>>s;
        int T=0,I=0,L=0;
        for (int i=0;i<n;i++) {
            if (s[i]=='T')T++;
            else if (s[i]=='I')I++;
            else L++;
        }
        int max_red=max(T,max(L,I));
        char max_letter;
        if (T == max_red)
            max_letter='T';
        else if (L == max_red)
            max_letter='L';
        else
            max_letter='I';

        for (int i=0;i<n-1;i++) {
            char curr =s[i],next=s[i+1];
            if (curr ==next)continue;
            if (curr != max_letter && next!=max_letter)continue;
            


        }
    }
    return 0;
}

