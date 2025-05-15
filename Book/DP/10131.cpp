#include <bits/stdc++.h>

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

const int maxn=(int)1007;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
struct elem{
    int iq, w, index;
};
bool comp (elem a, elem b){
    if(a.w != b.w) return a.w < b.w;
    else return a.iq > b.iq;
}

int n;
vector<elem> arr(maxn);
vi output,dp,p;
int res=0;
void print_lis(int i){
    res++;
    output.push_back(arr[i].index + 1);
    if(p[i] == -1) return;
    else print_lis(p[i]);
}

int main(){
    fast();
    string line;
    int in = 0;
    while(getline(cin, line)) {
        if(line.empty())break;
        stringstream ss(line);
        elem one;
        ss >> one.w >> one.iq;
        one.index = in;
        arr[in] = one;
        in++;
    }
    n = in;
    arr.resize(n);

    sort(all(arr), comp);
    //for(int i=0;i<n;i++)cout<<arr[i].w<<" "<<arr[i].iq<<endl;

    dp.resize(n,1);p.resize(n,-1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            //cout<<"here i j"<<i<<" "<<j<<endl;
            if(arr[i].w!=arr[j].w && arr[i].iq < arr[j].iq ){
                if(dp[j]+1 > dp[i]){
                    p[i]=j;
                    dp[i]=dp[j]+1;
                }
            }
        }
    }
    //for(int l:dp)cout<<l<<" ";
    int max_index = 0;
    for(int i=1;i<n;i++){
        if(dp[i] >= dp[max_index])max_index=i;
    }
    print_lis(max_index);
    reverse(all(output));
    cout << res << endl;
    for(int r : output) cout << r << endl;

    return 0;
}
