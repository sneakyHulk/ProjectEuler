#include <iostream>
#include <cstdint>
#include <array>
#include <vector>
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

constexpr bool is_unique(uint64_t num) {
    bool unique_values[10] = {false, false, false, false, false, false, false, false, false, false};

    while (num > 0) {
        if (unique_values[num % 10U]) return false;
        unique_values[num % 10U] = true;
        num /= 10U;
    }

    return true;
}

int main() {
    omp_set_num_threads(8);

    std::vector<uint64_t> nums(8877690U);
    for (uint64_t i = 1, j = 0; i <= 9876543210U; ++i) {
        if (is_unique(i)) {
            nums[j++] = i;
        }
    }

    std::cout << "ready producing!" << std::endl;


    ProgressBar pg;
    pg.start(8877690U);

    uint64_t sum = 0;

#pragma omp parallel for default(none) schedule(static, 1000) reduction(+:sum) shared(pg) firstprivate(nums)
    for (unsigned int i = 0; i < 8877690U; ++i) {
        for (unsigned int j = i; j < 8877690U; ++j) {
            uint64_t product = nums[i] * nums[j];
            if (product <= 9876543210U && is_unique(product)) {
                sum += product;
            }
        }
        pg.update(i);
    }

    std::cout << sum << std::endl;


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
}