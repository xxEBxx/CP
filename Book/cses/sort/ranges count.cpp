#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// Declaring ordered multiset
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_multiset;

typedef pair<int ,int > iip;

struct range{
    int l,r,index;
    bool operator < (const range &other) const{
        if (l==other.l){
            return r > other.r;
        }
        return l < other.l;
    }
};

int main(){
    int n;
    cin >> n;
    vector<range> data(n);
    vector<int> contained(n,0);
    vector<int> contains(n,0);
    // Input pairs and add them to the set
    for(int i = 0; i < n; i++) {
        int l,r;
        cin>>l>>r;
        range element={l,r,i};
        data[i]=element;
    }
    sort(data.begin(),data.end());
    //for(int i=0;i<n;i++){
      //cout<<data[i].index<<" "<<data[i].l<<" "<<data[i].r<<endl;
    //}
    //for contained
    //int max_right=data[0].r;
    ordered_multiset right;
    //right.insert(data[0].r);
    for(int i=0;i<n;i++){
        //for(auto x:right){
          //  cout<<x<<" ";
        //}
        contained[data[i].index]= right.size()-right.order_of_key(data[i].r);
        right.insert(data[i].r);
    }
    //int min_right=INT_MAX;
    right.clear();
    //right.insert(data[n-1].r);
    for(int i=n-1;i>=0;i--){
        contains[data[i].index]= right.order_of_key(data[i].r+1);
        right.insert(data[i].r);
    }
    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }
    return 0;
}

