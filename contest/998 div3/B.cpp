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
        vector<vi> arr(n,vi(m));
        for(int i=0;i<n;i++){
            vi temp(m);
            for(int j=0;j<m;j++)
                cin>>temp[j];
            sort(all(temp));
            arr[i]=temp;
        }
        bool sol=true;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j]-arr[i][j-1] != n){
                    sol=false;
                    break;
                }
            }
        }
        if(!sol)
            cout<<-1<<endl;
        else{
            vi res(n);
            int index=1;
            for(auto elem:arr){
                res[elem[0]]=index;
                index++;
            }
            for(auto elem : res){
                cout<<elem<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}