#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <vector>

#include <BigInt.h>

void naive(auto n) {
  BigInt bg = 0;
  for (auto i = 1; i <= n; ++i) {
    bg += pow(BigInt(i), i);
  }

  std::cout << bg << std::endl;
}

void fast(auto n) {
  std::uint64_t res = 0;
  for (auto i = 1; i <= n; ++i) {
    std::uint64_t last = i;

    for (auto j = 1; j < i; ++j) {
      last = (last * i) % 10000000000;
    }

    res = (res + last) % 10000000000;
  }

  std::cout << res << std::endl;
}


int main() {
  //naive(1000);
  fast(1000);

  return 0;
}