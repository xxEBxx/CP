#include<iostream>

int main(){
    int t,a=1,value;
    char c;
    int arr[4];
    std::cin>>t;
    for (int k=0;k<t;k++){
        value=0;
        a=1;
        for (int j=0;j<4;j++){
            std::cin>>c;
            if (c=='0'){
                arr[j]=10;
                continue;
            }
            arr[j] = c-'0';
        }

        for (int i : arr){
            value += abs(i-a)+1;
            a=i;
            }
        std::cout<<value<<"\n";
    }
}