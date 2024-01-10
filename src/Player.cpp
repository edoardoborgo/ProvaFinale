
#include "../include/Player.h"
#include "../include/exceptions.h"
#include <cstdlib>
#include <iostream>
#include <random>

Player::Player(int playerType_, int playerNumber_) : money(100), playerType(playerType_), playerNumber(playerNumber_){}

int Player::throwDices(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]


    int firstDice = dist6(rng);
    int secondDice = dist6(rng);;

    std::cout << "Giocatore " << playerNumber << " ha tirato i dadi ottenendo un valore di " << (firstDice + secondDice) << std::endl;
    return (firstDice+secondDice);
}

void Player::deposit(int value){
    money += value;
}
void Player::withdraw(int value){
    if(money-value>=0)
        money -= value;
    else
        throw outOfMoney(this); //TODO controllo puntatori
}

int Player::getMoney(){
    return money;
}

/*void Player::setMoney(int value){
    money += value;
}*/

int Player::getPlayerNumber(){
    return playerNumber;
}