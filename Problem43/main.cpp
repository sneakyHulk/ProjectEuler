#include <iostream>
#include <cstdint>
#include <cmath>
#include <array>

template<std::size_t N, typename ...T>
constexpr std::array<unsigned int, N - sizeof...(T)> get_array(T const ... skip_values) {
    std::array<unsigned int, sizeof...(T)> skip = {skip_values...};
    std::sort(skip.begin(), skip.end());
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
    unsigned long long sum = 0;
    unsigned int const N = 10;
    for (unsigned int const e0: get_array<N>()) {
        for (unsigned int const e1: get_array<N>(e0)) {
            for (unsigned int const e2: get_array<N>(e0, e1)) {
                for (unsigned int const e3: get_array<N>(e0, e1, e2)) {
                    if (e3 % 2 != 0) continue;
                    for (unsigned int const e4: get_array<N>(e0, e1, e2, e3)) {
                        if ((e2 + e3 + e4) % 3 != 0) continue;
                        for (unsigned int const e5: get_array<N>(e0, e1, e2, e3, e4)) {
                            if (e5 % 5 != 0) continue;
                            for (unsigned int const e6: get_array<N>(e0, e1, e2, e3, e4, e5)) {
                                if ((e4 * 100 + e5 * 10 + e6) % 7 != 0) continue;
                                for (unsigned int const e7: get_array<N>(e0, e1, e2, e3, e4, e5, e6)) {
                                    if ((e5 * 100 + e6 * 10 + e7) % 11 != 0) continue;
                                    for (unsigned int const e8: get_array<N>(e0, e1, e2, e3, e4, e5, e6, e7)) {
                                        if ((e6 * 100 + e7 * 10 + e8) % 13 != 0) continue;
                                        for (unsigned int const e9: get_array<N>(e0, e1, e2, e3, e4, e5, e6, e7,
                                                                                 e8)) {
                                            if ((e7 * 100 + e8 * 10 + e9) % 17 != 0) continue;

                                            sum += e9 + e8 * 10U + e7 * 100U + e6 * 1000U + e5 * 10000U + e4 * 100000U +
                                                   e3 * 1000000U + e2 * 10000000U + e1 * 100000000U + e0 * 1000000000U;
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

    std::cout << sum << std::endl;
}