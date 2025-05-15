#include<bits/stdc++.h>

#define aint(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,int> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<int> vl;
typedef vector<vector<int>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int dp[31][2];

int solve(int i,int last_one,int number){
    //we start with highest i of
    if(i==-1)
        return 1;
    if(dp[i][last_one]!=-1)
        return dp[i][last_one];
    int high;
    if(last_one==1 && (number>>i & 1)==1)
        high = 1;
    else
        high = 0;
    int res=0;
    for(int index=0;index<=high;index++){
        res += solve(i-1,index,number);
    }
    return dp[i][last_one]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1, sizeof dp);
        int number,number1;
        cin>>number>>number1;
        number--;
        int bit;
        for(bit=30;bit>=0;bit--) {
            if (number >> bit & 1)
                break;
        }
        //cout<<bit<<endl;
        int res1 = bit*(bit+1)/2 + solve(bit-1,1,number);
        //cout<<bit<<" "<<res1-solve(bit-1,1,number)<<endl;
        memset(dp,-1, sizeof dp);
        for(bit=30;bit>=0;bit--){
            if(number1>>bit & 1)
                break;
        }

        //cout<<bit<<endl;
        int res2 = bit*(bit+1)/2 + solve(bit-1,1,number1);
        //cout<<bit<<" "<<res2-solve(bit-1,1,number1)<<endl;
        //cout<<res1<<" "<<res2<<" "<<endl;
        cout<<res2-res1<<endl;
    }
    return 0;
}