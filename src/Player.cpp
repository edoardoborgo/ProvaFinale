#include "../include/Player.h"
#include "../include/exceptions.h"
#include "../include/GlobalLogger.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <sstream>

Player::Player(int playerType_, int playerNumber_) : money(20), playerType(playerType_), playerNumber(playerNumber_){}
Player::Player(const Player &other){
    money=other.money;
    playerNumber=other.playerNumber;
    playerType=other.playerType;
}

int Player::throwDices(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> diceThrow(1,6); // numero casuale in [1,6]

    int firstDice = diceThrow(rng);
    int secondDice = diceThrow(rng);;

    //stampa a console i dettagli del turno attuale, log 2
    std::stringstream msg;
    msg << "Giocatore " << playerNumber << " ha tirato i dadi ottenendo un valore di " << (firstDice + secondDice)<<std::endl;
    std::cout<<msg.str();
    //stampa su file i dettagli del turno attuale, log F2
    logger.log(msg.str());
    return (firstDice+secondDice);
}

void Player::deposit(int value){
    money += value;
}
void Player::withdraw(int value) {
    if (money - value >= 0) {
        money -= value;
    }else
        throw outOfMoneyException(this);
}

int Player::getMoney(){
    return money;
}

int Player::getPlayerNumber(){
    return playerNumber;
}

void Player::setPosition(int position){
    actualPosition=position;
}

int Player::getPosition(){
    return actualPosition;
}