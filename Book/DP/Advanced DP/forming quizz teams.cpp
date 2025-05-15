#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define s second

using namespace std;

typedef double dd;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
const int maxn=17;

int n,cordinates[maxn][2];
dd distance(int i,int j){
    int x=cordinates[i][0]-cordinates[j][0],y=(cordinates[i][1]-cordinates[j][1]);
    return sqrt(x*x+y*y);
}

dd dp[maxn][(1<<maxn)+2];

dd solve(int index,int mask){
    if(mask == ( (1<<n)-1) ) return (dd)0;
    if(dp[index][mask] != (dd)-1)return dp[index][mask];
    if(mask & (1<<index))//this element is already paired
        return dp[index][mask]=solve(index+1,mask);
    dd res=(dd)1e9;
    for(int i=index+1 ; i<n ; i++){
        if((mask & (1<<i)) == 0){
            //we will pair these elements
            res=min(res,distance(i,index)+solve(index+1,mask | (1<<i) | (1<<index)));
        }
    }
    return dp[index][mask]=res;
}


int main(){fast();int tt=0;
    while(cin>>n){tt++;
        if(n==0)break;
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < (1 << maxn) + 2; j++) {
                dp[i][j] = -1;
            }
        }        n*=2;
        for(int i=0;i<n;i++){
            string a;cin>>a;
            cin>>cordinates[i][0]>>cordinates[i][1];
        }
        cout<<"Case "<<tt<<": ";
        cout<<fixed<<setprecision(2)<<solve(0,0)<<endl;
    }
    return 0;
}