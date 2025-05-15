#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n),diffs(n);
        for(int &k:arr)cin>>k;
        if(n==1){cout<<1<<endl;continue;}
        sort(arr.begin(),arr.end());
        int pgcd=arr[1]-arr[0];
        for(int i=1;i<n-1;i++){
            pgcd=gcd(pgcd,arr[i+1]-arr[i]);
        }
        //cout<<"here is pgcd"<<pgcd<<endl;
        int last_elem=pgcd + arr[n-1];
        int res=0;
        int blassa=-1;
        for(int i=n-1;i > 0;i--){
            if(arr[i]-arr[i-1] > pgcd){
                blassa=i;
                break;
            }
        }
        if(blassa!=-1){
            last_elem=arr[n-1];
            res=(last_elem-(arr[blassa]-4))/pgcd ;
        }
        for(int i=0;i<n;i++){
            res +=(last_elem-arr[i])/pgcd;
        }
        cout<<res<<endl;
    }
}