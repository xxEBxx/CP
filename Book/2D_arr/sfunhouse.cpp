#include<bits/stdc++.h>

using namespace std;

void print_mat(vector<string> arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

pair<int,int> find_start(vector<string> arr){
    //ligne correspond à m
    int n = arr.size();
    int m = arr[0].size();

    for(int i = 0; i < n; i++){
        if(arr[i][0] == '*'){
            return make_pair(i, 0);
        }
        if(arr[i][m-1] == '*'){
            return make_pair(i, m-1);
        }
    }

    for(int j = 0; j < m; j++){
        if(arr[0][j] == '*'){
            return make_pair(0, j);
        }
        if(arr[n-1][j] == '*'){
            return make_pair(n-1, j);
        }
    }
}

pair<int ,int > find_next(vector<string> arr,pair<int,int> next,int dir){
//find next point and return its coordinates
//1 is up, 2 is down , 3 is left , 4 is right
    int n=arr.size(),m=arr[0].size();
    //cout<<"find next";
    while(arr[next.first][next.second]=='*' || (next.first>0 && next.second>0 && next.first<n-1 && next.second<m-1)){
        if (dir==1){
            next.first--;
        }
        else if(dir==2){
            next.first++;
        }
        else if(dir==3){
            next.second--;
        }
        else{
            next.second++;
        }
        if (arr[next.first][next.second]!='.'){
            return next;
        }
    }
}

int find_dir(vector<string> arr,pair<int,int> next,int dir){
    if(arr[next.first][next.second]=='*'){
        return -1;
    }
    if(arr[next.first][next.second]=='\\'){
        if(dir==1){
            return 3;
        }
        else if(dir==3){
            return 1;
        }
        else if(dir==4){
            return 2;
        }
        else{
            return 4;
        }
    }
    //1 is up, 2 is down , 3 is left , 4 is right
    if(arr[next.first][next.second]=='/'){
        if(dir==1){
            return 4;
        }
        else if(dir==4){
            return 1;
        }
        else if(dir==3){
            return 2;
        }
        else{
            return 3;
        }
    }
}

int main(){
    int n,m,kk=0;
    string temp;
    while (cin>>n>>m){
        if (n==0){
            if(m==0){
                break;
            }
        }
        cin.ignore();
        kk++;
        vector<string> arr;
        for(int i=0;i<m;i++){
            getline(cin,temp);
            arr.push_back(temp);
        }
        cout<<"HOUSE "<<kk<<endl;
        //print_mat(arr);
        pair<int,int> next = find_start(arr);
        //cout<<"first"<<next.first<<next.second;
        int dir;
        //1 is up, 2 is down , 3 is left , 4 is right
        if(next.first==0){
            dir=2;
        }
        else if(next.second==0){
            dir=4;
        }
        else if(next.first==m-1){
            dir=1;
        }
        else{
            dir=3;
        }
        next=find_next(arr,next,dir);//find next obstacle
        //cout<<endl<<"next:"<<next.first<<next.second;
        while(next.first!= 0 && next.first!=m-1 && next.second != n-1 && next.second!=0){
            dir=find_dir(arr,next,dir);//change direction
            next=find_next(arr,next,dir);//find next obstacle
            //cout<<endl<<"next:"<<next.first<<next.second;
        }
        //cout<<"hello";
        arr[next.first][next.second]='&';
        print_mat(arr);
    }
}
