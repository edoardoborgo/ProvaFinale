
#include "../include/Player.h"
#include <cstdlib>
#include <iostream>

Player::Player(int playerType_) : money(100), playerType(playerType_){}

int Player::throwDices(){
    int value = std::rand() % 12 + 1;
    std::cout << "Giocatore " << playerNumber << " ha tirato i dadi ottenendo un valore di " << value;
    return value;
}

void Player::deposit(int value){
    money += value;
}

int Player::getMoney(){
    return money;
}

void Player::setMoney(int value){
    money += value;
}

int Player::getPlayerNumber(){
    return playerNumber;
}