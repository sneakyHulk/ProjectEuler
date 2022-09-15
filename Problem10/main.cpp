#include <iostream>
#include <cstdint>
#include <cmath>

bool is_prime(uint32_t n) {
    for (uint32_t i = 2; i < sqrt(n) + 1; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    uint64_t sum = 0;

    for (uint32_t n = 2; n < 2000000; ++n) {
        if (is_prime(n)) {
            sum += n;
        }
    }

    std::cout << sum + 2 << std::endl;
}