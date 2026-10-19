#ifndef ONE_TO_N_HPP
#define ONE_TO_N_HPP

class OneToNSumCalculator {
    public:

        /// @brief Returns the sum of 1...n in constant time
        static unsigned long long sumConstant(unsigned long long n);

        /// @brief Returns the sum of 1...n in linear time
        static unsigned long long sumLinear(unsigned long long n);

        /// @brief Returns the sum of 1...n in quadratic time
        static unsigned long long sumQuadratic(unsigned long long n);
};

#endif
