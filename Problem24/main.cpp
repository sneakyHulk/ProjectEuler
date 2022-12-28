#include <iostream>
#include <vector>
#include <numeric>

/**
 *
 *  0 1
 *  1 0
 */

/**
 *
 *  0 1 2
 *  0 2 1
 *  1 0 2
 *  1 2 0
 *  2 0 1
 *  2 1 0
 */

/**
 *
 *  0 1 2 3
 *  0 1 3 2
 *  0 2 1 3
 *  0 2 3 1
 *  0 3 1 2
 *  0 3 2 1
 *  1 0 2 3
 *  1 0 3 2
 *  1 2 0 3
 *  1 2 3 0
 *  1 3 0 2
 *  1 3 2 0
 *  2 0 1 3
 *  2 0 3 1
 *  2 1 0 3
 *  2 1 3 0
 *  2 3 0 1
 *  2 3 1 0
 *  3 0 1 2
 *  3 0 2 1
 *  3 1 0 2
 *  3 1 2 0
 *  3 2 0 1
 *  3 2 1 0
 */

/**
 *
 * 0 1 2 3 = * 4
 * 0 1 2 3 4 = * 5
 * 0 1 2 3 4 5 = * 6
 * 0 1 2 3 4 5 6 = * 7
 * 0 1 2 3 4 5 6 7 = * 8
 * 0 1 2 3 4 5 6 7 8 = * 9
 * 0 1 2 3 4 5 6 7 8 9 = * 10
 *
 */

constexpr unsigned int factorial(unsigned int n) {
    unsigned int factorial = 1;
    for (unsigned int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}


int main() {
    unsigned int n_digits = 10;
    unsigned int permutation = 1000000;
    unsigned int value = permutation - 1;
    unsigned int fak = n_digits - 1;
    std::vector<unsigned int> arr(n_digits);
    std::iota(arr.begin(), arr.end(), 0);

    while (fak) {
        unsigned int testing = value / factorial(fak);
        std::cout << arr[testing];
        arr.erase(arr.begin() + testing);
        value = value % factorial(fak);
        --fak;
    }
    std::cout << arr.back() << std::endl;
}