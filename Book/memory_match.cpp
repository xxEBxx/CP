#include<bits/stdc++.h>
using namespace std;

#define maxn 1005

map<string, pair<int, int>> myMap; // Different variable name used to avoid conflict

int main() {
    int n, k;
    int a, b;
    string sa, sb;
    cin >> n;
    cin >> k;
    while (k--) {
        cin >> a >> b >> sa >> sb;
        if (sa == sb) {
            myMap[sb] = {-1, -1};
            continue;
        }
        if (myMap[sa].first == 0) {
            // First time occurring
            myMap[sa].first = a;
        } else if (myMap[sa].second == 0) {
            if (a != myMap[sa].first) {
                myMap[sa].second = a;
                // This one is known for sure
            }
        }
        if (myMap[sb].first == 0) {
            // First time occurring
            myMap[sb].first = b;
        } else if (myMap[sb].second == 0) {
            if (b != myMap[sb].first) {
                myMap[sb].second = a;
                // This one is known for sure
            }
        }
    }
    int count = 0;
    for (const auto& pair : myMap) {
        cout<<pair.first<<"  ";
        cout<<pair.second.first<<"  "<<pair.second.second<<endl;
        if (pair.second.first != 0 && pair.second.second != 0 && pair.second.first != -1 && pair.second.second != -1) {
            count++;
        }
    }
    cout << "Count: " << count << endl;
    return 0;
}
