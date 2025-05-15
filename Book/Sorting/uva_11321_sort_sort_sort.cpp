#include<bits/stdc++.h>

using namespace std;

int modulo(int n,int m){
    return n%m;
}

bool is_even(int n){
    return n%2==0;
}

vector<int> merge(vector<int> a,vector<int> b,int k){
    int i=0,j=0,n=a.size(),m=b.size();
    vector<int> res;
    while(i<n && j<m){
        int m1=modulo(a[i],k),m2=modulo(b[j],k);
        //cout<<m1<<m2;
        if(m1 > m2){
            res.push_back(b[j]);
            j++;
        }
        else if(m2 > m1){
            res.push_back(a[i]);
            i++;
        }
        else if (m1 == m2){
            // the odd will preceed
            if( is_even(a[i]) && !is_even(b[j])){
                res.push_back(b[j]);
                j++;
            }
            else if( !is_even(a[i]) && is_even(b[j])){
                res.push_back(a[i]);
                i++;
            }
                //if m2 is even and m1 is odd , m1 will be before , thats the case
            else if( !is_even(a[i]) && !is_even(b[j])){
                //both odd ,bigger should preceed
                if(a[i] < b[j]){
                    res.push_back(b[j]);
                    j++;
                }
                else{
                    res.push_back(a[i]);
                    i++;
                }
            }
            else if( is_even(a[i]) && is_even(b[j])){
                //both even,smaller should preceed
                if(a[i] > b[j]){
                    res.push_back(b[j]);
                    j++;
                }
                else{
                    res.push_back(a[i]);
                    i++;
                }
            }
        }
    }
    while (j<m){
        res.push_back(b[j]);
        j++;
    }
    while(i<n){
        res.push_back(a[i]);
        i++;
    }
    return res;
}

vector<int> merge_sort(vector<int> res,int k){
    int n=res.size();
    if(n<=1) return res;
    vector<int> a,b;
    int i=0;
    for(i;i<n/2;i++){
        a.push_back(res[i]);
    }
    for(i;i<n;i++) {
        b.push_back(res[i]);
    }
    a= merge_sort(a,k);
    b= merge_sort(b,k);
    return merge(a,b,k);
}

//even is paire , odd is impaire
int main(){
    int n,m;
    vector<int> test={2,3};
    merge_sort(test,3);
    //cout<<modulo(-100,5);
    while (cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        cout<<n<<" "<<m<<endl;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> res= merge_sort(arr,m);
        for(int i=0;i<n;i++){
            cout<<res[i]<<endl;
        }
    }
    cout<<"0 0"<<endl;
}
