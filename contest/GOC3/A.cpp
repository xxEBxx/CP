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
    int n;cin>>n;
    ll l = 3,r = 4;
    ll lll  = 2;
    ll rrr = 2;
    if(n==3 || n==4){
        cout<<2;
        return 0;
    }
    if(n >= 8 && n <= 11 ){
        cout << 4;
        return 0;
    }
    while(true){
        ll temp = r;
        lll = l;
        rrr = r;
        r = temp + (l + r)*(r - l + 1)/2;
        l = temp  +1;

        if(l <= n && r>=n) {
            break;
        }
    }
    ll a = lll;
    ll b = rrr;
    ll c=0 ;
    int cc = 0;

    while(b - a > 1){
        c = (a + b)/2;
        if (rrr + (((lll + c)*(c -lll + 1))/2) > n){
            b = c;
        }
        else if(rrr + ((lll + c)*(c -lll + 1)/2) == n){
            c = (a+b)/2;
            a = c;
            b = c;
            cc = 1;
            break;
        }
        else{
            a=c;
        }
    }

    if(lll == a && n <= rrr + (((lll + a)*(a -lll + 1))/2)){
        cout << a;
    }
    else{
        cout << b;
    }

    return 0;
}