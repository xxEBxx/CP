#include<bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("sleepy.out");
    ifstream fin ("art.in");
    int n;fin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        fin>>v[i];
    }
    int res=0;
    for(int i=0;i<n-1;i++){
        if(v[i] > v[i+1])res=i+1;
    }
    fout<<res;
    return 0;
}