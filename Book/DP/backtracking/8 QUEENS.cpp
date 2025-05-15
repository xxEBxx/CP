//link ; https://vjudge.net/problem/UVA-750
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int rows[8],testcase=1,rr,cc;

bool work (int c,int r){
    for(int i=0;i<c;i++){
        if(rows[i]==r || abs(i-c ) == abs(r-rows[i]) )return false;
    }
    return true;
}

void solve(int c){
    if(c==8){
        if(testcase<10)cout<<" ";
        cout<<testcase<<"     ";
        for(int elem:rows)cout<<" "<<elem+1;
        cout<<endl;
        testcase++;
    }
    if(c==cc){solve(c+1);return;}
    for (int r = 0; r < 8; r++) {
        if (r != rr && work(c, r) && abs(cc-c)!=abs(r-rr)) {
            rows[c] = r;
            solve(c + 1);
        }
    }
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        getchar();
        testcase=1;
        cin>>rr>>cc;rr--;cc--;
        rows[cc]=rr;
        cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
        solve(0);
        if(t)cout<<endl;
    }
    return 0;
}