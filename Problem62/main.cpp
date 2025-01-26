#include "common_ostream.h"
#include <cstdint>

#include <iostream>
#include <unordered_map>
#include <vector>

#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index_container.hpp>

union NumberOfDigits {
  std::uint8_t nums[10] = {};

  struct {
    std::uint8_t zeros;
    std::uint8_t ones;
    std::uint8_t twos;
    std::uint8_t threes;
    std::uint8_t fours;
    std::uint8_t fives;
    std::uint8_t sixes;
    std::uint8_t sevens;
    std::uint8_t eights;
    std::uint8_t nines;
  };

  bool operator!=(NumberOfDigits const &number_of_digits) const {
    return zeros != number_of_digits.zeros || ones != number_of_digits.ones ||
           twos != number_of_digits.twos || threes != number_of_digits.threes ||
           fours != number_of_digits.fours || fives != number_of_digits.fives ||
           sixes != number_of_digits.sixes ||
           sevens != number_of_digits.sevens ||
           eights != number_of_digits.eights || nines != number_of_digits.nines;
  }

  bool operator==(NumberOfDigits const &number_of_digits) const {
    return zeros == number_of_digits.zeros && ones == number_of_digits.ones &&
           twos == number_of_digits.twos && threes == number_of_digits.threes &&
           fours == number_of_digits.fours && fives == number_of_digits.fives &&
           sixes == number_of_digits.sixes &&
           sevens == number_of_digits.sevens &&
           eights == number_of_digits.eights && nines == number_of_digits.nines;
  }

  [[nodiscard]] std::uint8_t get_num_digits() const {
    return zeros + ones + twos + threes + fours + fives + sixes + sevens +
           eights + nines;
  }

  struct [[maybe_unused]] Hasher {
    std::size_t operator()(NumberOfDigits const &number_of_digits) const {
      std::size_t h = 0;
      for (std::uint8_t const e : number_of_digits.nums) {
        h ^= std::hash<std::uint8_t>{}(e) + 0x9e3779b9 + (h << 6) + (h >> 2);
      }
      return h;
    }
  };
};

std::ostream &operator<<(std::ostream &os,
                         NumberOfDigits const &number_of_digits) {
  os << "{ 0: " << unsigned(number_of_digits.zeros)
     << ", 1: " << unsigned(number_of_digits.ones)
     << ", 2: " << unsigned(number_of_digits.twos)
     << ", 3: " << unsigned(number_of_digits.threes)
     << ", 4: " << unsigned(number_of_digits.fours)
     << ", 5: " << unsigned(number_of_digits.fives)
     << ", 6: " << unsigned(number_of_digits.sixes)
     << ", 7: " << unsigned(number_of_digits.sevens)
     << ", 8: " << unsigned(number_of_digits.eights)
     << ", 9: " << unsigned(number_of_digits.nines);

  return os;
}

NumberOfDigits get_number_of_digits(std::uint64_t num) {
  NumberOfDigits number_of_digits;
  while (num) {
    ++number_of_digits.nums[num % 10];
    num /= 10;
  }

  return number_of_digits;
};

std::unordered_map<NumberOfDigits,
                   std::pair<std::uint8_t, std::vector<std::uint64_t>>,
                   NumberOfDigits::Hasher>
    cubes;

struct NumberOfDigitsNumberOfOccurrencesNumbers {
  struct NumberOfDigitsTag {};
  struct NumberOfOccurrencesTag {};
  struct TotalNumberOfDigitsTag {};
  NumberOfDigits number_of_digits;
  std::uint8_t number_of_occurrences;
  std::vector<std::uint64_t> numbers;
  std::uint8_t total_number_of_digits;
};

boost::multi_index_container<
    NumberOfDigitsNumberOfOccurrencesNumbers,
    boost::multi_index::indexed_by<
        boost::multi_index::ordered_non_unique<
            boost::multi_index::tag<NumberOfDigitsNumberOfOccurrencesNumbers::
                                        NumberOfOccurrencesTag>,
            boost::multi_index::member<
                NumberOfDigitsNumberOfOccurrencesNumbers, std::uint8_t,
                &NumberOfDigitsNumberOfOccurrencesNumbers::
                    number_of_occurrences>>,
        boost::multi_index::hashed_unique<
            boost::multi_index::tag<
                NumberOfDigitsNumberOfOccurrencesNumbers::NumberOfDigitsTag>,
            boost::multi_index::member<
                NumberOfDigitsNumberOfOccurrencesNumbers, NumberOfDigits,
                &NumberOfDigitsNumberOfOccurrencesNumbers::number_of_digits>,
            NumberOfDigits::Hasher>,
        boost::multi_index::ordered_non_unique<
            boost::multi_index::tag<NumberOfDigitsNumberOfOccurrencesNumbers::
                                        TotalNumberOfDigitsTag>,
            boost::multi_index::member<
                NumberOfDigitsNumberOfOccurrencesNumbers, std::uint8_t,
                &NumberOfDigitsNumberOfOccurrencesNumbers::
                    total_number_of_digits>>>>
    number_of_digits_number_of_occurrences_numbers_map;

int main() {
  std::cout << get_number_of_digits(41063625) << std::endl;
  std::cout << get_number_of_digits(56623104) << std::endl;
  std::cout << get_number_of_digits(66430125) << std::endl;
  std::cout << (get_number_of_digits(66430125) ==
                get_number_of_digits(41063625))
            << std::endl;

  auto &number_of_digits_index =
      number_of_digits_number_of_occurrences_numbers_map
          .get<NumberOfDigitsNumberOfOccurrencesNumbers::NumberOfDigitsTag>();

  // Larger 2642245 will produce overflow
  for (std::uint64_t num = 1; num < 2642245; ++num) {
    auto number_of_digits = get_number_of_digits(num * num * num);

    if (auto it = number_of_digits_index.find(number_of_digits);
        it != number_of_digits_index.end()) {
      number_of_digits_index.modify(
          it, [&num](NumberOfDigitsNumberOfOccurrencesNumbers
                         &number_of_digits_number_of_occurrences_numbers) {
            ++number_of_digits_number_of_occurrences_numbers
                  .number_of_occurrences;
            number_of_digits_number_of_occurrences_numbers.numbers.push_back(
                num);
          });
    } else {
      number_of_digits_index.insert(
          {number_of_digits, 1, {num}, number_of_digits.get_num_digits()});
    }
  }

  auto &number_of_occurrences_index =
      number_of_digits_number_of_occurrences_numbers_map.get<
          NumberOfDigitsNumberOfOccurrencesNumbers::NumberOfOccurrencesTag>();

  auto &total_number_of_digits_index =
      number_of_digits_number_of_occurrences_numbers_map.get<
          NumberOfDigitsNumberOfOccurrencesNumbers::TotalNumberOfDigitsTag>();

  for (auto it = total_number_of_digits_index.cbegin();
       it != total_number_of_digits_index.cend(); ++it) {
    if (it->number_of_occurrences == 5) {
      std::cout << unsigned(it->total_number_of_digits) << ": " << it->numbers
                << " -> "
                << it->numbers.front() * it->numbers.front() *
                       it->numbers.front()
                << std::endl;
      break;
    }
  }
}