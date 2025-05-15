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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        string new_s;
        new_s+=s[0];
        int i;
        for(i=1;i<n-1;i++){
            if(s[i]!=s[i-1] && s[i]!=s[i+1]) {
                new_s+=s[i+1];
                i++;
                continue;
            }
            new_s+=s[i];
        }
        if(i<n)new_s+=s[i];
        //cout<<new_s<<endl;

        int res=0;
        for(int ii=0;ii<new_s.size()-1;ii++){
            if(new_s[ii]==new_s[ii+1])
                res++;
        }
        cout<<res<<endl;

    }
    return 0;
}