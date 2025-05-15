#include<iostream>
#include<vector>
int main(){
    int t,n,value ;
    int min;
    std::vector<int > v;
    std::cin>>t;
    for (int k=0;k<t;k++){
        std::cin>>n;
        std::cin>>k;
        min=k-1;
        for (int j=0;j<n;j++){
            std::cin>>value;
            v.push_back(value);
        }
        for (int i: v){
            if (v[i]%k < min){
                min=v[i]%k;
            }
        }
        std::cout<<min<<"\n";
    }
}