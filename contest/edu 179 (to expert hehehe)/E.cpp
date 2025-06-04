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
        int n,q;cin>>n>>q;
        string s;cin>>s;
        int ba=0,ca=0,bc=0,cb=0,cba=0,bca=0;
        for(int i=0;i<q;i++){
            char x,y;
            cin>>x>>y;
            if(x=='b' && y=='a') {
                ba++;
                if(cb > cba)cba ++;
            }
            else if(x=='c' && y=='a') {
                ca++;
                if(bc > bca)bca ++;
            }
            else if(x=='c' && y=='b') {
                cb++;
            }
            else if(x=='b' && y=='c') {
                bc++;
            }
        }
        //making a
        for(int i=0;i<n;i++){
            if(s[i]=='c' && ca>0){
                s[i]='a';
                ca--;
                bca = min(bca,ca);
            }
            else if(s[i]=='c' && cba>0){
                s[i]='a';
                cba--;
                cb--;
                ba--;
            }
            else if(s[i]=='c' && cb>0){
                s[i]='b';
                cb--;
                cba--;
            }
            else if(s[i]=='b' && ba>0){
                s[i]='a';
                ba--;
                cba=min(cba,ba);
            }
            else if(s[i]=='b' && bca>0){
                s[i]='a';
                bca--;
                bc--;
                ca--;
            }
        }
        cout<<s<<endl;

    }
    return 0;
}