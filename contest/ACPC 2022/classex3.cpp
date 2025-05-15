#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class complex{
private:
    double real;
    double imaginary;
public:
    complex(): real(0),imaginary(0){
        imaginary=0.0;
        real=0.0;
    }
    complex(int r,int i):real(r),imaginary(i){

    }

};