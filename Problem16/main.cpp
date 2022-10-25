#include <iostream>

#include "bigint.h"

int main() {
    bigint a = 2;
    bigint b = 1000;

    bigint c = big_pow(a, b);

    unsigned int res = 0;

    for (int i = 0; i < c.str.size(); ++i) {
        res += c.str[i] - '0';
    }

    std::cout << res << std::endl;
}