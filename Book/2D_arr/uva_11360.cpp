#include <bits/stdc++.h>
using namespace std;

void print_mat(vector<vector<int>>& A, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j];
        }
        cout << endl;
    }
}

void row(vector<vector<int>>& arr,int n,int a,int b){
    a--;
    b--;
    vector<int> temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void col(vector<vector<int>>& arr,int n,int a,int b){
    a--;b--;
    int temp;
    for(int i=0;i<n;i++){
        temp=arr[i][a];
        arr[i][a]=arr[i][b];
        arr[i][b]=temp;
    }
}

void inc(vector<vector<int>>& arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             if(arr[i][j]==9){
                 arr[i][j]=0;
             }
             else{
                 arr[i][j]++;
             }
        }
    }
}

void dec(vector<vector<int>>& arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0){
                arr[i][j]=9;
            }
            else{
                arr[i][j]--;
            }
        }
    }
}

void transpose(vector<vector<int>>& arr,int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}
int main() {
    int t;
    cin >> t;
    int kk=0;
    while (t--) {
        kk++;
        int n;
        cin >> n;
        vector<vector<int>> arr(n,vector<int>(n, 0)); // 2D vector initialization
        // Populate the 2D vector
        char value;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> value;
                arr[i][j] = value - '0'; // Convert char to int
            }
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            cin.ignore();
            string word1;
            cin>>word1;
            //cout<<word1;
            if(word1=="row"){
                //cout<<"entered row";
                int a,b;
                cin>>a>>b;
                row(arr,n,a,b);
            }
            else if(word1=="col"){
                int a,b;
                cin>>a>>b;
                col(arr,n,a,b);
            }
            else if (word1=="inc"){
                inc(arr,n);
            }
            else if(word1=="dec"){
                dec(arr,n);
            }
            else if (word1=="transpose"){
                transpose(arr,n);
            }
            //cout<<"step "<<i+1<<endl;
            //print_mat(arr,n);
        }
        cout<<"Case #"<<kk<<endl;
        print_mat(arr,n);
        cout<<"\n";
    }

    return 0;
}
