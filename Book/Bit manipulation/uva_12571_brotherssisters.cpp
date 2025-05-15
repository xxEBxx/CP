#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,q;cin>>t;
    map<int,int> m;//this map q to the max value;
    while(t--){

        cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int value,max_value;
        while (q--){
            cin>>value;
            if (m.find(value)==m.end()) {
                max_value=0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] & value > max_value) {
                        max_value = arr[i] & value;
                    }
                }
                m[value]=max_value;
            }
            cout<<m[value]<<endl;
        }
    }
}