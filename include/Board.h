//
// Created by borgo on 08/01/2024.
//

#ifndef PROVAFINALE_BOARD_H
#define PROVAFINALE_BOARD_H

#include "BoardBox.h"
#include "Player.h"
#include <initializer_list>

class Board{
public:
    Board(int gameType);
    void move(int n);
    bool EndedGame();
    void addPlayer(std::initializer_list<Player*>);
    int getLength();

private:
    int gameMode;
    int playerRound;
    BoardBox* listBox[28];
    Player* listPlayer[4];
    int listPosition[4];

    void assignBoxType();
    void setPlayersOrder(Player*, Player*, Player*, Player*);
};

#endif //PROVAFINALE_BOARD_H
