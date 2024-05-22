#include "Dice.h"
#include <cstdlib> // For std::rand and std::srand
#include <ctime>   // For std::time

Dice::Dice() : topFace(1) {
    // Initialize top face to 1 by default
    // It's better to seed the random generator outside of the constructor to avoid re-seeding.
}

bool Dice::setTopFace(int num) {
    // Sets the value for top face of the dice.
    if (num < 1 || num > 6)
        return false;
    topFace = num;
    return true;
}

void Dice::rollDice() {
    // Generates a random number between 1 and 6 to mimic the rolling of a dice in real-life.
    int newValue = std::rand() % 6 + 1;
    setTopFace(newValue);
}

int Dice::getTopFace() const {
    return topFace;
}
