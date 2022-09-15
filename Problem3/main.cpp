#include <iostream>
#include <cstdint>

int main() {
    uint64_t zahl = 600851475143;
    uint64_t teiler = 2;

    while (teiler * teiler <= zahl) {
        if (zahl % teiler == 0) {
            std::cout << teiler << " * ";
            zahl /= teiler;
        } else {
            ++teiler;
        }
    }

    std::cout << zahl << std::endl;
}