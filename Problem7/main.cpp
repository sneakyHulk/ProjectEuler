#include <iostream>
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
    uint32_t n_prime = 1;
    uint32_t n = 2;

    while (n_prime < 10001) {
        if (is_prime(++n)) {
            ++n_prime;
        }
    }

    std::cout << n << std::endl;
}