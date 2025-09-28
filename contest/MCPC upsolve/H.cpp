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
vector<pair<int,int>> arr(101);
int n,m,c,k;

ii work(int i,int j,int l) {
    int i1 = i+l-1,j1=j+l-1;

    vi ps(102,0);
    for (auto elem : arr) {
        int start=-1,end=-1;
        if (i <= elem.f && elem.f<=i1  &&
            j <= elem.s && elem.s<=j1) {
            start = 0;
            end = max(max(elem.f-i,i1-elem.f),max(elem.s-j,j1-elem.s));
            }
        else if (i <= elem.f && elem.f<=i1) {
            if (elem.s < j) {
                start = j-elem.s;
                end = j1-elem.s;
            }
            else {
                start = elem.s-j1;
                end = elem.s-j;
            }
        }
        else if (j <= elem.s && elem.s<=j1) {
            if (elem.f < i) {
                start = i-elem.f;
                end = i1-elem.f;
            }
            else {
                start = elem.f-i1;
                end = elem.f-i;
            }
        }
        if (start == -1) continue;
        ps[start]++;
        ps[end+1]--;
    }

    if (ps[0] >= k) return {l,0};

    for (int kk = 1; kk < 102; kk++) {
        ps[kk] += ps[kk - 1];
        if (ps[kk] >= k) {
            return {l,kk};
        }
    }
    return {-1,-1};

}

int main() {
    fast();
    cin>>n>>m>>c>>k;//c number of mice
    // k is what we need to catch
    for (int i =0;i<c;i++) {
        cin>>arr[i].f>>arr[i].s;
    }
    ii res={1e9,1e9};
    for (int i =1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            int mnl=1,mxl = min(n-i+1,m-j+1),l=(mnl+mxl)/2;
            while (mnl < mxl) {
                l = (mnl+mxl)/2;
                if (i+l-1 > n || j+l-1>m){//it overgrew , make it smaller
                    mxl = l-1;
                    continue;
                }

                ii loc = work(i,j,l);
                if (loc.f == -1) {//didnt work , make it bigger
                    mnl = l+1;
                    continue;
                }
                if (loc.f < res.f) {
                    res = loc;
                }
                else if (res.f==loc.f){
                    res.s =min(loc.s , res.s);
                }
                mxl = l-1;
            }
            l = mnl;
            ii loc = work(i,j,l);
            if (loc.f==-1) {
                continue;
            }
            if (loc.f < res.f) {
                res = loc;
            }
            else if (res.f==loc.f){
                res.s = min(loc.s , res.s);
            }
        }
    }
    if (res.f == 1e9)
        cout<<-1<<endl;
    else
        cout<<res.f<<" "<<res.s<<endl;

    return 0;
}
