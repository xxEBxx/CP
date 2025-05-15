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

int gcd1(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd1(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


int main(){fast();
    int a,b,c;cin>>a>>b>>c;
    for(int i=0;i<c+1;i++){
        for(int j=0;j<1+c;j++){
            if(a*i+b*j==c){
                cout<<"Yes";
                return 0;
            }
            else if(a*i+b*j>c){
                break;
            }
        }
    }
    cout<<"NO";

    return 0;
}