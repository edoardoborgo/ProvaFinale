
#ifndef PROVAFINALE_BOARDBOXPROPERTY_H
#define PROVAFINALE_BOARDBOXPROPERTY_H

#include <iostream>
#include "BoardBox.h"
#include "Player.h"

class BoardBoxProperty : public BoardBox{

public:
    BoardBoxProperty(){};
    BoardBoxProperty(char typeCharacter_, int price_, int housePrice_, int hotelPrice_, int houseNightPrice_, int hotelNightPrice_) : BoardBox("property", typeCharacter_),  price(price_), housePrice(housePrice_), hotelPrice(hotelPrice_), houseNightPrice(houseNightPrice_), hotelNightPrice(hotelNightPrice_){};
    std::string getBoxType() override{ return boxType; }
    char getTypeCharacter() override {return typeCharacter; };
    int getPropertyLevel() const {return propertyLevel;};

    void action(Player* actualPlayer) override{
        if(owner!=nullptr && owner==actualPlayer) {
            //miglioramento proprietà, se migliorabile
            if (propertyLevel != 2) {
                //migliorabile
                if (actualPlayer->getPlayerType() == 1) {
                    //pc, se ha abbastanza soldi compra/migliora
                    if (actualPlayer->getMoney() >= getUpgradeCost()){
                        actualPlayer->withdraw(getUpgradeCost());
                        upgradePropertyLevel();
                    }
                }else{
                    //human, chiedo cosa vuole fare solo se ha abbastanza soldi
                    if (actualPlayer->getMoney() >= getUpgradeCost()){
                        std::cout << "Vuoi migliorare la proprietà? costo: "<<getUpgradeCost()<<"$.";
                        std::string input;
                        std::getline(std::cin, input);
                        if(input==std::string("s")){
                            actualPlayer->withdraw(getUpgradeCost());
                            upgradePropertyLevel();
                        }
                    }
                }
            }
        }else if(owner!=nullptr){
            //proprietà occupata ma non dall'actual player
            actualPlayer->withdraw(getRentCost());
            owner->deposit(getRentCost());
        }else if(owner==nullptr){
            //acquistabile
            if (actualPlayer->getPlayerType() == 1) {
                //pc, se ha abbastanza soldi compra/migliora
                if (actualPlayer->getMoney() >= getUpgradeCost()){
                    actualPlayer->withdraw(getUpgradeCost());
                    upgradePropertyLevel();
                }
            }else {
                //human, chiedo cosa vuole fare solo se ha abbastanza soldi
                if (actualPlayer->getMoney() >= getUpgradeCost()) {
                    std::cout << "Vuoi migliorare la proprietà? costo: " << getUpgradeCost() << "$.";
                    std::string input;
                    std::getline(std::cin, input);
                    if (input == std::string("s")) {
                        actualPlayer->withdraw(getUpgradeCost());
                        upgradePropertyLevel();
                    }
                }
            }
        }
    }

    void eraseOwner() override{
        //cancella il proprietario e ri-inizializza l'oggetto
        owner=nullptr;
        propertyLevel=-1;
    }

    Player* getOwner() override{
        return owner;
    }

    void setOwner(Player* owner_){
        owner = owner_;
    }

    std::string toString() override{
        std::string output = "";
        switch(propertyLevel){
            case 0:
                output += typeCharacter + '|';
                break;
            case 1:
                output += typeCharacter + '*';
                break;
            case 2:
                output += typeCharacter + '^';
                break;
        }
        return output;
    }

protected:
    int price, housePrice, hotelPrice, houseNightPrice, hotelNightPrice;
    Player* owner = nullptr;
    int propertyLevel=-1; //0-terreno, 1-casa, 2-hotel
    int getUpgradeCost(){
        if(propertyLevel==0)
            return housePrice;
        else if(propertyLevel==1)
            return hotelPrice;
        else
            return price;
    }
    int getRentCost(){
        if(propertyLevel==1)
            return houseNightPrice;
        else if(propertyLevel==2)
            return hotelNightPrice;
        else
            return 0;
    }
    void upgradePropertyLevel(){ propertyLevel++; }

    virtual ~BoardBoxProperty(){};

private:

};

std::ostream& operator<<(std::ostream& output, BoardBoxProperty& boardBoxProperty) {
    //TODO controllare se sulla casella c'è un giocatore
    switch(boardBoxProperty.getPropertyLevel()){
        case 0:
            output << boardBoxProperty.getTypeCharacter() << "|";
            break;
        case 1:
            output << boardBoxProperty.getTypeCharacter() << "*";
            break;
        case 2:
            output << boardBoxProperty.getTypeCharacter() << "^";
            break;
    }
    return output;


}

#endif //PROVAFINALE_BOARDBOXPROPERTY_H
