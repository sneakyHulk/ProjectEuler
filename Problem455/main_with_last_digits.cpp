#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <cassert>
#include <omp.h>

template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

constexpr uint8_t get_last_digit(unsigned long long int const number) {
    return number % 10;
}

constexpr uint8_t get_second_last_digit(unsigned long long int const number) {
    return get_last_digit(number / 10);
}


int main() {
    omp_set_num_threads(24);

    std::cout << sqrt(std::numeric_limits<unsigned long long int>::max()) << std::endl;
    std::cout << 1000000000 << std::endl;

    std::vector<std::vector<unsigned long long int>> last_digits(100);
    std::vector<std::vector<unsigned long long int>> sub_last_digits(100);

    for (unsigned long long int i = 200; i < 300; ++i) {
        std::cout << i % 100 << " : ";
        for (int j = 2; j < 30; ++j) {
            uint8_t v = modpow<unsigned long long int>(i, j, 100);

            if (std::find(last_digits[i % 100].cbegin(), last_digits[i % 100].cend(), v) != last_digits[i % 100].cend()) {
                assert(std::find(last_digits[i % 100].cbegin(), last_digits[i % 100].cend(), v) == last_digits[i % 100].cbegin());
                std::cout << "break";
                break;
            }

            std::cout << (unsigned int) v << ",";
            last_digits[i % 100].push_back(v);
            sub_last_digits[i % 100].push_back(100 - v);
        }
        std::cout << ", size: " << last_digits[i % 100].size() << std::endl; // hier fehlt sorted

        std::sort(sub_last_digits[i % 100].begin(), sub_last_digits[i % 100].end());
    }

    uint_fast8_t sub_last_digits_sorted[100][20];

    for (size_t i = 0; i < sub_last_digits.size(); ++i) {
        for (size_t j = 0; j < sub_last_digits[i].size(); ++j) {
            sub_last_digits_sorted[i][j] = sub_last_digits[i][j];
        }
    }

#pragma omp parallel for default(none) firstprivate(sub_last_digits_sorted, last_digits) shared(std::cout)
    for (unsigned long long int n = 2; n <= 1000; ++n) {

        const uint_fast8_t last_digit_n = get_last_digit(n);
        if (last_digit_n == 0) std::cout << "n: " << n << ", f(n): " << 0 << std::endl;

        if (last_digit_n == 5) {
            const uint_fast8_t second_last_digit_n = get_second_last_digit(n);
            if (second_last_digit_n % 2 == 0) { // is even
                for (unsigned long long int x = 1000000000; x >= 100; x -= 100) {
                    if (x - 75 == modpow<unsigned long long int>(n, x - 75, 1000000000)) { // ends in 25
                        std::cout << "n: " << n << ", f(n): " << x - 75 << std::endl; break;
                    }
                }
            }
            else { // is odd
                for (unsigned long long int x = 1000000000; x >= 100; x -= 100) {
                    if (x - 25 == modpow<unsigned long long int>(n, x - 25, 1000000000)) { // ends in 75
                        std::cout << "n: " << n << ", f(n): " << x - 25 << std::endl; break;
                    }
                }
            }
            continue;
        }

        const size_t size_sub_last_digits_sorted = last_digits[n % 100].size();
        const uint_fast8_t* const current_ptr_sub_last_digits_sorted = sub_last_digits_sorted[n % 100];

        for (unsigned long long int x = 1000000000; x >= 100; x -= 100) {

            for (size_t i = 0; i < size_sub_last_digits_sorted; ++i) {
                if (x - current_ptr_sub_last_digits_sorted[i] == modpow<unsigned long long int>(n, x - current_ptr_sub_last_digits_sorted[i], 1000000000)) {
                    std::cout << "n: " << n << ", f(n): " << x - current_ptr_sub_last_digits_sorted[i] << std::endl; break;
                }
            }
        }
    }

    /*for (unsigned long long int n = 5; n <= 1000; n+=5) {
        for (unsigned long long int x = 1000000000; x >= 100; x -= 100) {
            for (unsigned long long int const sub_last_digits_to_test : sub_last_digits[n % 100]) {
                if (x - sub_last_digits_to_test == modpow<unsigned long long int>(n, x - sub_last_digits_to_test, 1000000000)) {
                    std::cout << x - sub_last_digits_to_test << std::endl; break;
                }
            }
        }
    }*/

    /*for (unsigned long long int n = 10000; n <= 10000; ++n){ // 10000
        const uint8_t last_digit_n = get_last_digit(n);
        const uint8_t second_last_digit_n = get_second_last_digit(n);
        std::cout << "n: " << n << ", f(n): ";
        if (last_digit_n == 0) {
            std::cout << 0 << std::endl;
        }
        /*if (last_digit_n == 1) {
            for (unsigned long long int x = 1000000000; x >= 10; x -= 10) {
                unsigned long long int x_sampled = x - 9;
                const uint8_t target_second_last_digit_x = get_second_last_digit(x_sampled);
                const uint8_t is_second_last_digit_x = (second_last_digit_n * get_last_digit(x_sampled)) % 10;
                if (target_second_last_digit_x == is_second_last_digit_x) {
                    if (x_sampled == modpow<unsigned long long int>(n, x_sampled, 1000000000)) {
                        std::cout << x_sampled << std::endl; break;
                    }
                }
            }
        }*/
    /*if (last_digit_n == 4) {
        for (unsigned long long int x = 1000000000; x >= 10; x -= 10) {
            if (x - 4 == modpow<unsigned long long int>(n, x - 4, 1000000000)) {
                std::cout << x - 4 << std::endl; break;
            }
            if (x - 6 == modpow<unsigned long long int>(n, x - 6, 1000000000)) {
                std::cout << x - 6 << std::endl; break;
            }
        }
    }
    if (last_digit_n == 5) {
        if (second_last_digit_n % 2 == 0) { // is even
            for (unsigned long long int x = 1000000000; x >= 100; x -= 100) {
                if (x - 75 == modpow<unsigned long long int>(n, x - 75, 1000000000)) { // ends in 25
                    std::cout << x - 75 << std::endl; break;
                }
            }
        }
        else { // is odd
            for (unsigned long long int x = 1000000000; x >= 100; x -= 100) {
                if (x - 25 == modpow<unsigned long long int>(n, x - 25, 1000000000)) { // ends in 75
                    std::cout << x - 25 << std::endl; break;
                }
            }
        }
    }
}*/
    return 0;
}