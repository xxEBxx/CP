#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr ,vector<pair<int,int>>& p) {
    map<int,int> m;
    int n=arr.size(),l=p.size();
    for(int i=0;i<n;i++){
        m[arr[i]]=i;
    }
    int round=1;
    for(int i=0;i<n;i++){
        //i<i+1 , round finish if m[i]>m[i+1]
        //cout<<" mi and mi+1"<<m[i]<<" "<<m[i+1]<<endl;
        if(m[i] > m[i+1]){
            round++;
        }
    }
    cout<<round<<endl;
    for(int i=0;i<l;i++){
        int value1=arr[p[i].first-1],value2=arr[p[i].second-1],bad_before=0,bad_after=0;

        int ls9a=m[value1]-m[value2];

        cout<<ls9a;
        cout<<"value: "<<value1<<"  "<<value2<<endl;
        cout<<"index: "<< m[value1]<<" "<<m[value2]<<endl;
        if(m[value1-1]!=0 && m[value1] < m[value1-1]){
            bad_before++;
        }
        if (m[value1+1]!=0 && m[value1] > m[value1+1]){
            bad_before++;
        }
        if (m[value2-1]!=0 && m[value2] < m[value2-1]){
            if(ls9a!=-1)bad_before++;
        }
        if(m[value2+1]!=0 && m[value2] > m[value2+1]){
            if(!ls9a)bad_before++;
        }


        if(m[value1-1]!=0 && m[value2] < m[value1-1]){
            bad_after++;
        }
        if(m[value1+1]!=0 && m[value2] > m[value1+1]){
            bad_after++;
        }
        if(m[value2-1]!=0 && m[value1] < m[value2-1]){
            if(!ls9a) bad_after++;
        }
        if(m[value2+1]!=0 && m[value1] > m[value2+1]) {
            if(!ls9a)bad_after++;
        }

        int temp=m[value1];
        m[value1]=m[value2];
        m[value2]=temp;

        cout<<bad_before<<bad_after<<endl;
        round+=-bad_before+bad_after;
        cout<<round<<endl;
    }
}

int main() {
    int n,m;
    cin >> n>>m;
    vector<int> v(n);
    vector<pair<int,int>> p(m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i=0;i<m;i++){
        cin>>p[i].first;
        cin>>p[i].second;
    }
    solve(v,p);

    return 0;
}
/*
 5 1
4 2 1 5 3
2 3
 */