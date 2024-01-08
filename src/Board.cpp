#include "../include/Board.h"
#include "../include/BoardManager.h"
#include "../include/Pc.h"
#include "../include/Human.h"
#include "../include/BoardBoxStart.h"
#include <algorithm>
#include <iostream>


void Board::move(int n){
    int actualPosition = listPosition[playerRound];
    listPosition[playerRound] = movePlayer(actualPosition, n, getLength());

    //controllo del tipo di casella
    int boxType = listBox[listPosition[playerRound]]->getType();
    switch (boxType) {
        case 0:
            //START, ritiro di X fiorini al giocatore attuale
            Player* actualPlayer = listPlayer[playerRound];
            actualPlayer->deposit(n);
            break;
        case 1:
            //ANGOLARE, passo il turno
            //TODO prossimo turno
            break;
        default: //caso std, eco, lux
        // STD, verifico la disponibilità in denaro, solo se è tale da procedere all'acquisto chiedo all'utente cosa fare, se sono nel turno Human altrimenti non chiedo
            if(listBox[listPosition[playerRound]]->getHouseType()==0){
                //proprietà libera
                if(listPlayer[playerRound]->getMoney() >= listBox[listPosition[playerRound]]->getPrice()){
                    //player attuale ha abbastanza soldi
                    if(listPlayer[playerRound]->getPlayerNumber()==1){
                        //PC, compra per default
                        //TODO ACQUISTO
                    }else{
                        //UMANO, chiedo se vuole comprare
                        //TODO RICHIESTA
                    }
                }
            break;
    }
    //eventuali azioni
}

int Board::getLength() {
    return sizeof(listBox) / sizeof(listBox[0]);
}

Board :: Board(int gameType){
    Player p = Pc();
    Player pp = Pc();
    Player ppp = Pc();
    Player* pppp;

    if(gameType == 1){
        pppp = new Pc();
        gameMode = 1;
    } else if( gameType == 2){
        pppp = new Human();
        gameMode = 2;
    }

    setPlayersOrder(&p, &pp, &ppp, pppp);
    assignBoxType();

}

void Board :: setPlayersOrder(Player* p, Player* pp, Player* ppp, Player* pppp){
    int arrD[4];

    Player* arrP[]= {p,pp,ppp,pppp};

    std::cout << "I giocatori tirano i dadi per decidere l'ordine di gioco:" << std::endl;

    for(int i=0; i<4; i++){
        arrD[i] = arrP[i]->throwDices();
    }


    for (int i = 0; i < 4 - 1; ++i) {
        for (int j = 0; j < 4 - i - 1; ++j) {
            if (arrD[j] > arrD[j + 1]) {
                // Scambia gli elementi se non sono in ordine
                std::swap(arrD[j], arrD[j + 1]);
                std::swap(arrP[j], arrP[j + 1]);
            }
        }
    }


    addPlayer({arrP[0], arrP[1], arrP[2], arrP[3]});

}

void Board::assignBoxType(){
    listBox[0] = new BoardBoxStart();

    //assegnazione caselle economiche
    for(int i=0;i<8;i++){
        int n = std::rand() % getLenght();
    }
}