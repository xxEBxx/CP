#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> lis;
    lis.push_back(v[0]);
    //this vector will have the same length as the real lis but not the same elements appearently
    for(int i=1;i<n;i++){
        if(v[i] > lis[lis.size()-1])lis.push_back(v[i]);
        else{
            // binary search to find element just higher than it and switch them
            auto it = lower_bound(lis.begin(), lis.end(),v[i]);
            *it=v[i];
        }
    }
    cout<<lis.size();
}
