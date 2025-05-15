#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t,n,c;
    float value,sum;
    vector<float> proba;
    vector<float> gain;
    vector<float> sums;
    cin>>c;
    cin>>t;
    for(int k=0;k<t;k++){
        sum=0;
        proba.clear();
        gain.clear();
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>value;
            gain.push_back(value);
        }
        for (int i=0;i<n;i++){
            cin>>value;
            proba.push_back(value);
        }
        for (int i=0;i<n;i++){
            sum += gain[i]*proba[i];
        }
        sums.push_back(sum/n);
    }
    float max= *max_element(sums.begin(), sums.end());
    cout<<c*max;
}