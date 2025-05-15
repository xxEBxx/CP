#include<bits/stdc++.h>


using namespace std;
const int maxn=1e6+7;
typedef long long ll;


int main(){
    for(int i=0;i<1000;i++){
        bool premier=true;
        for(int j=2;j<i;j++){
            if(i%j==0)premier=false;
        }
        if(premier)cout<<i;
    }
}
