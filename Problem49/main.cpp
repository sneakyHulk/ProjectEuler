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

int main() {
  std::vector<int> primes;

  for (auto i = 1000; i <= 9999; ++i) {
    if (is_prime(i))
      primes.push_back(i);
  }

  for (auto i = 0; i < primes.size(); ++i) {
    for (auto j = i + 1; j < primes.size(); ++j) {
      auto diff = primes[j] - primes[i];
      for (auto k = j + 1; k < primes.size(); ++k) {
        if (diff == primes[k] - primes[j]) {
          std::set<int> si = {primes[i] % 10, (primes[i] / 10) % 10,
                              (primes[i] / 100) % 10, (primes[i] / 1000) % 10};
          std::set<int> sj = {primes[j] % 10, (primes[j] / 10) % 10,
                              (primes[j] / 100) % 10, (primes[j] / 1000) % 10};
          std::set<int> sk = {primes[k] % 10, (primes[k] / 10) % 10,
                              (primes[k] / 100) % 10, (primes[k] / 1000) % 10};
          if (si == sj && si == sk) {
            std::cout << primes[i] << ", " << primes[j] << ", " << primes[k]
                      << std::endl;
          }
        }
      }
    }
  }

  return 0;
}