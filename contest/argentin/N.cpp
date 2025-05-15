#include<bits/stdc++.h>
//lucky number
using namespace std;
map<int,int> m;

int main(){
    int n;cin>>n;
    while(n--){
        int val;cin>>val;
        m[val%5] += 1;
    }
    int count = m[0];
    //did all the 5's
    int k;
    //CARD 2
    k=min(m[1],m[4]);
    count+=k;
    m[1]-=k;m[4]-=k;

    k=min(m[3],m[2]);
    count+=k;
    m[3]-=k;m[2]-=k;
    //CARD 3
    k=min(m[2]/2,m[1]);
    count+=k;
    m[2]-=2*k;m[1]-=k;

    k=min(m[1]/2,m[3]);
    count+=k;
    m[1]-=2*k;m[3]-=k;

    k=min(m[3]/2,m[4]);
    count+=k;
    m[3]-=2*k;m[4]-=k;

    k=min(m[4]/2,m[2]);
    count+=k;
    m[4]-=2*k;m[2]-=k;

    //CARD 4
    k=min(m[1]/3,m[2]);
    count+=k;
    m[1]-=3*k;m[2]-=k;

    k=min(m[2]/3,m[4]);
    count+=k;
    m[2]-=3*k;m[4]-=k;

    k=min(m[3]/3,m[1]);
    count+=k;
    m[3]-=3*k;m[1]-=k;

    k=min(m[4]/3,m[3]);
    count+=k;
    m[4]-=3*k;m[3]-=k;
    //CARD 5
    count += m[1]/5 + m[2]/5 + m[3]/5 +m[4]/5;

    cout<<count;
}