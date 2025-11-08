#include<bits/stdc++.h>

#define aint(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

//typedef long long int;
typedef pair<int, int> ii;
typedef pair<int, int> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<int> vl;
typedef vector<vector<int> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

ii max_upto(vi arr,int j) {
    int mx=-1,mx_i=-1;
    for (int i =0;i<arr.size();i++) {
        int curr=0;
        for (int b =0;b<j;b++) {
            if (arr[i]>>b &1)
                curr |= (1<<b);
        }
        if (curr > mx_i) {
            mx_i = i;
            mx = curr;
        }
    }
    return {mx,mx_i};
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n>>m;
        vi arr(n);
        int tot  =0;

        vi freq(32,0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            tot |= arr[i];
            for (int j =0;j<32;j++) {
                if (arr[i]>>j)
                    freq[j]++;
            }
        }
        int k =__builtin_popcount(tot);
        vi price(32,INT32_MAX);
        //we wiint start from k+1;
        vi elems(n,0);
        for (int i =0;i<=k;i++) {
            price[i]=0;
        }
        int curr_price=0;
        for (int j=0;j<32;j++) {
            price[__builtin_popcount(tot)] = min(price[__builtin_popcount(k)],curr_price);
            if ((tot>>j &1) == 0) {
                ii change = max_upto(arr,j);
                int first_jj=-1;
                for (int jj=0;jj<j;jj++) {
                    freq[jj]--;
                    if (freq[jj]==0) {
                        tot ^= (1 << jj);
                        if (first_jj == -1)
                            first_jj=jj;
                    }
                }
                freq[j]++;
                arr[change.s] += (1<<j)-change.f;
                curr_price += (1<<j)-change.f;
                tot |= (1<<j);
                if (first_jj != -1)
                    j = first_jj-1;
            }

        }
        for (int i =0;i<m;i++) {
            int val;cin>>val;
            for (int j=31;j>=0;j--) {
                if (price[j] < val) {
                    cout<<j<<endl;
                    break;
                }
            }
        }

    }
    return 0;
}
