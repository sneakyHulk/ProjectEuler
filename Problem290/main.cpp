#include <iostream>
#include <cstdint>
#include <limits>

template<typename T>
class max_value {
    static T _max_value;
public:
    void test_value(T const &value) {
        if (value > _max_value) {
            _max_value = value;
        }
    }

    T get_max_value() {
        return _max_value;
    }
};

template<typename T>
T max_value<T>::_max_value = std::numeric_limits<T>::min();

uint8_t get_sum_of_digits(uint64_t uint) {
    uint8_t sum = 0U;

    while (uint > 0) {
        sum += uint % 10;
        uint /= 10;
    }

    return sum;
}

constexpr unsigned int cache_size = (18 + 1) * 137 * (2 * 116 + 1);

uint64_t cache[cache_size];

static max_value<uint32_t> tmp;

uint64_t recursive_search_of_numbers(uint8_t potenz, uint32_t u = 0U, int32_t v = 0) {
    uint64_t result = 0U;

    tmp.test_value(u);

    uint32_t cache_id = (potenz * 137 + u) * 233 + v + 116;

    if (cache[cache_id] != UINT64_MAX) {
        return cache[cache_id];
    }

    if (potenz == 1) {
        for (uint64_t ziffer = 0; ziffer <= 9; ++ziffer) {
            if (get_sum_of_digits(137U * ziffer + u) + v == ziffer) {
                result++;
            }
        }

        cache[cache_id] = result;
        return result;
    }

    for (uint64_t ziffer = 0; ziffer <= 9; ++ziffer) {
        uint64_t value_1 = (137U * ziffer + u) / 10U;
        int64_t value_2 = (137U * ziffer + u) % 10U + v - ziffer;

        result += recursive_search_of_numbers(potenz - 1, value_1, value_2);
    }

    cache[cache_id] = result;
    return result;
}

int main() {
    for (unsigned int i = 0; i < cache_size; ++i) {
        cache[i] = UINT64_MAX;
    }

    std::cout << recursive_search_of_numbers(18) << std::endl;

    unsigned int anzahl = 0U;
    for (unsigned int i = 0U; i < cache_size; ++i) {
        if (cache[i] != UINT64_MAX) {
            //std::cout << cache[i] << '\n';
            anzahl++;
        }
    }
    std::cout << anzahl << '\n';
    std::cout << tmp.get_max_value() << '\n';

    /*
     * naiver Ansatz:
     *

     for (uint64_t i = 0; i <= 100000000000U; i += 9) { // 17 nullen 100000000000000000U
         uint8_t a = get_sum_of_digits(i);
         uint8_t b = get_sum_of_digits(i * 137);

         if (a == b) {
             ++anzahl;
         }
     }

     std::cout << anzahl << std::endl;

     */
}