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
    int a,b;
    float aa,bb;
    cin>>a>>b>>aa>>bb;
    aa*=100;
    bb*=100;

    float f=(a-1)/aa,s=(b-1)/bb;
    //cout<<f<<" "<<s<<endl;
    if(abs(f-s) < 1e-8)
        cout<<"SAME";
    else if(f<s){
        cout<<"TAOYUAN";
    }
    else if(s<f) cout<<"JAKARTA";


    return 0;
}