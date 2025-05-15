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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
    int tt;cin>>tt;
    vector<ll> pow(maxn);
    pow[0]=1;
    for(int i=1;i<maxn;i++){
        pow[i]=pow[i-1]*2;
        pow[i]%=mod;
    }
    while(tt--){
        string s,s2;
        cin >> s >> s2;
         int count = 0;
         for(int i=0;i<s.length();i++){
             if(s[i] =='0')
                 count++;
             else
                 break;
        }


         if(count == 0){
             bool tr = true;
             for(int i=1;i<s.length();i++){
                 if(s[i] =='1'){
                     tr =false;
                     cout << -1 << endl;
                     break;
                 }
             }
             if(tr)
                 cout << 0 << endl;
         }else{
             int c1 =0;
             string t;
             for(int i=count;i<s.length();i++){
                 if(s[i] =='1') {
                     c1++;
                     t.push_back('0');
                 }
                 else
                     t.push_back('1');

             }
             if(c1 == 1) {
                 cout << count << endl;
                 continue;
             }

             long long res=0;
             for(int i=t.length()-1;i>=0;i--){
                 if(t[i] =='1') {
                     res += pow[t.length() -1-i];
                     res %= mod;
                 }
             }
             cout << (res + count)%mod  << endl;
         }
    }
    return 0;
}