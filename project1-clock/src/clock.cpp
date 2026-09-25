#include "clock.hpp"
#include <stdexcept>

#define MINUTES_IN_DAY 1440
#define MINUTES_IN_HOUR 60
#define HOURS_IN_DAY 24

int Clock::Hour() const {
    return (this->minutes / MINUTES_IN_HOUR) % HOURS_IN_DAY;
}

int Clock::Minute() const {
    return this->minutes % MINUTES_IN_HOUR;
}

void Clock::Advance(int minutes) {
    if (minutes < 0) {
        throw std::invalid_argument("minutes must be positive");
    }

    this->minutes += minutes % MINUTES_IN_DAY;
}

#undef MINUTES_IN_DAY
#undef MINUTES_IN_HOUR
#undef HOURS_IN_DAY
