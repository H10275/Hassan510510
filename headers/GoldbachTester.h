#pragma once
#include <vector>

class GoldbachTester {
public:
    void testOddPrimes(const std::vector<unsigned long long>& primes);
    void testOddNonPrimes(const std::vector<unsigned long long>& primes,
        unsigned long long upperBound);

    int countOddPrimeRepresentations(const std::vector<unsigned long long>& primes);
    int countOddNonPrimeRepresentations(const std::vector<unsigned long long>& primes,
        unsigned long long upperBound);
};
