
#include<bits/stdc++.h>
using namespace std;




int solve(vector<int> v,vector<int> a,int k ){
    int n=v.size();
    int i=0,j=0;
    int max_value=0;
    int sum=a[0];
    if ( sum<=k)max_value = max(max_value,1);
    while( j < n-1 ){
        if(v[j] % v[j+1]==0){
            if(i==j && sum > k){
                j++;
                i=j;
                sum = a[i];
                if (sum<=k){
                    max_value = max(max_value,1);
                }
            }


            else if(sum +a[j+1] <= k){
                j++;
                sum += a[j];
                max_value=max(max_value,j-i+1);

            }
            else{
                sum -=a[i];
                i++;
            }
        }
        else{
            j++;
            i=j;
            sum =a[i];
            if (sum<=k){
                max_value = max(max_value,1);
            }
        }


    }



    return max_value;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<solve(v,a,k)<<endl;
    }


    return 0;
}