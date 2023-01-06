#include <iostream>
#include <cstdint>
#include <set>

constexpr bool is_pandigital_2(unsigned int a, unsigned int b) {
    uint_fast16_t unique_values = 1U;

    while (a > 0U) {
        uint_fast16_t const mask = 1U << (a % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        a /= 10U;
    }

    while (b > 0U) {
        uint_fast16_t const mask = 1U << (b % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        b /= 10U;
    }

    return unique_values == 0b1111111111;
}

constexpr bool is_pandigital_3(unsigned int a, unsigned int b, unsigned int c) {
    uint_fast16_t unique_values = 1U;

    while (a > 0U) {
        uint_fast16_t const mask = 1U << (a % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        a /= 10U;
    }

    while (b > 0U) {
        uint_fast16_t const mask = 1U << (b % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        b /= 10U;
    }

    while (c > 0U) {
        uint_fast16_t const mask = 1U << (c % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        c /= 10U;
    }

    return unique_values == 0b1111111111;
}

constexpr bool is_pandigital_4(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    uint_fast16_t unique_values = 1U;

    while (a > 0U) {
        uint_fast16_t const mask = 1U << (a % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        a /= 10U;
    }

    while (b > 0U) {
        uint_fast16_t const mask = 1U << (b % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        b /= 10U;
    }

    while (c > 0U) {
        uint_fast16_t const mask = 1U << (c % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        c /= 10U;
    }

    while (d > 0U) {
        uint_fast16_t const mask = 1U << (d % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        d /= 10U;
    }

    return unique_values == 0b1111111111;
}

constexpr bool is_pandigital_5(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    uint_fast16_t unique_values = 1U;

    while (a > 0U) {
        uint_fast16_t const mask = 1U << (a % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        a /= 10U;
    }

    while (b > 0U) {
        uint_fast16_t const mask = 1U << (b % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        b /= 10U;
    }

    while (c > 0U) {
        uint_fast16_t const mask = 1U << (c % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        c /= 10U;
    }

    while (d > 0U) {
        uint_fast16_t const mask = 1U << (d % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        d /= 10U;
    }

    while (e > 0U) {
        uint_fast16_t const mask = 1U << (e % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        e /= 10U;
    }

    return unique_values == 0b1111111111;
}

constexpr bool is_pandigital_6(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                               unsigned int f) { // if a == 3
    uint_fast16_t unique_values = 1U;

    while (a > 0U) {
        uint_fast16_t const mask = 1U << (a % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        a /= 10U;
    }

    while (b > 0U) {
        uint_fast16_t const mask = 1U << (b % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        b /= 10U;
    }

    while (c > 0U) {
        uint_fast16_t const mask = 1U << (c % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        c /= 10U;
    }

    while (d > 0U) {
        uint_fast16_t const mask = 1U << (d % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        d /= 10U;
    }

    while (e > 0U) {
        uint_fast16_t const mask = 1U << (e % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        e /= 10U;
    }

    while (f > 0U) {
        uint_fast16_t const mask = 1U << (f % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        f /= 10U;
    }

    return unique_values == 0b1111111111;
}

int main() {
    unsigned int max = 0U;

    for (unsigned int i = 1234U; i <= 9876U; ++i) {
        if (is_pandigital_2(i, i * 2)) {
            std::cout << i << ", " << i * 2 << std::endl;

            max = std::max<unsigned int>(max, std::stoul(std::to_string(i) + std::to_string(i * 2)));
        }
    }

    for (unsigned int i = 123U; i <= 987U; ++i) {
        if (is_pandigital_3(i, i * 2, i * 3)) {
            std::cout << i << ", " << i * 2 << ", " << i * 3 << std::endl;

            max = std::max<unsigned int>(max,
                                         std::stoul(std::to_string(i) + std::to_string(i * 2) + std::to_string(i * 3)));
        }
    }

    for (unsigned int i = 12U; i <= 98U; ++i) {
        if (is_pandigital_4(i, i * 2, i * 3, i * 4)) {
            std::cout << i << ", " << i * 2 << ", " << i * 3 << ", " << i * 4 << std::endl;

            max = std::max<unsigned int>(max, std::stoul(
                    std::to_string(i) + std::to_string(i * 2) + std::to_string(i * 3) + std::to_string(i * 4)));
        }
    }

    for (unsigned int i = 1U; i <= 9U; ++i) {
        if (is_pandigital_5(i, i * 2, i * 3, i * 4, i * 5)) {
            std::cout << i << ", " << i * 2 << ", " << i * 3 << ", " << i * 4 << ", " << i * 5 << std::endl;

            max = std::max<unsigned int>(max, std::stoul(
                    std::to_string(i) + std::to_string(i * 2) + std::to_string(i * 3) + std::to_string(i * 4) +
                    std::to_string(i * 5)));
        }
        if (is_pandigital_6(i, i * 2, i * 3, i * 4, i * 5, i * 6)) {
            std::cout << i << ", " << i * 2 << ", " << i * 3 << ", " << i * 4 << ", " << i * 5 << ", " << i * 5
                      << std::endl;

            max = std::max<unsigned int>(max, std::stoul(
                    std::to_string(i) + std::to_string(i * 2) + std::to_string(i * 3) + std::to_string(i * 4) +
                    std::to_string(i * 5) + std::to_string(i * 6)));
        }
    }

    std::cout << max << std::endl;
}