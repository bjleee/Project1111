#include "Player.h"
#include<iostream>
#include<vector>
Player::Player(const std::string& name) : name(name), score(0) {}

std::vector<int> Player::setRolledHistory(const std::vector<Dice>& lsDice) {
    rolledHistory.clear();
    for (const auto& dice : lsDice) {
        rolledHistory.push_back(dice.getTopFace());
    }
    return rolledHistory;
}

std::vector<int> Player::rollDice(std::vector<Dice>& lsDice) {
    for (auto& dice : lsDice) {
        dice.rollDice();
    }
    return setRolledHistory(lsDice);
}

int Player::updateScore() {
    score = 0;
    for (int value : rolledHistory) {
        score += value;
    }
    return score;
}
