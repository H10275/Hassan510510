#pragma once

class CompositeFilter {
public:
    // Applies the full composite filter D(x)
    bool isComposite(int x) const;

private:
    // D1: Divisibility by small primes
    bool divisibleBySmallPrimes(int x) const;

    // D2: Last digit exclusion
    bool hasBadLastDigit(int x) const;

    // D3: Modular pattern exclusion
    bool matchesModularPattern(int x) const;

    // D4: Special condition exclusion
    bool matchesSpecialCondition(int x) const;
};
