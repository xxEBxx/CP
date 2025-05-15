#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;


int main(){
    //for each element search for its barre if found remove it
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        multiset<int> arr;
        for(int i=0;i<n;i++){
            int v;cin>>v;
            arr.insert(v);
        }
        int res=0;
        while(!arr.empty()){
            res++;
            int elem=*arr.begin(),elem_barre=0;
            for(int i=0;i<31;i++){
                if(!(elem>>i & 1)){
                    //if he has a 0 make it 1
                    elem_barre = elem_barre | (1<<i);
                    //cout<<elem_barre<<endl;
                }
                //if its a one keep it a 0
            }
            auto it = arr.lower_bound(elem_barre);
            if(elem_barre == *it){
                arr.erase(it);
            }
            arr.erase(arr.begin());

        }
        cout<<res<<endl;
    }
}
