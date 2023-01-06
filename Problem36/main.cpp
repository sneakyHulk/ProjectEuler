#include <iostream>
#include <cstdint>

bool is_palindrome(std::string const &str) {
    for (unsigned int i = 0; i < str.size() / 2U; ++i) {
        if (str[i] != str[str.size() - 1 - i]) return false;
    }

    return true;
}

std::string get_bin(unsigned int const num) {
    std::string binary;
    uint mask = 0x80000000U;
    bool start = false;
    while (mask > 0) {
        if ((num & mask)) {
            binary += '1';
            start = true;
        } else {
            if (start) {
                binary += '0';
            }
        }

        mask >>= 1;
    }

    return binary;
}

int main() {
    unsigned int sum = 0U;
    for (unsigned int i = 0U; i < 1'000'000U; ++i) {
        if (is_palindrome(std::to_string(i)) && is_palindrome(get_bin(i))) sum += i;
    }

    std::cout << sum << std::endl;
}