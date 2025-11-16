#include "ResidueSystem.h"

// Fallback gcd function for compilers without std::gcd
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ResidueSystem::ResidueSystem(int m) : modulus(m) {
    computeCoprimeResidues();
}

void ResidueSystem::computeCoprimeResidues() {
    residues.clear();
    for (int r = 1; r < modulus; ++r) {
        if (gcd(r, modulus) == 1) {
            residues.push_back(r);
        }
    }
}

const std::vector<int>& ResidueSystem::getResidues() const {
    return residues;
}

int ResidueSystem::getModulus() const {
    return modulus;
}
