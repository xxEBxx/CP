#include<bits/stdc++.h>

using namespace std;

void merge(vector<string>& arr, vector<int>& switches, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);
    vector<int> L_switches(n1), R_switches(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        L_switches[i] = switches[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        R_switches[j] = switches[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L_switches[i] <= R_switches[j]) {
            arr[k] = L[i];
            switches[k] = L_switches[i];
            i++;
        } else {
            arr[k] = R[j];
            switches[k] = R_switches[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        switches[k] = L_switches[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        switches[k] = R_switches[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string>& arr, vector<int>& switches, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, switches, left, mid);
        mergeSort(arr, switches, mid + 1, right);

        merge(arr, switches, left, mid, right);
    }
}

void stableMergeSort(vector<string>& arr, vector<int>& switches) {
    mergeSort(arr, switches, 0, arr.size() - 1);
}

vector<int> find_switches(vector<string>& arr){
    int n=arr.size(),m=arr[0].size();
    vector<int> switches;
    for(int i=0;i<n;i++){
        int count =0;
        for(int j=0;j<m;j++){
            for(int k=j+1;k<m;k++){
                if(arr[i][j]>arr[i][k]){
                    count++;
                }
            }
        }
        switches.push_back(count);
    }
    return switches;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>m>>n;
        vector<string> data(n);
        string line;
        getline(cin,line);
        for(int i=0;i<n;i++){
            getline(cin,data[i]);
        }
        vector<int> sortness= find_switches(data);
        stableMergeSort(data,sortness);
        for(string a:data){
            cout<<a<<endl;
        }
        if(t!=0){ cout << "\n"; }
    }
}

