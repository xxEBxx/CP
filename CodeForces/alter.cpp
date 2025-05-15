#include<iostream>
#include<string>
//longuer b7al b7al / 
unsigned long long int facto(int n){
    unsigned long long int x=1;
    for (int i=2;i<n+1;i++){
        x*=i;
    }
    return x;
}

int main(){
    int t;
    std::cin>>t;
    std::cin.ignore();
    int n=1,x=0;
    unsigned long long int y=1;
    std::string s;
    for(int k=0;k<t;k++){
    n=1,x=0,y=1;
    std::getline(std::cin, s);
    int len=s.length();
    for (int i=0;i<len;i++){
        while(i<len-1 && s[i]==s[i+1]){
            n++;
            i++;
        }
        x+=n-1;
        y*=facto(n);
        n=1;
    }
    std::cout<<x<<" "<<y%998244353<<"\n";}
}