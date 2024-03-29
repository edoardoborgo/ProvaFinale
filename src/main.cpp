#include <iostream>
#include <string>
#include "../include/Board.h"
#include "../include/GlobalLogger.h"

int main(int argc, char* argv[]) {
    Board* playBoard;
    logger.log("ciao");
    if(argc==2){
        //viene passato un parametro, COMPUTER oppure HUMAN
        if(std::string(argv[1])=="COMPUTER"){
            //3 COMPUTER 1 HUMAN
            playBoard = new Board(1);
        }else if(std::string(argv[1])=="HUMAN"){
            //4 COMPUTER
            playBoard = new Board(2);
        }else{
            //errore inserimento parametro
            std::cout<<"Errore inserimento parametro scelta della modalità di gioco."<<std::endl;
            return 0;
        }

        while(!playBoard->endedGame()){
            playBoard->move();
            playBoard->nextPlayerRound();
        }
    }else{
        std::cout<<"Errore inserimento parametro scelta della modalità di gioco."<<std::endl;
        return 0;
    }

    return 0;
}