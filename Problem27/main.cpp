#include <iostream>
#include <cmath>
#include <cstdint>

bool is_prime(uint32_t n) {
    for (uint32_t i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

constexpr int func(int const n, int const a, int const b) {
    return n * n + a * n + b;
}

int main() {
    unsigned int max = 0;
    int max_a;
    int max_b;
    for (int a = -999; a <= 999; ++a) {
        for (int b = -1000; b <= 1000; ++b) {
            int erg;
            unsigned int n = 0;
            do {
                if (n > max) {
                    max = n;
                    max_a = a;
                    max_b = b;
                    std::cout << "new max: " << n << ", a: " << a << ", b: " << b << std::endl;
                }
                erg = func(static_cast<int>(n++), a, b);
            } while (erg >= 2 && is_prime(erg));
        }
    }

    std::cout << max_a * max_b << std::endl;
}