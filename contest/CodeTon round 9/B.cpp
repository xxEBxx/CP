#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

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
        string s;cin>>s;
        int n=(int)s.size();
        //cout<<s<<endl;
        string res="";
        for(int i=0;i<n-2;i++){
            if(s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2]){
                res+=s[i];
                res+=s[i+1];
                res+=s[i+2];
                break;
            }
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                res="";
                res+=s[i];
                res+=s[i+1];
                break;
            }
        }
        if(res.empty())
            cout<<-1<<endl;
        else{
            cout<<res<<endl;
        }
    }
    return 0;
}