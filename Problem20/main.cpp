#include <iostream>

#include "bigint.h"

int main() {
    bigint fak = 1;
    for(int i = 1; i <= 100; ++i) {
        fak *= i;
    }

    unsigned int res = 0;
    for (int i = 0; i < fak.str.size(); ++i) {
        res += fak.str[i] - '0';
    }

    std::cout << res << std::endl;
}