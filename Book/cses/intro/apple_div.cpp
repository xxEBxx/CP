#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll solve(vector<int>& apple,int index,ll sum1,ll sum2){
    if(index==apple.size())return abs(sum1-sum2);
    return min(solve(apple,index+1,sum1+apple[index],sum2) , solve(apple,index+1,sum1,sum2+apple[index]));
}

int main(){
    int n;cin>>n;
    vector<int> apple(n);
    for(int i=0;i<n;i++){
        cin>>apple[i];
    }
    cout<<solve(apple,0,0,0);
}