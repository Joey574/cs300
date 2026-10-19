#include "oneToN.hpp"

unsigned long long OneToNSumCalculator::sumConstant(unsigned long long n) {
    // impl 1:
    //
    // long double half = n / 2.0;
    // return ((long double)n * half + half);
    //
    // impl 2:

   if (n == 0 || n == 1) return n;

    const unsigned long long half = n >> 1;
    const unsigned long long remainder = (n & 1) ? half+1 : 0;

    return n*half + half + remainder;
}

unsigned long long OneToNSumCalculator::sumLinear(unsigned long long n) {
    unsigned long long sum = 0;

    for (unsigned long long i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

unsigned long long OneToNSumCalculator::sumQuadratic(unsigned long long n) {
    unsigned long long sum = 0;

    for (unsigned long long i = 0; i <= n; i++) {
        for (unsigned long long j = 0; j < i; j++) {
            sum++;
        }
    }

    return sum;
}
