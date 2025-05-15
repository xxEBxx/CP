#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& vec, int value) {
    vec.push_back(value);
}

int search(const vector<int>& vec, int value) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == value) {
            return i; // Found
        }
    }
    return -1; // Not found
}

int main(){
    int n;
    cin >>n;
    vector<int> expect;
    while(n--){
        int value;
        cin>>value;
        int index=search(expect,value);
        if (index==-1){
            insert(expect,value-1);
        }
        else{
            expect[index]--;
        }
    }
    cout<<expect.size()<<endl;
}