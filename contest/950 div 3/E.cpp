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

bool comp (vector<int> a, vector<int> b){
    return a[0]<b[0];
}

void print_mat(vvi mat){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vvi m1(n,vi(m)),m2(n,vi(m))
            ,tm1(m,vi(n)),tm2(m,vi(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>m1[i][j];
                tm1[j][i]=m1[i][j];
            }
            sort(all(m1[i]));
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>m2[i][j];
                tm2[j][i]=m2[i][j];
            }
            sort(all(m2[i]));
        }
        for(int i=0;i<m;i++){
            sort(all(tm1[i]));
            sort(all(tm2[i]));
        }
        //print_mat(m1);cout<<endl;
        //print_mat(m2);

        sort(all(m1),comp);
        sort(all(m2),comp);
        sort(all(tm1),comp);
        sort(all(tm2),comp);

        if(m1==m2 && tm1==tm2)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}