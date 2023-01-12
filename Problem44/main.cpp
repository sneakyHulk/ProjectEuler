#include <iostream>
#include <cstdint>
#include <cmath>
#include <array>
#include <set>
#include <cmath>



int main() {
    const unsigned int max = 10000U;
    std::set<uint64_t> arr;

    for (uint64_t i = 1U; i <= max; ++i) {
        arr.insert(i * (3 * i - 1) / 2);
    }

    for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
        for (auto it2 = it; it2 != arr.cend(); ++it2) {
            if (arr.contains(*it2 - *it) && arr.contains(*it + *it2)) {
                std::cout << *it2 - *it << std::endl;
            }
        }
    }
}