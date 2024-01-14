
#ifndef PROVAFINALE_PC_H
#define PROVAFINALE_PC_H

#include "Player.h"
#include <ctime>
#include <cstdlib>

class Pc : public Player{
    public:
        /* Costruttore della classe Human:
         *  crea un Player con parametro playerType=1 -> giocatore umano
         */
        Pc(int playerNumber_) : Player(1, playerNumber_){};
        /* getPlayerType:
         * out: 1 se Player è Umano, 2 se è di tipo Computer
         * Permette di conoscere il tipo del giocatore.
         */
        int getPlayerType() override;

        /* takeDecision():
         * out: true se il PC decide di acquistare/migliorare, false se il PC decide di NON acquistare/migliorare
         * Calcola la decisione presa dal PC (true-false -> s-n) con una probabilita' del 25%
         */
        bool takeDecision() override;

    protected:

    private:
        //tasso di 's' della decisione presa dal PC
        int decisionRate = 25;
};

#endif //PROVAFINALE_PC_H