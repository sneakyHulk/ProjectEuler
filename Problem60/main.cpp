#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <string>
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

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
  u64 result = 1;
  base %= mod;
  while (e) {
    if (e & 1)
      result = (u128)result * base % mod;
    base = (u128)base * base % mod;
    e >>= 1;
  }
  return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
  u64 x = binpower(a, d, n);
  if (x == 1 || x == n - 1)
    return false;
  for (int r = 1; r < s; r++) {
    x = (u128)x * x % n;
    if (x == n - 1)
      return false;
  }
  return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
  if (n < 2)
    return false;

  int r = 0;
  u64 d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a)
      return true;
    if (check_composite(n, a, d, r))
      return false;
  }
  return true;
}

bool MillerRabin(int n) { // returns true if n is prime, else returns false.
  if (n < 2)
    return false;

  int r = 0;
  u64 d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for (int a : {2, 3, 5, 7}) {
    if (n == a)
      return true;
    if (check_composite(n, a, d, r))
      return false;
  }
  return true;
}

// std::uint64_t concat(std::uint64_t a, std::uint64_t b) {
//   return std::stoull(std::to_string(a) + std::to_string(b));
// }
int concat(int a, int b) {
  return std::stoi(std::to_string(a) + std::to_string(b));
}

struct node {
  int prime;
  std::vector<node *> adj;
};

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

extern "C" {

// a list of edges, where index_offset is the starting index
int max_clique(long long nedges, int *ei, int *ej, int index_offset,
               int outsize, int *clique);
};

int main2() {
  std::vector<int> ei;
  std::vector<int> ej;
  std::vector<int> primes;
  for (int i = 0; i < 21474; ++i) {
    if (is_prime(i)) {
      for (auto p : primes) {
        auto test1 = std::stoi(std::to_string(i) + std::to_string(p));
        auto test2 = std::stoi(std::to_string(p) + std::to_string(i));
        if (is_prime(test1) && is_prime(test2)) {
          ei.push_back(p);
          ej.push_back(i);
        }
      }
      primes.push_back(i);
    }
  }

  // std::sort(ej.begin(), ej.end(), [&ei, &ej](auto const &i, auto const &j) {
  //   return ei[&i - ej.data()] < ei[&j - ej.data()];
  // });
  // std::sort(ei.begin(), ei.end());

  std::ranges::sort(std::ranges::views::zip(ei, ej), [](auto a, auto b) {
    return std::get<0>(a) == std::get<0>(b) ? std::get<1>(a) < std::get<1>(b)
                                            : std::get<0>(a) < std::get<0>(b);
  });

  int output[] = {0, 0, 0, 0, 0};

  int C = max_clique(ei.size(), ej.data(), ei.data(), 1, 5, output);
  std::cout << C << std::endl;

  return 0;
}

int main() {
  // std::vector<bool> primes1(10000 - 1000);
  // std::vector<bool> primes2(10000 - 1000);
  //
  // for (auto i = 10000; i < 10000; ++i) {
  //  primes1[i - 10000] = MillerRabin(i);
  //  primes2[i - 10000] = is_prime(i);
  //}
  //
  // std::cout << std::boolalpha << (primes1 == primes2) << std::endl;

  // std::vector<node *> nodes;
  // for (int i = 0; i < 100; ++i) {
  //   if (is_prime(i)) {
  //     auto new_node = new node{i, {}};
  //     for (auto n : nodes) {
  //       auto test1 = std::stoi(std::to_string(i) +
  //       std::to_string(n->prime)); auto test2 =
  //       std::stoi(std::to_string(n->prime) + std::to_string(i)); if
  //       (is_prime(test1) && is_prime(test2)) {
  //         n->adj.push_back(new_node);
  //         new_node->adj.push_back(n);
  //       }
  //     }
  //     nodes.push_back(new_node);
  //   }
  // }
  //
  // for (auto e : nodes) {
  //  for (auto a : e->adj) {
  //    std::cout << e->prime << " " << a->prime << std::endl;
  //  }
  //}

  // int max = 2147483647 -> with concat max number is 21474
  std::vector<int> primes;
  for (auto i = 2; i < 21474 / 2; ++i) {
    if (MillerRabin(i))
      primes.push_back(i);
  }

  std::vector<std::tuple<int, int>> prime_pairs;
  std::vector<int> candidates;
  for (auto i = 0; i < primes.size(); ++i) {
    for (auto ii = i + 1; ii < primes.size(); ++ii) {
      if (MillerRabin(concat(primes[i], primes[ii])) &&
          MillerRabin(concat(primes[ii], primes[i]))) {
        prime_pairs.emplace_back(primes[i], primes[ii]);
      }
    }
  }

  std::cout << prime_pairs.size() << std::endl;

  std::vector<std::tuple<int, int, int>> prime_triples;
  for (auto const [first, second] : prime_pairs) {
    for (auto const p : primes) {
      if (MillerRabin(concat(first, p)) && MillerRabin(concat(p, first)) &&
          MillerRabin(concat(second, p)) && MillerRabin(concat(p, second))) {
        prime_triples.emplace_back(first, second, p);
        std::cout << first << ", " << second << ", " << p << std::endl;
      }
    }
  }

  std::vector<std::tuple<int, int, int, int>> prime_quadruples;
  for (auto const [first, second, third] : prime_triples) {
    for (auto const p : primes) {
      if (MillerRabin(concat(first, p)) && MillerRabin(concat(p, first)) &&
          MillerRabin(concat(second, p)) && MillerRabin(concat(p, second)) &&
          MillerRabin(concat(third, p)) && MillerRabin(concat(p, third))) {
        prime_quadruples.emplace_back(first, second, third, p);
        std::cout << first << ", " << second << ", " << third << ", " << p
                  << std::endl;
      }
    }
  }

  std::vector<std::tuple<int, int, int, int, int>> prime_quintuples;
  for (auto const [first, second, third, forth] : prime_quadruples) {
    for (auto const p : primes) {
      if (MillerRabin(concat(first, p)) && MillerRabin(concat(p, first)) &&
          MillerRabin(concat(second, p)) && MillerRabin(concat(p, second)) &&
          MillerRabin(concat(third, p)) && MillerRabin(concat(p, third)) &&
          MillerRabin(concat(forth, p)) && MillerRabin(concat(p, forth))) {
        prime_quintuples.emplace_back(first, second, third, forth, p);
        std::cout << first << ", " << second << ", " << third << ", " << forth
                  << ", " << p << " = " << first + second + third + forth + p
                  << std::endl;
      }
    }
  }

  return 0;

  for (auto e1 : primes) {
    for (auto e2 : primes) {
      for (auto e3 : primes) {
        if (MillerRabin(concat(e1, e2)) && MillerRabin(concat(e2, e1)) &&
            MillerRabin(concat(e3, e1)) && MillerRabin(concat(e1, e3)) &&
            MillerRabin(concat(e2, e3)) && MillerRabin(concat(e3, e2))) {
          std::cout << e1 << ", " << e2 << ", " << e3 << std::endl;
        }
      }
    }
  }

  return 0;

  std::vector<std::vector<std::uint64_t>> cliques;
  for (std::uint64_t i = 2; i < 107623; ++i) {
    if (is_prime(i)) {
      for (auto &c : cliques) {
        bool add_to_cliquee = true;
        for (auto e : c) {
          if (!MillerRabin(concat(i, e))) {
            add_to_cliquee = false;
            break;
          }
          if (!MillerRabin(concat(e, i))) {
            add_to_cliquee = false;
            break;
          }
        }
        if (add_to_cliquee)
          c.push_back(i);
      }
      cliques.push_back({i});
    }
  }

  for (auto const &c : cliques) {
    if (c.size() >= 5) {
      std::uint64_t sum = 0;
      for (auto e : c) {
        std::cout << e << ", ";
        sum += e;
      }
      std::cout << " = " << sum << std::endl;
    }
  }

  return 0;
}