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
        int n;cin>>n;
        vector<int> count(101,0),arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            count[arr[i]]++;
        }
        //for(int elem:count)cout<<elem<<" ";cout<<endl;
        int unique=0,mult=-1;
        //mult is the actual number who is multiple
        for(int i=1;i<=100;i++){
            if(count[i] == 1 )unique++;
            if(count[i] > 2)mult=i;
        }
        //cout<<unique<<endl;
        //cout<<mult<<endl;
        if(unique%2 == 0){
            char c='A';
            string s="";
            for(int i=0;i<n;i++){
                if(count[arr[i]]==1){
                    s+=c;
                    if(c=='A')c='B';
                    else c='A';
                }
                else {
                    s+='A';
                }
            }
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
        else{
            if(mult==-1){
                cout<<"NO"<<endl;
            }
            else{
                string s="";
                char c='A';
                bool first=true;
                for(int i=0;i<n;i++){
                    if(arr[i]==mult){
                        if(first){
                            s+='B';
                            first=false;
                        }
                        else{
                            s+='A';
                        }
                    }
                    else if(count[arr[i]]==1){
                        s+=c;
                        if(c=='A')c='B';
                        else c='A';
                    }
                    else {
                        s+='A';
                    }
                }
                cout<<"YES"<<endl;
                cout<<s<<endl;

            }



    }
    return 0;
}