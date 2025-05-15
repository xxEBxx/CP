#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int solve(vector<pii> arr){
    //we will make a set of pii to store top of towers and there indexes
    //we do a set because we need the higher_bound
    int n=arr.size(),count=0;
    set<pii> s;
    //s.insert(arr[0]);
    for(int i=0;i<n;i++){
        set<pii>::iterator it =s.upper_bound(arr[i]);
        if(it != s.end()){
            s.erase(it);
        }
        else {
            count++;
            //cout << arr[i];
        }
        s.insert(arr[i]);
    }
return count;
}

int main(){
    int n;cin>>n;
    vector<pii> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    cout<<solve(arr);

}