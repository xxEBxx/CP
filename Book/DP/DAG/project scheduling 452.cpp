#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn = (int)1e6 + 7;
const int mod = (int)1e9 + 7;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int price[28],last,dp[28],sortant[28],exist[28];
map<int,vi> dag;

int solve(int v){
    if(v==last) return price[v];
    if(dp[v]!=-1)return dp[v];
    int res=price[v];
    for(int next : dag[v]){
        res=max(res,price[v]+solve(next));
    }
    return dp[v]=res;
}

int main() {
    fast();
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after t
    bool first=true;
    while (t--) {
        if(!first)cout<<endl;
        else first=false;
        memset(dp,-1,sizeof(dp));
        memset(price, -1, sizeof(price));
        dag.clear();
        char h;
        cin >> h;
        int head = h- 'A';
        cin.ignore();
        int val;cin>>val;

        price[head]=val;
        exist[head]=1;

        cin.ignore(); // To ignore the newline character after head
        string line;
        while (getline(cin, line) && !line.empty()) {
            istringstream ss(line);
            char to;
            ss >> to;
            int p;
            ss >> p;
            price[to - 'A'] = p;

            //exist[to-'A']=1;
            char from;
            while (ss >> from) {
                dag[from - 'A'].push_back(to-'A');
                sortant[from-'A']=1;
            }
        }
        for(int i=0;i<28;i++){
            if(exist[i]==1 && sortant[i]==0){
                last=i;
                break;
            }
        }
        //for(int i=0;i<10;i++)cout<<price[i]<<" ";cout<<endl;

        //we will satart from head to the end
        int res=0;
        for(int i=0;i<26;i++)if(exist[i]==1)res=max(res,solve(i));
        cout<<res<<endl;
    }
    return 0;
}
