#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        map<int,int> m;//value:index
        //map is sorted by value , but we still ahve original index
        //index ,element
        int value;
        for(int i=0;i<n;i++){
            cin>>value;
            m[value]=i;
        }
        map<int,int> prefix_sum;
        prefix_sum[0]=0;
        prefix_sum[m[0]]=1;
        //prefix sum (without element itself)-> original index
        for(int i=2;i<n;i++){
            prefix_sum[m[i-1]+m[i-2]]=i;
        }
        // we now need a binary search function that get
        //a set of numbers (input sorted) and find the prefix sum is bigger than how much other elements
    }
}