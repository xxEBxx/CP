#include<iostream>
#include<vector>
#include<algorithm>

int div(std::vector<char> v,int i){
    //give as input i such that 2î is divisible
    for (int k=0;k<i;k++){
        if (v[k] != '0'){
            return 0;
        }
    }
    return 1;
}

int makediv(std::vector<char> v,int x,int i ){
    //x is number of steps already done;
    //we know its divisible by 2^(i-1)
    if (x==-1){
        return x;
    }
    int steps=1;
    int switches=1;
    if (v[i]==0){
        return x;
    }
    int j=i;
    v[i]=0;
    i++;
    while(steps > 0 && i<v.size()){
        if (v[i]==1){
            v[i]=0;
            steps++;
            switches++;
        }
        else{
            v[i]=1;
            steps--;
        }
        i++;
    }
    x+=steps*steps;
    if (steps==0){
        return x;
    }
    if (i==v.size() && steps>0){
        return -1;
    }


}

void write(std::vector <char> s){
    int x=0;
    for (int i=0;i<s.size();i++){
        std::cout<<makediv(s,x,i);
    }
    std::cout<<"\n";
}

int main(){
    int t1,n;
    int j;
    std::vector<char> s;
    char value;
    std::cin>>t1;
    for(int k=0;k<t1;k++){
        std::cin>>n;
        for(int i=0;i<n;i++){
            std::cin>>value;        
            s.push_back(value);
        }
        std::reverse(s.begin(), s.end());
        write(s);
        s.clear();
    }
}