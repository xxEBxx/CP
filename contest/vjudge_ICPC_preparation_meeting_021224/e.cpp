#include<iostream>
#include<vector>
//we use 2 pointers start from 0 and 1
//first one id impaire /impaire
//if we have more pair we need to add a pair or remove impair
//if we have more impair we remove impair or add pair
// BASED ON THE POINTERS
using namespace std;

int solve(vector<int>& v,int i,int j) {
    int pair = 0;
    int impaire = 0;
    for (int k = i; k < j+1; k++) {
        if(k%2==0){
            pair+=v[k];
            continue;
        }
        impaire+=v[k];
    }
        if (pair==impaire){
            return 1;
        }
        if(pair>impaire){
            return 0;
        }
        return -1;
}

int main(){
    int t,value;
    cin>>t;
    for(int kk=0;kk<t;kk++){
        int n;
        int output=0;
        cin>>n;
        vector<int> v;
        for(int j=0;j<n;j++) {
            cin >> value;
            v.push_back(value);
        }
        int i=0,j=1;
        while (i<n && j<n && i<j){
            //cout<<"Here are indexes and solution of them : "<<i<<j<<solve(v,i,j)<<endl;
            if (solve(v,i,j)==1){
                cout<<"YES"<<endl;
                output=1;
                break;
            }
            //This is the case of pair > impair
            else if (solve(v,i,j)==0){
                if (i%2==0){
                    i++;
                }
                else{
                    j++;
                }
            }
            //CASE OF impair > pair
            else{
                if(i%2==0) {
                    j++;
                }
                else{
                    i++;
                }
            }
        }
        if (output==0){
            cout<<"NO"<<endl;
        }
    }
}
