#include <iostream>
#include "bigint.h"

int main() {
    bigint second_last_fib = 1;
    bigint last_fib = 1;
    bigint fib = 0;
    unsigned int index = 2;


    while(fib.str.size() < 1000) {
        fib = last_fib + second_last_fib;
        ++index;

        second_last_fib = last_fib;
        last_fib = fib;
    }

    std::cout << fib << std::endl;
    std::cout << index << std::endl;
}