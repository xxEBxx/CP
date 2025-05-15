#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, n, op,value,i;
    vector<int> v;
    cin >> t;

    for (int j = 0; j < t; j++) {
        cin >>n;
        for (int i=0;i<n;i++){
            cin>>value;
            v.push_back(value);
        }
        reverse(v.begin(), v.end());
        op=0;
        i=0;
        while (i<op+n-1){
            if (v[i]<v[i+1]){
                v.insert(v.begin() + i+2, v[i+1]-v[i]);
                v[i+1]=v[i];
                op++;
            }
            for (int i:v){
                cout<<i<<"\t";
            }
            cout<<endl;
            i++;
        }
        cout<<op<<endl;
        v.clear();
    }

}
