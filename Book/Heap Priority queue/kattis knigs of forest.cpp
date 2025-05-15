#include<bits/stdc++.h>
//link to problem :https://vjudge.net/problem/Kattis-knigsoftheforest
using namespace std;
typedef pair<int,int> iip;

struct comp{
    bool operator()(iip &a,iip &b){
        if(a.first==b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

int solve(priority_queue<iip,vector<iip>,comp> heap,iip mouse){
    //cout<<"heu";
    while(!heap.empty() && heap.top().first != mouse.first){
        //cout<<"pop"<<heap.top().first<<" "<<heap.top().second<<endl;
        int prev_year=heap.top().first;
        heap.pop();
        while(!heap.empty() && heap.top().first==prev_year){
            int strentgh=heap.top().second;
            heap.pop();
            heap.push({prev_year+1,strentgh});
        }
    }
    while(!heap.empty() && mouse.second < heap.top().second){
        //cout<<"pop"<<heap.top().first<<" "<<heap.top().second<<endl;
        int prev_year=heap.top().first;
        heap.pop();
        while(!heap.empty() && heap.top().first==prev_year){
            int strentgh=heap.top().second;
            heap.pop();
            heap.push({prev_year+1,strentgh});
        }
    }

    if(heap.empty()) return -1;
    return heap.top().first;

}

int main(){
    int k,n;cin>>k>>n;
    iip mouse;
    cin>>mouse.first>>mouse.second;
    priority_queue<iip,vector<iip>,comp> heap;
    for(int i=0;i<n;i++){
        int year,strength;
        cin>>year>>strength;
        heap.push({year,strength});
        //cout<<"push";
    }
    //cout<<"first"<<heap.top().first<<" "<<heap.top().second<<endl;
    int v=solve(heap,mouse);
    if(v==-1) {
        cout<<"unknown";
        return 0;
    }
    cout<<v;
    return 0;
}/*
3 6
2011 2
2011 3
2012 2
2013 5
2015 0
2014 1
2011 7
*/

