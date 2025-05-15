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
        string a;cin>>a;

        int c=0;
        for(int i=0;i<n;i++){
            if(a[i]=='1') {
                c++;
            }
        }
        if(c==1) {
            if(a[1]=='1')
                cout<<"BOB"<<endl;
            else
                cout << "ALICE" << endl;
        }
        else {
            if(a[0]=='0' && a[1]=='0')
                cout << "ALICE" << endl;
            else
                cout << "BOB" << endl;
        }
    }
    return 0;
}