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

int dp[9][2][3],pals[18];
void fill(){
    pals[0]=0;
    pals[1]=10;
    pals[2]=19;
    int val=9;
    for(int i=3;i<18;i++) {
        if(i&1)val *= 10;
        pals[i] = val + pals[i - 1];
    }
}
string a,b;
int solve(int i,int small,int semi_small,string word){
    if(word=="0")return 1;
    int n=word.size();
    if(i== ((n+1)/2)) {
        if(small)return 1;
        if(semi_small >= 1)return 1;
        return 0;
    }

    if(dp[i][small][semi_small]!=-1)return dp[i][small][semi_small];

    int res=0,high=word[i]-'0';
    if(small)high=9;

    int start=0;
    if(i==0 && n>1)start=1;

    for(int index=start;index<=high;index++){
        int n_small=small,n_ssmall=semi_small;
        if(index<high)n_small=1;
        if( (word[n-i-1]-'0') > index){//means it is good at the other side
            n_ssmall=2;
        }
        else if( (word[n-i-1]-'0') < index){//means it is good at the other side
            n_ssmall=0;
        }

        res+=solve(i+1,n_small,n_ssmall,word);
    }
    return dp[i][small][semi_small]=res;

}

int main(){fast();
    fill();
    int t,tt=0;cin>>t;
    while(t--){tt++;
        memset(dp,-1,sizeof(dp));

        cin>>a>>b;
        if(a.size()>b.size() || (a.size()==b.size() && a>b))swap(a,b);

        int second=pals[b.size()-1],first=pals[a.size()-1];

        second+=solve(0,0,1,b);
        memset(dp,-1,sizeof(dp));

        first+=solve(0,0,1,a);

        int res=second-first;
        int to_add=1;
        for(int i=0;i<((a.size()+1)/2);i++){
            if(a[i]!=a[a.size()-1-i]){
                to_add=0;
                break;
            }
        }

        cout<<"Case "<<tt<<": "<<res+to_add<<endl;
    }
    return 0;
}