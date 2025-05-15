#include<bits/stdc++.h>

using namespace std;

const int len = 1e6 + 5;

void solve( vector<int> start1,vector<int> end1,vector<int> start2,vector<int> end2,vector<int> ranges) {
    int n=start1.size(),m=start2.size(),a,b,range;
    bitset<len> bit;
    for (int i = 0; i < n; i++) {
        a=start1[i];
        b=end1[i];
        for (int j = a; j < b; j++) {
            if (bit.test(j)) {
                cout << "CONFLICT" << endl;
                return;
            }
            bit.set(j);
        }
    }

    for (int i = 0; i < m; i++) {
        a=start2[i];
        b=end2[i];
        range=ranges[i];
        for (int k = 0; k * range + a < len; ++k) {
            for (int j = a; j < b && k * range + j < len; ++j) {
                if (bit.test(k * range + j)) {
                    cout << "CONFLICT" << endl;
                    return;
                }
                bit.set(k * range + j);
            }
        }
    }
    cout << "NO CONFLICT" << endl;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        //cout<<"here are n and m: "<<n<<" "<<m<<" ";
        if (n == 0 && m == 0) {
            break;
        }
        vector<int> start1(n),end1(n),start2(m),end2(m),ranges(m);
        for(int i=0;i<n;i++){
            cin>>start1[i]>>end1[i];
        }
        for(int i=0;i<m;i++){
            cin>>start2[i]>>end2[i]>>ranges[i];
        }
        solve( start1,end1,start2,end2,ranges);
    }
    return 0;
}
