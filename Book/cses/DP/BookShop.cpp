#include<bits/stdc++.h>

using namespace std;
#define mod 1000000009
#define maxn 1000+2
const int maxx=1e5+2;
const int INF = 1e9;
int n, x;
vector<int> price(maxn,0),pages(maxn,0);

//vector<vector<int>> memo(maxn,vector<int> (maxx, 0));

// memo[i][curr]  max value after considering first i books with remain curr money from x

/*int solve(int i,int money){
    if (i == n) return 0;
    if (memo[i][money] != -1) return memo[i][money];
    if (money >= price[i]) return memo[i][money] = max(solve(i + 1, money), solve(i + 1, money - price[i]) + pages[i]);
    return memo[i][money] = solve(i + 1, money);
}*/

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>> max_pages(n+1,vector<int> (x+1,0));
    //cout<<solve(0, x)<<endl;
    for(int i=0;i<n;i++){
        for(int money=0;money<=x;money++){
            if(money >= price[i]){
                max_pages[i+1][money]=max(max_pages[i][money],max_pages[i][money-price[i]]+pages[i]);
            }
            else{
                max_pages[i+1][money]=max_pages[i][money];
            }
        }
    }
    /*for(int i=0;i<n+1;i++){
        for(int money=0;money<=x;money++){
            cout<<max_pages[i][money]<<" ";
        }
        cout<<endl;
    }*/
    cout<<max_pages[n][x];
}