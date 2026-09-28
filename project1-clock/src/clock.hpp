#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <stdexcept>
#define MINUTES_IN_DAY 1440
#define MINUTES_IN_HOUR 60

class Clock {
    public:
        Clock() : minutes(0) {}
        Clock(int hour, int minute) : minutes(((hour * MINUTES_IN_HOUR) + minute) % MINUTES_IN_DAY) {
            if (hour < 0 || minute < 0) {
                this->minutes = 0;
                throw std::invalid_argument("hour and minute must be non negative");
            }
        }

        ///@brief Returns the current hour in a 24 hour day
        ///@returns int [0-24)
        int Hour() const;

        ///@brief Returns the current minute of the hour
        ///@returns int [0-60)
        int Minute() const;

        ///@brief Advances the time of the day by the given number of minutes, value can be negative to advance time backwards
        void Advance(int minutes);
    private:
        int minutes;
};

#undef MINUTES_IN_DAY
#undef MINUTES_IN_HOUR
#endif // CLOCK_HPP
