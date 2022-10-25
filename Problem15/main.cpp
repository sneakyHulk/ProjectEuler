#include <iostream>
#include <cstdint>

int64_t nCr(int64_t n, int64_t r) {
    if (r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    int64_t ans = 1;
    int64_t i;

    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

// Driver code
int main() {
    int64_t n = 40, r = 20;
    std::cout << nCr(n, r) << std::endl;
    return 0;
}