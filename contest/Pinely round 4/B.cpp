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
        int n;cin>>n;
        vector<int> arr(n-1),res(n);
        for(int i=0;i<n-1;i++){
            cin>>arr[i];
        }
        res[0]=arr[0];
        res[1]=arr[0];
        for(int i=1;i<n-1;i++){
            for(int j=0;j<31;j++){
                if(arr[i]& (1<<j) )
                    res[i]|=(1<<j);
            }
            res[i+1]=arr[i];
        }
        bool ex=true;
        for(int i=0;i<n-1;i++){
            if( (res[i]&res[i+1]) != arr[i]){
                ex=false;break;
            }
        }
        if(!ex)cout<<-1<<endl;
        else {
            for (int i = 0; i < n; i++)cout << res[i] << " ";
            cout << endl;
        }
    }
    return 0;
}


