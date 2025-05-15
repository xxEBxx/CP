#include<bits/stdc++.h>

using namespace std;
bitset<10> poss(0);
unordered_map<int,array<int,4>> m;

void check(vector<string> arr,int k){

}



int main() {
    ofstream fout ("art.out");
    ifstream fin ("art.in");
    int n;
    fin>>n;
    //cout<<"hello from art";

    vector<string> v(n);
    fout<<"hello from art";
    for(int i=0;i<n;i++){
        fin>>v[i];
        for(int j=0;j<n;j++){
            poss[v[i][j]-'0']=true;
            m[v[i][j]-'0']={i,j,i,j};
            //most top , most left , most botttom , most right
        }
    }
    //cout<<"hello again";
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if (v[i][j] != '0') {
                if( i < m[v[i][j]-'0'][0] )m[v[i][j]-'0'][0]=i;
                if( i > m[v[i][j]-'0'][2] )m[v[i][j]-'0'][2]=i;
                if( j < m[v[i][j]-'0'][1] )m[v[i][j]-'0'][1]=j;
                if( j > m[v[i][j]-'0'][3] )m[v[i][j]-'0'][3]=j;
            }
        }
    }
    //cout<<"hello123";
    //bitset<10> to_check
    while(true){
        bool good=true;
        for (int k = 1; k < 10; k++) {
            if (poss[k]) {//exist
                //function here :::
                for (int i = m[k][0]; i <= m[k][2]; i++) {
                    for (int j = m[k][1]; j <= m[k][3]; j++) {
                        if (v[i][j] != '0') {
                            good = false;
                            if(k && poss[v[i][j]-'0']==0){
                                poss[v[i][j] - '0'] = false;
                                v[i][j] = (char) ((int) '0' + k);
                            }
                        }
                    }
                }
            }
        }
        if(good)break;
    }
    int res=0;
    for(int i=1;i<10;i++){
        if(poss[i])res++;
    }
    fout<<res;
    return 0;
}