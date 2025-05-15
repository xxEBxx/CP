#include<bits/stdc++.h>

using namespace std;
typedef priority_queue<int,vector<int>,greater<int>> min_heap ;

min_heap merging(min_heap h1,min_heap h2,int n){
    min_heap res;
    int v1=h1.top(),v2=h2.top();
    h1.pop();h2.pop();
    res.push(v1+v2);
    int repetition_v1=1,repetition_v2=1;
    while(h1.top()==v1){
        repetition_v1++;
        h1.pop();
    }
    while(h2.top()==v2){
        repetition_v2++;
        h2.pop();
    }
    //cout<<repetition_v2<<repetition_v1;
    while(res.size() < n){
        if (v1 + h2.top() < v2 + h1.top()) {
            int rep=repetition_v1;
            while(res.size() < n && rep--){
                res.push(v1 + h2.top());
            }
            h2.pop();
            /*while(res.size() < n && h2.top()==min_found_h2){
                res.push(v1 + h2.top());
                h2.pop();
            }*/
        } else {
            int rep=repetition_v2;
            while(res.size() < n && rep--){
                res.push(v2 + h1.top());
            }
            h1.pop();
            /*while(res.size() < n && h1.top()==min_value_h1){
                res.push(v2 + h1.top());
                h1.pop();
            }*/
        }
    }
    return res;
}

int main(){
    int n,value;
    min_heap h1;

    while(cin>>n){
        if(cin.eof()){
            return 0;
        }
        for(int i=0;i<n;i++){
            cin>>value;
            h1.push(value);
        }
        for(int kk=1;kk<n;kk++){
            min_heap h2;
            for (int i = 0; i < n; i++) {
                cin >> value;
                h2.push(value);
            }
            h1=merging(h1,h2,n);
        }
        while(!h1.empty()){
            cout<<h1.top()<<" ";
            h1.pop();
        }
        cout<<endl;
    }
}
