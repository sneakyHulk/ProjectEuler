#include <iostream>

int main() {
    for (unsigned int a = 1; a < 1000; ++a) {
        for (unsigned int b = 1; b < 1000; ++b) {
            for (unsigned int c = 1; c < 1000; ++c) {
                if (a * a + b * b == c * c && a + b + c == 1000) {
                    std::cout << a << " * " << b << " * " << c << " = " << a * b * c << std::endl;
                    return 0;
                }
            }
        }
    }
}