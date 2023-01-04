#include <iostream>
#include <vector>
#include <numeric>
#include <array>

/**
 *
 *  0 1
 *  1 0
 */

/**
 *
 *  0 1 2
 *  0 2 1
 *  1 0 2
 *  1 2 0
 *  2 0 1
 *  2 1 0
 */

/**
 *
 *  0 1 2 3
 *  0 1 3 2
 *  0 2 1 3
 *  0 2 3 1
 *  0 3 1 2
 *  0 3 2 1
 *  1 0 2 3
 *  1 0 3 2
 *  1 2 0 3
 *  1 2 3 0
 *  1 3 0 2
 *  1 3 2 0
 *  2 0 1 3
 *  2 0 3 1
 *  2 1 0 3
 *  2 1 3 0
 *  2 3 0 1
 *  2 3 1 0
 *  3 0 1 2
 *  3 0 2 1
 *  3 1 0 2
 *  3 1 2 0
 *  3 2 0 1
 *  3 2 1 0
 */

/**
 *
 * 0 1 2 3 = * 4
 * 0 1 2 3 4 = * 5
 * 0 1 2 3 4 5 = * 6
 * 0 1 2 3 4 5 6 = * 7
 * 0 1 2 3 4 5 6 7 = * 8
 * 0 1 2 3 4 5 6 7 8 = * 9
 * 0 1 2 3 4 5 6 7 8 9 = * 10
 *
 */

constexpr unsigned int factorial(unsigned int n) {
    unsigned int factorial = 1;
    for (unsigned int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

template<std::size_t N, typename ...T>
constexpr std::array<unsigned int, N - sizeof...(T)> get_array(T const ... skip_values) {
    std::array<unsigned int, sizeof...(T)> skip = {skip_values...}; std::sort(skip.begin(), skip.end());
    std::array<unsigned int, N - sizeof...(T)> arr{};
    for (unsigned int value = 0; unsigned int &e: arr) {
        for (unsigned int const e2: skip) {
            if (e2 == value) {
                ++value;
            }
        }
        e = value++;
    }

    return arr;
}

int main() {
    unsigned int n_digits = 10;
    unsigned int permutation = 1000000;
    unsigned int value = permutation - 1;
    unsigned int fak = n_digits - 1;
    std::vector<unsigned int> arr(n_digits);
    std::iota(arr.begin(), arr.end(), 0);

    while (fak) {
        unsigned int testing = value / factorial(fak);
        std::cout << arr[testing];
        arr.erase(arr.begin() + testing);
        value = value % factorial(fak);
        --fak;
    }
    std::cout << arr.back() << std::endl;

    // or:

    unsigned int sum = 0;
    unsigned int const N = 10;
    for (unsigned int const e0: get_array<N>()) {
        for (unsigned int const e1: get_array<N>(e0)) {
            for (unsigned int const e2: get_array<N>(e0, e1)) {
                for (unsigned int const e3: get_array<N>(e0, e1, e2)) {
                    for (unsigned int const e4: get_array<N>(e0, e1, e2, e3)) {
                        for (unsigned int const e5: get_array<N>(e0, e1, e2, e3, e4)) {
                            for (unsigned int const e6: get_array<N>(e0, e1, e2, e3, e4, e5)) {
                                for (unsigned int const e7: get_array<N>(e0, e1, e2, e3, e4, e5, e6)) {
                                    for (unsigned int const e8: get_array<N>(e0, e1, e2, e3, e4, e5, e6, e7)) {
                                        for (unsigned int const e9: get_array<N>(e0, e1, e2, e3, e4, e5, e6, e7, e8)) {
                                            if (++sum == 1'000'000U)
                                                std::cout << e0 << e1 << e2 << e3 << e4 << e5 << e6 << e7 << e8 << e9
                                                          << std::endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}