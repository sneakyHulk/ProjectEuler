#include <TGraph.h>
#include <TROOT.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>
#include <chrono>
#include <thread>

std::uint64_t bitwise_xor(std::uint64_t const a, std::uint64_t const b) {
  return a ^ b;
}

constexpr bool get_digit(std::uint64_t const a, std::integral auto pos) {
  return a & (1ULL << pos);
}

std::uint64_t bitwise_xor_product(std::uint64_t const a,
                                  std::uint64_t const b) {
  std::uint64_t res;
  auto cutoff = 0;
  auto cutoff2 = 0;
  for (std::signed_integral auto i = 63; i >= 0; --i) {
    if (get_digit(b, i)) {
      if (!cutoff) {
        cutoff = i;
        res = a << i;
      } else {
        res ^= a << i;
      }
    }
    if (get_digit(a, i) && !cutoff2)
      cutoff2 = i;
  }

  return (res << (63 - cutoff2 - cutoff)) >> (63 - cutoff2 - cutoff);
}

int main(int argc, char **argv) {
  TApplication theApp("tapp", &argc, argv);
  // for (std::uint64_t i = 2; i < 10000; ++i) {
  //   std::cout << bitwise_xor_product(3, i) << " -> " <<
  //   std::bitset<8>(bitwise_xor_product(3, i)).to_string() << std::endl;
  // }

  std::vector<double> x{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<double> y{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto c1 = TCanvas("c1", "Graph Draw Options", 200, 10, 600, 400);
  auto gr = TGraph(9, x.data(), y.data());
  gr.Draw("AC*");
  c1.Update();
  theApp.Run();

  return 0;

  std::vector<std::uint64_t> xornt_primes;
  for (std::uint64_t i = 2; i < 10000; ++i) {
    for (std::uint64_t j = i; j < 10000; ++j) {
      xornt_primes.push_back(bitwise_xor_product(i, j));
    }
  }
  auto it = xornt_primes.begin();
  auto number = 0;
  for (auto i = 2; i < *xornt_primes.rbegin(); ++i) {
    if (i == *it)
      ++it;
    else
      ++number;

    if (number == 1000) {
      std::cout << i << std::endl; // 9277195, 10683395
      return 0;
    }
  }

  return 0;
}