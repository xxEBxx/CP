#include<bits/stdc++.h>

using namespace std;
void print_mat(vector<vector<char>>& A, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j];
        }
        cout << endl;
    }
}

int check(vector<vector<char>>& big,vector<vector<char>>& small,int n,int m){
    for(int i1=0;i1<n;i1++){
        for(int j1=0;j1<n;j1++){
            if(big[i1][j1]=='*'){
                for(int i2=0;i2<m;i2++){
                    for(int j2=0;j2<m;j2++){
                        if (small[i2][j2]=='*'){
                            //if for everything in small , it is in big
                            for(int i3=i2;i3<m;i3++){
                                for(int j3=i2;j3<m;j3++){
                                    if (small[i3][j3]=='*'){
                                        if (big[i3][j3]=='.'){
                                            return 0;
                                        }
                                        else{
                                            big[i3][j3]='.';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}
int main(){
    int n,m;
    while (cin>>n>>m){
        vector<vector<char>> big(n,vector<char> (n));
        vector<vector<char>> small(m,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>big[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                cin>>small[i][j];
            }
        }
        cout<<check(big,small,n,m)<<endl;
    }
}
