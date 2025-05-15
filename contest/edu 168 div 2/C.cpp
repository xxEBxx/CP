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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int count=0,price=0;
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='(')count++;
                else count--;
            }
            else {
                if(count > 0) {
                    count--;
                    s[i] = ')'; }
                else {
                    count++;
                    s[i]='(';
                }
            }
        }
        stack<int> st;
        int res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(i);
            else {
                int from=st.top();
                st.pop();
                res+=i-from;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}