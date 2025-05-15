#include<bits/stdc++.h>

using namespace std;
const int maxn=2*1e5+5;
int visited[2][maxn];

int main(){
    int t;cin>>t;
    while(t--){
        memset(visited,0, sizeof(visited));
        int n;cin>>n;
        string arr[2];
        cin>>arr[0];cin>>arr[1];
        //start from (0,0) or (1,0)
        int i=0,j=0;
        bool ans1=true,ans2=true;
        if(arr[i][j]=='B'){
            while(j<n-1){
            // i can either go up,down or right
            visited[i][j]=1;

            if(arr[1-i][j]=='B' && !visited[1-i][j]){
                i=1-i;
                continue;
            }

            if(arr[i][j+1]=='B' && !visited[i][j+1]){
                j++;
                continue;
            }

            ans1=false;
            break;
        }}
        else ans1=false;

        i=1;j=0;
        memset(visited,0, sizeof(visited));
        if(arr[i][j]=='B'){
            while(j<n-1){
            // i can either go up,down or right
            visited[i][j]=1;

            if(arr[1-i][j]=='B' && !visited[1-i][j]){
                i=1-i;
                continue;
            }

            if(arr[i][j+1]=='B' && !visited[i][j+1]){
                j++;
                continue;
            }

            ans2=false;
            break;
        }}
        else ans2=false;
        if(ans1 || ans2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}