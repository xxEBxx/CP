#include<bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("taming.out");
    ifstream fin ("art.in");
    int n;fin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        fin>>v[i];
    }
    v[0]=0;
    for(int i=n-1;i>0;i--){
        if(v[i]!=-1 && v[i]!=0){
            if(v[i-1]!=-1 && v[i-1]!=v[i]-1){
                fout<<-1;
                return 0;
            }
            v[i-1]=v[i]-1;
        }
    }
    int count0=0,count1=0;
    for(int i=0;i<n;i++){
        if(v[i]==0)count0++;
        else if(v[i]==-1)count1++;
    }
    fout<<count0<<" "<<count0+count1;
    return 0;
}