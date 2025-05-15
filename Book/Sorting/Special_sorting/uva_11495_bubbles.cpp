#include<bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b, int* switches) {
    int i = 0, j = 0, n = a.size(), m = b.size();
    vector<int> merged;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            merged.push_back(a[i]);
            i++;
        } else {
            merged.push_back(b[j]);
            *switches += n - i; // Increment the value at the memory location pointed by switches
            j++;
        }
    }
    while (i < n) {
        merged.push_back(a[i]);
        i++;
    }
    while (j < m) {
        merged.push_back(b[j]);
        j++;
    }
    return merged;
}

vector<int> mergesort(vector<int> arr, int* switches) {
    vector<int> a, b;
    int n = arr.size();
    if (n <= 1) {
        return arr;
    }
    for (int i = 0; i < n / 2; i++) {
        a.push_back(arr[i]);
    }
    for (int i = n / 2; i < n; i++) {
        b.push_back(arr[i]);
    }
    a = mergesort(a, switches);
    b = mergesort(b, switches);
    return merge(a, b, switches);
}

int main() {
    int n;
    while(cin>>n){
        if(n==0){
            return 0;
        }
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int switches = 0;
        int* p = &switches;
        mergesort(arr, p);
        if(switches%2==0){
            cout<<"Carlos"<<endl;
        }
        else{
            cout<<"Marcelo"<<endl;
        }
    }
}