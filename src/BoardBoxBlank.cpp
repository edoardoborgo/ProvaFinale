#include "../include/BoardBoxBlank.h"

BoardBoxBlank::BoardBoxBlank(){}
BoardBoxBlank::BoardBoxBlank(char typeCharacter_) : BoardBox("blank", typeCharacter_){}

std::string BoardBoxBlank::getBoxType() { return boxType; }
char BoardBoxBlank::getTypeCharacter() { return typeCharacter; }
void BoardBoxBlank::action(Player* actualPlayer) {}
void BoardBoxBlank::eraseOwner() {};
Player* BoardBoxBlank::getOwner() { return nullptr; }
std::string BoardBoxBlank::toString() {
    std::string output = "";
    output = typeCharacter;
    return output;
}
