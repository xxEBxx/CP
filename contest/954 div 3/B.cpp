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

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vvi arr(n,vi (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ cin >> arr[i][j]; }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int max_neighbour=0;
                if(i>0)max_neighbour=max(max_neighbour,arr[i-1][j]);
                if(j>0)max_neighbour=max(max_neighbour,arr[i][j-1]);
                if(i<n-1)max_neighbour=max(max_neighbour,arr[i+1][j]);
                if(j<m-1)max_neighbour=max(max_neighbour,arr[i][j+1]);
                if(max_neighbour < arr[i][j]){
                    arr[i][j]=max_neighbour;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
                }
            cout<<endl;
            }
    }
    return 0;
}