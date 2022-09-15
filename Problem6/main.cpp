#include <iostream>
#include <cstdint>

int main() {
    uint64_t erg_sum_squares = 0U;
    uint64_t erg_squares_of_sum = 0U;

    for (uint64_t n = 1U; n <= 100U; ++n) {
        erg_sum_squares += n * n;
    }

    for (uint64_t n = 1U; n <= 100U; ++n) {
        erg_squares_of_sum += n;
    }

    erg_squares_of_sum = erg_squares_of_sum * erg_squares_of_sum;

    std::cout << "Sum of squares: '" << erg_sum_squares << "'." << std::endl;
    std::cout << "Square of sum: '" << erg_squares_of_sum << "'." << std::endl;

    uint64_t difference = erg_squares_of_sum - erg_sum_squares;

    std::cout << "Difference: '" << difference << "'." << std::endl;

    return 0;
}