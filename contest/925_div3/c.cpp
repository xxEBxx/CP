#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int t,value;
    cin>>t;
    for(int kk=0;kk<t;kk++){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            cin>>value;
            v.push_back(value);
        }
        int a=v[0];int b=v[v.size()-1];
        int i=0;int j=v.size()-1;
        int counta=0,countb=0;
        while (v[i]==a){
            i++;
            counta++;
        }
        while (v[j]==b){
            j--;
            countb++;
        }
        if (n==2){
            if (v[0]==v[1]){
                cout<<0<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
        else if (i>j){
            cout<< 0<<endl;
        }
        else if (a==b){
            cout<< n-counta-countb<<endl;
        }
        else{
            cout<<n-max(counta,countb)<<endl;
        }

    }
}

