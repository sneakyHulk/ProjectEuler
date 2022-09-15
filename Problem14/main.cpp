#include <iostream>
#include <cstdint>
#include <limits>

template<typename T>
class max_value {
    static T _max_value;
public:
    void test_value(T const &value, T const &start_value) {
        if (value > _max_value) {
            _max_value = value;
            std::cout << value << " -> " << start_value << std::endl;
        }
    }

    T get_max_value() {
        return _max_value;
    }
};

template<typename T>
T max_value<T>::_max_value = std::numeric_limits<T>::min();

int main() {
    max_value<uint32_t> max;

    for (unsigned int start = 1; start < 1000000; ++start) {
        uint64_t n = start;
        uint32_t sum = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            ++sum;
        }
        max.test_value(sum, start);
    }
}