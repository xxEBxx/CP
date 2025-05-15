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
        string n;
        cin>>n;
        if(n.size()>2 && n[0]=='1' && n[1]=='0'){
            string a="";
            for(int i=2;i<n.size();i++)a+=n[i];
            if(a>"1")
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

        }
        else cout<<"No"<<endl;
    }
    return 0;
}