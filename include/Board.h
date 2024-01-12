
#ifndef PROVAFINALE_BOARD_H
#define PROVAFINALE_BOARD_H

#include "BoardBox.h"
#include "Player.h"
#include <initializer_list>

class Board{
public:
    Board(int gameType);

    void move();
    bool endedGame();
    void addPlayer(std::initializer_list<Player*>);
    int getLength();
    void show();
    void deletePlayer(Player* actualPlayer);
    void nextPlayerRound();

private:
    int gameMode;
    int maxRounds = 30;
    int playerRound = 0;        //di quale giocatore è il turno
    BoardBox* listBox[28];
    Player* listPlayer[4];
    int listPosition[4] = {};
    int activePlayers=4;
    bool exit=false; //flag da usare in partite PC usato da endedGame per terminare il gioco prima di controllare se ci sono più di 1 player vivo

    void assignBoxType();
    void setPlayersOrder(Player* p, Player* pp, Player* ppp, Player* pppp);
    void passedRound();
};

#endif //PROVAFINALE_BOARD_H