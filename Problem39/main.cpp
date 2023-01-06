#include <iostream>
#include <cstdint>
#include <cmath>
#include <array>
#include <algorithm>

uint16_t int_sqrt32(uint32_t x) {
    uint16_t res = 0;
    uint16_t add = 0x8000;
    int i;
    for (i = 0; i < 16; i++) {
        uint16_t temp = res | add;
        uint32_t g2 = (uint32_t) temp * temp;
        if (x >= g2) {
            res = temp;
        }
        add >>= 1;
    }
    return res;
}


int main() {
    std::array<unsigned int, 1000U> p{};

    for (unsigned int a = 1U; a < 999U; ++a) {
        for (unsigned int b = 1U; b < 999U; ++b) {
            unsigned int c = int_sqrt32(a * a + b * b);
            if (c * c == a * a + b * b) {
                if (a + b + c <= 1000) {
                    ++p[a + b + c];
                }
            }
        }
    }

    std::cout << std::distance(p.begin(), std::max_element(p.begin(), p.end())) << std::endl;
}