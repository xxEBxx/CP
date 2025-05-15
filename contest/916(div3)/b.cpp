#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int tep=0;tep<t;tep++){
        int n,k;
        cin>>n;
        cin>>k;
        if (k==0){
            for (int i=0;i<n;i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
            continue;
        }
        vector<int> arr;
        for(int i=1;i<n+1;i++){
            if(i%k != 0){
            arr.push_back(i);
            }
            else {
                cout << i <<" ";
            }
        }
        for (int i = arr.size()-1; i >-1; i--) {
        cout << arr[i] << " ";
    }
    cout <<endl;
    }
}