#include <sstream>
#include "../include/BoardBoxProperty.h"
#include "../include/exceptions.h"
#include "../include/GlobalLogger.h"

BoardBoxProperty::BoardBoxProperty() {};
BoardBoxProperty::BoardBoxProperty(char typeCharacter_, int price_, int housePrice_, int hotelPrice_, int houseNightPrice_, int hotelNightPrice_) : BoardBox("property", typeCharacter_),  price(price_), housePrice(housePrice_), hotelPrice(hotelPrice_), houseNightPrice(houseNightPrice_), hotelNightPrice(hotelNightPrice_){ propertyLevel=0;};
std::string BoardBoxProperty::getBoxType() { return boxType; }
char BoardBoxProperty::getTypeCharacter() {return typeCharacter; }
int BoardBoxProperty::getPropertyLevel() {return propertyLevel;};

void BoardBoxProperty::action(Player* actualPlayer) {
    if(owner!=nullptr && owner==actualPlayer) {
        std::cout<<"Proprieta' mia :)"<<std::endl;
        //il giocatore si trova in una casella di sua proprietà, può migliorarla se possibile
        if (propertyLevel == 1 || propertyLevel==2) {
            //migliorabile
            if (actualPlayer->getPlayerType() == 1) {
                //probabilità del 25%, se possiede abbastanza soldi
                if(actualPlayer->takeDecision()){
                    //pc, se ha abbastanza soldi compra/migliora
                    if (actualPlayer->getMoney() >= getUpgradeCost()){
                        actualPlayer->withdraw(getUpgradeCost());
                        upgradePropertyLevel();

                        if(propertyLevel==2){
                            //stampa a console i dettagli del turno attuale, log 5
                            std::stringstream msg;
                            msg<<"Giocatore "<<actualPlayer->getPlayerNumber()<<" ha costruito una casa sul terreno "<<actualPlayer->getPosition()<<std::endl;
                            std::cout<<msg.str();
                            //stampa su file i dettagli del turno attuale, log F5
                            logger.log(msg.str());
                        }else if(propertyLevel==3) {
                            //stampa a console i dettagli del turno attuale, log 6
                            std::stringstream msg;
                            msg << "Giocatore " << actualPlayer->getPlayerNumber() << " ha migliorato una casa in albergo sul terreno "<< actualPlayer->getPosition() << std::endl;
                            std::cout<<msg.str();
                            //stampa su file i dettagli del turno attuale, log F6
                            logger.log(msg.str());
                        }
                    }
                }
            }else{
                //human, chiedo cosa vuole fare solo se ha abbastanza soldi
                if (actualPlayer->getMoney() >= getUpgradeCost()){
                    std::cout << "Vuoi migliorare la proprietà'? costo: "<<getUpgradeCost()<<"$.";
                    std::string input;
                    std::getline(std::cin, input);
                    if(input==std::string("s")){
                        actualPlayer->withdraw(getUpgradeCost());
                        upgradePropertyLevel();
                        if(propertyLevel==2){
                            //stampa a console i dettagli del turno attuale, log 5
                            std::stringstream msg;
                            msg<<"Giocatore "<<actualPlayer->getPlayerNumber()<<" ha costruito una casa sul terreno "<<actualPlayer->getPosition()<<std::endl;
                            std::cout<<msg.str();
                            //stampa su file i dettagli del turno attuale, log F5
                            logger.log(msg.str());
                        }else if(propertyLevel==3) {
                            //stampa a console i dettagli del turno attuale, log 6
                            std::stringstream msg;
                            msg << "Giocatore " << actualPlayer->getPlayerNumber() << " ha migliorato una casa in albergo sul terreno "<< actualPlayer->getPosition() << std::endl;
                            std::cout<<msg.str();
                            //stampa su file i dettagli del turno attuale, log F6
                            logger.log(msg.str());
                        }
                    }else if(input==std::string("show")){
                        throw showRequestException();
                    }
                }
            }
        }
    }else if(owner!=nullptr){
        //proprietà occupata ma non dall'actual player
        actualPlayer->withdraw(getRentCost());
        owner->deposit(getRentCost());

        //stampa a console i dettagli del turno attuale, log 7
        std::stringstream msg;
        msg << "Giocatore " << actualPlayer->getPlayerNumber() << " ha pagato "<< getRentCost() << " fiorini a giocatore "<< owner->getPlayerNumber()<<" per pernottamento nella casella "<< actualPlayer->getPosition()<< std::endl;
        std::cout << msg.str();
        //stampa su file i dettagli del turno attuale, log F7
        logger.log(msg.str());

    }else if(owner==nullptr){
        //acquistabile
        if (actualPlayer->getPlayerType() == 1) {
            //pc, se ha abbastanza soldi compra/migliora
            if (actualPlayer->getMoney() >= getUpgradeCost()){
                //probabilità del 25%, se possiede abbastanza soldi
                if(actualPlayer->takeDecision()){
                    actualPlayer->withdraw(getUpgradeCost());
                    owner=actualPlayer;
                    upgradePropertyLevel();
                    //stampa a console i dettagli del turno attuale, log 4
                    std::stringstream msg;
                    msg<<"Giocatore "<<actualPlayer->getPlayerNumber()<<" ha acquistato il terreno "<<actualPlayer->getPosition()<<std::endl;
                    std::cout<<msg.str();
                    //stampa su file i dettagli del turno attuale, log F4
                    logger.log(msg.str());
                }
            }
        }else{
            //human, chiedo cosa vuole fare solo se ha abbastanza soldi
            if (actualPlayer->getMoney() >= getUpgradeCost()) {
                std::cout << "Vuoi acquistare la proprieta'? costo: " << getUpgradeCost() << " fiorini"<<std::endl;
                std::string input;
                std::getline(std::cin, input);
                if (input == std::string("s")) {
                    actualPlayer->withdraw(getUpgradeCost());
                    owner=actualPlayer;
                    //stampa a console i dettagli del turno attuale, log 4
                    std::stringstream msg;
                    msg<<"Giocatore "<<actualPlayer->getPlayerNumber()<<" ha acquistato il terreno "<<actualPlayer->getPosition()<<std::endl;
                    std::cout<<msg.str();
                    //stampa su file i dettagli del turno attuale, log F4
                    logger.log(msg.str());
                }else if(input==std::string("show")){
                    throw showRequestException();
                }
            }
        }
    }
}

void BoardBoxProperty::eraseOwner() {
    //cancella il proprietario e riinizializza l'oggetto
    owner=nullptr;
    propertyLevel=0;
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
            //output += "|";
            break;
        case 2:
            output = typeCharacter;
            output += '*';
            break;
        case 3:
            output = typeCharacter;
            output += '^';
            break;
    }
    return output;
}
int BoardBoxProperty::getUpgradeCost(){
    if(propertyLevel==1)
        return housePrice;
    else if(propertyLevel==2)
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