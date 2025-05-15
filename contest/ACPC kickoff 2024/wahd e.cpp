#include <bits/stdc++.h>
#define ll long long
const ll mod=1e9 + 7;
const int maxn=1e5 + 5;
using namespace std;

int  m;
int n;
vector<double> difficulties(101);
vector<double> res(101);
vector<vector<double>> matrix;
int k;


vector<vector<double>> mult(vector<vector<double>> &a,vector<vector<double>>&b){
    vector<vector<double>> res(n,vector<double>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            double sum = 0;
            for(int k = 0;k<n;k++){
                sum += a[i][k] * b[k][j];
            }
            res[i][j] = sum;
        }
    }

    return res;
}

vector<vector<double>> poww(vector<vector<double>> & a , int b){
    vector<vector<double>> res(n,vector<double>(n,0));
    vector<vector<double>> p = a;

    for(int i=0;i<n;i++){
        res[i][i] = (double)1;
    }
    while(b>0){
        if((b&1) > 0){
            res = mult(res,p);
        }
        p = mult(p,p);
        b >>= 1;
    }
    return res;
}



int main(){
    cin >> n >> m >> k;
    matrix.assign(n,vector<double>(n,0));
    for(int i=0;i<n;i++){
        cin >> difficulties[i];
    }

    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i != j)
                matrix[i][j] = double(min(min(i,j) + 1,n - max(i,j))) / double(n*(n+1)/2);
            else{
                matrix[i][j] =  double(min(min(i,j) + 1,n - max(i,j)) + (i)(i+1)/2 + (n- i - 1)(n-i)/2) / double(n*(n+1)/2);

            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<double>> ans = poww(matrix,k);

    for(int i=0;i<n;i++){
        double x = 0;
        for(int j=0;j<n;j++){
            if(difficulties[j] <= m){
                x += ans[j][i];
            }
        }
        printf("%.6f\n",x);

    }

   return 0;
}
