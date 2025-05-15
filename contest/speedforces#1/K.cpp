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
    int n,q;cin>>n>>q;
    vi arr(n);
    int total=0;
    for(int i=0;i<n;i++) { cin >> arr[i];total+=arr[i] ;}
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        if(a==1){
            b--;
            if(arr[b]==0){
                arr[b]=1;
                total++;
            }
            else{
                arr[b]=0;
                total--;
            }
        }
        else{
            if(total>=b)cout<<1<<endl;
            else cout<<0<<endl;
        }
    }

    return 0;
}