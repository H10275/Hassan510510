#include "CompositeFilter.h"

bool CompositeFilter::isComposite(int x) const {
    return divisibleBySmallPrimes(x)
        || hasBadLastDigit(x)
        || matchesModularPattern(x)
        || matchesSpecialCondition(x);
}

bool CompositeFilter::divisibleBySmallPrimes(int x) const {
    return (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 ||
        x % 7 == 0 || x % 11 == 0 || x % 13 == 0 || x % 17 == 0);
}

bool CompositeFilter::hasBadLastDigit(int x) const {
    int lastDigit = x % 10;
    return (lastDigit == 0 || lastDigit == 2 || lastDigit == 4 ||
        lastDigit == 5 || lastDigit == 6 || lastDigit == 8);
}

bool CompositeFilter::matchesModularPattern(int x) const {
    return (x % 6 == 3);
}

bool CompositeFilter::matchesSpecialCondition(int x) const {
    return (x >= 100000000 && (x - 100000000) % 3 == 0);
}
