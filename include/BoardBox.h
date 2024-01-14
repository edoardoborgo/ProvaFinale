
#ifndef PROVAFINALE_BOARDBOX_H
#define PROVAFINALE_BOARDBOX_H

#include <string>
#include "Player.h"

class BoardBox{

public:
    BoardBox(){};
    /* getBoxType:
     * Restituisce la tipologia della casella.
     */
    virtual std::string getBoxType(){ return boxType;};
    /* getTypeCharacter:
     * Restituisce il carattere identificativo della casella.
     */
    virtual char getTypeCharacter(){ return ' '; };
    virtual int getPropertyLevel() { return -1;};
    virtual void eraseOwner(){};
    virtual Player* getOwner(){ return nullptr; };
    /* action:
     * in: Player* actualPlayer, giocatore la cui posizione conincide con questa casella
     * Gestisce le meccaniche di gioco della determinata casella.
     */
    virtual void action(Player* actualPlayer){};
    /* toString:
     * Restituisce una descrizione testuale della casella
     */
    virtual std::string toString(){ return  "";};

protected:
    BoardBox(std::string boxType_, char typeCharacter_) : boxType(boxType_), typeCharacter(typeCharacter_) {};
    //boxType, determina il tipo di una casella: property se proprietà, blank se vuota
    std::string boxType = "";
    //carattere identificativo della casella
    char typeCharacter;

private:
};

#endif //PROVAFINALE_BOARDBOX_H