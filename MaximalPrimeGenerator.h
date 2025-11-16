#pragma once
#include "ResidueSystem.h"
#include "CompositeFilter.h"
#include <vector>

class MaximalPrimeGenerator {
private:
    ResidueSystem residueSystem;
    CompositeFilter filter;

public:
    // Constructor takes a ResidueSystem instance
    MaximalPrimeGenerator(const ResidueSystem& rs);

    // Generates a fixed number of primes
    std::vector<unsigned long long> generate(int count);

    // Generates all primes up to a given upper bound
    std::vector<unsigned long long> generateUpTo(unsigned long long max);
};