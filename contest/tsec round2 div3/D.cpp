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
        string a;cin>>a;
        a="a"+a;
        vector<vector<int>> ps(n+1,vi(7,0));
        for(int i=1;i<=n;i++){
            for(int j=0 ; j<7 ; j++){
                ps[i][j]=ps[i-1][j];
            }
            if(a[i]=='h')
                ps[i][0]++;
            else if(a[i]=='a')
                ps[i][1]++;
            else if(a[i]=='r')
                ps[i][2]++;
            else if(a[i]=='d')
                ps[i][3]++;
            else if(a[i]=='w')
                ps[i][4]++;
            else if(a[i]=='o')
                ps[i][5]++;
            else if(a[i]=='k')
                ps[i][6]++;
        }

        int i=1,j=1;
        int res=1e9;
        while(i < n+1){
            bool valid=true;
            for(int letter=0;letter<7;letter++){
                if(letter==2) {
                    if (ps[i][2] - ps[j-1][2] < 2) {
                        valid = false;
                        break;
                    }
                }
                else{
                    if (ps[i][letter] - ps[j-1][letter] < 1) {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid){
                res=min(res,i-j+1);
                j++;
            }
            else{
                i++;
            }
        }
        if(res > 1e8)
            cout<<-1<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}//
// Created by benje on 10/23/2024.
//
