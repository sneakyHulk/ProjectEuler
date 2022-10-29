#include <iostream>

int main() {

    int January = 31;
    int February = 28;
    int March = 31;
    int April = 30;
    int May = 31;
    int June = 30;
    int July = 31;
    int August = 31;
    int September = 30;
    int October = 31;
    int November = 30;
    int December = 31;


    // Monday = 0 --> Sunday = 6
    int current_day = 365 % 7; // 1. Jan 1900
    int sundays = 0;

    for (int i = 1901; i < 2001; ++i) {
        if (current_day == 6) sundays++;
        current_day = (current_day + January) % 7;

        if (current_day == 6) sundays++;
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            current_day = (current_day + February + 1) % 7;
        } else {
            current_day = (current_day + February) % 7;
        }

        if (current_day == 6) sundays++;
        current_day = (current_day + March) % 7;

        if (current_day == 6) sundays++;
        current_day = (current_day + April) % 7;

        if (current_day == 6) sundays++;
        current_day = (current_day + May) % 7;

        if (current_day == 6) sundays++;
        current_day = (current_day + June) % 7;

        if (current_day == 6) sundays++;
        current_day = (current_day + July) % 7;

        if (current_day == 6) sundays++;
        current_day = (current_day + August) % 7;

        if (current_day == 6) sundays++;
        current_day = (current_day + September) % 7;

        if (current_day == 6) sundays++;
        current_day = (current_day + October) % 7;

        if (current_day == 6) sundays++;
        current_day = (current_day + November) % 7;

        if (current_day == 6) sundays++;
        current_day = (current_day + December) % 7;
    }

    std::cout << sundays << std::endl;
}