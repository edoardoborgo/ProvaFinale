
#ifndef PROVAFINALE_BOARDBOXBLANK_H
#define PROVAFINALE_BOARDBOXBLANK_H

#include "BoardBox.h"

class BoardBoxBlank : public BoardBox{

    public:
        /* BoardBoxBlank:
         * Costruttore di default
         */
        BoardBoxBlank();
        /* BoardBoxBlank:
         * in: char typeCharacter_, determina il carattere della casella
         * Costruttore che inizializza typeCharacter
         */
        BoardBoxBlank(char typeCharacter_);
        /* getBoxType:
         * Restituisce la tipologia della casella.
         */
        std::string getBoxType() override;
        /* getTypeCharacter:
         * Restituisce il carattere identificativo della casella.
         */
        char getTypeCharacter() override;
        /* action:
         * Funzione vuota
         */
        void action(Player* actualPlayer) override;
        /* eraseOwner:
         * Funzione vuota
         */
        void eraseOwner() override;
        /* getOwner:
         * Funzione vuota
         */
        Player* getOwner() override;
        /* toString:
         * Funzione vuota
         */
        std::string toString() override;

    protected:

    private:

};

#endif //PROVAFINALE_BOARDBOXBLANK_H