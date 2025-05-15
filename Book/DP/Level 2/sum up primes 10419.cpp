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

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
const int maxn=1001,maxt=15,maxi=62;
vi primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,
           163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293};

int n,t,dp[maxi][maxn][maxt];

int solve(int index,int number,int t_far){
    //index means all elements from 0 to primes[i](exclusive) are banned aka used once /twice in another way

    if(t_far==0)return number==0;
    if(number <= 0 || index==62 || t_far<=0)return 0;

    if(dp[index][number][t_far]!=-1)return dp[index][number][t_far];

//always better to take smaller elements for solution
    if(primes[index]!=2 && solve(index+1,number-primes[index]*2,t_far-2)){
        return dp[index][number][t_far]=1;
    }

    if(solve(index+1,number-primes[index],t_far-1)){
        return dp[index][number][t_far]=1;
    }

    return dp[index][number][t_far]=solve(index+1,number,t_far);
}

vi get_ans(int sum,int t_far){
    vi ans;
    for(int i=0;i<62;i++){
        //cout<<sum<<endl;
        if(primes[i]!=2 && sum-2*primes[i]>=0 && t_far-2>=0 && solve(i+1,sum-2*primes[i],t_far-2)){
            ans.push_back(primes[i]);
            ans.push_back(primes[i]);
            t_far-=2;
            sum-=2*primes[i];
        }
        else if(sum-primes[i]>=0 && t_far-1>=0 && solve(i+1,sum-primes[i],t_far-1)){
            int a=primes[i];
            ans.push_back(a);
            t_far--;
            sum -= primes[i];
        }
    }
    return ans;
}


int main(){fast();

    sort(primes.begin(),primes.end(),[](int a,int b){
        return to_string(a)< to_string(b);
    });

    int tt=0;
    while(cin>>n>>t){tt++;
        memset(dp,-1,sizeof(dp));
        if(n==0)break;
        cout<<"CASE "<<tt<<":"<<endl;
        int res=solve(0,n,t);
            if(res){
                vi ans= get_ans(n,t);
                for(int i=0;i<t-1;i++)cout<<ans[i]<<"+";
                if(t>0)cout<<ans[t-1]<<endl;
            }
            else cout<<"No Solution."<<endl;
    }
    return 0;
}