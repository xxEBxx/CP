#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>& arr) {
   map<int,int> m;
   int n=arr.size();
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
   return round;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << solve(v) << endl;

    return 0;
}
