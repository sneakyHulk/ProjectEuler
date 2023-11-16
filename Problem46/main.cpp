#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

bool is_prime2(int n) {
  for (int i = 2; i < sqrt(n) + 1; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

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

bool is_odd(int n) { return n % 2; }

int main() {
  std::vector<int> twice_a_squares;
  std::vector<int> odd_composites;
  std::vector<int> primes;
  twice_a_squares.reserve(100000);
  odd_composites.reserve(100000);
  primes.reserve(100000);
  primes.push_back(2);

  // for (auto i = 2; i < 200000; ++i) {
  //   if (is_odd(i)) {
  //     if (is_prime(i)) {
  //       primes.push_back(i);
  //     } else {
  //       odd_composites.push_back(i);
  //     }
  //   }
  // }

  for (auto i = 1; i < 1000; ++i) {
    twice_a_squares.push_back(i * i * 2);
  }

  std::cout << twice_a_squares.back() << std::endl;

  auto check = [&twice_a_squares](int composite) {
    for (auto e : twice_a_squares) {
      if (composite - e < 2)
        continue;
      else if (is_prime(composite - e)) {
        std::cout << composite << " = " << composite - e << " + " << e
                  << std::endl;
        return true;
      }
    }

    return false;
  };

  for (auto i = 2; i < twice_a_squares.back(); ++i) {
    if (is_odd(i) && !is_prime(i)) {
      if (!check(i)) {
        std::cout << "found! " << i << std::endl;
        return 0;
      }
    }
  }

  return 0;
}