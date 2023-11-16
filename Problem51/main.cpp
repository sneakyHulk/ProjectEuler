#include <algorithm>
#include <array>
#include <iostream>
#include <set>
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
  for (auto i = 0; i <= 9; ++i) {
    for (auto ii = 0; ii <= 9; ++ii) {
      for (auto iii = 0; iii <= 9; ++iii) {
        for (auto iiii = 0; iiii <= 9; ++iiii) {
          for (auto iiiii = 1; iiiii <= 9; ++iiiii) {
            for (auto iiiiii = 1; iiiiii <= 9; ++iiiiii) {
              for (auto j = 1; j < (1 << 6); ++j) {
                auto count = 0;
                for (auto k = 0; k <= 9; ++k) {
                  auto num = ((j & 1) ? k : i) +
                             10 * ((j & (1 << 1)) ? k : ii) +
                             100 * ((j & (1 << 2)) ? k : iii) +
                             1000 * ((j & (1 << 3)) ? k : iiii) +
                             10000 * ((j & (1 << 4)) ? k : iiiii) +
                             100000 * ((j & (1 << 5)) ? k : iiiiii);
                  // std::cout << num << std::endl;
                  if (is_prime(num))
                    ++count;
                }
                if (count > 7) {
                  for (auto k = 0; k <= 9; ++k) {
                    auto num = ((j & 1) ? k : i) +
                               10 * ((j & (1 << 1)) ? k : ii) +
                               100 * ((j & (1 << 2)) ? k : iii) +
                               1000 * ((j & (1 << 3)) ? k : iiii) +
                               10000 * ((j & (1 << 4)) ? k : iiiii) +
                               100000 * ((j & (1 << 5)) ? k : iiiiii);
                    if (is_prime(num))
                      std::cout << num << ", ";
                  }
                  std::cout << std::endl;
                }
              }
            }
          }
        }
      }
    }
  }

  /*for (auto digits = 1, i = 10; digits < 2; i *= 10, ++digits) {
    std::vector<int> primes;
    for (auto j = i; j < i * 10; ++j) {
      if (is_prime(j))
        primes.push_back(j);
    }

    for (auto digit = 0; digit <= digits; ++digit) {
    }

    for (auto e : primes) {
      for (auto digit = 0; digit <= digits; ++digit) {
        auto placeholder = get_digit(e, digit);
        auto count = std::count_if(primes.begin(), primes.end(),
                                   [placeholder, digit](auto i) {
                                     return get_digit(i, digit) ==
  placeholder;
                                   });
        if (count < 8)
          continue;
        if (count == 8) {
          auto num = 0;
          for (auto pos = 0, j = 1; pos < digits; ++pos) {
            if (pos == digit)
              continue;
            num += get_digit(e, pos) * (j *= 10);
          }
          std::cout << num << std::endl;

          std::cout << placeholder << " (";
          std::for_each(primes.begin(), primes.end(),
                        [placeholder, digit](auto i) {
                          if (get_digit(i, digit) == placeholder)
                            std::cout << i << ", ";
                        });
          std::cout << ") " << std::endl;
          return 0;
        }
        for (auto digit2 = 0; digit2 <= digits; ++digit2) {
          if (digit == digit2)
            continue;
          auto count2 =
              std::count_if(primes.begin(), primes.end(),
                            [placeholder, digit, digit2](auto i) {
                              return get_digit(i, digit) == placeholder &&
                                     get_digit(i, digit2) == placeholder;
                            });
          if (count2 < 8)
            continue;
          if (count2 == 8) {
            auto num = 0;
            for (auto pos = 0, j = 1; pos < digits; ++pos) {
              if (pos == digit || pos == digit2)
                continue;
              num += get_digit(e, pos) * (j *= 10);
            }
            std::cout << num << std::endl;

            std::cout << placeholder << " (";
            std::for_each(primes.begin(), primes.end(),
                          [placeholder, digit, digit2](auto i) {
                            if (get_digit(i, digit) == placeholder &&
                                get_digit(i, digit2) == placeholder)
                              std::cout << i << ", ";
                          });
            std::cout << ") " << std::endl;
            return 0;
          }
          for (auto digit3 = 0; digit3 <= digits; ++digit3) {
            if (digit == digit3 || digit2 == digit3)
              continue;
            auto count3 =
                std::count_if(primes.begin(), primes.end(),
                              [placeholder, digit, digit2, digit3](auto i) {
                                return get_digit(i, digit) == placeholder &&
                                       get_digit(i, digit2) == placeholder &&
                                       get_digit(i, digit3) == placeholder;
                              });
            if (count3 < 8)
              continue;
            if (count3 == 8) {
              auto num = 0;
              for (auto pos = 0, j = 1; pos < digits; ++pos) {
                if (pos != digit || pos != digit2 || pos != digit3)
                  continue;
                num += get_digit(e, pos) * j;
                j *= 10;
              }
              std::cout << num << std::endl;

              std::cout << placeholder << " (";
              std::for_each(primes.begin(), primes.end(),
                            [placeholder, digit, digit2, digit3](auto i) {
                              if (get_digit(i, digit) == placeholder &&
                                  get_digit(i, digit2) == placeholder &&
                                  get_digit(i, digit3) == placeholder)
                                std::cout << i << ", ";
                            });
              std::cout << ") " << std::endl;
              //return 0;
            }
          }
        }
      }
    }


    for (auto j = 0; j <= digits; ++j) {
      for (auto e : primes) {
        auto count = std::count_if(primes.begin(), primes.end(),
                                   [dig = get_digit(e, j), j](auto i) {
                                     return get_digit(i, j) == dig;
                                   });
        if (count == 8) {
          std::cout << e << ", " << count << ", " << get_digit(e, j) << ", ";

          std::for_each(primes.begin(), primes.end(),
                        [dig = get_digit(e, j), j](auto i) {
                          if (get_digit(i, j) == dig)
                            std::cout << i << ", ";
                        });
          std::cout << std::endl;
          return 0;
        } else if (count > 8) {
          for (auto jj = 0; jj <= digits; ++jj) {
            if (jj == j)
              continue;
            if (get_digit(e, j) != get_digit(e, jj))
              continue;
            count = std::count_if(primes.begin(), primes.end(),
                                  [dig = get_digit(e, j), j,
                                   dig2 = get_digit(e, jj), jj](auto i) {
                                    return get_digit(i, j) == dig &&
                                           get_digit(i, jj) == dig2;
                                  });
            if (count == 8) {
              std::cout << e << ", " << count << " (" << get_digit(e, j) << ",
  "
                        << get_digit(e, jj) << "), ";
              std::count_if(primes.begin(), primes.end(),
                            [dig = get_digit(e, j), j, dig2 = get_digit(e,
  jj), jj](auto i) { if (get_digit(i, j) == dig && get_digit(i, jj) == dig2) {
                                std::cout << i << ", ";
                                return true;
                              }
                              return false;
                            });
              std::cout << std::endl;

              return 0;
            } else if (count > 8) {
              for (auto jjj = 0; jjj <= digits; ++jjj) {
                if (jjj == j || jjj == jj)
                  continue;
                count = std::count_if(primes.begin(), primes.end(),
                                      [dig = get_digit(e, j), j,
                                       dig2 = get_digit(e, jj), jj,
                                       dig3 = get_digit(e, jjj), jjj](auto i)
  { return get_digit(i, j) == dig && get_digit(i, jj) == dig2 && get_digit(i,
  jjj) == dig3;
                                      });
                if (count == 8) {
                  std::cout << e << ", " << count << " (" << get_digit(e, j)
                            << ", " << get_digit(e, jj) << ", "
                            << get_digit(e, jjj) << ")" << std::endl;
                }
              }
            }
          }
        }
      }
    }
  }*/

  return 0;
}