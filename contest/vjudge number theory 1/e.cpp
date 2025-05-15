#include <iostream>
#include<string>
using namespace std;

int main() {
    string largeNumber ;
    getline(cin,largeNumber);
    int num = 0;
    for (int i = largeNumber.size() - 2; i < largeNumber.size(); ++i) {
        num = num * 10 + (largeNumber[i] - '0');
    }
    cout<<num;
    if (num%4==0){
        cout<<4;
    }
    else{
        cout<<0;
    }
    return 0;
}
