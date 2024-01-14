
#ifndef PROVAFINALE_HUMAN_H
#define PROVAFINALE_HUMAN_H

#include "Player.h"

class Human : public Player{
    public:
        /* Costruttore della classe Human:
         * Crea un Player con parametro playerType=1 -> giocatore Umano
         * */
        Human(int playerNumber) : Player(2, playerNumber){};

        /* getPlayerType:
         * out: 1 se Player è Umano, 2 se è di tipo Computer
         * Permette di conoscere il tipo del giocatore.
         */
        int getPlayerType() override;

    protected:

private:
};

#endif //PROVAFINALE_HUMAN_H