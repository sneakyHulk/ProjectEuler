#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

bool is_prime(int n) {
  if (n == 2 || n == 3)
    return true;

  if (n <= 1 || n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }

  return true;
}

auto int_power(auto const a, auto b) {
  auto res = 1;
  while (b--) {
    res *= a;
  }
  return res;
}

auto get_digit(auto value, auto n_digit) {
  return (value / int_power(10, n_digit)) % 10;
}

std::int64_t combi(std::int64_t n, std::int64_t k) {
  std::int64_t ans = 1;
  k = k > n - k ? n - k : k;
  std::int64_t j = 1;
  for (; j <= k; j++, n--) {
    if (n % j == 0) {
      ans *= n / j;
    } else if (ans % j == 0) {
      ans = ans / j * n;
    } else {
      ans = (ans * n) / j;
    }
  }
  return ans;
}

int main() {
  auto count = 0;
  for (auto n = 0; n <= 100; ++n) {
    for (auto r = 0; r < n; ++r) {
      if (combi(n, r) > 1000000) {
        count += n - 2 * r + 1;
        break;
      }
    }
  }

  std::cout << count << std::endl;

  // std::vector<std::vector<int>> triangle(101);
  // triangle[0].push_back(1);
  // for (auto n = 1; n < triangle.size(); ++n) {
  //   triangle[n].push_back(1);
  //   for (auto r = 1; r < n; ++r) {
  //     triangle[n].push_back(triangle[n - 1][r - 1] + triangle[n - 1][r]);
  //     if (triangle[n].back() > 1000000)
  //       std::cout << r << std::endl;
  //   }
  //   triangle[n].push_back(1);
  // }
  //
  // for (const auto &e : triangle) {
  //  for (auto ee : e) {
  //    // if (ee > 1000000)
  //    // std::cout << ee << std::endl;
  //  }
  //}

  return 0;
}