#include "../include/BoardBoxProperty.h"

BoardBoxProperty::BoardBoxProperty() {};
BoardBoxProperty::BoardBoxProperty(char typeCharacter_, int price_, int housePrice_, int hotelPrice_, int houseNightPrice_, int hotelNightPrice_) : BoardBox("property", typeCharacter_),  price(price_), housePrice(housePrice_), hotelPrice(hotelPrice_), houseNightPrice(houseNightPrice_), hotelNightPrice(hotelNightPrice_){ propertyLevel=0;};
std::string BoardBoxProperty::getBoxType() { return boxType; }
char BoardBoxProperty::getTypeCharacter() {return typeCharacter; }
int BoardBoxProperty::getPropertyLevel() const {return propertyLevel;};
void BoardBoxProperty::action(Player* actualPlayer) {
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
        }else{
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
void BoardBoxProperty::eraseOwner() {
    //cancella il proprietario e ri-inizializza l'oggetto
    owner=nullptr;
    propertyLevel=-1;
}
Player* BoardBoxProperty::getOwner(){
    return owner;
}
void BoardBoxProperty::setOwner(Player* owner_){
    owner = owner_;
}
std::string BoardBoxProperty::toString(){
    std::string output = "";
    switch(propertyLevel){
        case 0:
            output = typeCharacter;
            //output += "|";
            break;
        case 1:
            output = typeCharacter;
            output += '*';
            break;
        case 2:
            output = typeCharacter;
            output += '*';
            break;
    }
    return output;
}
int BoardBoxProperty::getUpgradeCost(){
    if(propertyLevel==0)
        return housePrice;
    else if(propertyLevel==1)
        return hotelPrice;
    else
        return price;
}
int BoardBoxProperty::getRentCost(){
    if(propertyLevel==1)
        return houseNightPrice;
    else if(propertyLevel==2)
        return hotelNightPrice;
    else
        return 0;
}
void BoardBoxProperty::upgradePropertyLevel(){ propertyLevel++; }
BoardBoxProperty::~BoardBoxProperty(){};
