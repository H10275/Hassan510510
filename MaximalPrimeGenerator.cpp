#include "MaximalPrimeGenerator.h"

MaximalPrimeGenerator::MaximalPrimeGenerator(const ResidueSystem& rs)
    : residueSystem(rs) {
}

// Generates a fixed number of primes using the maximal method
std::vector<unsigned long long> MaximalPrimeGenerator::generate(int count) {
    std::vector<unsigned long long> primes;

    // Manually insert small primes ≤ 17
    int smallPrimes[] = { 2, 3, 5, 7, 11, 13, 17 };
    for (int p : smallPrimes) {
        primes.push_back(p);
        if (primes.size() == count) return primes;
    }

    const int M = residueSystem.getModulus();
    const std::vector<int>& residues = residueSystem.getResidues();

    for (unsigned long long k = 0; primes.size() < count; ++k) {
        for (int r : residues) {
            unsigned long long x = static_cast<unsigned long long>(M) * k + r;
            if (x <= 17) continue; // Already added manually
            if (!filter.isComposite(static_cast<int>(x))) {
                primes.push_back(x);
                if (primes.size() == count) break;
            }
        }
    }

    return primes;
}

// Generates all primes up to a given upper bound
std::vector<unsigned long long> MaximalPrimeGenerator::generateUpTo(unsigned long long max) {
    std::vector<unsigned long long> primes;

    // Manually insert small primes ≤ 17
    int smallPrimes[] = { 2, 3, 5, 7, 11, 13, 17 };
    for (int p : smallPrimes) {
        if (p <= max) primes.push_back(p);
    }

    const int M = residueSystem.getModulus();
    const std::vector<int>& residues = residueSystem.getResidues();

    for (unsigned long long k = 0;; ++k) {
        for (int r : residues) {
            unsigned long long x = static_cast<unsigned long long>(M) * k + r;
            if (x > max) return primes;
            if (x <= 17) continue;
            if (!filter.isComposite(static_cast<int>(x))) {
                primes.push_back(x);
            }
        }
    }
}