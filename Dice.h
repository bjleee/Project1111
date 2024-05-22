#ifndef DICE_H
#define DICE_H

#include <cstdlib> // Necessary for std::rand and std::srand
#include <ctime>   // Necessary for std::time

class Dice {
public:
    Dice();
    bool setTopFace(int num);
    void rollDice();
    int getTopFace() const;

private:
    int topFace;
};

#endif // DICE_H
