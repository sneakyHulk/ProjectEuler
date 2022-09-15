#include <iostream>
#include <cstdint>

int main() {
    uint64_t sum = 0;
    for (uint16_t i = 1; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;
}