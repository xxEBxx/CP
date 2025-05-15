#include<bits/stdc++.h>

using namespace std;
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
      //  cout<<data[i].index<<" "<<data[i].l<<" "<<data[i].r<<endl;
    //}
    //for contained
    int max_right=INT_MIN;
    for(int i=0;i<n;i++){
        if (data[i].r <= max_right){
            contained[data[i].index]=1;
        }
        else{
            max_right=data[i].r;
        }
    }
    int min_right=INT_MAX;
    for(int i=n-1;i>=0;i--){
        if (data[i].r >= min_right){
            contains[data[i].index]=1;
            //cout<<"here is index right and min right"<<data[i].index<<" "<<data[i].r<<"  "<<min_right<<endl;
        }
        else{
            min_right=data[i].r;
            //cout<<"here is index right and min right"<<data[i].index<<" "<<data[i].r<<"  "<<min_right<<endl;
        }
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

