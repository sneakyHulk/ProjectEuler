#include <iostream>
#include <cstdint>
#include <set>

#include <BigInt.h>

int main() {
    std::set<BigInt> values;
    for (BigInt a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            values.insert(pow(a, b));
        }
    }

    std::cout << values.size() << std::endl;
}