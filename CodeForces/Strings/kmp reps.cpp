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

vi get_lps(string p){
    int m=p.size(),i=1,j=0;
    vi res(m);res[0]=0;
    while(i<m){
        if(p[i]==p[j]){
            j++;
            res[i]=j;
            i++;
        }
        else if(j>0){
            j=res[j-1];
        }
        else {
            res[i]=0;
            i++;
        }
    }
    return res;
}

int kmp(string t,string p){
    int n=t.size(),m=p.size(),i=0,j=0,res=0;
    vi lps=get_lps(p);
    while(i<n){
        if(j==m){
            j=0;
            res++;
            //cout<<"here is i "<<i<<endl;
        }
        if(t[i]==p[j]){
            i++;j++;
        }
        else if (j>0){
            j=lps[j-1];
        }
        else{
            i++;
        }
    }
    return res+(j==m);
}

int main(){fast();
        string a,p;cin>>a>>p;
        cout<<kmp(a,p)<<endl;
    return 0;
}