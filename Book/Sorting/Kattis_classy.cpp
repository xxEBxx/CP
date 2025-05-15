#include<bits/stdc++.h>

using namespace std;

pair<string, string> transform(const string& inputString) {
    string name = "";
    string values = "";

    size_t i = 0;
    while (i < inputString.size() && inputString[i] != ':') {
        name += inputString[i];
        i++;
    }

    i += 2; // Move past the colon and the space
    while (i < inputString.size() && inputString[i] != ' ') {
        if (inputString[i] == 'u') {
            values += 'c';
            i += 6; // Move past "upper-" which has length 6
        } else if (inputString[i] == 'm') {
            values += 'b';
            i += 7; // Move past "middle-" which has length 7
        } else if (inputString[i] == 'l') {
            values += 'a';
            i += 6; // Move past "lower-" which has length 6
        } else {
            break; // Exit the loop if an unexpected character is encountered
        }
    }
    reverse(values.begin(), values.end());
    return make_pair(name, values);
}
void complete_b(vector<pair<string,string>>& map_all){
    int n=map_all.size(),max_len=0;
    for(int i=0;i<n;i++){
        if(map_all[i].second.size()>max_len){
            max_len=map_all[i].second.size();
        }
    }
    for(int i=0;i<n;i++){
        int diff=max_len - map_all[i].second.size();
        for(int j=0;j< diff;j++){
            map_all[i].second+='b';
        }
    }
}

void merge(std::vector<std::pair<std::string, std::string>>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary vectors
    std::vector<std::pair<std::string, std::string>> L(n1), R(n2);

    // Copy data to temporary vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary vectors back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].second < R[j].second) {
            arr[k] = L[i];
            i++;
        }
        else if(L[i].second == R[j].second){
            if(L[i].first < R[j].first){
                arr[k]=R[j];
                j++;
            }
            else{
                arr[k] = L[i];
                i++;
            }
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(std::vector<std::pair<std::string, std::string>>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;cin>>n;cin.ignore();
        vector<string> arr(n);
        vector<pair<string,string>> map_all;
        for(int i=0;i<n;i++){
            getline(cin,arr[i]);
            //cout<<arr[i];
            map_all.push_back(transform(arr[i]));
        }

        complete_b(map_all);

        mergeSort(map_all,0,n-1);
        for(int i=n-1;i>-1;i--){
            cout<<map_all[i].first<<endl;
        }
        for(int i=0;i<30;i++){
            cout<<'=';
        }
        cout<<endl;
    }

}