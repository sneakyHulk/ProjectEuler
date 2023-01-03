#include <iostream>
#include <vector>
#include <numeric>
#include "bigint.h"
#include <regex>

int main() {
    bigint one("10000");
    bigint hundred(100);

    unsigned int max = 0;
    unsigned int max_index = 0;
    std::regex word_regex("([0-9]+?)\\1+$");
    for (unsigned int i = 2; i < 1000; ++i) {
        bigint divisor = bigint(i);
        bigint erg = one / divisor;
        one *= hundred;

        for (std::sregex_iterator it = std::sregex_iterator(erg.str.begin(), erg.str.end(), word_regex); it != std::sregex_iterator(); ++it) {
            if(it->str(1).size() > max) {
                max = it->str(1).size();
                max_index = i;

                std::cout << "new max: " << max << ", index: " << max_index << std::endl;
            }
        }
    }

    std::cout << "one size: " << one.str.size() << std::endl;
    std::cout << "max: " << max << std::endl;
    std::cout << "max index: " << max_index << std::endl;
}