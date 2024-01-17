#include <BigInt.h>
#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <set>
#include <sstream>
#include <vector>

bool is_palindrome(std::string const &str) {
  std::string reverse_string = str;
  std::reverse(reverse_string.begin(), reverse_string.end());

  return str == reverse_string;
}

int main() {
  std::vector<int> lychrel;

  for (auto i = 1; i <= 10000; ++i) {
    BigInt kj = i;
    auto str = kj.to_string();
    std::reverse(str.begin(), str.end());
    BigInt jk = str;

    BigInt new_kj = kj, new_jk = jk;
    auto it = 50;

    do {
      if (it-- < 0) {
        lychrel.push_back(i);
        break;
      }

      new_kj = new_kj + new_jk;
      auto new_str = new_kj.to_string();
      std::reverse(new_str.begin(), new_str.end());
      new_jk = new_str;
    } while (new_jk != new_kj);
  }

  std::cout << lychrel.size() << std::endl;

  return 0;
}