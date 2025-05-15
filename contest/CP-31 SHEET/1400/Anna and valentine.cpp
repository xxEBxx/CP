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
        int digits=0;
        int n,m;cin>>n>>m;
        vi z;
        for(int i=0;i<n;i++){
            int val,zeros=0;
            cin>>val;
            while(val%10 == 0){
                zeros++;
                val/=10;
            }
            while(val){
                digits++;
                val/=10;
            }
            z.push_back(zeros);
        }
        sort(all(z));
        reverse(all(z));

        for(int i=1;i<z.size();i+=2){
            digits+=z[i];
        }
        if(digits > m){
            cout<<"Sasha"<<endl;
        }
        else{
            cout<<"Anna"<<endl;
        }

    }
    return 0;
}