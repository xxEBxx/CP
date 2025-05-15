#include<bits/stdc++.h>

using namespace std;
int main() {
    int elem=0,elem_barre=0,count=0;
    for(int i=0;i<31;i++){
        if(!(elem>>i & 1)){
            count++;
            //if he has a 0 make it 1
            elem_barre = elem_barre | (1<<i);
        }
        //if its a one keep it a 0
    }
    cout<<elem_barre<<" "<<count;
}
