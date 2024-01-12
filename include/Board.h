
#ifndef PROVAFINALE_BOARD_H
#define PROVAFINALE_BOARD_H

#include "BoardBox.h"
#include "Player.h"
#include <initializer_list>
#include <vector>

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
        int playerRound;
        int dim = 28;
        std::vector<BoardBox*> listBox;
        //BoardBox* listBox[28];
        //std::vector<Player*> listPlayer;
        Player* listPlayer[4];
        int listPosition[4];

        void assignBoxType();
        void setPlayersOrder(Player* p, Player* pp, Player* ppp, Player* pppp);
};

#endif //PROVAFINALE_BOARD_H
