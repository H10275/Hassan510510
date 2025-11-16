#pragma once
#include <vector>

class ResidueSystem {
private:
    int modulus;
    std::vector<int> residues;

public:
    // Constructor with default modulus set to 510510
    ResidueSystem(int m = 510510);

    // Computes all integers less than modulus that are coprime to it
    void computeCoprimeResidues();

    // Returns the list of coprime residues
    const std::vector<int>& getResidues() const;

    // Returns the modulus value
    int getModulus() const;
};