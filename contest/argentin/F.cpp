#include<bits/stdc++.h>

using namespace std;
int tx,ty;
int distance(int bx,int by){
    return (tx-bx)*(tx-bx)+(ty-by)*(ty-by);
}

int main(){
    int n;cin>>n;
    int w,l;
    cin>>w>>l>>tx>>ty;
    set<int> a,b;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        a.insert(distance(x,y));
    }
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        b.insert(distance(x,y));
    }
    if(*a.begin() < *b.begin()){
        cout<<"A ";
        int val=*b.begin();
        int count=0;
        auto it=a.begin();
        while(  it!=a.end() && val > *it ){
            count++;
            it=next(it);
        }
        cout<<count;
    }
    else{
        cout<<"R ";
        int val=*a.begin();
        int count=0;
        auto it=b.begin();
        while(it!=b.end() && val > *it){
            count++;
            it=next(it);
        }
        cout<<count;
    }


}