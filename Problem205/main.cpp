#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    std::vector<uint64_t> haufigkeitsverteilung_pyramidical(37);
    haufigkeitsverteilung_pyramidical.resize(37);

    for (uint8_t i1 = 1; i1 <= 4; ++i1) {
        for (uint8_t i2 = 1; i2 <= 4; ++i2) {
            for (uint8_t i3 = 1; i3 <= 4; ++i3) {
                for (uint8_t i4 = 1; i4 <= 4; ++i4) {
                    for (uint8_t i5 = 1; i5 <= 4; ++i5) {
                        for (uint8_t i6 = 1; i6 <= 4; ++i6) {
                            for (uint8_t i7 = 1; i7 <= 4; ++i7) {
                                for (uint8_t i8 = 1; i8 <= 4; ++i8) {
                                    for (uint8_t i9 = 1; i9 <= 4; ++i9) {
                                        ++haufigkeitsverteilung_pyramidical[i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    std::vector<uint64_t> haufigkeitsverteilung_cubic(37);
    haufigkeitsverteilung_cubic.resize(37);

    for (uint8_t i1 = 1; i1 <= 6; ++i1) {
        for (uint8_t i2 = 1; i2 <= 6; ++i2) {
            for (uint8_t i3 = 1; i3 <= 6; ++i3) {
                for (uint8_t i4 = 1; i4 <= 6; ++i4) {
                    for (uint8_t i5 = 1; i5 <= 6; ++i5) {
                        for (uint8_t i6 = 1; i6 <= 6; ++i6) {
                            ++haufigkeitsverteilung_cubic[i1 + i2 + i3 + i4 + i5 + i6];
                        }
                    }
                }
            }
        }
    }

    // normieren:

    constexpr uint64_t normfaktor_pyramidical = 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4;
    constexpr uint64_t normfaktor_cubic = 6 * 6 * 6 * 6 * 6 * 6;
    constexpr uint64_t teiler = normfaktor_pyramidical * normfaktor_cubic;

    uint64_t anzahl = 0U;

    for (uint64_t i = 1; i < 37; ++i) {
        uint64_t summe = 0U;
        for (uint64_t j = 0; j < i; ++j) {
            summe += haufigkeitsverteilung_cubic[j]; // / normfaktor_cubic
        }

        summe *= haufigkeitsverteilung_pyramidical[i]; // / normfaktor_pyramidical

        anzahl += summe;
    }

    std::cout.precision(7);
    std::cout << (double) anzahl / (double) teiler << std::endl;

    return 0;
}