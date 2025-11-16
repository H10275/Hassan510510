#include "GoldbachTester.h"
#include <iostream>
#include <unordered_set>

void GoldbachTester::testOddPrimes(const std::vector<unsigned long long>& primes) {
    std::unordered_set<unsigned long long> primeSet(primes.begin(), primes.end());

    std::cout << "\n[Goldbach Test: Odd Primes as 3 + p1 + p2]\n";
    for (auto n : primes) {
        if (n < 7 || n % 2 == 0) continue;

        bool found = false;
        for (auto p1 : primes) {
            if (p1 >= n) break;
            unsigned long long p2 = n - 3 - p1;
            if (p2 >= 2 && primeSet.count(p2)) {
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Failed: " << n << "\n";
        }
    }
}

void GoldbachTester::testOddNonPrimes(const std::vector<unsigned long long>& primes,
    unsigned long long upperBound) {
    std::unordered_set<unsigned long long> primeSet(primes.begin(), primes.end());

    std::cout << "\n[Goldbach Test: Odd Non-Primes as 5 + p1 + p2]\n";
    for (unsigned long long n = 9; n <= upperBound; n += 2) {
        if (primeSet.count(n)) continue;

        bool found = false;
        for (auto p1 : primes) {
            if (p1 >= n) break;
            unsigned long long p2 = n - 5 - p1;
            if (p2 >= 2 && primeSet.count(p2)) {
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Failed: " << n << "\n";
        }
    }
}

int GoldbachTester::countOddPrimeRepresentations(const std::vector<unsigned long long>& primes) {
    std::unordered_set<unsigned long long> primeSet(primes.begin(), primes.end());
    int count = 0;

    for (auto n : primes) {
        if (n < 7 || n % 2 == 0) continue;
        for (auto p1 : primes) {
            if (p1 >= n) break;
            unsigned long long p2 = n - 3 - p1;
            if (p2 >= 2 && primeSet.count(p2)) {
                ++count;
                break;
            }
        }
    }
    return count;
}

int GoldbachTester::countOddNonPrimeRepresentations(const std::vector<unsigned long long>& primes,
    unsigned long long upperBound) {
    std::unordered_set<unsigned long long> primeSet(primes.begin(), primes.end());
    int count = 0;

    for (unsigned long long n = 9; n <= upperBound; n += 2) {
        if (primeSet.count(n)) continue;
        for (auto p1 : primes) {
            if (p1 >= n) break;
            unsigned long long p2 = n - 5 - p1;
            if (p2 >= 2 && primeSet.count(p2)) {
                ++count;
                break;
            }
        }
    }
    return count;
}