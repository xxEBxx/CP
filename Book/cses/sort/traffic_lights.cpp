#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> iip;

int main(){
    int n,m;cin>>n>>m;
    vector<int> division(m);
    for(int i=0;i<m;i++){
        cin>>division[i];
    }
    set<iip> interval;
    multiset<int> distance;
    interval.insert(make_pair(0,n));
    distance.insert(n);
    for(int i=0;i<m;i++){
        int slash=division[i];
        auto it=prev(interval.lower_bound(make_pair(slash,0)));
        iip element=*it;//pair that will change;
        //cout<<"here is lower bound intervalle :"<<i<<" "<<element.first<<" "<<element.second<<endl;
        //louwer ^ bound
        auto itr=distance.find(element.second-element.first);

        interval.erase(it);
        interval.insert(make_pair(element.first,slash));
        interval.insert(make_pair(slash,element.second));

        distance.erase(itr);
        distance.insert(slash-element.first);
        distance.insert(element.second-slash);

        //cout<<"all intervalls :";
        /*for(auto x:interval){
            cout<<x.first<<","<<x.second<<"  ";
        }
        cout<<endl<<"all distances: ";
        for(auto x:distance){
            cout<<x<<" ";
        }*/
        cout<<*prev(distance.end())<<" ";
    }
}
/*
  8 1
  3
  */