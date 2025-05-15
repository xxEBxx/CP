#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<char> vi;
typedef vector<vector<char>> vvi;
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

    vvi s(n,vi(n)),t(n,vi(n));
    vvi t1=t,t2=t,t3=t,t4=t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>t1[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t2[i][j] = t1[j][n-1-i];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t3[i][j] = t2[j][n-1-i];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t4[i][j] = t3[j][n-1-i];
        }
    }
    int s1=0,s2=1,s3=2,s4=3;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j] != t1[i][j])s1++;
            if(s[i][j] != t2[i][j])s2++;
            if(s[i][j] != t3[i][j])s3++;
            if(s[i][j] != t4[i][j])s4++;
        }
    }
    cout<<min(min(s1,s2),min(s3,s4))<<endl;

    return 0;
}