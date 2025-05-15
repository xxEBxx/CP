#include<bits/stdc++.h>

int maxn=1e6+5;
using namespace std;

int main(){
    int n,x;cin>>n>>x;
    vector<int> pieces(n);
    for(int i=0;i<n;i++) cin>>pieces[i];

    vector<int> number_coins(x+1,1000000000);
    number_coins[0]=0;
    for (int j = 1; j <= x+1; j++) {
        for (int i = 0; i < n; i++) {
            if (j - pieces[i] >= 0) {
                number_coins[j] =
                        min(number_coins[j], 1 + number_coins[j - pieces[i]]);
            }
        }
    }
    if(number_coins[x]==1000000000) cout<<-1;
    else cout << number_coins[x];

}