#include <iostream>
#include <vector>
#include <fstream>
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
    std::ifstream in("names.txt");
    in.imbue(std::locale(in.getloc(), new custom_delimiter<' ', ',', '\"', '\n'>));

    std::vector<std::string> names;
    std::string name;
    while (in >> name) {
        names.push_back(name);
    }

    std::sort(names.begin(), names.end());

    unsigned int res = 0;
    for (int i = 0; i < names.size(); ++i) {
        unsigned int names_count = 0;
        for (auto const &c: names[i]) {
            names_count += c - 'A' + 1;
        }

        res += names_count * (i + 1);
    }

    std::cout << res << std::endl;

    return 0;
}