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

const int N=(int)1e5+2;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    vector<vector<int>> divisors(N);
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisors[j].push_back(i);
        }
    }

    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> arr(m+1);
        for(int i=1;i<=m;i++){
            cin>>arr[i];
        }
//to take element arr[i] u need to be premier with m[arr[i]]
        vector<int> res;
        res.push_back(arr[m]);
        map<int,int> prim;
        for(int i=2;i<=n;i++){
            /*map<int,int> not_allowed;
            for(int elem :divisors[i]) {
                not_allowed[elem]=1;
            }
            for(int j=m-1;j>=1;j--){
                if(not_allowed[arr[j]]==0){
                    res.push_back(arr[j]);
                    break;
                }
            }*/
            for(int j=m-1;j>=1;j--){
                if(prim[arr[j]]==0){
                    prim[arr[j]]=i;
                    res.push_back(arr[j]);
                    break;
                }
                else if(gcd(prim[arr[j]],i)==1){
                    prim[arr[j]]=lcm(prim[arr[j]],i);
                    res.push_back(arr[j]);
                    break;
                }
            }
        }
        if(res.size() < n) {
            cout << -1 << endl;
            for (int elem: res) {
                cout << elem << " ";
            }
        }
        else{
            for(int elem:res){
                cout<<elem<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}