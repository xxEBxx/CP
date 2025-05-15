#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("input.txt");

    int t;
    inputFile>>t;

    while(t--){
        int n;inputFile>>n;
        int money=0;
        string ans;
        for(int i=0;i<n;i++){
            string c;
            int num;
            inputFile>>c>>num;
            if(num > money){
                ans=c;
            }
        }
        cout<<ans<<endl;
    }

    inputFile.close();
    return 0;
}
