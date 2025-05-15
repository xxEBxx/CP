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
    int t;cin>>t;
    int log=20;
    while(t--){
        int n,q;cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> temp;
        for(int i=0;i<n-1;i++){
            temp.push_back(abs(arr[i]-arr[i+1]));
        }
        arr=temp;
        n=arr.size();
        vvi st(n,vi (log,0));

        for(int i=0;i<n;i++){
            st[i][0]=arr[i];
        }

        for(int j=1;j<log;j++){
            for(int i=0;i<n;i++){
                if(i+(1<<(j-1)) < n)
                    st[i][j] = gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }

        while(q--){
            int a,b;cin>>a>>b;
            a--;b--;
            //we want gcd from [a;b[
            int diff=b-a;
            int res=-1;
            for(int j=log-1;j>=0;j--){
                if(diff & (1<<j)){
                    if(res==-1)res = st[a][j];
                    else res=gcd(st[a][j],res);
                    a += (1<<j);
                }
            }
            cout<<max(0,res)<<" ";
        }
        cout<<endl;
    }
    return 0;
}