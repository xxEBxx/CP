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
    string s;
    cin >> s;
        string s2 = s.substr(5,2);
        if(s2 == "09"){
            string s3;
            s3 = s.substr(8,2);
            int d=0;
            for(int i=0;i<2;i++){
                d*=10;
                d+= s3[i]- '0';
            }
            if(d >= 17)
                cout << "TOO LATE";
            else
                cout << "GOOD";

        }
        else if(s2 >= "10")
            cout << "TOO LATE";
        else
            cout << "GOOD";

    return 0;
}