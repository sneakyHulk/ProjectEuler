#include <iostream>
#include <cstdint>
#include <vector>

bool has_only_worthy_digits(uint64_t n) {
    while (n > 0) {
        if (n % 10 > 2) return false;
        n /= 10;
    }

    return true;
}

uint64_t f(const uint64_t n) {
    uint64_t value = n;
    while (!has_only_worthy_digits(value)) {
        value += n;
    }

    return value;
}

/*
10 * 0 = 0
 0 + 1 = 1
 1 + 1 = 2
10 * 1 = 10
10 + 1 = 11
10 + 2 = 12
10 * 2 = 20
20 + 1 = 21
20 + 2 = 22
*/

const size_t anzahl_sum = 10000;
std::vector<uint64_t> numbers_to_test(anzahl_sum - 1);

uint64_t summe = 0;

void test_numbers(uint64_t number) {
    for (int i = 0; i < numbers_to_test.size(); ++i) {
        if (number % numbers_to_test[i] == 0) {
            summe += number / numbers_to_test[i];
            numbers_to_test.erase(numbers_to_test.begin() + i--);
        }
    }
}

int main() {
    for (size_t i = 0; i < anzahl_sum - 1; ++i) {
        numbers_to_test[i] = i + 1;
    }

    //test all numbers:
    uint64_t i = 1LLU;
    uint64_t ii = 0LLU;
    uint64_t iii = 0LLU;
    uint64_t iiii = 0LLU;
    uint64_t iiiii = 0LLU;
    uint64_t iiiiii = 0LLU;
    uint64_t iiiiiii = 0LLU;
    uint64_t iiiiiiii = 0LLU;
    uint64_t iiiiiiiii = 0LLU;
    uint64_t iiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiiiiiiiiiii = 0LLU;
    uint64_t iiiiiiiiiiiiiiiiiiii = 0LLU;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    for (; iiiiiiiiiiiiiiiiiiii <= 10000000000000000000LLU; iiiiiiiiiiiiiiiiiiii += 10000000000000000000LLU) {
        for (; iiiiiiiiiiiiiiiiiii <= 2000000000000000000LLU; iiiiiiiiiiiiiiiiiii += 1000000000000000000LLU) {
            for (; iiiiiiiiiiiiiiiiii <= 200000000000000000LLU; iiiiiiiiiiiiiiiiii += 100000000000000000LLU) {
                for (; iiiiiiiiiiiiiiiii <= 20000000000000000LLU; iiiiiiiiiiiiiiiii += 10000000000000000LLU) {
                    for (; iiiiiiiiiiiiiiii <= 2000000000000000LLU; iiiiiiiiiiiiiiii += 1000000000000000LLU) {
                        for (; iiiiiiiiiiiiiii <= 200000000000000LLU; iiiiiiiiiiiiiii += 100000000000000LLU) {
                            for (; iiiiiiiiiiiiii <= 20000000000000LLU; iiiiiiiiiiiiii += 10000000000000LLU) {
                                for (; iiiiiiiiiiiii <= 2000000000000LLU; iiiiiiiiiiiii += 1000000000000LLU) {
                                    for (; iiiiiiiiiiii <= 200000000000LLU; iiiiiiiiiiii += 100000000000LLU) {
                                        for (; iiiiiiiiiii <= 20000000000LLU; iiiiiiiiiii += 10000000000LLU) {
                                            for (; iiiiiiiiii <= 2000000000LLU; iiiiiiiiii += 1000000000LLU) {
                                                for (; iiiiiiiii <= 200000000LLU; iiiiiiiii += 100000000LLU) {
                                                    for (; iiiiiiii <= 20000000LLU; iiiiiiii += 10000000LLU) {
                                                        for (; iiiiiii <= 2000000LLU; iiiiiii += 1000000LLU) {
                                                            for (; iiiiii <= 200000LLU; iiiiii += 100000LLU) {
                                                                for (; iiiii <= 20000LLU; iiiii += 10000LLU) {
                                                                    for (; iiii <= 2000LLU; iiii += 1000LLU) {
                                                                        for (; iii <= 200LLU; iii += 100LLU) {
                                                                            for (; ii <= 20LLU; ii += 10LLU) {
                                                                                for (; i <= 2LLU; ++i) {
                                                                                    test_numbers(i + ii + iii + iiii +
                                                                                                 iiiii + iiiiii +
                                                                                                 iiiiiii + iiiiiiii +
                                                                                                 iiiiiiiii +
                                                                                                 iiiiiiiiii +
                                                                                                 iiiiiiiiiii +
                                                                                                 iiiiiiiiiiii +
                                                                                                 iiiiiiiiiiiii +
                                                                                                 iiiiiiiiiiiiii +
                                                                                                 iiiiiiiiiiiiiii +
                                                                                                 iiiiiiiiiiiiiiii +
                                                                                                 iiiiiiiiiiiiiiiii +
                                                                                                 iiiiiiiiiiiiiiiiii +
                                                                                                 iiiiiiiiiiiiiiiiiii +
                                                                                                 iiiiiiiiiiiiiiiiiiii);
                                                                                }
                                                                                i = 0;
                                                                            }
                                                                            ii = 0;
                                                                        }
                                                                        iii = 0;
                                                                    }
                                                                    iiii = 0;
                                                                }
                                                                iiiii = 0;
                                                            }
                                                            iiiiii = 0;
                                                        }
                                                        iiiiiii = 0;
                                                    }
                                                    iiiiiiii = 0;
                                                }
                                                iiiiiiiii = 0;
                                            }
                                            iiiiiiiiii = 0;
                                        }
                                        iiiiiiiiiii = 0;
                                    }
                                    iiiiiiiiiiii = 0;
                                }
                                iiiiiiiiiiiii = 0;
                            }
                            iiiiiiiiiiiiii = 0;
                        }
                        iiiiiiiiiiiiiii = 0;
                    }
                    iiiiiiiiiiiiiiii = 0;
                }
                iiiiiiiiiiiiiiiii = 0;
            }
            iiiiiiiiiiiiiiiiii = 0;
        }
        iiiiiiiiiiiiiiiiiii = 0;
    }
#pragma clang diagnostic pop
#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
    iiiiiiiiiiiiiiiiiiii = 0;

    std::cout << summe + 1 << std::endl;
#pragma clang diagnostic pop

    /*
     * naiver Ansatz:
     *

     uint64_t sum = 0;
     for (uint64_t n = 1; n < 1000; ++n) {
         sum += f(n) / n;
     }

     std::cout << sum + 1 << std::endl;

     */
}