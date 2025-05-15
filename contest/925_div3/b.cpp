#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t,n,value;
    cin>>t;
    for(int kk=0;kk<t;kk++){
        cin>>n;
        vector<int> v;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>value;
            v.push_back(value);
            sum+=value;
        }
        float avg=sum/n;
        int average=sum/n;
        if (avg!=average || v[0]<average){
            cout<<"NO"<<endl;
            continue;
        }
        int count=v[0]-average;
        int output=0;
        for(int i=1;i<n;i++){
            if (count<0){
                cout<<"NO"<<endl;
                output=1;
                break;
            }
            count+= v[i]-average;
        }
    if (output==0){
        cout<<"YES"<<endl;
    }
    }
}
