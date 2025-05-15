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
//initially we are H

int main(){fast();
    int n,a,b,t;
    cin>>n>>a>>b>>t;
    string s;cin>>s;
    int res=0,i=0,j=n-1,price=t;
    char state='h';
    while(i<n && price >= 0){
        if(s[i]==state){
            price-=b;
            if(state=='h')state='w';
            else state='h';
        }
        else{
            price-=a;
        }
        i++;
    }
    res=i;
    if(i!=n)res--;
    while(i>=0 && price >= 0){
        if(s[i]==state){
            price-=b;
            if(state=='h')state='w';
            else state='h';
        }
        else{
            price-=a;
        }
        i--;
    }

    return 0;
}