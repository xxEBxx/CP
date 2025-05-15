#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    int w;
    std::vector<int> v;
    std::vector<int> vei;
    int t,n;
    long int value;
    std::cin>>t;
    for(int i=0;i<t;i++){
    std::cin>>n;
        for(int j=0;j<2*n;j++){
            std::cin>>value;
            v.push_back(value);
        }
        for(int j=3;j<2*n;j+=2){
            if (v[j] >= v[1]){
                vei.push_back(v[j-1]);
            }
        }
        if (vei.empty()){
            std::cout<<v[0];
            std::cout<<"\n";
            v.clear();
            continue;
        }
        auto pmaxsi = std::max_element(vei.begin(), vei.end());
        if (*pmaxsi >= v[0]){
            std::cout<<"-1";
        }
        else{std::cout<<*pmaxsi+1;}
        std::cout<<"\n";
        v.clear();
        vei.clear();
    }
}