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

  for (auto i = 2; i <= 1000000; ++i) {
    if (is_prime(i))
      primes.push_back(i);
  }

  auto max_value = 0;
  auto max_consecutive = 1;
  for (auto i = 0; i < primes.size(); ++i) {
    auto value = primes[i];
    auto consecutive = 1;
    for (auto j = i + 1; j < primes.size(); ++j) {
      value += primes[j];
      ++consecutive;
      if (value > 1000000)
        break;
      if (is_prime(value) && max_consecutive <= consecutive) {
        max_consecutive = consecutive;
        max_value = value;

        std::cout << max_consecutive << ", " << max_value << std::endl;
      }
    }
  }

  std::cout << max_consecutive << ", " << max_value << std::endl;

  return 0;
}