#include <bits/stdc++.h>
#define ll long long
const ll mod = 1e9 + 7;
const double maxn = 1e5 + 5;
using namespace std;

double dis(pair<double,double> a,pair<double,double> b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

int n;
vector<pair<double,double>> pairs; // from input
double res;
vector<vector<double>> mat;

void solve(int bitmask,double distance_far){
    if(res <= distance_far)return;
    
    if(bitmask == ( (1<<(2*n)) -1) ){
        res = min(distance_far,res);
    }

    int first = -1;
    for (int i = 0; i < 2 * n; i++) {
        if (!(bitmask & (1<<i))) {
            first = i;
            break;
        }
    }
    if (first == -1) return;

    for (int j = first + 1; j < 2 * n; j++) {
        if (!(bitmask & (1<<j))) {
            int new_bitmask = bitmask | (1 << first) | (1 << j);
            solve(new_bitmask, distance_far + mat[first][j]);
        }
    }
}

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int main(){fast();
    int t;cin >> t;
    while(t--){
        cin >> n;
        pairs.assign(2*n,{0,0});
        string a;
        for(int i=0;i < 2*n;i++){
            cin >> a;
            cin>>pairs[i].first>>pairs[i].second;
        }
        mat.assign(2*n,vector<double>(2*n,0.0));
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){
                mat[i][j] = dis(pairs[i],pairs[j]);
            }
        }

        res = 1e30;
        solve(0,0.0);
        cout << fixed << setprecision(2) << res << endl;
    }

    return 0;
}


