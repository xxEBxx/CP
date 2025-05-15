#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;cin>>n>>k;int out=0;
    deque<int> child;
    for(int i=0;i<n;i++){
        child.push_back(i+1);
    }

    while(child.size() > k){
        //cout<<"size"<<child.size();
        deque<int> survivors;
        for (int i = 0; i < child.size(); i++) {
            if (i % (k+1) == k) {
                out++;
                cout<<child[i]<<" ";
            }
            else{
                survivors.push_back(child[i]);
            }
        }
        int ch7al_chat=child.size()%(k+1);
        //is the amount of elements in the end that should be in the beginning
        for(int i=0;i<ch7al_chat;i++){
            int last=survivors.back();
            survivors.pop_back();
            survivors.push_front(last);
        }
        child.clear();
        for(int x:survivors){
            child.push_back(x);
        }
    }
    while(child.size()>1){
        out++;
        int index=k%child.size();
        //cout<<"index:"<<index<<endl;
        cout<<child[index]<<" ";
        child.erase(child.begin() + index);
        int ch7al_chat=child.size()-index;
        //cout<<"vh7al cht: "<<ch7al_chat<<endl;
        for(int i=0;i<ch7al_chat;i++){
            int last=child.back();
            child.pop_back();
            child.push_front(last);
        }
    }
    if(out<n){
        cout<<child[0];
    }
}