// link : https://vjudge.net/problem/UVA-10313
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
    int n=303,m=303;
    vvi dp(n,vi(m,0));


    for(int mon=2;mon<m;mon++){//the amount of money to take or to not take
        for(int i=2;i<n;i++){//the number of coins
            dp[mon][i]=
        }
    }


    string line;
    while(getline(cin,line)){
        stringstream ss(line);
        int elem;
        vi elements;
        while(ss>>elem)elements.push_back(elem);
        if(elements.size()==0)cout<<dp[elements[0]][300]<<endl;
        else if(elements.size()==1)cout<<dp[elements[0]][elements[1]]<<endl;
        else cout<<dp[elements[0]][elements[2]]-dp[elements[0]][elements[1]]<<endl;
    }
    return 0;
}