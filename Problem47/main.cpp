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

long long mult(long long a, long long b, long long mod) {
  long long result = 0;
  while (b) {
    if (b & 1)
      result = (result + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return result;
}

long long f(long long x, long long c, long long mod) {
  return (mult(x, x, mod) + c) % mod;
}

long long rho(long long n, long long x0 = 2, long long c = 1) {
  long long x = x0;
  long long y = x0;
  long long g = 1;
  while (g == 1) {
    x = f(x, c, n);
    y = f(y, c, n);
    y = f(y, c, n);
    g = std::gcd(std::abs(x - y), n);
  }
  return g;
}

long long brent(long long n, long long x0 = 2, long long c = 1) {
  long long x = x0;
  long long g = 1;
  long long q = 1;
  long long xs, y;

  int m = 128;
  int l = 1;
  while (g == 1) {
    y = x;
    for (int i = 1; i < l; i++)
      x = f(x, c, n);
    int k = 0;
    while (k < l && g == 1) {
      xs = x;
      for (int i = 0; i < m && i < l - k; i++) {
        x = f(x, c, n);
        q = mult(q, std::abs(y - x), n);
      }
      g = std::gcd(q, n);
      k += m;
    }
    l *= 2;
  }
  if (g == n) {
    do {
      xs = f(xs, c, n);
      g = std::gcd(std::abs(xs - y), n);
    } while (g == 1);
  }
  return g;
}

int prime_factors(long long n) {
  std::vector<long long> factors;
  factors.reserve(100);

  long long factor;
  int i = 0;
  do {
    n /= factor = rho(n);
    if (!std::count(factors.begin(), factors.end(), factor)) {
      factors.push_back(factor);
      ++i;
    }
  } while (n > 1);

  return i;
}

void prime_factors2(long long n) {
  long long factor;
  do {
    n /= factor = rho(n);
    std::cout << factor << ", ";
  } while (n > 1);

  std::cout << std::endl;
}

void distinctPrimeFactors(int N) {
  if (N < 2) {
    std::cout << -1;
    return;
  }
  if (N == 2) {
    std::cout << 2;
    return;
  }

  std::unordered_map<int, bool> visited;

  for (int i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      if (!visited[i]) {
        std::cout << i << " ";
        visited[i] = 1;
      }
      N /= i;
    }
  }
  if (N > 2)
    std::cout << N;
}

// int main() {
//   int N = 253894;
//   distinctPrimeFactors(N);
//   return 0;
// }

auto const N = 500000;
std::array<int, N> primes{};

std::set<int> get_prime_factors(auto n) {
  std::set<int> factors;
  while (n > 1) {
    for (auto i = 0; i < N; ++i) {
      if (n % primes[i] == 0) {
        n /= primes[i];
        factors.insert(primes[i]);
        break;
      }
    }
  }

  return factors;
}

int main() {
  for (auto i = 0, j = 2; i < primes.size(); ++j) {
    if (is_prime(j))
      primes[i++] = j;
  }

  for (auto i = 0; i < N; ++i) {
    if (get_prime_factors(i).size() == 4) {
      if (get_prime_factors(i + 1).size() == 4) {
        if (get_prime_factors(i + 2).size() == 4) {
          if (get_prime_factors(i + 3).size() == 4) {
            for (auto j = 0; j < 4; ++j) {
              std::cout << i + j << ": ";
              for (auto e : get_prime_factors(i + j)) {
                std::cout << e << " ";
              }
              std::cout << std::endl;
            }
          }
        }
      }
    }
  }

  return 0;
}

/*

int main() {
  for (auto i = 2; i < 2000000; ++i) {
    if (prime_factors(i) == 4) {
      if (prime_factors(i + 1) == 4) {
        if (prime_factors(i + 2) == 4) {
          if (prime_factors(i + 3) == 4) {
            prime_factors2(i);
            prime_factors2(i + 1);
            prime_factors2(i + 2);
            prime_factors2(i + 3);

            std::cout << i << std::endl;
          }
        }
      }
    }
  }
}*/