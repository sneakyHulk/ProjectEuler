#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>

unsigned int get_number(unsigned int number) {
    static std::vector<std::string> x = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    static std::vector<std::string> z = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                                         "seventeen",
                                         "eighteen", "nineteen"};

    int num_digits = floor(log10(abs(number ? number : 1)) + 1);


    for (; num_digits; num_digits--, number /= 10) {
        std::cout << number % 10 << " ";
    }


}


int main() {
    std::vector<std::string> x = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> y = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::vector<std::string> z = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                                  "eighteen", "nineteen"};
    std::vector<std::string> a = {"hundred"};
    std::vector<std::string> b = {"and"};
    std::vector<std::string> c = {"onethousand"};

    unsigned int res10 = 0;

    res10 += x[0].size();
    res10 += x[1].size();
    res10 += x[2].size();
    res10 += x[3].size();
    res10 += x[4].size();
    res10 += x[5].size();
    res10 += x[6].size();
    res10 += x[7].size();
    res10 += x[8].size();

    std::cout << res10 << std::endl;

    unsigned int res100 = 0;

    res100 += res10;

    res100 += z[0].size();
    res100 += z[1].size();
    res100 += z[2].size();
    res100 += z[3].size();
    res100 += z[4].size();
    res100 += z[5].size();
    res100 += z[6].size();
    res100 += z[7].size();
    res100 += z[8].size();
    res100 += z[9].size();

    res100 += 10 * y[0].size() + res10;
    res100 += 10 * y[1].size() + res10;
    res100 += 10 * y[2].size() + res10;
    res100 += 10 * y[3].size() + res10;
    res100 += 10 * y[4].size() + res10;
    res100 += 10 * y[5].size() + res10;
    res100 += 10 * y[6].size() + res10;
    res100 += 10 * y[7].size() + res10;

    std::cout << res100 << std::endl;

    unsigned int res1000 = 0;

    res1000 += res100 * 10;

    res1000 += (x[0].size() + a[0].size()) * 100 + b[0].size() * 99;
    res1000 += (x[1].size() + a[0].size()) * 100 + b[0].size() * 99;
    res1000 += (x[2].size() + a[0].size()) * 100 + b[0].size() * 99;
    res1000 += (x[3].size() + a[0].size()) * 100 + b[0].size() * 99;
    res1000 += (x[4].size() + a[0].size()) * 100 + b[0].size() * 99;
    res1000 += (x[5].size() + a[0].size()) * 100 + b[0].size() * 99;
    res1000 += (x[6].size() + a[0].size()) * 100 + b[0].size() * 99;
    res1000 += (x[7].size() + a[0].size()) * 100 + b[0].size() * 99;
    res1000 += (x[8].size() + a[0].size()) * 100 + b[0].size() * 99;

    res1000 += c[0].size();

    std::cout << res1000 << std::endl;

}