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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
    string b;cin>>b;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string bi ; cin>>bi;
        int a=0,j=0;
        int m = bi.length();
        while(a<b.length() && j<m){
            if(b[a] ==  bi[j]){
                a++;
                j++;
            }
            else
            a++;
        }
        if(j == m)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}