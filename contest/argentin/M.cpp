#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x;cin>>n>>x;
    set<float> p,u;
    for(int i=0;i<n;i++){
        char c;cin>>c;
        int val;cin>>val;
        if(c=='P')p.insert(val);
        else u.insert(val);
    }
    float v_p=0.75*x,v_u=0.25*x;
    float time_p=0,time_u=0;
    while(!u.empty()){
        cout<<"here is time and card"<<time_u<<u.size()<<endl;
        float new_time = *u.begin() / (v_u/u.size());
        time_u += new_time;
        set<float> new_u;
        for(float k:u){
            new_u.insert(k-*u.begin());
        }
        u=new_u;
        u.erase(u.begin());
    }
    cout<<"here is time "<<time_u<<endl;
    cout<<"**************"<<endl;
    while(!p.empty()){
        cout<<"here is p time "<<time_p<<endl;
        float new_time =  *p.begin() / (v_p/p.size());
        time_p+=new_time;
        set<float> new_p;
        for(float k:p){
            new_p.insert(k-*p.begin());
        }
        p=new_p;
        p.erase(p.begin());
    }
    if(time_p > time_u){
        float time=0;float new_time;
        while(time < time_u && !p.empty()){
            new_time =  *p.begin() / (v_p/p.size());
            time_p+=new_time;
            set<float> new_p;
            for(float k:p){
                new_p.insert(k-*p.begin());
            }
            p=new_p;
            p.erase(p.begin());
        }
        time-=new_time;
        v_u=x;
    }
    cout<<"here is p time "<<time_p<<endl;

    cout<<min(time_u,time_p);
    return 0;
}