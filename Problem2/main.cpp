#include <iostream>
#include <cstdint>

int main() {
    uint32_t max = 4000000;

    uint32_t current = 1;
    uint32_t current_before = 1;

    uint32_t sum = 0;

    while (current < 4000000) {
        if (current % 2 == 0) {
            sum += current;
        }

        uint32_t tmp = current;
        current += current_before;
        current_before = tmp;
    }

    std::cout << sum << std::endl;
}