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
        map<char,int> count;
        for(int i=0;i<n;i++)count[s[i]]++;
        int c1=count['N']-count['S'],c2=count['W']-count['E'];
        if(abs(c1) %2== 1||abs(c2) %2== 1) {
            cout << "NO" << endl;
            continue;
        }
        if(count['N']<2 && count['W']<2 && count['E']<2 && count['S']<2);
        int no,so,we,ea;//These are for helicopter
        if(c1==0 && c2==0){
            if(count['N']>0 && count['W']>0){
                no=1;so=1;ea=0;we=0;
            }
            else if(count['N']>1){
                no=1;so=1;ea=0;we=0;
            }
            else if(count['W']>1){
                no=0;so=0;ea=1;we=1;
            }
            else no=so=ea=we=0;
        }
        else if(c1 == 0){//let the helicopter move
            no=count['N'];
            so=0;
            if(count['N']>0){
                no=1;
                so=1;
            }
        }
        else if(c2 == 0){//let the van move
            ea=0;
            we=0;
            if(count['W']>0){
                ea=1;
                we=1;
            }
        }

        if(c1 > 0){
            no=c1/2;
            so=0;
        }
        if(c2 > 0){
            we=c2/2;
            ea=0;
        }

        if(c1<0){
            c1=-c1;
            no=0;
            so=c1/2;
        }
        if(c2 < 0){
            c2=-c2;
            we=0;
            ea=c2/2;
        }
        string w="";
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                if(no > 0)w+='H';
                else w+='R';
                no--;
            }
            if(s[i]=='S'){
                if(so > 0)w+='H';
                else w+='R';
                so--;
            }
            if(s[i]=='E'){
                if(ea > 0)w+='H';
                else w+='R';
                ea--;
            }
            if(s[i]=='W'){
                if(we > 0)w+='H';
                else w+='R';
                we--;
            }
        }
        bool h=false,d=false;
        for(int i=0;i<n;i++){
            if(w[i]=='R')h=true;
            else d=true;
        }
        if(h && d)cout<<w<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}