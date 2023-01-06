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

int main() {
    std::set<std::string> primes;

    for (unsigned int i = 2; i < 10'000'000U; ++i) {
        if (is_prime(i))
            primes.insert(std::to_string(i));
    }

    unsigned int sum = 0U;
    for (std::string const &e: primes) {
        bool truncatable = true;
        for (unsigned int i = 1U; i < e.size(); ++i) {
            if (!primes.contains(e.substr(i))) {
                truncatable = false;
                break;
            }
            if (!primes.contains(e.substr(0U, e.size() - i))) {
                truncatable = false;
                break;
            }
        }

        if (truncatable) {
            sum += std::stoul(e);
        }
    }

    std::cout << sum - 2 - 3 - 5 - 7 << std::endl;
}