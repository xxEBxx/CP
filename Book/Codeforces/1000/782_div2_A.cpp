#include<bits/stdc++.h>

using namespace std;

string solve(int r, int b){
    string res="";
    char win,lose;
    (r>b)? win='R':win='B';
    (win=='R')?lose='B':lose='R';
    int g=max(r,b),l=min(r,b);
    int interval;
    (g%(l+1)==0)? interval=g/(l+1):interval=g/(l+1)+1;
    int mean=g/l,upper_bound=g-l*mean;

    while(g>0 || l>0){
        //cout<<"hi";
        int curr_interval;
        if(upper_bound>0){
            upper_bound--;
            curr_interval=interval;
        }
        else{
            curr_interval=interval-1;
        }
        for(int i=0;i<curr_interval && g>0;i++){
            res+=win;
            g--;
        }
        if(l>0){
            res += lose;
            l--;
        }
    }
    return res;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,r,b;cin>>n>>r>>b;
        cout<<solve(r,b)<<endl;
    }
}