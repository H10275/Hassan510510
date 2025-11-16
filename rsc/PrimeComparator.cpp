#include "PrimeComparator.h"
#include <iostream>
#include <unordered_set>

// Simple sieve of Eratosthenes for reference primes
std::vector<unsigned long long> PrimeComparator::generateReferencePrimes(unsigned long long max) {
    std::vector<bool> isPrime(max + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (unsigned long long i = 2; i * i <= max; ++i) {
        if (isPrime[i]) {
            for (unsigned long long j = i * i; j <= max; j += i) {
                isPrime[j] = false;
            }
        }
    }

    std::vector<unsigned long long> primes;
    for (unsigned long long i = 2; i <= max; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

// Compares two prime lists and returns match ratio
double PrimeComparator::compare(const std::vector<unsigned long long>& generated,
    const std::vector<unsigned long long>& reference) {
    std::unordered_set<unsigned long long> genSet(generated.begin(), generated.end());
    int matchCount = 0;

    for (auto p : reference) {
        if (genSet.count(p)) ++matchCount;
    }

    return 100.0 * matchCount / reference.size();
}

// Prints missing primes from reference that were not generated
void PrimeComparator::printMissing(const std::vector<unsigned long long>& generated,
    const std::vector<unsigned long long>& reference) {
    std::unordered_set<unsigned long long> genSet(generated.begin(), generated.end());

    std::cout << "[Missing Primes]\n";
    for (auto p : reference) {
        if (!genSet.count(p)) {
            std::cout << p << "\n";
        }
    }
}
