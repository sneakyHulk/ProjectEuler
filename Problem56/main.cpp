#include <BigInt.h>
#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <set>
#include <sstream>
#include <vector>

auto comp_digit_sum(BigInt const &number) {
  auto res = 0;
  for (auto const e : number.to_string()) {
    res += e - '0';
  }
  return res;
}

int main() {
  auto max_digit_sum = 0;
  for (auto i = 1; i < 100; ++i) {
    for (auto j = 1; j < 100; ++j) {
      BigInt ii = i;
      BigInt kk = pow(ii, j);
      if (int const digit_sum = comp_digit_sum(kk); max_digit_sum < digit_sum)
        max_digit_sum = digit_sum;
      std::cout << i << "^" << j << std::endl;
    }
  }

  std::cout << max_digit_sum;

  return 0;
}