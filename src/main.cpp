#include <iostream>
#include <string>

#include "../include/Board.h";

int main(int argc, char* argv[]) {
    Board* playBoard;
    if(argc==2){
        //viene passato un parametro, COMPUTER oppure HUMAN
        if(std::string(argv[1])=="HUMAN"){
            //3 computer 1 human
            playBoard = new Board(1);

        }else if(std::string(argv[1])=="COMPUTER"){
            //4 computer
            playBoard = new Board(2);
        }else{
            //errore inserimento parametro
        }
    }






    return 0;
}
