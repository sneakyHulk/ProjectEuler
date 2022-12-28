#include <iostream>
#include <vector>

bool is_abundant(unsigned int n) {
    unsigned int res = 0;
    for (unsigned int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            res += i;
        }
    }

    return res > n;
}

int main() {
    std::vector<unsigned int> abundant_numbers;

    for (unsigned int i = 0; i <= 28123*2; ++i) {
        if (is_abundant(i)) abundant_numbers.push_back(i);
    }

    std::vector<bool> reached(abundant_numbers.back() * 2, false);


    for (unsigned int i = 0; i < abundant_numbers.size(); ++i) {
        for (unsigned int j = 0; j < abundant_numbers.size(); ++j) {
            reached[abundant_numbers[i] + abundant_numbers[j]] = true;
        }
    }

    unsigned int res = 0;
    for (unsigned int i = 0; i < 28123; ++i) {
        if (!reached[i]) {
            res += i;
        }
    }

    std::cout << res << std::endl;
}