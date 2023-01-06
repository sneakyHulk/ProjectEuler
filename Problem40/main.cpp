#include <iostream>
#include <cstdint>

int main() {
    std::string fractional_part;

    for (unsigned int i = 0; i < 1000000U; ++i) {
        fractional_part += std::to_string(i);
    }

    unsigned int product = 1U;
    for (unsigned int i = 1; i <= 1000000U; i *= 10) {
        product *= fractional_part[i] - '0';
    }

    std::cout << product << std::endl;
}