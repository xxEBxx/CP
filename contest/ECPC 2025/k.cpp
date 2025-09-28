#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int  main() {
    fast();
        int n;
        cin>>n;
        int total=0;
        string res="DRAW";
        bool found =false;
        for (int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            if (found)continue;

            if (a==1)
                total+=b;
            else
                total-=b;
            if (total < 0) {
                if (i%2==0)
                    res="AHMED";
                else
                    res="AMIRA";
                found=true;
            }
        }
        cout<<res<<endl;

}
