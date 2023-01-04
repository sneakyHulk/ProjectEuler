#include <iostream>
#include <range/v3/view/cartesian_product.hpp>

template<typename ...T>
void print_values(T const... values) {
    (std::cout << ... << values) << std::endl;
}

template<typename ...T>
auto get_range(T... values) {
    return ranges::v3::view::cartesian_product(values...);
}

std::array<unsigned int, 7> get_value(size_t const) {
    return {1U, 2U, 5U, 10U, 20U, 50U, 100U};
}

template<std::size_t N, std::size_t... I>
void func(std::index_sequence<I...>) {
    auto range = get_range(get_value(I)...);

    for (auto const &e: range) {
        ((std::cout << std::get<I>(e) << ' '), ...) << std::endl;
    }
}

template<std::size_t N, typename Indices = std::make_index_sequence<N>>
auto sequence() {
    return func<N>(Indices{});
}

template<size_t N>
unsigned int combinations(unsigned int const pence, unsigned int coins) {
    if (N == 1) return 0;
    //combinations<N - 1>()
}

template<std::size_t N, std::size_t VAL>
bool combinations(unsigned int &index, std::array<unsigned int, N> indices) {
    static std::array<unsigned int, 8> arr = {1U, 2U, 5U, 10U, 20U, 50U, 100U, 200U};
    if (index == 8) index = 0;
    if (N == 1) {
        //return value + arr[index++] == VAL;
    } else {

    }
}

uint64_t int_power(uint64_t const a, unsigned int b) {
    uint64_t res = 1;
    while (b--) {
        res *= a;
    }

    return res;
}

int main() {
    //std::cout << int_power(8, 20) << std::endl;

    //sequence<10>();

    std::vector<unsigned int> multipliers(3);
    multipliers[0] = 1;
    for (unsigned int i = 1; i < 3; ++i) {
        multipliers[i] = multipliers[i - 1] * 8;
    }

    unsigned int i = 0;
    while (++i) {
        unsigned int test = 0;
        for (unsigned int j = 0; j < 3; ++j) {
            unsigned int tmp = i / multipliers[j] % 8;
            if (tmp == 7) ++test;
            std::cout << tmp;
        }

        if (test == 3) break;
        std::cout << std::endl;
    }


    //for(uint64_t i = 0; i < )


    //std::array<unsigned int, 7> tmp = {1U, 2U, 5U, 10U, 20U, 50U, 100U};
    //std::vector<int> data1{1, 5, 2, 7, 6, 3, 4, 8, 9, 0};
    //std::vector<int> data2{1, 5, 2, 7, 6, 3, 4, 8, 9, 0};
    //auto range = ranges::v3::view::cartesian_product(data1, data2);
//
    //auto range2 = ranges::v3::view::cartesian_product(tmp,
    //                                                  tmp); //{1U, 2U, 5U, 10U, 20U, 50U, 100U}, {1U, 2U, 5U, 10U, 20U, 50U, 100U});
}