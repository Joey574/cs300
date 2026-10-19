#include "oneToN.hpp"
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define TEST_RUNS 250

struct RunData {
    public:
        unsigned long long n;
        unsigned long long sum;

        double average;
        double nanoseconds[TEST_RUNS];
};

void writeCSV(const char* path, const std::vector<RunData>& constant, const std::vector<RunData>& linear, const std::vector<RunData>& quadratic) {
    auto f = std::ofstream(path, std::ios::trunc);
    if (!f.is_open()) {
        std::cerr << "cannot open file: " << path << "\n";
        return;
    }

    // write header
    f << "n,linear sum,linear time (ns),quadratic sum,quadratic time (ns),constant sum,constant time (ns)\n";

    for (size_t i = 0; i < constant.size(); i++) {
        auto c = constant[i];
        auto l = linear[i];
        auto q = quadratic[i];

        f   << c.n << ','
            << l.sum << ','
            << l.average << ','
            << q.sum << ','
            << q.average << ','
            << c.sum << ','
            << c.average
            << '\n';
    }
}

RunData runTest(unsigned long long (*sum)(unsigned long long), unsigned long long n) {
    RunData r = { .n = n };

    for (int j = 0; j < TEST_RUNS; j++) {
        auto start = std::chrono::high_resolution_clock::now();
        auto s = sum(n);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;

        r.nanoseconds[j] = elapsed.count();
        r.sum = s;
    }

    r.average = std::reduce(&r.nanoseconds[0], &r.nanoseconds[TEST_RUNS], 0) / (double)TEST_RUNS;
    return r;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Must pass path to output file\n";
        exit(1);
    }

    std::string input;

    std::cout << "Enter maxN: ";
    std::cin >> input;

    auto n = std::stoull(input);

    std::cout << "Enter increment: ";
    std::cin >> input;

    auto inc = std::stoull(input);

    printf("Running with parameters: n='%llu', inc='%llu'\n", n, inc);

    auto constantRuns = std::vector<RunData>();
    constantRuns.reserve(n/inc);

    auto linearRuns = std::vector<RunData>();
    linearRuns.reserve(n/inc);

    auto quadraticRuns = std::vector<RunData>();
    quadraticRuns.reserve(n/inc);

    for (unsigned long long i = 0; i <= n; i += inc) {
        constantRuns.push_back(runTest(OneToNSumCalculator::sumConstant, i));
        linearRuns.push_back(runTest(OneToNSumCalculator::sumLinear, i));
        quadraticRuns.push_back(runTest(OneToNSumCalculator::sumQuadratic, i));
    }

    writeCSV(argv[1], constantRuns, linearRuns, quadraticRuns);
}
