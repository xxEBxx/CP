#include<bits/stdc++.h>

using namespace std;



int main(){
    int n;cin>>n;
    vector<string> arr1(n);
    vector<long long>arr2(n);
    for(int i=0;i<n;i++){
        cin >> arr1[i] >> arr2[i];
    }
    long long m=0;
    for(int i=0;i<n;i++){
        if(arr1[i] == "pig"){
            if(arr2[i] >= m)
                m = arr2[i];
        }
    }
    long long out=m;
    for(int i=0;i<n;i++){
        if(arr1[i] != "pig" && arr2[i] < m)
            out += arr2[i];
    }
    cout << out;

    return 0;
}