#include<bits/stdc++.h>

using namespace std;

vector<int> find_values(vector<int> arr,int n){
    int sum;
    vector<int> res;
    for(int k=0;k<arr.size();k++){
        sum=0;
        for (int i = 0; i < n; i++) {
            sum += arr[k ^ (1 << i)];
        }
        res.push_back(sum);
    }
    return res;
}

int find_max_from_two(vector<int> arr,vector<int> values, int input_n){
    int n=arr.size(),max_value=0,neighbour_index,max_neighbour_value;
    for(int i=0;i<n;i++){
        max_neighbour_value=0;
        for(int j=0;j<input_n;j++){
            neighbour_index= i ^ (1<<j);
            if(values[neighbour_index] > max_neighbour_value){
                max_neighbour_value = values[neighbour_index];
            }
        }
        max_value=max(max_value,values[i]+max_neighbour_value);
    }
    return max_value;
}

int main(){
    //cout<<neighbours(4,6,3);
    while(true){
        int n;
        cin>>n;
        if(cin.eof()) break;
        //cout<<n;
        int size=1<<n;
        vector<int> arr(size);
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
        vector<int> values= find_values(arr,n);
        cout<<find_max_from_two(arr,values,n)<<endl;
    }
}