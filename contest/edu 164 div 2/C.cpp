#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(v) v.begin(),v.end()

int main(){
    int t;cin>>t;
    while(t--){
        string a,b;cin>>a>>b;
        int i=0;
        while(a[i]==b[i]){
            i++;
        }
        //we have first difference;
        if(a[i] > b[i]){
            //a take all smalls
            for(int j=i+1;j<a.size();j++){
                char max_el=max(a[j],b[j]),min_el=min(a[j],b[j]);
                a[j]=min_el;
                b[j]=max_el;
            }
        }
        else{
            //a take all bigs
            for(int j=i+1;j<a.size();j++){
                char max_el=max(a[j],b[j]),min_el=min(a[j],b[j]);
                a[j]=max_el;
                b[j]=min_el;
            }
        }



        cout<<a<<endl<<b<<endl;
    }
    return 0;
}