#include<iostream>
#include<algorithm>
#include <numeric>
int main(){
    long long int t,n,x,y,value;
    long long int cardx,cardy,cardint;
    std::cin>>t;
    for (int k=0;k<t;k++){
        std::cin>>n;
        std::cin>>x;
        std::cin>>y;
    
        
        //cardx=n/x,cardy=n/y,cardint=n/(std::lcm(x, y));
        cardy-=cardint;
        cardx-=cardint;
        value=n*(n+1)/2 - (n-cardx)*(n-cardx+1)/2 - cardy*(cardy+1)/2;
    std::cout<<value<<"\n";

}
}