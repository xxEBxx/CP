#include<iostream>
#include<vector>
using namespace std;
#define maxn 100005
#define dp_with_after[maxn] // dp_with_after[i] will store the min cost to travel from i city to i+1
#define dp_with_before[maxn] // dp_with before[i] will store the min cost to travel from i xity to i-1 city 

char closest(int i ,vector<int>& arr){
    if (i==0){
        return 'r';
    }
    if(i==arr.size()-1){
        return 'l';
    }
    if (arr[i+1]-arr[i] < arr[i]-arr[i-1]){
        return 'r';
    }
    return 'l';
}

int main(){
    int t,value,n;
    cin>>t;
    for(int kk=0;kk<t;kk++){
        cin>>n;
        vector<int> arr;
        for (int i=0;i<n;i++){
            cin>>value;
            arr.push_back(value);
        }
        int m,a,b;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            int count=0;
            a-=1;
            b-=1;
            if (a<b){
                // here we need to go to the right 
                //so the good thing will be if the
                //closest city is on the right
                for (int j=a;j<b;j++){
                    if(dp_with_after[j]==0){
                        if(closest(j,arr)=='r'){
                            dp_with_after[j]=1;
                        }
                        else{
                            dp_with_after[j]=arr[j+1]-arr[j];
                        }
                }
                    count+=dp_with_after[j]
                }
            }
            else{
                for (int j=a;j>b;j--){
                    if(closest(j,arr)=='l'){
                        count+=1;
                    }
                    else{
                        count+=arr[j]-arr[j-1];
                    }
                }
            }
            //cout<<endl<<"output"<<i+1<<":"<<count<<endl;
            cout<<count<<endl;
        }
    }

}