#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include <vector>
#include <string>
#include <iostream>

class Player{
public:
    Player(const std::string& name);

    // Static method
    std::vector<int> setRolledHistory(const std::vector<Dice>& lsDice);
    std::vector<int> rollDice(std::vector<Dice>& lsDice);
    int updateScore();

public:
    std::string name;
    int score;
    std::vector<int> rolledHistory;
};

#endif