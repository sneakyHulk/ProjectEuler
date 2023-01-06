#include <iostream>
#include <cstdint>
#include <boost/rational.hpp>

int main() {
    boost::rational<unsigned int> product = 1U;

    for (unsigned int numerator = 10U; numerator <= 99U; ++numerator) {
        for (unsigned int denominator = numerator + 1; denominator < 99U; ++denominator) {
            unsigned int zehnerstelle_numerator = numerator % 10U;
            unsigned int hunderterstelle_numerator = (numerator / 10) % 10U;
            unsigned int zehnerstelle_denominator = denominator % 10U;
            unsigned int hunderterstelle_denominator = (denominator / 10) % 10U;

            if (zehnerstelle_numerator == 0 || zehnerstelle_denominator == 0) continue;

            double division = static_cast<double>(numerator) / static_cast<double>(denominator);
            if (zehnerstelle_numerator == zehnerstelle_denominator) {
                double division2 = static_cast<double>(hunderterstelle_numerator) /
                                   static_cast<double>(hunderterstelle_denominator);
                if (division == division2) {
                    std::cout << numerator << " / " << denominator << " = " << division << " --> "
                              << hunderterstelle_numerator << " / " << hunderterstelle_denominator << " = " << division2
                              << std::endl;
                    product *= boost::rational<unsigned int>(numerator, denominator);
                }
            }
            if (zehnerstelle_numerator == hunderterstelle_denominator) {
                double division2 = static_cast<double>(hunderterstelle_numerator) /
                                   static_cast<double>(zehnerstelle_denominator);
                if (division == division2) {
                    std::cout << numerator << " / " << denominator << " = " << division << " --> "
                              << hunderterstelle_numerator << " / " << zehnerstelle_denominator << " = " << division2
                              << std::endl;
                    product *= boost::rational<unsigned int>(numerator, denominator);
                }
            }
            if (hunderterstelle_numerator == zehnerstelle_denominator) {
                double division2 = static_cast<double>(zehnerstelle_numerator) /
                                   static_cast<double>(hunderterstelle_denominator);
                if (division == division2) {
                    std::cout << numerator << " / " << denominator << " = " << division << " --> "
                              << zehnerstelle_numerator << " / " << hunderterstelle_denominator << " = " << division2
                              << std::endl;
                    product *= boost::rational<unsigned int>(numerator, denominator);
                }
            }
            if (hunderterstelle_numerator == hunderterstelle_denominator) {
                double division2 = static_cast<double>(zehnerstelle_numerator) /
                                   static_cast<double>(zehnerstelle_denominator);
                if (division == division2) {
                    std::cout << numerator << " / " << denominator << " = " << division << " --> "
                              << zehnerstelle_numerator << " / " << zehnerstelle_denominator << " = " << division2
                              << std::endl;
                    product *= boost::rational<unsigned int>(numerator, denominator);
                }
            }
        }
    }

    std::cout << product.denominator() << std::endl;
}