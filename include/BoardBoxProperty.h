
#ifndef PROVAFINALE_BOARDBOXPROPERTY_H
#define PROVAFINALE_BOARDBOXPROPERTY_H

#include <iostream>
#include "BoardBox.h"
#include "Player.h"

class BoardBoxProperty : public BoardBox{

    public:
        /* BoardBoxProperty:
         * Costruttore di default.
         */
        BoardBoxProperty();
        /* BoardBoxProperty:
         * Costruttore con inizializzazione.
         */
        BoardBoxProperty(char typeCharacter_, int price_, int housePrice_, int hotelPrice_, int houseNightPrice_, int hotelNightPrice_);
        /* getBoxType:
         * Restituisce la tipologia della casella.
         */
        std::string getBoxType() override;
        /* getTypeCharacter:
         * Restituisce il carattere identificativo della casella.
         */
        char getTypeCharacter() override;
        /* getPropertyLevel:
         * out: 'int propertyLevel': 0 se non di propeietà, 1 se di proprietà, 2 se con casa, 3 se con albergo
         * Restituisce il livello della proprietà.
         */
        int getPropertyLevel() override;
        /* action:
         * in: Player* actualPlayer, giocatore la cui posizione conincide con questa casella
         * Gestisce le meccaniche di gioco della determinata casella.
         */
        void action(Player* actualPlayer) override;
        /* eraseOwner:
         * Resetta il proprietario della casella.
         */
        void eraseOwner() override;
        /* getOwner:
         * Restituisce il proprietario della casella.
         */
        Player* getOwner() override;
        /* setOwner:
         * Permette di salavare il proprietario della casella.
         */
        void setOwner(Player* owner_);
        /* toString:
         * Restituisce una descrizione testuale della casella
         */
        std::string toString() override;

    protected:
        //prezzi
        int price, housePrice, hotelPrice, houseNightPrice, hotelNightPrice;
        //giocatore proprietario
        Player* owner = nullptr;
        //livello della proprietà: 0 se non di propeietà, 1 se di proprietà, 2 se con casa, 3 se con albergo
        int propertyLevel=0;
        /* getUpgradeCost:
         * out: prezzo per il miglioramento, se disponibile.
         * Restituisce il prezzo del miglioramento se è disponibile.
         */
        int getUpgradeCost();
        /* getRentCost:
         * out: prezzo per il pernottamento, se disponibile.
         * Restituisce il prezzo del pernottamento se è disponibile.
         */
        int getRentCost();
        /* upgradePropertyLevel:
         * Permette di aumentare il livello della proprietà, se disponibile.
         */
        void upgradePropertyLevel();
        //TODO distruttore rimosso
        //virtual ~BoardBoxProperty();

    private:

};

#endif //PROVAFINALE_BOARDBOXPROPERTY_H