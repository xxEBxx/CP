#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=5608;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}


struct turtle{
    int w,s;
};
vector<turtle> arr;
bool comp(turtle a, turtle b){
    if(a.s != b.s)return a.s > b.s;
    return a.w > b.w;
}
int n,dp[5608][2000];

int solve(int i,int power){
    if(i==n)return 0;
    if(i>0 && dp[i][power]!=-1)return dp[i][power];
    int res=0;
    if(power >= arr[i].w)
        res=max(res,1 + solve(i+1,min(arr[i].s,power-arr[i].w)));
    res=max(res,solve(i+1,power));
    if(i==0)return res;
    return dp[i][power]=res;

}

int main(){fast();
    int a,b;
    n=0;
    memset(dp,-1,sizeof(dp));
    while(cin>>a>>b){
        if(a==0)break;
        n++;
        arr.push_back({a,b-a});
    }
    sort(all(arr),comp);
    for(auto elem :arr)cout<<elem.w<<" "<<elem.s<<endl;

    cout<<solve(0,1e9)<<endl;
    return 0;
}
/*
 vi lis(n,1),ch7al_haz(n,0);

    for(auto elem :arr)cout<<elem.w<<" "<<elem.s<<endl;

    for(int j=0;j<n;j++){
        for(int i=0;i<j;i++){
            if(arr[i].s >= arr[j].w+ch7al_haz[j]){
                if(lis[i]+1 > lis[j]){
                    lis[j]=lis[i]+1;
                    ch7al_haz[i]=ch7al_haz[j]+arr[j].w;
                }
                else if(lis[i]+1==lis[j]){
                    ch7al_haz[j]=min(ch7al_haz[j],)
                }
            }
        }
    }

    int res=1;
    for(int i=0;i<n;i++)res=max(res,lis[i]);

    cout<<res<<endl;
 */