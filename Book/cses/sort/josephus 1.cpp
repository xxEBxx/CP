#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> childs(n);
    for (int i = 0; i < n; i++) {
        childs[i] = i + 1;
    }
    while (childs.size() > 1) {
        //cout<<"children size"<<childs.size();
        vector<int> survivors;
        for (int i = 0; i < childs.size(); i++) {
            if (i % 2 == 1) {
                cout << childs[i] << " ";
            } else {
                survivors.push_back(childs[i]);
            }
        }
        if (childs.size() % 2 == 1) {
            //cout<<"here is the back :"<<survivors.back()<<endl;
            int start = survivors.back();
            survivors.pop_back();
            childs.clear();
            childs.push_back(start);
            for(int x:survivors){
                childs.push_back(x);
            }
        }
        else {
            childs = survivors;
        }
        //cout<<"here is survivors;";
             /* for(int x:childs){
                  cout<<x<<" ";
              }*/
    }
    cout<<childs[0];

}