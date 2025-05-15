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
    int a,b,c;cin>>a>>b>>c;
    int number_prop=1,money=0,res=0;
    while(number_prop < c){
        money += number_prop*b;
        int to_add = money/a;
        money -= to_add*a;
        number_prop += to_add;
        res++;
    }
    cout<<res<<endl;
    return 0;
}