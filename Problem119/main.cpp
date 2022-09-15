#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

uint8_t get_sum_of_digits(uint64_t uint) {
    uint8_t sum = 0U;

    while (uint > 0) {
        sum += uint % 10;
        uint /= 10;
    }

    return sum;
}

std::vector<uint64_t> a_n;

int main() {
    constexpr uint64_t max = UINT64_MAX / 180U;

    for (uint64_t base = 2U; base <= 180U; ++base) {
        uint64_t number = base;
        do {
            number *= base;

            if (get_sum_of_digits(number) == base) {
                a_n.push_back(number);
            }
        } while (number < max);
    }

    std::sort(a_n.begin(), a_n.end());

    int i = 1;
    for (uint64_t number: a_n) {
        std::cout << i++ << ": " << number << std::endl;
    }

    /*
     * naiver Ansatz:
     *

     for (uint64_t uint = 0U; uint < 1000000000000U; ++uint) {
         uint64_t base_power = get_sum_of_digits(uint);
         if (base_power <= 1) continue;

         uint64_t power = base_power;

         do {
             power *= base_power;
         } while (uint > power);

         if (uint == power) {
             std::cout << power << std::endl;
         }
     }

     */
}