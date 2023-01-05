#include <iostream>
#include <cstdint>
#include <array>
#include <bitset>
#include <vector>
#include "progressbar.h"

constexpr bool is_unique(uint64_t num) {
    std::bitset<10> unique_values;

    while (num > 0) {
        if (unique_values[num % 10U]) return false;
        unique_values[num % 10U] = true;
        num /= 10U;
    }

    return true;
}

int main() {
    std::bitset<9876543210U> arr;
    std::vector<uint64_t> nums(8877690U);

    for (uint64_t i = 1, j = 0; i <= 9876543210U; ++i) {
        if (is_unique(i)) {
            arr[i] = true;
            nums[j++] = i;
        }
    }

    uint64_t sum = 0;

    progressbar bar(8877690U);
    for (unsigned int i = 0; i < 8877690U; ++i) {
        for (unsigned int j = i; j < 8877690U; ++j) {
            uint64_t product = nums[i] * nums[j];
            if (arr[product]) {
                sum += product;
            }
        }
        bar.update();
    }

    std::cout << nums.back() << std::endl;

    //progressbar bar(9876543210U);
    //uint64_t sum = 0;
    //for (uint64_t i = 1; i < 9876543210U; ++i) {
    //    if (is_unique(i)) [[unlikely]] {
    //        for (uint64_t j = i; j < 9876543210U; ++j) {
    //            if (is_unique(j)) [[unlikely]] {
    //                uint64_t product = i * j;
    //                if (product <= 9876543210 && is_unique(product)) [[unlikely]] {
    //                    sum += product;
    //                    //std::cout << i << " * " << j << " = " << product << std::endl;
    //                }
    //            }
    //        }
    //    }
    //    bar.update();
    //}

    //arr[9807654321] = true;

/*

    for (uint64_t iiiiiiiii = 0; iiiiiiiii < 10; ++iiiiiiiii) {
        for (uint64_t iiiiiiii = 0; iiiiiiii < 10; ++iiiiiiii) {
            for (uint64_t iiiiiii = 0; iiiiiii < 10; ++iiiiiii) {
                for (uint64_t iiiiii = 0; iiiiii < 10; ++iiiiii) {
                    for (uint64_t iiiii = 0; iiiii < 10; ++iiiii) {
                        for (uint64_t iiii = 0; iiii < 10; ++iiii) {
                            for (uint64_t iii = 0; iii < 10; ++iii) {
                                for (uint64_t ii = 0; ii < 10; ++ii) {
                                    for (uint64_t i = 0; i < 10; ++i) {

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }*/
}