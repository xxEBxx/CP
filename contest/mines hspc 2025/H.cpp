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
    int a,b,c;cin>>a>>b>>c;
    int res = a*25 + b*25 +c*50;
    if(res >= 9000){
        cout<<"A";
    }
    else if(res >= 8000){
        cout<<"B";
    }
    else if(res>=7000){
        cout<<"C";
    }
    else if(res>=6000){
        cout<<"D";
    }
    else{
        cout<<"F";

    }
    return 0;
}