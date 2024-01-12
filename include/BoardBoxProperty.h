
#ifndef PROVAFINALE_BOARDBOXPROPERTY_H
#define PROVAFINALE_BOARDBOXPROPERTY_H

#include <iostream>
#include "BoardBox.h"
#include "Player.h"

class BoardBoxProperty : public BoardBox{

public:
    BoardBoxProperty();
    BoardBoxProperty(char typeCharacter_, int price_, int housePrice_, int hotelPrice_, int houseNightPrice_, int hotelNightPrice_);
    std::string getBoxType() override;
    char getTypeCharacter() override;
    int getPropertyLevel() const;
    void action(Player* actualPlayer) override;
    void eraseOwner() override;
    Player* getOwner() override;
    void setOwner(Player* owner_);
    std::string toString() override;

protected:
    int price, housePrice, hotelPrice, houseNightPrice, hotelNightPrice;
    Player* owner = nullptr;
    int propertyLevel=0; //0->non di propeietà 1->di proprietà 2->con casa 3->con albergo
    int getUpgradeCost();
    int getRentCost();
    void upgradePropertyLevel();
    virtual ~BoardBoxProperty();

private:

};

#endif //PROVAFINALE_BOARDBOXPROPERTY_H