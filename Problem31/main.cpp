#include <iostream>
#include <array>
#include <vector>
//#include <range/v3/view/cartesian_product.hpp>

//template<typename ...T>
//void print_values(T const... values) {
//    (std::cout << ... << values) << std::endl;
//}
//
//template<typename ...T>
//auto get_range(T... values) {
//    //return ranges::v3::view::cartesian_product(values...);
//}
//
//std::array<unsigned int, 7> get_value(size_t const) {
//    return {1U, 2U, 5U, 10U, 20U, 50U, 100U};
//}
//
//template<std::size_t N, std::size_t... I>
//void func(std::index_sequence<I...>) {
//    auto range = get_range(get_value(I)...);
//
//    for (auto const &e: range) {
//        ((std::cout << std::get<I>(e) << ' '), ...) << std::endl;
//    }
//}
//
//template<std::size_t N, typename Indices = std::make_index_sequence<N>>
//auto sequence() {
//    return func<N>(Indices{});
//}
//
//template<size_t N>
//unsigned int combinations(unsigned int const pence, unsigned int coins) {
//    if (N == 1) return 0;
//    //combinations<N - 1>()
//}
//
//template<std::size_t N, std::size_t VAL>
//bool combinations(unsigned int &index, std::array<unsigned int, N> indices) {
//
//    if (index == 8) index = 0;
//    if (N == 1) {
//        //return value + arr[index++] == VAL;
//    } else {
//
//    }
//}
//
//uint64_t int_power(uint64_t const a, unsigned int b) {
//    uint64_t res = 1;
//    while (b--) {
//        res *= a;
//    }
//
//    return res;
//}
//void get_combinations(unsigned int const value, unsigned int &combinations) {
//    static const std::array<unsigned int, 8> arr = {1U, 2U, 5U, 10U, 20U, 50U, 100U, 200U};
//    if (value > 6) return;
//    if (value == 6) {
//        ++combinations;
//        return;
//    }
//    for (unsigned int const e: arr) {
//        get_combinations(value + e, combinations);
//    }
//}


int main() {
    unsigned int combinations = 0;
    unsigned int const max_value = 200;
    unsigned int const ergiiiiiiiii = 0;
    for (uint64_t iiiiiiii = 0; ergiiiiiiiii + iiiiiiii * 200 <= max_value; ++iiiiiiii) { // £2
        unsigned int const ergiiiiiiii = ergiiiiiiiii + iiiiiiii * 200;
        for (uint64_t iiiiiii = 0; ergiiiiiiii + iiiiiii * 100 <= max_value; ++iiiiiii) { // £1
            unsigned int const ergiiiiiii = ergiiiiiiii + iiiiiii * 100;
            for (uint64_t iiiiii = 0; ergiiiiiii + iiiiii * 50 <= max_value; ++iiiiii) { // 50p
                unsigned int const ergiiiiii = ergiiiiiii + iiiiii * 50;
                for (uint64_t iiiii = 0; ergiiiiii + iiiii * 20 <= max_value; ++iiiii) { // 20p
                    unsigned int const ergiiiii = ergiiiiii + iiiii * 20;
                    for (uint64_t iiii = 0; ergiiiii + iiii * 10 <= max_value; ++iiii) { // 10p
                        unsigned int const ergiiii = ergiiiii + iiii * 10;
                        for (uint64_t iii = 0; ergiiii + iii * 5 <= max_value; ++iii) { // 5p
                            unsigned int const ergiii = ergiiii + iii * 5;
                            for (uint64_t ii = 0; ergiii + ii * 2 <= max_value; ++ii) { // 2p
                                unsigned int const ergii = ergiii + ii * 2;
                                for (uint64_t i = 0; ergii + i * 1 <= max_value; ++i) { // 1p
                                    unsigned int const ergi = ergii + i * 1;

                                    if (ergi == 200) {
                                        ++combinations;
                                        //std::cout << i << " * 1p + " << ii << " * 2p + " << iii << " * 5p + " << iiii << " * 10p" << std::endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << combinations << std::endl;















    //unsigned int combinations = 0;
    //get_combinations(0, combinations);
//
    //std::cout << combinations << std::endl;




    //std::cout << int_power(8, 20) << std::endl;

    //sequence<10>();

    //std::vector<unsigned int> multipliers(3);
    //multipliers[0] = 1;
    //for (unsigned int i = 1; i < 3; ++i) {
    //    multipliers[i] = multipliers[i - 1] * 8;
    //}
//
    //unsigned int i = 0;
    //while (++i) {
    //    unsigned int test = 0;
    //    for (unsigned int j = 0; j < 3; ++j) {
    //        unsigned int tmp = i / multipliers[j] % 8;
    //        if (tmp == 7) ++test;
    //        std::cout << tmp;
    //    }
//
    //    if (test == 3) break;
    //    std::cout << std::endl;
    //}


    //for(uint64_t i = 0; i < )


    //std::array<unsigned int, 7> tmp = {1U, 2U, 5U, 10U, 20U, 50U, 100U};
    //std::vector<int> data1{1, 5, 2, 7, 6, 3, 4, 8, 9, 0};
    //std::vector<int> data2{1, 5, 2, 7, 6, 3, 4, 8, 9, 0};
    //auto range = ranges::v3::view::cartesian_product(data1, data2);
//
    //auto range2 = ranges::v3::view::cartesian_product(tmp,
    //                                                  tmp); //{1U, 2U, 5U, 10U, 20U, 50U, 100U}, {1U, 2U, 5U, 10U, 20U, 50U, 100U});
}