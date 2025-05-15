#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int val;cin>>val;
            arr.push_back(val);
        }
        int res=1,index=-1;
        for(int i=arr.size()-2;i>=0;i--){
            //cout<<"hey";
            if(arr[i] > arr[i+1]){
                if(arr[i] < 10){
                    res=0;
                    break;
                }
                index=i;
//index to wich everything should break 0 to i
                break;
            }
        }
        //cout<<"here is index"<<index<<endl;
        if(index==-1){
            if(res)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        vector<int> v;
        for(int i=0;i<=index;i++){
            if(arr[i] < 10){
                v.push_back(arr[i]);
            }
            else{
                v.push_back(arr[i]/10);
                v.push_back(arr[i]-arr[i]/10 *10);
            }
        }
        for(int i=index+1;i<n;i++){
            v.push_back(arr[i]);
        }
        vector<int> other=v;
        sort(other.begin(),other.end());
        if(other==v)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
