#include <iostream>
#include <cstdint>
#include <set>

constexpr bool check_pandigital(unsigned int multiplicand, unsigned int multiplier, unsigned int product) {
    uint_fast16_t unique_values = 1; // damit keine 0 auftritt

    while (product > 0U) {
        uint_fast16_t const mask = 1U << (product % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        product /= 10U;
    }

    while (multiplicand > 0U) {
        uint_fast16_t const mask = 1U << (multiplicand % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        multiplicand /= 10U;
    }

    while (multiplier > 0U) {
        uint_fast16_t const mask = 1U << (multiplier % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        multiplier /= 10U;
    }

    if (unique_values == 1023U) return true;

    return false;
}


/*
 * 1 + 1 = 7; // max: 81
   1 + 2 = 6; // max: 891
   1 + 3 = 5; // max: 8991
   1 + 4 = 4; <--------------- possible
   1 * 5 = 3; // min: 11111
   2 + 2 = 5; // max: 9801
   2 + 3 = 4; <--------------- possible
   3 + 1 = 5;

    ...
 */

int main() {
    std::set<unsigned int> products;

    for (unsigned int multiplicand = 1U; multiplicand <= 9U; ++multiplicand) {
        for (unsigned int multiplier = 1234U; multiplier <= 9876U; ++multiplier) {
            unsigned int const product = multiplicand * multiplier;
            if (check_pandigital(multiplicand, multiplier, product)) {
                products.insert(product);
                std::cout << multiplicand << " * " << multiplier << " = " << product << std::endl;
            }
        }
    }


    for (unsigned int multiplicand = 1U; multiplicand <= 98U; ++multiplicand) {
        for (unsigned int multiplier = 123U; multiplier <= 987U; ++multiplier) {
            unsigned int const product = multiplicand * multiplier;
            if (check_pandigital(multiplicand, multiplier, product)) {
                products.insert(product);
                std::cout << multiplicand << " * " << multiplier << " = " << product << std::endl;
            }
        }
    }

    unsigned int sum = 0U;
    for (unsigned int const e: products) {
        sum += e;
    }

    std::cout << sum << std::endl;
}

/*
 * auto start = std::chrono::system_clock::now();

    unsigned int test = 0;
    std::vector<uint64_t> nums(986409);
    for (uint64_t i = 1, j = 0; i <= 987654321U; ++i) {
        if (is_unique(i)) {
            ++test;
            nums[j++] = i;
        }
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "took: " << diff.count() << "s" << std::endl;

    std::cout << test << std::endl;
    std::cout << "ready producing!" << std::endl;

    uint64_t sum = 0U;
    for (unsigned int i = 0U; i < 986409U; ++i) {
        if (check_product(nums, nums[i])) {
            sum += nums[i];
            continue;
        }
    }

    auto end2 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff2 = end2 - end;
    std::cout << "took: " << diff2.count() << "s" << std::endl;

    std::cout << sum << std::endl;

    return 0;
}
/*
    //ProgressBar pg;
    //pg.start(10000U);

//#pragma omp parallel for default(none) schedule(dynamic, 256) reduction(+:sum) firstprivate(nums)
    for (unsigned int i = 0; i < 986409U; ++i) {
        for (unsigned int j = i; j < 986409U; ++j) {
            uint64_t const product = nums[i] * nums[j];
            if(product > 987654321U) break;
            if (is_unique(product)) {
                sum += product;

                std::cout << nums[i] << " * " << nums[j] << " = " << product << std::endl;
            }
        }
        //std::cout << i << std::endl;

        //if (i % (4206095U / 10000U) == 0U) pg.update(i * 10000U / 4206095U);
    }

    auto end2 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff2 = end2 - end;
    std::cout << "took: " << diff2.count() << "s" << std::endl;

    std::cout << sum << std::endl;


//    ProgressBar pg;
//    pg.start(100U);
//
//    uint64_t sum = 0;
//
//    uint8_t update_value = 0;
//
//    for (unsigned int i = 0; i < 8877690U; ++i) {
//        for (unsigned int j = i; j < 8877690U; ++j) {
//            uint64_t product = nums[i] * nums[j];
//            if (product <= 9876543210U && is_unique(product)) {
//                sum += product;
//            }
//        }
//        if (i % (8877690U / 100) == 0) pg.update(update_value++);
//    }

//    std::cout << sum << std::endl;


 constexpr bool is_unique(uint64_t num) { // muss > 0 sein
    //bool unique_values[10] = {true, false, false, false, false, false, false, false, false, false};
    uint_fast16_t unique_values = 1;

    for (unsigned int i = 0; i < 8; ++i) {
        uint_fast16_t const mask = 1U << (num % 10U);
        if (unique_values & mask) return false;
        unique_values |= mask;
        num /= 10U;

        if (num == 0) return true;
    }

    uint_fast16_t const mask = 1U << (num % 10U);
    return !(unique_values & mask);

    //unique_values |= 1 << num % 10U;
    //num /= 10U;
//
    //for (unsigned int i = 1; i < 10; ++i) {
    //    if (num == 0) return true;
//
    //    if (unique_values & (1 << num % 10U)) {
    //        return false;
    //    }
    //    num /= 10U;
    //}
//
    //return true;

    //while (num > 0) {
    //    if (unique_values[num % 10U]) return false;
    //    unique_values[num % 10U] = true;
//        num /= 10U;
    //}


}

//constexpr bool check_product(std::vector<uint64_t> const &nums, uint64_t const num) {
//    for (unsigned int j = 0U; j < 986409U; ++j) {
//        if (nums[j] * nums[j] > num) return false;
//        for (unsigned int k = j; k < 986409U; ++k) {
//            uint64_t const product = nums[j] * nums[k];
//            if (product > num) break;
//            if (product == num) {
//                if (check_pandigital(nums[j], nums[k], num)) {
//                    std::cout << nums[j] << " * " << nums[k] << " = " << num << std::endl;
//                    return true;
//                }
//            }
//        }
//    }
//
//    std::cout << "NOT POSSIBLE" << std::endl;
//    return false;
//}

    /*
#pragma omp parallel for default(none) schedule(static, 1000) reduction(+:sum) shared(pg)
    for (uint64_t i = 2; i < 9876543210U; ++i) {
        if (is_unique(i)) [[unlikely]] {
            for (uint64_t j = i; j < 9876543210U; ++j) {
                if (is_unique(j)) [[unlikely]] {
                    uint64_t product = i * j;
                    if (product <= 9876543210 && is_unique(product)) [[unlikely]] {
                        sum += product;
                        //std::cout << i << " * " << j << " = " << product << std::endl;
                    }
                }
            }
        }
        if (i % (9876543210 / 1000000) == 0) [[unlikely]] pg.update(i * 1000000U / 9876543210U);
    }





    //const rlim_t kStackSize = 256 * 1024 * 1024;   // min stack size = 128 MB


    //rlimit lim;
    //int res = getrlimit(RLIMIT_STACK, &lim);
    //if (res) perror("ERR: ");
    //else {
    //    std::cout << lim.rlim_cur << std::endl;
    //    std::cout << lim.rlim_max << std::endl;
//
    //    lim.rlim_cur = lim.rlim_cur * 16;
//
    //    res = setrlimit(RLIMIT_STACK, &lim);
    //    if (res) perror("ERR: ");
    //}
//
    //rlimit lim2;
    //int res2 = getrlimit(RLIMIT_STACK, &lim2);
    //if (res2) perror("ERR: ");
    //else {
    //    std::cout << lim.rlim_cur << std::endl;
    //    std::cout << lim.rlim_max << std::endl;
    //}

    //std::bitset<9876543210U> arr;
    //uint64_t nums[8877690U];
//
    //for (uint64_t i = 1, j = 0; i <= 9876543210U; ++i) {
    //    if (is_unique(i)) {
    //        //arr[i] = true;
    //        nums[j++] = i;
    //    }
    //}
//
    //uint64_t sum = 0;
//
    //progressbar bar(8877690U);
    //for (unsigned int i = 0; i < 8877690U; ++i) {
    //    for (unsigned int j = i; j < 8877690U; ++j) {
    //        uint64_t product = nums[i] * nums[j];
    //        if (product <= 9876543210U && is_unique(product)) {
    //            sum += product;
    //        }
    //    }
    //    bar.update();
    //}
//
    //std::cout << sum << std::endl;



    //arr[9807654321] = true;

/*

    for (uint64_t iiiiiiiii = 0; iiiiiiiii < 10; ++iiiiiiiii) {
        for (uint64_t iiiiiiii = 0; iiiiiiii < 10; ++iiiiiiii) {
            for (uint64_t iiiiiii = 0; iiiiiii < 10; ++iiiiiii) {
                for (uint64_t iiiiii = 0; iiiiii < 10; ++iiiiii) {
                    for (uint64_t iiiii = 0; iiiii < 10; ++iiiii) {
                        for (uint64_t iiii = 0; iiii < 10; ++iiii) {
                            for (uint64_t iii = 0; iii < 10; ++iii) {
                                for (uint64_t ii = 0; ii < 10; ++ii) {
                                    for (uint64_t i = 0; i < 10; ++i) {

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }*/