#include <iostream>

int main() {
    uint32_t n = 1U;

    while (!(n % 20 == 0 && n % 19 == 0 && n % 18 == 0 && n % 17 == 0 && n % 16 == 0 && n % 15 == 0 && n % 14 == 0 &&
             n % 13 == 0 && n % 12 == 0
             && n % 11 == 0)) {
        ++n;
    }

    std::cout << "Nummer: '" << n << "'." << std::endl;
}

/*
 * Studie welche Teiler geprüft werden müssen
 *

 20: 20, 4, 5, 10

 19: 19

 18: 18, 9, 3

 17: 17

 16: 16, 8

 15: 15, 5, 3

 14: 14, 7, 2

 13: 13

 12: 12, 6, 2

 11: 11
*/