#include <bits/stdc++.h>
#define f first
#define  s second
using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<pair<int,char>> arr(3);
        cin >> arr[0].f >> arr[1].f >> arr[2].f;
        arr[0].s = 'R';
        arr[1].s = 'G';
        arr[2].s = 'B';

        sort(arr.begin(),arr.end());
        int tot = arr[0].f+arr[1].f+arr[2].f;

        if( arr[2].f > (n+1)/2 || tot>n){
            cout <<  -1 <<endl;
            continue;
        }
        while (tot < n) {
            tot++;
            arr[0].f++;
            sort(arr.begin(),arr.end());
        }
        char last = 'w';
        string res="";
        for (int i=0;i<n;i++) {
            if (arr[2].s != last) {
                res += arr[2].s;
                arr[2].f--;
                last = arr[2].s;
            }
            else if (arr[1].f > 0 && arr[1].s != last){
                res += arr[1].s;
                arr[1].f--;
                last = arr[1].s;
            }
            else {
                res += arr[0].s;
                arr[0].f--;

                last = arr[0].s;
            }
            sort(arr.begin(),arr.end());
        }
        cout<<res<<endl;
    }
    return 0;
}