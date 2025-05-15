#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void step(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] += i+1;
        cout << v[i] << " ";
    }
    cout << endl;
}

int findmin(const vector<int>& v) {
    int j=0;
    while (v[j]<0){
        j++;
    }
    int i=0;
    if (v[i]!=0){
        return 0;
    }
    while (v[j] == i) {
        i++;
        j++;
    }
    return i;
}

int main() {
    int m, n;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cout << v[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        step(v, n);
        sort(v.begin(), v.end());
        cout << findmin(v) << endl;
    }

    return 0;
}
