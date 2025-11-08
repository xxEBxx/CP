
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
        vi arr(5,-1);
        for (int i=0;i<2;i++) {
            int ind,v;
            cin>>ind>>v;
            arr[ind]=v;
        }

        if (arr[2]==-1) {
            arr[2] = 90-arr[1];
        }
        else {
            arr[1] = 90-arr[2];
        }

        if (arr[3]==-1) {
            arr[3] = 180-arr[4]-arr[2];
        }
        else {
            arr[4] = 180-arr[3]-arr[2];
        }
        bool val=true;
        for (int i=1;i<5;i++) {
            if (arr[i] <= 0)val=false;
        }
        //if (arr[1]==90 || arr[3]==180 || (arr[1]==0 && arr[4]==90))val=false;
        if (val) {
            for (int i=1;i<5;i++) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else {
            cout<<-1<<endl;
        }


    }
    return 0;
}
