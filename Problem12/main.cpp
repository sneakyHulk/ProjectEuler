#include <iostream>
#include <vector>

int main() {
    std::vector<uint64_t> triangle;
    triangle.reserve(10000000);

    triangle.push_back(1);

    for (unsigned int i = 2; i < 10000000; ++i) {
        triangle.push_back(triangle[i - 2] + i);
    }

    uint32_t sum = 0;

    for (unsigned int i = 0; i < triangle.size(); ++i) {
        for (unsigned int j = 2; j <= triangle[i] / 2 + 1; ++j) {
            if (triangle[i] % j == 0) {
                ++sum;
            }
        }

        if (sum + 2 > 500) {
            std::cout << triangle[i] << " -> " << sum + 2 << std::endl;
        }

        sum = 0;
    }

    return 0;
}