#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int index;
    while(scanf("%d",&n)){
        //printf("%d",n);
        if(n==0){
            break;
        }
        int arr[100]={0};
        for(int i=0;i<n;i++){
            scanf("%d",&index);
            arr[index-1]++;
        }
int first=0;
        for(int i=0;i<100;i++){
            for(int j=0;j<arr[i];j++){
                if(!first){
                    printf("%d",i+1);
                    first=1;
                }
                else{
                    printf(" %d",i+1);

                }
            }
        }
        printf("\n");
    }
}