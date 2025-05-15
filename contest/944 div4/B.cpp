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
        string word;cin>>word;
        int n=word.size(),i=1;
        if(n==1){
            cout<<"NO"<<endl;
            continue;
        }
        while(i<n && word[i]==word[0]){
            i++;
        }
        if(i==n){
            cout<<"NO";
        }
        else{
            cout<<"YES"<<endl;
            char c=word[i];
            word[i]=word[0];
            word[0]=c;
            cout<<word;
        }
        cout<<endl;

    }
    return 0;
}