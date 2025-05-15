#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include<fstream>
using namespace std;


int main() {
    ofstream fout;
    fout.open("input1.txt");
    int n=100000;
    fout<<n<<" "<<n-1<<endl;
    for(int i=1;i<n;i++){
        fout<<i<<" "<<i+1<<" "<<1000000<<endl;
    }

}
