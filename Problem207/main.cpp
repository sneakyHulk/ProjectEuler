#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <cstdint>

static uint32_t log2_custom(uint32_t val) {
    if (val == 1) return 0;
    uint32_t ret = 0;
    while (val > 1) {
        val >>= 1;
        ++ret;
    }
    return ret;
}

int main() {
    uint32_t index = 2U;
    while (true) {
        uint32_t loger = log2_custom(index);
        double portion = (double) loger / (double) (index - 1);
        if (portion < (1.0 / 12345.0)) {
            std::cout << index << std::endl;
            break;
        }
        ++index;
    }

    double exponent = std::log2(index);
    double m = std::pow(4.0, exponent) - std::pow(2.0, exponent);

    std::cout.precision(15);
    std::cout << m << std::endl;
}