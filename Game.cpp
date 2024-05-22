#include "Dice.h"
#include "Player.h"
#include <iostream>
#include <string>

int playerDice1 = 1;
int playerDice2 = 1;
int nDices = 2;
bool flag = true;

std::string printDice(std::vector<int> lsDices){
    std::string str_out = " ";
    for(auto& dice : lsDices){
        str_out += std::to_string(dice) + " ";
    }
    return str_out.c_str();
}

int main()
{
    srand(std::time(nullptr)); // Seed the random number generator only once
    /* Description: Generates the Dice and Player objects needed for the game. */
    // Initialise a list of two Dice objects
    std::vector<Dice> dices(nDices);
    // Initialise a list of Player Objects
    std::string playerName;
    std::cout << "What is your name?";
    std::getline(std::cin, playerName);

    Player humanPlayer(playerName);
    Player computerPlayer("Computer");

    /* Start game */
    printf("The player with highest roll wins.\n");
    printf("Humans go first. \n");

    while (flag)
    {
        std::cout << "Do you want to roll the dice [Y|N]? " << std::endl;
        std::string action;
        std::getline(std::cin, action);
        if(action == "Y" || action == "y"){
            std::cout << humanPlayer.name << " rolls: " << printDice(humanPlayer.rollDice(dices)) << std::endl;
            std::cout << computerPlayer.name << " rolls: " << printDice(computerPlayer.rollDice(dices)) << std::endl;
            int playerPoint = humanPlayer.updateScore();
            int computerPoint = computerPlayer.updateScore();
            if(playerPoint > computerPoint){
                std::cout << humanPlayer.name << " wins." << std::endl;
            }
            else if (playerPoint < computerPoint)
            {
                std::cout << "Computer wins."<< std::endl;
            }
            else{
                std::cout<<"It is a draw."<< std::endl;
            }
            break;
        }
        else if(action == "n" || action == "N"){
            printf("Ok. I will roll then.\n");
            printf("%s rolls: %d %d\n", humanPlayer.name.c_str(), playerDice1, playerDice2);
            std::cout << computerPlayer.name << " rolls: " << printDice(computerPlayer.rollDice(dices)) << std::endl;
            int playerPoint = 2;
            int computerPoint = computerPlayer.updateScore();
            if(playerPoint > computerPoint){
                std::cout << humanPlayer.name << " wins." << std::endl;
            }
            else if (playerPoint < computerPoint)
            {
                std::cout << "Computer wins."<< std::endl;  
            }
            else{
                std::cout<<"It is a draw."<< std::endl;
            }
        }
    }
}
