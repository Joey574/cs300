#include <climits>
#include <cstdlib>
#include <iostream>
#include "clock.hpp"

int main() {
    std::string input;

    std::cout << "Enter initial hour [0-24): ";
    std::cin >> input;

    int hour = std::atoi(input.c_str());
    if (hour < 0 || hour >= 24) {
        std::cout << "Invalid hour, got " << hour << " expected [0-24)\n";
        return 1;
    }

    std::cout << "Enter initial minute [0-60): ";
    std::cin >> input;

    int minute = std::atoi(input.c_str());
    if (minute < 0 || minute >= 60) {
        std::cout << "Invalid minute, got " << minute << " expected [0-60)\n";
        return 1;
    }

    std::cout << "Enter time in minutes to advance by [0-2147483647): ";
    std::cin >> input;

    int advance = std::atoi(input.c_str());
    if (advance < 0 || advance > INT_MAX) {
        std::cout << "Invalid advance, got " << advance << " expected [0-2147483647)\n";
        return 1;
    }

    auto c = Clock(hour, minute);
    c.Advance(advance);

    std::cout << "The time is now " << c.Hour() << ":" << c.Minute() << "\n";
}
