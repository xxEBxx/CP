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
    string s;cin>>s;
    string res="";
    int first_a=-1,last_a=-1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='@') { last_a = i;break; }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='@') { first_a = i;break; }
    }
    if(first_a==-1 || first_a==0 || last_a==s.size()-1){
        cout<<"No solution"<<endl;
        return 0;
    }
    if(first_a==last_a){
        cout<<s<<endl;
        return 0;
    }
    int i=0,n=s.size();
    while(i<n){
        if(i>last_a){
            res+=s[i];
            i++;
            continue;
        }
        if(s[i]=='@'){
            res+='@';
            i++;
            res+=s[i];
            if(i<last_a) {
                res += ',';
                //cout<<i<<" "<<last_a<<endl;
            }
        }
        else{
            res+=s[i];
        }
        i++;
    }

    for(int index=1;index<res.size();index++){
        if(res[index]=='@' ){
            if(res[index-1]==',' || res[index-1]=='@'){
                cout << "No solution";
                return 0;
            }
        }
    }
    //if(res[res.size()-1]==',')res.erase(res.size()-1);
    cout<<res<<endl;

    return 0;
}
