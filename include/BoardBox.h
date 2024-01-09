
#ifndef PROVAFINALE_BOARDBOX_H
#define PROVAFINALE_BOARDBOX_H

#include <string>
#include "Player.h"

class BoardBox{

    public:
        BoardBox(){};
        void setBoxType(int boxType_){ boxType = boxType_; };
        virtual std::string getBoxType();
        virtual char getTypeCharacter ();
        virtual void eraseOwner();
        virtual Player* getOwner();
        virtual void action(Player* actualPlayer);
        virtual std::string toString();


    protected:
        BoardBox(std::string boxType_, char typeCharacter_);
        std::string boxType; // property-proprietà  blank-vuota
        char typeCharacter; //per stampare tabellone

    private:
        int index;

};



#endif //PROVAFINALE_BOARDBOX_H
