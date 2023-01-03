#include <iostream>
#include <cstdint>

int main() {
    uint64_t erg = 1;
    uint64_t num = 1;
    for (unsigned int i = 2; i < 1001; i += 2) {
        erg += num += i;
        erg += num += i;
        erg += num += i;
        erg += num += i;
    }

    std::cout << erg << std::endl;
}