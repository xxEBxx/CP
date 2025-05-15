#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<int> l7lwa(n),rest(1);

    for(int i=0;i<n;i++){
        cin>>l7lwa[i];
    }
    cin>>rest[0];
    for(int i=1;i<m;i++){
        int value;cin>>value;
        if(value < rest[rest.size()-1])rest.push_back(value);
    }
    reverse(rest.begin(),rest.end());
    for(int i=0;i<rest.size();i++){
        //cout<<rest[i]<<" ";
    }
    //cout<<endl;
    for(int i=0;i<n;i++){
        int value=l7lwa[i];
        while(value >= rest[0]){
            //cout<<"here is value"<<value<<endl;
            //index = prev() - rest.begin();//this is index of li yallah 9bel mn l7lwa
            //cout <<"here the index"<< index << endl;
            if(value == *lower_bound(rest.begin(), rest.end(), value)){
                value=0;
                break;
            }
            value = value % *prev(lower_bound(rest.begin(), rest.end(), value));
        }
        cout<<value<<" " ;
    }

}
/*
 3 3
 140 79 5
 90 42 5

 1 8
 120
 97 73 61 41 52 23 11 7

 1 3
50
30 10 100
 */