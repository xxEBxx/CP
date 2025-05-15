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
        int n,m;
        cin  >> n >> m;
        vector<vector<long long>> arr(n,vector<long long> (m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin >> arr[i][j];
        }
        vector<vector<long long>> arr2 = arr ;

        vector<int> vis(n,0);
        int row = n;
        for(int i=0;i<min(n,m);i++){
            int a = arr[i][i];
            for(int j=0;j<m;j++)
                arr[i][j] = arr[i][j]/a;
            for(int j=i+1;j<n;j++){
                int b = arr[j][i];
                for(int k=i;k<m;k++)
                    arr[j][k] = arr[j][k] - b*arr[i][k];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    return 0;
}