
#include "../include/Player.h"
#include "../include/exceptions.h"
#include <cstdlib>
#include <iostream>

Player::Player(int playerType_) : money(100), playerType(playerType_){}

int Player::throwDices(){
    int firstDice = std::rand() % 6 + 1;
    int secondDice = std::rand() % 6 + 1;

    std::cout << "Giocatore " << playerNumber << " ha tirato i dadi ottenendo un valore di " << (firstDice + secondDice) ;
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