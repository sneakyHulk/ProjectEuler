#include <iostream>
#include <cinttypes>
#include <chrono>
#include <omp.h>
#include <iomanip>
#include <stdexcept>

///@brief Used to time how intervals in code.
///
///Such as how long it takes a given function to run, or how long I/O has taken.
class Timer {
private:
    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::duration<double, std::ratio<1> > second;

    std::chrono::time_point<clock> start_time; ///< Last time the timer was started
    double accumulated_time;                   ///< Accumulated running time since creation
    bool running;                              ///< True when the timer is running

public:
    Timer() {
        accumulated_time = 0;
        running = false;
    }

    ///Start the timer. Throws an exception if timer was already running.
    void start() {
        if (running)
            throw std::runtime_error("Timer was already started!");
        running = true;
        start_time = clock::now();
    }

    ///Stop the timer. Throws an exception if timer was already stopped.
    ///Calling this adds to the timer's accumulated time.
    ///@return The accumulated time in seconds.
    double stop() {
        if (!running)
            throw std::runtime_error("Timer was already stopped!");

        accumulated_time += lap();
        running = false;

        return accumulated_time;
    }

    ///Returns the timer's accumulated time. Throws an exception if the timer is
    ///running.
    double accumulated() {
        if (running)
            throw std::runtime_error("Timer is still running!");
        return accumulated_time;
    }

    ///Returns the time between when the timer was started and the current
    ///moment. Throws an exception if the timer is not running.
    double lap() {
        if (!running)
            throw std::runtime_error("Timer was not started!");
        return std::chrono::duration_cast<second>(clock::now() - start_time).count();
    }

    ///Stops the timer and resets its accumulated time. No exceptions are thrown
    ///ever.
    void reset() {
        accumulated_time = 0;
        running = false;
    }
};


///@brief Manages a console-based progress bar to keep the user entertained.
///
///Defining the global `NOPROGRESS` will
///disable all progress operations, potentially speeding up a program. The look
///of the progress bar is shown in ProgressBar.hpp.
class ProgressBar {
private:
    uint32_t total_work;    ///< Total work to be accomplished
    uint32_t next_update;   ///< Next point to update the visible progress bar
    uint32_t call_diff;     ///< Interval between updates in work units
    uint32_t work_done;
    uint16_t old_percent;   ///< Old percentage value (aka: should we update the progress bar) --> Maybe that we do not need this
    Timer timer;         ///< Used for generating ETA

    ///Clear current line on console so a new progress bar can be written
    void clearConsoleLine() const {
        std::cerr << "\r\033[2K" << std::flush;
    }

public:
    ///@brief Start/reset the progress bar.
    ///@param total_work  The amount of work to be completed, usually specified in cells.
    void start(uint32_t total_work) {
        timer = Timer();
        timer.start();
        this->total_work = total_work;
        next_update = 0;
        call_diff = total_work / 200;
        old_percent = 0;
        work_done = 0;
        clearConsoleLine();
    }

    ///@brief Update the visible progress bar, but only if enough work has been done.
    ///
    ///Define the global `NOPROGRESS` flag to prevent this from having an
    ///effect. Doing so may speed up the program's execution.
    void update(uint32_t work_done0) {
        //Provide simple way of optimizing out progress updates
#ifdef NOPROGRESS
        return;
#endif

        //Quick return if this isn't the main thread
        if (omp_get_thread_num() != 0)
            return;

        //Update the amount of work done
        work_done = work_done0;

        //Quick return if insufficient progress has occurred
        if (work_done < next_update)
            return;

        //Update the next time at which we'll do the expensive update stuff
        next_update += call_diff;

        //Use a uint16_t because using a uint8_t will cause the result to print as a
        //character instead of a number
        uint16_t percent = (uint8_t) (work_done * omp_get_num_threads() * 100 / total_work);

        //Handle overflows
        if (percent > 100)
            percent = 100;

        //In the case that there has been no update (which should never be the case,
        //actually), skip the expensive screen print
        if (percent == old_percent)
            return;

        //Update old_percent accordingly
        old_percent = percent;

        //Print an update string which looks like this:
        //  [================================================  ] (96% - 1.0s - 4 threads)
        std::cerr << "\r\033[2K["
                  << std::string(percent / 2, '=') << std::string(50 - percent / 2, ' ')
                  << "] ("
                  << percent << "% - "
                  << std::fixed << std::setprecision(1) << timer.lap() / percent * (100 - percent)
                  << "s - "
                  << omp_get_num_threads() << " threads)" << std::flush;
    }

    ///Increment by one the work done and update the progress bar
    ProgressBar &operator++() {
        //Quick return if this isn't the main thread
        if (omp_get_thread_num() != 0)
            return *this;

        work_done++;
        update(work_done);
        return *this;
    }

    ///Stop the progress bar. Throws an exception if it wasn't started.
    ///@return The number of seconds the progress bar was running.
    double stop() {
        clearConsoleLine();

        timer.stop();
        return timer.accumulated();
    }

    ///@return Return the time the progress bar ran for.
    double time_it_took() {
        return timer.accumulated();
    }

    uint32_t cellsProcessed() const {
        return work_done;
    }
};

uint64_t binpow(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;

        a = a * a % m;
        b >>= 1;
    }

    return res;
}

int main() {
    omp_set_num_threads(24);

    auto start = std::chrono::system_clock::now();

    uint64_t sum = 0;

    /*test_value = value % 10U;
    for (; result < 1000000000U; result += 1U) {
        if (binpow(test_value, result, 10U) == result) {
            //std::cout << result << std::endl;
            break;
        }
    }

    test_value = value % 100U;
    for (; result < 1000000000U; result += 10U) {
        if (binpow(test_value, result, 100U) == result) {
            //std::cout << result << std::endl;
            break;
        }
    }*/

#pragma omp parallel for default(none) reduction(+:sum)
    for (uint64_t value = 2; value <= 1000U; ++value) {
        if (value % 10 == 0) {
            //std::cout << 0 << std::endl;
            continue;
        }

        uint64_t test_value = 0;
        uint64_t result = 0;

        test_value = value % 1000U;
        for (; result < 1000000000U; result += 1U) { // += 100
            if (binpow(test_value, result, 1000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 10000U;
        for (; result < 1000000000U; result += 1000U) {
            if (binpow(test_value, result, 10000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 100000U;
        for (; result < 1000000000U; result += 10000U) {
            if (binpow(test_value, result, 100000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 1000000U;
        for (; result < 1000000000U; result += 100000U) { // += 100000U
            if (binpow(test_value, result, 1000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 10000000U;
        for (; result < 1000000000U; result += 1000000U) {
            if (binpow(test_value, result, 10000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 100000000U;
        for (; result < 1000000000U; result += 10000000U) {
            if (binpow(test_value, result, 100000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 1000000000U;
        for (; result < 1000000000U; result += 100000000U) {
            if (binpow(test_value, result, 1000000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        sum += result;
    }

#pragma omp parallel for default(none) reduction(+:sum)
    for (uint64_t value = 1001U; value <= 10000U; ++value) {
        if (value % 10 == 0) {
            //std::cout << 0 << std::endl;
            continue;
        }

        uint64_t test_value = 0;
        uint64_t result = 0;

        test_value = value % 10000U;
        for (; result < 1000000000U; result += 1U) {
            if (binpow(test_value, result, 10000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 100000U;
        for (; result < 1000000000U; result += 10000U) {
            if (binpow(test_value, result, 100000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 1000000U;
        for (; result < 1000000000U; result += 100000U) { // += 100000U
            if (binpow(test_value, result, 1000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 10000000U;
        for (; result < 1000000000U; result += 1000000U) {
            if (binpow(test_value, result, 10000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 100000000U;
        for (; result < 1000000000U; result += 10000000U) {
            if (binpow(test_value, result, 100000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 1000000000U;
        for (; result < 1000000000U; result += 100000000U) {
            if (binpow(test_value, result, 1000000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        sum += result;
    }

    ProgressBar pg1;
    pg1.start(100000U - 10001U);

#pragma omp parallel for default(none) schedule(static) reduction(+:sum) shared(pg1)
    for (uint64_t value = 10001U; value <= 100000U; ++value) {
        pg1.update(value - 10001U);

        if (value % 10 == 0) {
            //std::cout << 0 << std::endl;
            continue;
        }

        uint64_t test_value = 0;
        uint64_t result = 0;

        test_value = value % 100000U;
        for (; result < 1000000000U; result += 1U) {
            if (binpow(test_value, result, 100000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 1000000U;
        for (; result < 1000000000U; result += 100000U) { // += 100000U
            if (binpow(test_value, result, 1000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 10000000U;
        for (; result < 1000000000U; result += 1000000U) {
            if (binpow(test_value, result, 10000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 100000000U;
        for (; result < 1000000000U; result += 10000000U) {
            if (binpow(test_value, result, 100000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 1000000000U;
        for (; result < 1000000000U; result += 100000000U) {
            if (binpow(test_value, result, 1000000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        sum += result;
    }

    ProgressBar pg2;
    pg2.start(1000000U - 100001U);

#pragma omp parallel for default(none) schedule(static) reduction(+:sum) shared(pg2)
    for (uint64_t value = 100001U; value <= 1000000U; ++value) {
        pg2.update(value - 100001U);

        if (value % 10 == 0) {
            //std::cout << 0 << std::endl;
            continue;
        }

        uint64_t test_value = 0;
        uint64_t result = 0;

        test_value = value % 1000000U;
        for (; result < 1000000000U; result += 1U) { // += 100000U
            if (binpow(test_value, result, 1000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 10000000U;
        for (; result < 1000000000U; result += 1000000U) {
            if (binpow(test_value, result, 10000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 100000000U;
        for (; result < 1000000000U; result += 10000000U) {
            if (binpow(test_value, result, 100000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        test_value = value % 1000000000U;
        for (; result < 1000000000U; result += 100000000U) {
            if (binpow(test_value, result, 1000000000U) == result) {
                //std::cout << result << std::endl;
                break;
            }
        }

        sum += result;
    }

    std::cout << std::endl << "result: " << sum << std::endl;

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "took: " << diff.count() << "s" << std::endl;

    // result: 450186511399999
    // took: 1277.77s

    /*for (uint64_t ii = 1000U; ii <= 1000000000U; ii *= 10U) {
        uint64_t test_value = 157U % ii;

        auto start = std::chrono::system_clock::now();

        for (uint64_t i = 1; i < 1000000000U; ++i) {
            if (binpow(test_value, i, ii) == i) {
                std::cout << i << std::endl;
                break;
            }
        }
        auto end = std::chrono::system_clock::now();

        std::chrono::duration<double> diff = end - start;

        std::cout << "took " << diff.count() << "s" << std::endl;
    }*/
}