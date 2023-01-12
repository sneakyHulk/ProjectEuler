#include <iostream>
#include <cstdint>
#include <cmath>

double get_triangle(double const a, double const b, double const m) {
    double x = pow(7.0 - 4.0 * sqrt(3.0), 2.0 * m);
    double y = pow(7.0 + 4.0 * sqrt(3.0), 2.0 * m);
    return 1.0 / 12.0 * (a * x - b * x + a * y + b * y - 6.0);
}

double get_pentagonal(double const a, double const b, double const m) {
    double x = pow(7.0 - 4.0 * sqrt(3.0), 2.0 * m);
    double y = pow(7.0 + 4.0 * sqrt(3.0), 2.0 * m);
    return 1.0 / 12.0 * (a * x - b * x + a * y + b * y + 2.0);
}

double get_hexagonal(double const a, double const b, double const m) {
    double x = pow(7.0 - 4.0 * sqrt(3.0), 2.0 * m);
    double y = pow(7.0 + 4.0 * sqrt(3.0), 2.0 * m);
    return 1.0 / 24.0 * (a * x - b * x + a * y + b * y + 6.0);
}

double calc_trinagle(double const n) {
    return n * (n + 1.0) / 2.0;
}

uint64_t calc_trinagle(uint64_t const n) {
    return n * (n + 1ULL) / 2ULL;
}

double calc_pentagonal(double const n) {
    return n * (3.0 * n - 1.0) / 2.0;
}

uint64_t calc_pentagonal(uint64_t const n) {
    return n * (3ULL * n - 1ULL) / 2ULL;
}

double calc_hexagonal(double const n) {
    return n * (2.0 * n - 1.0);
}

uint64_t calc_hexagonal(uint64_t const n) {
    return n * (2ULL * n - 1ULL);
}

bool is_natural_number(double const n) {
    if (n > 0.0 && n - static_cast<double>(static_cast<int64_t>(n)) == 0.0) return true;
    return false;
}

bool check(double const trinagle_n, double const pentagonal_n, double const hexagonal_n) {
    //if (!is_natural_number(trinagle_n) || !is_natural_number(pentagonal_n) || !is_natural_number(hexagonal_n))
    //    return false;

    //if (!is_natural_number(calc_trinagle(trinagle_n)) || !is_natural_number(calc_pentagonal(pentagonal_n)) ||
    //    !is_natural_number(calc_hexagonal(hexagonal_n)))
    //    return false;

    std::cout << "T" << trinagle_n << " = " << calc_trinagle(trinagle_n) << ", P" << pentagonal_n << " = "
              << calc_pentagonal(pentagonal_n) << ", H" << hexagonal_n << " = " << calc_hexagonal(hexagonal_n)
              << std::endl;

    return true;
}

int main() {
    double n = 2.0;

    check(get_triangle(33.0, 19.0 * sqrt(3.0), n),
          get_pentagonal(-19.0, 11.0 * sqrt(3.0), n),
          get_hexagonal(33.0, 19.0 * sqrt(3.0), n));
    check(get_triangle(-3.0, -sqrt(3.0), n),
          get_pentagonal(-1.0, -sqrt(3.0), n),
          get_hexagonal(-3.0, -sqrt(3.0), n));
    check(get_triangle(-3.0, sqrt(3.0), n),
          get_pentagonal(-1.0, sqrt(3.0), n),
          get_hexagonal(-3.0, sqrt(3.0), n));
    check(get_triangle(9.0, 5.0 * sqrt(3.0), n),
          get_pentagonal(5.0, 3.0 * sqrt(3.0), n),
          get_hexagonal(9.0, 5.0 * sqrt(3.0), n));
    check(get_triangle(3.0, sqrt(3.0), n),
          get_pentagonal(-1.0, -sqrt(3.0), n),
          get_hexagonal(3.0, sqrt(3.0), n));

    std::cout << calc_trinagle(static_cast<uint64_t>(std::round(get_triangle(9.0, 5.0 * sqrt(3.0), n)))) << std::endl;
}