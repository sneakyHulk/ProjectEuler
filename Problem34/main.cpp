#include <iostream>
#include <cstdint>
#include <array>

int main() {
    std::array<unsigned int, 10> factorials = {1U, 1U, 2U, 6U, 24U, 120U, 720U, 5040U, 40320U, 362880U};

    unsigned int sum = 0U;
    for (uint64_t iiiiiiiii = 0; iiiiiiiii < 10; ++iiiiiiiii) {
        for (uint64_t iiiiiiii = 0; iiiiiiii < 10; ++iiiiiiii) {
            for (uint64_t iiiiiii = 0; iiiiiii < 10; ++iiiiiii) {
                for (uint64_t iiiiii = 0; iiiiii < 10; ++iiiiii) {
                    for (uint64_t iiiii = 0; iiiii < 10; ++iiiii) {
                        for (uint64_t iiii = 0; iiii < 10; ++iiii) {
                            for (uint64_t iii = 0; iii < 10; ++iii) {
                                for (uint64_t ii = 0; ii < 10; ++ii) {
                                    for (uint64_t i = 0; i < 10; ++i) {
                                        unsigned int const num =
                                                i + ii * 10 + iii * 100 + iiii * 1000 + iiiii * 10000 +
                                                iiiiii * 100000 + iiiiiii * 1000000 +
                                                iiiiiiii * 10000000 +
                                                iiiiiiiii * 100000000;

                                        unsigned int num2 = 0U;
                                        if (iiiiiiiii > 0U) num2 += factorials[iiiiiiiii];
                                        if (iiiiiiii > 0U || num2 > 0U) num2 += factorials[iiiiiiii];
                                        if (iiiiiii > 0U || num2 > 0U) num2 += factorials[iiiiiii];
                                        if (iiiiii > 0U || num2 > 0U) num2 += factorials[iiiiii];
                                        if (iiiii > 0U || num2 > 0U) num2 += factorials[iiiii];
                                        if (iiii > 0U || num2 > 0U) num2 += factorials[iiii];
                                        if (iii > 0U || num2 > 0U) num2 += factorials[iii];
                                        if (ii > 0U || num2 > 0U) num2 += factorials[ii];
                                        if (i > 0U || num2 > 0U) num2 += factorials[i];

                                        if (num == num2) {
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

    std::cout << sum - 1 - 2 << std::endl;
}