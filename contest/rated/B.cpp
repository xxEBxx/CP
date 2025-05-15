#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n),mex(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int min_elem=0;
        vector<bool> done(n+1,false);
        for(int i=0;i<n;i++){
            if(arr[i] > 0) {
                while(done[min_elem])min_elem++;
                cout << min_elem << " ";
                min_elem++;
            }
            else{
                done[min_elem-arr[i]]=true;
                cout<< min_elem-arr[i] <<" ";
            }
        }
        cout<<endl;
    }
}