#include <iostream>
#include <cstdint>

bool ist_palindrom(uint32_t n) {
    uint32_t stellen[10];
    uint32_t size = 0;

    while (n > 0) {
        stellen[size] = n % 10;
        ++size;
        n /= 10;
    }

    for (uint32_t i = 0; i < size / 2; ++i) {
        if (stellen[i] != stellen[size - 1 - i]) {
            return false;
        }
    }

    return true;
}

/*
 * Iteratorstudie
 *

 #include <set>
 #include <algorithm>

 struct greater_array {
    constexpr bool operator()(const std::array<int, 2> &lhs, const std::array<int, 2> &rhs) const {
        return lhs[0] * lhs[1] > rhs[0] * rhs[1];
    }
 };

 std::set<std::array<int, 2>, greater_array> m;

    for (int i = 50; i; --i) {
        for (int j = 50; j; --j) {
            m.insert({std::min(i, j), std::max(i, j)});
        }
    }

    for (auto const & key: m) {
        std::cout << key[1] * key[0] << std::endl;
    }
 */

int main() {
    uint32_t max = 0;
    uint32_t max_i = 0;
    uint32_t max_j = 0;

    for (uint32_t i = 999; i; --i) {
        for (uint32_t j = 999; j >= i; --j) {
            uint32_t mul = i * j;

            if (ist_palindrom(mul) && max < mul) {
                max = mul;
                max_i = i;
                max_j = j;
            }
        }
    }

    std::cout << max_i << " * " << max_j << " = " << max << std::endl;
}