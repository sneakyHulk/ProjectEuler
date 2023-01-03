#include <iostream>
#include <cstdint>
#include <unordered_set>
#include "bigint.h"

uint64_t int_power(uint64_t const a, unsigned int b) {
    uint64_t res = 1;
    while (b--) {
        res *= a;
    }

    return res;
}

int main() {
    std::unordered_set<bigint> values;
    for (bigint a = bigint(2); a <= bigint(100); ++a) {
        for (bigint b = bigint(2); b <= bigint(100); ++b) {
            values.insert(big_pow(a, b));
        }
    }

    std::cout << values.size() << std::endl;
}