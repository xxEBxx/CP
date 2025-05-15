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
        if(n==2){
            if(s[0]!='0')cout<<s<<endl;
            else cout<<s[1]<<endl;
            continue;
        }
        int res=0;
        int count_z=0,index_z;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count_z++;
                index_z=i;
            }
        }
        if(count_z>1) {
            cout << 0 << endl;
            continue;
        }
        if(count_z==1){
            if(n==3 && index_z==1){
                if(s[0]=='1' || s[2]=='1')cout<<(s[0]-'0')*(s[2]-'0')<<endl;
                else cout<<s[0]+s[2]-'0'-'0'<<endl;
            }
            else{
                cout<<0<<endl;
            }
            continue;
        }
            int min_index=0;
            for(int i=1;i<n-1;i++){
                if(s[i] < s[min_index])min_index=i;
                else if (s[i]==s[min_index] && s[i+1] > s[min_index+1])min_index=i;
            }
                for(int i=0;i<n;i++){
                    if(min_index==i){
                        res+=10*(s[i]-'0');
                        res+=s[i+1]-'0';// i know i+1 exist
                        i++;
                    }
                    else if(s[i]=='1'){
                    }
                    else{
                        res+=s[i]-'0';
                    }

            }
            cout<<res<<endl;


    }
    return 0;
}