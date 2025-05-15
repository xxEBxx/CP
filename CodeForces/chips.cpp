//This problem is about putting chips on a n*n board with minimal cost 
//the cost is given by 2 arrays of n 
#include<iostream>
#include<vector>
#include<algorithm>
int calculate(std::vector<long int> v1,std::vector<long int> v2){
    long long int t1=0,t2=0;
    long int n=v1.size();
    auto pmin1=std::min_element(v1.begin(), v1.end());
    auto pmin2=std::min_element(v2.begin(), v2.end());
    long int min1=*pmin1,min2=*pmin2;
    for(long int i:v1){
        t1+=i;
    }
    for(long int i:v2){
        t2+=i;
    }
    long long int value=n*min1+t2;
    if (n*min2+t1 < value){
        std::cout<<n*min2+t1<<"\n";
        return 1;
    }
    std::cout<<value<<"\n";
    return 1;
}

int main(){
    std::vector<long int> v1;
    std::vector<long int> v2;
    int t,n;
    long int value;
    std::cin>>t;
    for(int i=0 ;i<t;i++){
        std::cin>>n;
        //std::cout<<"\n";
        for(int j=0;j<n;j++){
            std::cin>>value;
            v1.push_back(value);
        }
        //std::cout<<"\n";
        for(int j=0;j<n;j++){
            std::cin>>value;
            v2.push_back(value);
        }
        //std::cout<<"\n";
        calculate(v1,v2);
        v1.clear();
        v2.clear();
    }
}