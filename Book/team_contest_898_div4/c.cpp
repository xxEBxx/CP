#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int prod=1;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int min_index=0;
        for(int i=1;i<n;i++){
            if(v[i]<v[min_index]){
                min_index=i;
            }
        }
        v[min_index]++;
        for(int i=0;i<n;i++){
            prod*=v[i];
        }

        cout<<prod<<endl;
    }

}