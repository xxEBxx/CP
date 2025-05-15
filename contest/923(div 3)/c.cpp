#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t,n,m,value,k;
    cin>>t;

    for(int kk=0;kk<t;kk++){
        cin>>n;
        cin>>m;
        cin>>k;
        vector<int> a,b;
        for (int i=0;i<n;i++){
            cin>>value;
            a.push_back(value);
        }
        for (int i=0;i<m;i++){
            cin>>value;
            b.push_back(value);
        }
        int j1,j2=0;
        for (int i=0;i<k;i++){
            while (a[j1] < i+1){
                j1++;
            }
            while (b[j2] < i+1){
                j2++;
            }
            if (a[j1] != i+1 && b[j2]!= i+1){
                cout<<"NO"<<endl;
                break;
            }
        }
        cout<<"YES";
    }
}
