#include <iostream>
#include <cstdint>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

template<char ...Delims>
struct custom_delimiter : std::ctype<char> {
public:
    custom_delimiter() : std::ctype<char>(get_table()) {}

    static mask const *get_table() {
        static mask rc[table_size];
        for (char delim: {Delims...}) {
            rc[delim] = std::ctype_base::space;
        }
        return &rc[0];
    }
};

int main() {
    std::ifstream in("words.txt");
    in.imbue(std::locale(in.getloc(), new custom_delimiter<' ', ',', '\"', '\n'>));

    std::vector<unsigned int> words_value;
    std::string word;
    while (in >> word) {
        words_value.push_back(0U);
        for (char const e: word) {
            words_value.back() += e - 'A' + 1;
        }
    }

    unsigned int const max_value = *std::max_element(words_value.begin(), words_value.end());

    std::set<unsigned int> triangle_numbers;

    for (unsigned int i = 1; true; ++i) {
        unsigned int const triangle_number = ((i + 1) * i) / 2;
        if (triangle_number > max_value) break;
        triangle_numbers.insert(triangle_number);
    }

    unsigned int sum = 0U;
    for (unsigned int const e: words_value) {
        if (triangle_numbers.contains(e)) ++sum;
    }

    std::cout << sum << std::endl;
}