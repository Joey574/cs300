#ifndef CLOCK_HPP
#define CLOCK_HPP

#define MINUTES_IN_DAY 1440
#define MINUTES_IN_HOUR 60

class Clock {
    public:
        Clock() : minutes(0) {}
        Clock(int hour, int minute) : minutes(((hour * MINUTES_IN_HOUR) + minute) % MINUTES_IN_DAY) {}

        int Hour() const;
        int Minute() const;
        void Advance(int minutes);
    private:
        int minutes;
};

#undef MINUTES_IN_DAY
#undef MINUTES_IN_HOUR
#endif // CLOCK_HPP
