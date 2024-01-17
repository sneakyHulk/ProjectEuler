#include <BigInt.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <sstream>
#include <vector>

class Fraction {
public:
  BigInt numerator;
  BigInt denominator;

  Fraction(BigInt const &numerator, BigInt const &denominator)
      : numerator(numerator), denominator(denominator) {
    reduce();
  }
  Fraction(BigInt const &numerator_, Fraction const &fraction) {
    Fraction const res = numerator_ / fraction;
    numerator = res.numerator;
    denominator = res.denominator;
    reduce();
  }

  void reduce() {
    // auto const gcd = std::gcd(numerator, denominator);
    BigInt const res = gcd(numerator, denominator);
    numerator /= res;
    denominator /= res;
  }

  Fraction &operator+=(Fraction const &rhs) {
    BigInt const new_denominator = lcm(rhs.denominator, denominator);

    numerator = numerator * (new_denominator / denominator) +
                rhs.numerator * (new_denominator / rhs.denominator);

    denominator = new_denominator;
    reduce();
    return *this;
  }
  friend Fraction operator+(Fraction lhs, Fraction const &rhs) {
    lhs += rhs;
    lhs.reduce();
    return lhs;
  }
  friend Fraction operator+(BigInt const &lhs, Fraction rhs) {
    rhs.numerator += lhs * rhs.denominator;
    rhs.reduce();
    return rhs;
  }
  friend Fraction operator+(Fraction lhs, BigInt const &rhs) {
    lhs.numerator += rhs * lhs.denominator;
    lhs.reduce();
    return lhs;
  }

  ////

  Fraction &operator*=(Fraction const &rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    reduce();
    return *this;
  }
  friend Fraction operator*(Fraction lhs, Fraction const &rhs) {
    lhs *= rhs;
    return lhs;
  }
  friend Fraction operator*(BigInt const &lhs, Fraction rhs) {
    rhs *= Fraction(lhs, 1);
    return rhs;
  }
  friend Fraction operator*(Fraction lhs, BigInt const &rhs) {
    lhs *= Fraction(rhs, 1);
    return lhs;
  }

  ////

  Fraction &operator/=(Fraction const &rhs) {
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;

    reduce();
    return *this;
  }
  friend Fraction operator/(Fraction lhs, Fraction const &rhs) {
    lhs /= rhs;
    return lhs;
  }
  friend Fraction operator/(BigInt const &lhs, Fraction const &rhs) {
    Fraction res = Fraction(lhs, 1);
    res /= rhs;
    return res;
  }

  friend std::ostream &operator<<(std::ostream &out, Fraction const &rhs) {
    return out << rhs.numerator << '/' << rhs.denominator;
  }
};

int count_digits(std::uint64_t const n) {
  return std::floor(std::log10(n) + 1);
}

int main() {
  auto count = 0;
  auto x = 2U + Fraction(1, 2);
  for (auto i = 1; i < 1000; ++i) {
    auto const num = 1U + 1U / x;
    x = 2U + 1U / x;
    if (num.numerator.to_string().size() > num.denominator.to_string().size()) {
      ++count;
      std::cout << num << std::endl;
    }
  }

  std::cout << count << std::endl;
}