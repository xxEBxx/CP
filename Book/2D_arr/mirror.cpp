#include<bits/stdc++.h>
using namespace std;

int check(string A[],string B[],int n){
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != B[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void rotate(string A[],int n){
    for(int i=0;i<n/2;i++){
        //the idea is to change 1st element of every group(ith column/line n-1-ith column/line )
        for (int j=i;j<n-i-1;j++){
            //now we rotate all the elements of one group
            char temp=A[i][j];
            A[i][j]=A[n-j-1][i];
            A[n-j-1][i]=A[n-i-1][n-j-1];
            A[n-i-1][n-j-1]=A[j][n-i-1];
            A[j][n-i-1]=temp;
        }
    }
}

void reflect(string A[],int n){
    string temp;
    for(int i=0;i<n/2;i++){
        temp=A[i];
        A[i]=A[n-1-i];
        A[n-1-i]=temp;
    }

}

void print_cube(string A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
}

int main(){
    int n;
    int index=0;
    while(cin>>n){
        index++;
        //cout<<"here";
        string original[n],modified[n];
        //cout<<"mn3rf";
        for(int i=0;i<n;i++){
            //cout<<"hna";
            cin>>original[i]>>modified[i];
            //cout<<"kk";
            //cout<<original[i];
        }
        //cout<<"OUTPUT";print_cube(original,n);
        //cout<<"first check "<<check(original,modified,n);
        if(check(original,modified,n)){
            cout<<"Pattern "<<index<<" was preserved."<<endl;
            continue;
        }
        rotate(original,n);
        if(check(original,modified,n)){
            cout<<"Pattern "<<index<<" was rotated 90 degrees."<<endl;
            continue;
        }
        rotate(original,n);
        if(check(original,modified,n)){
            cout<<"Pattern "<<index<<" was rotated 180 degrees."<<endl;
            continue;
        }
        rotate(original,n);
        if(check(original,modified,n)){
            cout<<"Pattern "<<index<<" was rotated 270 degrees."<<endl;
            continue;
        }
        ///////////////////////
        rotate(original,n);
        reflect(original,n);
        if(check(original,modified,n)){
            cout<<"Pattern "<<index<<" was reflected vertically."<<endl;
            continue;
        }
        rotate(original,n);
        if(check(original,modified,n)){
            cout<<"Pattern "<<index<<" was reflected vertically and rotated 90 degrees."<<endl;
            continue;
        }
        rotate(original,n);
        if(check(original,modified,n)){
            cout<<"Pattern "<<index<<" was reflected vertically and rotated 180 degrees."<<endl;
            continue;
        }
        rotate(original,n);
        if(check(original,modified,n)){
            cout<<"Pattern "<<index<<" was reflected vertically and rotated 270 degrees."<<endl;
            continue;
        }
        cout<<"Pattern "<<index<<" was improperly transformed.";
        cout<<endl;

    }
}