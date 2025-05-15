#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> iip;
int main(){
    string s;
    int freq,id;
    //return true to switch
    auto compare=[](iip a,iip b){
        if(a.first!=b.first) return a.first > b.first;
        return a.second > b.second;
    };
    priority_queue<iip,vector<iip>,decltype(compare)> heap(compare);
    map<int,int> m;
    while(cin>>s){
        if(s=="#") {
            break;
        }
        cin>>id>>freq;
        cin.ignore();
        heap.push({freq,id});
        m[id]=freq;
    }
    int k;
    cin>>k;
    while(k--){
        iip element=heap.top();
        heap.pop();
        cout<<element.second<<"\n";
        heap.push({element.first+m[element.second],element.second});
    }
    return 0;
}
