#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()

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
    ifstream cin("foot.in");
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        map<string,int> g;
        string team;cin>>team;
        int val;cin>>val;
        string s=team;
        int score_s=val;
        for(int i=1;i<n;i++){
            cin>>team;cin>>val;
            g[team]=val;
        }
        int m;cin>>m;
        set<string> opponents;
        for(int i=0;i<m;i++){
            string a,b;
            cin>>a>>b;
            if(a!=s)
                g[a]+=3;
            else
                opponents.insert(b);

            if(b!=s)
                g[b]+=3;
            else
                opponents.insert(a);

        }
        string res="YES";
        int used=0;
        for(auto elem : g){
            if(elem.first==s)continue;

            if(elem.second < score_s){
                continue;
            }
            else if(elem.second < score_s+3){
                if((int)opponents.size() > 0)
                    continue;
                else{
                    res="NO";
                    break;
                }
            }
            else if(elem.second < score_s+6 && used==0 && opponents.find(elem.first) != opponents.end()){
                used=1;
                continue;
            }
            else{
                res="NO";
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}