#include <algorithm>
#include <array>
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

int main() {
  for (auto iiiiiii = 0; iiiiiii <= 1; ++iiiiiii) {
    for (auto iiiiii = 0; iiiiii <= 9; ++iiiiii) {
      for (auto iiiii = 0; iiiii <= 9; ++iiiii) {
        for (auto iiii = 0; iiii <= 9; ++iiii) {
          for (auto iii = 0; iii <= 9; ++iii) {
            for (auto ii = 0; ii <= 9; ++ii) {
              for (auto i = 0; i <= 9; ++i) {
                auto num = iiiiiii * 1000000 + iiiiii * 100000 + iiiii * 10000 +
                           iiii * 1000 + iii * 100 + ii * 10 + i;
                auto num_s = std::to_string(num);
                std::sort(num_s.begin(), num_s.end());

                auto num2 = num * 2;
                auto num2_s = std::to_string(num2);
                std::sort(num2_s.begin(), num2_s.end());

                auto num3 = num * 3;
                auto num3_s = std::to_string(num3);
                std::sort(num3_s.begin(), num3_s.end());

                auto num4 = num * 4;
                auto num4_s = std::to_string(num4);
                std::sort(num4_s.begin(), num4_s.end());

                auto num5 = num * 5;
                auto num5_s = std::to_string(num5);
                std::sort(num5_s.begin(), num5_s.end());

                auto num6 = num * 6;
                auto num6_s = std::to_string(num6);
                std::sort(num6_s.begin(), num6_s.end());

                if (num_s == num2_s && num_s == num3_s && num_s == num4_s && num_s == num5_s && num_s == num6_s) {
                  std::cout << num << std::endl;
                }
              }
            }
          }
        }
      }
    }
  }

  return 0;
}