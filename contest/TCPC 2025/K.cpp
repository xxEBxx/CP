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

string s;
int nn;
vector<string> all;
void find(int i,string &curr_s) {
    if (i==nn) {
        all.push_back(curr_s);
        return ;
    }
    find(i+1,curr_s);
    string nxt=curr_s+s[i];
    find(i+1,nxt);
}

bool inside(string sub,string super) {
    int n=super.size(),m=sub.size();
    if (m > n)return false;
    int j = 0;
    for (int i=0;i<n;i++) {
        if (j==m)break;
        if (sub[j] == super[i])
            j++;
    }
    return j==m;
}

int main() {
    fast();
    int n;
    cin>>n;
    vector<string> arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    s=arr[0];
    string empt="";
    nn = s.size();
    find(0,empt);

    string best = "";
    for (auto elem : all) {
        bool valid=true;
        for (int i=1;i<n;i++) {
            bool res = inside(elem,arr[i]);
            valid &= res;
            if (!valid)break;
        }
        if (valid) {
            if (elem.size() > best.size() ||
                (elem.size() == best.size() && elem < best))
                best = elem;
        }
    }
    if (best=="")cout<<-1<<endl;
    else
        cout<<best<<endl;
    return 0;
}
