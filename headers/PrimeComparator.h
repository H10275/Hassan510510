#pragma once
#include <vector>

class PrimeComparator {
public:
    // Generates reference primes using a basic sieve up to a given limit
    std::vector<unsigned long long> generateReferencePrimes(unsigned long long max);

    // Compares generated primes with reference primes and returns match ratio
    double compare(const std::vector<unsigned long long>& generated,
        const std::vector<unsigned long long>& reference);

    // Prints missing primes that were not generated
    void printMissing(const std::vector<unsigned long long>& generated,
        const std::vector<unsigned long long>& reference);
};
