#include "../include/Board.h"
#include "../include/BoardBoxProperty.h"
#include "../include/BoardBoxBlank.h"
#include "../include/BoardManager.h"
#include "../include/Pc.h"
#include "../include/Human.h"
#include <algorithm>
#include <iostream>
#include <initializer_list>



void Board::move(){
    int shift = listPlayer[playerRound]->throwDices();
    int actualPosition = listPosition[playerRound];
    listPosition[playerRound] = movePlayer(actualPosition, shift);

    int newPosition;
    try{
        newPosition = movePlayer(actualPosition, shift);
    }catch(completeTurn& e){
        newPosition = e.getNewPosition();
        //accredito di 20 fiorini al giocatore attuale
    }

    //se 'blank' esegue il metodo action vuoto, se 'property' esegue il metodo action che gestisce le meccaniche di gioco
    //interrompe il turno se un giocatore finisce i soldi, eccezione sollevata da withdraw nel momento in cui bisogna pagare l'affitto ad un altro giocatore
    try{
        listBox[listPosition[playerRound]]->action(listPlayer[playerRound]);
    }catch(outOfMoney& e){
        //actualPlayer ha terminato i soldi
        deletePlayer(listPlayer[playerRound]);
    }
}

void Board::deletePlayer(Player* actualPlayer){
    for(int i=0; i<28; i++){
        if(listBox[i]->getOwner()==actualPlayer)
            listBox[i]->eraseOwner();
    }
}

int Board::getLength() {
    return sizeof(listBox) / sizeof(listBox[0]);
}

void Board::nextPlayerRound(){
    playerRound = (playerRound+1)%4;
}

Board::Board(int gameType){
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

void Board::setPlayersOrder(Player* p, Player* pp, Player* ppp, Player* pppp){
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


    //addPlayer({arrP[0], arrP[1], arrP[2], arrP[3]});

}

/*void Board::addPlayer(std::initializer_list<Player*> lst){

}*/

void Board::assignBoxType(){
    listBox[0] = new BoardBoxBlank('P');
    listBox[7] = new BoardBoxBlank(' ');
    listBox[14] = new BoardBoxBlank(' ');
    listBox[21] = new BoardBoxBlank(' ');

    //1 std, 2 eco, 3 lusso

    //assegnazione caselle economiche
    for(int i=0;i<8;i++){
        int n = std::rand() % getLength();
        if (listBox[n]->getBoxType() == "")      //check che non abbia già un tipo
            listBox[n] = new BoardBoxProperty('E',6,3,3,2,4);
    }

    //assegnazione caselle standard
    for(int i=0;i<10;i++){
        int n = std::rand() % getLength();

        if (listBox[n]->getBoxType() == "")      //check che non abbia già un tipo
            listBox[n] = new BoardBoxProperty('S',10, 5, 5, 4, 8);
    }


    //assegnazione caselle lusso
    for(int i=0;i<6;i++){
        int n = std::rand() % getLength();
        if (listBox[n]->getBoxType() == "")      //check che non abbia già un tipo
            listBox[n] = new BoardBoxProperty('L',20,10,10,7,14);
    }
}

void Board::show() {
    std::cout << "\t\t 1\t\t 2\t\t 3\t\t 4\t\t 5\t\t 6\t\t 7\t\t 8\nA";
    //output prima riga
    for(int i=0;i<8;i++){
        std::cout << "\t\t|" << listBox[i]->toString();
        for(int j=0;j<4;j++){
            if(listPosition[j] == i)
                std::cout << listPosition[j];
        }
        std::cout << '|';
    }
    char lineIndex = 'B';
    int leftColumnIndex=27, rightColumnIndex=8;
    for(int i=0;i<6;i++){
        std::cout << std::endl << lineIndex << "\t\t|" << listBox[leftColumnIndex]->toString();
        for(int j=0;j<4;j++){
            if(listPosition[j] == i)
                std::cout << listPosition[j];
        }
        std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t|" << listBox[rightColumnIndex]->toString();
        for(int j=0;j<4;j++){
            if(listPosition[j] == i)
                std::cout << listPosition[j];
        }
        std::cout << "|";
        leftColumnIndex--;
        rightColumnIndex++;
    }

    std::cout << std::endl << "H";
    for(int i=21;i>14;i--){
        std::cout << "\t\t|" << listBox[i]->toString();
        for(int j=0;j<4;j++){
            if(listPosition[j] == i)
                std::cout << listPosition[j];
        }
        std::cout << '|';
    }

    /*std::cout << "A\t\t|" << listBox[0] << "|\t\t|1|\t\t|2|\t\t|3|\t\t|4|\t\t|5|\t\t|6|\t\t|7|" << std::endl;
    std::cout << "B\t\t|" << listBox[27]->toString() << "|\t\t\t\t\t\t\t\t\t\t\t\t\t|8|\t" << std::endl;
    std::cout << "C\t\t|26|\t\t\t\t\t\t\t\t\t\t\t\t\t|9|\t" << std::endl;
    std::cout << "D\t\t|25|\t\t\t\t\t\t\t\t\t\t\t\t\t|10|\t" << std::endl;
    std::cout << "E\t\t|24|\t\t\t\t\t\t\t\t\t\t\t\t\t|11|\t" << std::endl;
    std::cout << "F\t\t|23|\t\t\t\t\t\t\t\t\t\t\t\t\t|12|\t" << std::endl;
    std::cout << "G\t\t|22|\t\t\t\t\t\t\t\t\t\t\t\t\t|13|\t" << std::endl;
    std::cout << "H\t\t|21|\t|20|\t|19|\t|18|\t|17|\t|16|\t|15|\t|14|" << std::endl;
     */
}