#include <iostream>
#include <cstdint>
#include <cmath>

constexpr bool is_prime(unsigned int n) {
    for (unsigned int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

template<std::size_t N>
// 1 to N
constexpr bool is_pandigital(unsigned int a) {
    uint_fast16_t unique_values = 0U;

    for (unsigned int i = 0; i < N - 1; ++i) {
        uint_fast16_t const mask = 1U << (a % 10U);
        unique_values |= mask;
        a /= 10U;
    }

    uint_fast16_t const mask = 1U << (a % 10U);
    unique_values |= mask;

    if constexpr (N == 9) return unique_values == 0b1111111110;
    if constexpr (N == 8) return unique_values == 0b0111111110;
    if constexpr (N == 7) return unique_values == 0b0011111110;
    if constexpr (N == 6) return unique_values == 0b0001111110;
    if constexpr (N == 5) return unique_values == 0b0000111110;
    if constexpr (N == 4) return unique_values == 0b0000011110;
    if constexpr (N == 3) return unique_values == 0b0000001110;
    if constexpr (N == 2) return unique_values == 0b0000000110;
    if constexpr (N == 1) return unique_values == 0b0000000010;

}

int main() {
    for (unsigned int i = 987654321U; i >= 123456789U; --i) {
        if (is_pandigital<9>(i) && is_prime(i)) {
            std::cout << i << std::endl;

            return 0;
        }
    }
    for (unsigned int i = 87654321U; i >= 12345678U; --i) {
        if (is_pandigital<8>(i) && is_prime(i)) {
            std::cout << i << std::endl;

            return 0;
        }
    }
    for (unsigned int i = 7654321U; i >= 1234567U; --i) {
        if (is_pandigital<7>(i) && is_prime(i)) {
            std::cout << i << std::endl;

            return 0;
        }
    }
    for (unsigned int i = 654321U; i >= 123456U; --i) {
        if (is_pandigital<6>(i) && is_prime(i)) {
            std::cout << i << std::endl;

            return 0;
        }
    }
    for (unsigned int i = 54321U; i >= 12345U; --i) {
        if (is_pandigital<5>(i) && is_prime(i)) {
            std::cout << i << std::endl;

            return 0;
        }
    }
    for (unsigned int i = 4321U; i >= 1234U; --i) {
        if (is_pandigital<4>(i) && is_prime(i)) {
            std::cout << i << std::endl;

            return 0;
        }
    }
    for (unsigned int i = 321U; i >= 123U; --i) {
        if (is_pandigital<3>(i) && is_prime(i)) {
            std::cout << i << std::endl;

            return 0;
        }
    }
    for (unsigned int i = 21U; i >= 12U; --i) {
        if (is_pandigital<2>(i) && is_prime(i)) {
            std::cout << i << std::endl;

            return 0;
        }
    }
}