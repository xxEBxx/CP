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
    string s = "45 4c 20 43 4f 44 49 47 4f 20 44 45 20 44 45 53 41 43 54 49 56 41 43 49 4f 4e 20 45 53 3a 20 22 43 4f 44 45 3a 52 55 53 48 3a 54 45 43 22";
    int n=s.size();
    map<string,int> freq;

    for(int i=0;i<n;i++){
        if(s[i]==' ')continue;

        int a,b;
        if(s[i]>='0' && s[i]<='9')
            a=s[i]-'0';
        else
            a=s[i]-'a'+10;

        if(s[i+1]>='0' && s[i+1]<='9')
            b=s[i+1]-'0';
        else
            b=s[i+1]-'a';

        char c = 'a' + ((a*10 +b) % 26);
        cout<<c<<" ";
        string in;
        in+=s[i];
        in+=s[i+1];
        freq[in]++;
        i++;
    }
    cout<<freq.size()<<endl;
    for(auto elem : freq){
        cout<<elem.f<<" "<<elem.s<<endl;
    }

    return 0;
}