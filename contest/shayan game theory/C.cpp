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
        int even=0,odd=0;
        for(int i=0;i<n;i++){
            int val;cin>>val;
            if(val&1)
                odd++;
            else
                even++;
        }

        if(odd%4==2){
            cout<<"Bob"<<endl;
        }
        else if(odd%4==0){
            if(even%2==1 || even==0 || odd==0)
                cout<<"Alice"<<endl;
            else
                cout<<"Bob"<<endl;
        }
        else if(odd%4==1){
            if(even%2==1)
                cout<<"Alice"<<endl;
            else
                cout<<"Bob"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}