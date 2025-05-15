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
    string a;
    int res=0;
    while(cin>>a){
        if(a=="0")break;
        //cout<<a<<endl;
        for (int i = 0; i < a.size(); i++) {
            //cout<<"hey"<<endl;
            if (a[i] >= 'a' && a[i] <= 'z') {
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}