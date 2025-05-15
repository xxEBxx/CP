#include<stdio.h>
#include<stdint.h>

//here is we create a 64 bit manupulatable integer
uint64_t array_of_bits=0;
#define set(BF,N) BF |= ((uint64_t)0x1 << N)
#define reset(BF,N) BF &= ~((uint64_t)0x1 << N)
//  NB: |= is for or bitwise operation
//   and || is for logical or
#define is_bit_set(BF,N) ((BF>>N) & 0x1)

int main(){
    set(array_of_bits,0);
    set(array_of_bits,4);
    set(array_of_bits,6);    
    set(array_of_bits,34);    
    set(array_of_bits,45);    
    set(array_of_bits,60);    

    reset(array_of_bits,4);
    
    for (int i=0;i<64;i++){
        if (is_bit_set(array_of_bits,i)){
            printf("1");
        }
        else{
            printf("0");
        }
    }
}
