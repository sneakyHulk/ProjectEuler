#include <iostream>
#include <cstdint>
#include <set>
#include <cmath>

constexpr bool is_prime(unsigned int n) {
    for (unsigned int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

std::string leftrotate(std::string const &str) {
    std::string tmp = str.substr(1);
    tmp.push_back(str[0]);

    return tmp;
}

int main() {
    std::set<std::string> primes;

    for (unsigned int i = 2; i < 1'000'000U; ++i) {
        if (is_prime(i))
            primes.insert(std::to_string(i));
    }

    unsigned int sum = 0U;

    for (std::string const &e: primes) {
        std::string tmp = e;
        bool _break = false;
        for (unsigned int i = 1; i < e.size(); ++i) {
            tmp = leftrotate(tmp);
            if (!primes.contains(tmp)) {
                _break = true;
                break;
            }
        }
        if (_break) continue;

        ++sum;
    }

    std::cout << sum << std::endl;
}