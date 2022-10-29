#include <iostream>
#include <vector>

int main() {
    std::vector<unsigned int> sums(10000, 0);
    std::vector<bool> amicable(10000, false);

    for (unsigned int i = 2; i < sums.size(); ++i) {
        for (unsigned int j = 1; j < i; ++j) {
            if (i % j == 0) {
                sums[i] += j;
            }
        }
    }

    for (unsigned int i = 2; i < sums.size(); ++i) {
        if (sums[i] < sums.size()) {
            if (i == sums[sums[i]] && i != sums[i]) {
                amicable[i] = true;
            }
        }
    }

    unsigned int res = 0;
    for (unsigned int i = 2; i < amicable.size(); ++i) {
        if (amicable[i]) {
            res += i;
        }
    }

    std::cout << res << std::endl;
}