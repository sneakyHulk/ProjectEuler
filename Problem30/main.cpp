#include <iostream>
#include <cstdint>
#include <vector>
#include <array>

template<size_t N>
uint64_t fifth_power(std::array<uint64_t, N> const &&x) {
    uint64_t erg = 0;

    for (uint64_t const &e: x) {
        erg += e * e * e * e * e;
    }

    return erg;
}

int main() {
    uint64_t sum = 0;
    for (uint64_t iiiiiiiii = 0; iiiiiiiii < 10; ++iiiiiiiii) {
        for (uint64_t iiiiiiii = 0; iiiiiiii < 10; ++iiiiiiii) {
            for (uint64_t iiiiiii = 0; iiiiiii < 10; ++iiiiiii) {
                for (uint64_t iiiiii = 0; iiiiii < 10; ++iiiiii) {
                    for (uint64_t iiiii = 0; iiiii < 10; ++iiiii) {
                        for (uint64_t iiii = 0; iiii < 10; ++iiii) {
                            for (uint64_t iii = 0; iii < 10; ++iii) {
                                for (uint64_t ii = 0; ii < 10; ++ii) {
                                    for (uint64_t i = 0; i < 10; ++i) {
                                        uint64_t power = fifth_power<9>(
                                                {iiiiiiiii, iiiiiiii, iiiiiii, iiiiii, iiiii, iiii, iii, ii, i});
                                        uint64_t num =
                                                i + ii * 10 + iii * 100 + iiii * 1000 + iiiii * 10000 +
                                                iiiiii * 100000 + iiiiiii * 1000000 +
                                                iiiiiiii * 10000000 +
                                                iiiiiiiii * 100000000;

                                        if (power == num) [[unlikely]] {
                                            std::cout << num << " = ";
                                            for (auto const &e: {iiiiiiiii, iiiiiiii, iiiiiii, iiiiii, iiiii, iiii, iii,
                                                                 ii, i}) {
                                                std::cout << e << "^5 + ";
                                            }
                                            std::cout << std::endl;

                                            sum += num;
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

    std::cout << sum - 1 << std::endl;
}