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
int n,dp[maxn][2][2],a[maxn],b[maxn],a_lost,b_lost,jump_a,jump_b;

int solve(int i,int inserted_a,int inserted_b){
    if(i==n)return 0;
    if(dp[i][inserted_a][inserted_b]!=-1)return dp[i][inserted_a][inserted_b];

    int res=0;
    //if both inserted just continue
    if(inserted_b==1 && inserted_a==1){//no jumps here
        res=abs(a[i-1]-b[i-1]) + solve(i+1,1,1);
    }
    else if(inserted_b==0 && inserted_a==1){
        //try to insert b here or dont ,
        if(i<n-1)res=max(abs(b[i]-a[i-1])+solve(i+1,1,0),res);
        if(res < abs(b_lost-a[i-1])+solve(i+1,1,1)){
            jump_b=i;

            res=abs(b_lost-a[i-1])+solve(i+1,1,1);
            jump_b=i;

        }
    }
    else if(inserted_a==0 && inserted_b==1){
        //try to insert b here or dont ,
        if(i<n-1)res=max(abs(a[i]-b[i-1])+solve(i+1,0,1),res);
        if(res < abs(a_lost-b[i-1])+solve(i+1,1,1)){
            jump_a=i;

            res=abs(a_lost-b[i-1])+solve(i+1,1,1);
            jump_a=i;

        }
    }
    else{
        if(i<n-1)res=max(res,abs(a[i]-b[i])+solve(i+1,0,0));
        if(i<n-1)if(res < abs(a[i]-b_lost)+solve(i+1,0,1)){
                jump_b=i;

                res=abs(a[i]-b_lost)+solve(i+1,0,1);
            jump_b=i;
        }
        if(i<n-1)if(res<abs(b[i]-a_lost)+solve(i+1,1,0)){
                jump_a=i;
                res=abs(b[i]-a_lost)+solve(i+1,1,0);
            jump_a=i;
        }
        if(res < abs(a_lost-b_lost)+solve(i+1,1,1)){
            jump_a=i;
            jump_b=i;
            res=abs(a_lost-b_lost)+solve(i+1,1,1);
            jump_a=i;
            jump_b=i;
        }
    }

    return dp[i][inserted_a][inserted_b]=res;
}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    cin>>n;
    int tot_a=0,tot_b=0;
    for(int i=0;i<n-1;i++) {
        cin >> a[i];
        tot_a+=a[i];
    }
    for(int i=0;i<n-1;i++) {
        cin >> b[i];
        tot_b+=b[i];
    }
    a_lost=n*(n+1)/2-tot_a;
    b_lost=n*(n+1)/2-tot_b;
    //cout<<a_lost<<" "<<b_lost<<endl;
    cout<<solve(0,0,0)<<endl;
    for(int i=0;i<n;i++){
        if(i==jump_a)cout<<a_lost<<" ";
        if(i<n-1)cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i==jump_b)cout<<b_lost<<" ";
        if(i<n-1)cout<<b[i]<<" ";
    }
    //cout<<jump_a<<" "<<jump_b;
    return 0;
}