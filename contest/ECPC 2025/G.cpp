#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define f first
#define s second
void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int  main() {
    fast();
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vi arr(n);
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        if (arr[0]==0) {
            cout<<"NO"<<endl;
            continue;
        }
        //find first 0
        int i=0;
        while (i<n && arr[i]!=0) {
            i++;
        }
        if (i==n) {
            cout<<"NO"<<endl;
            continue;
        }
        int first_0 = i;
        //find first one ;
        while (i<n && arr[i]!=1) {
            i++;
        }
        if (i==n) {
            cout<<"NO"<<endl;
            continue;
        }
        while (i>first_0 && arr[i]!=2) {
            i--;
        }
        if (i==first_0 || arr[i]==2)
            i++;
        //now we compute the mex of the rest
        bool z_exist = false;
        string res="YES";
        while (i<n) {
            if (arr[i]==0)
                z_exist=true;
            else if (arr[i]==2)
                res="NO";
            i++;
        }
        if (!z_exist)
            res = "NO";
        cout<<res<<endl;

    }
}
