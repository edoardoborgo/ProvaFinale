
#ifndef PROVAFINALE_LOGGER_H
#define PROVAFINALE_LOGGER_H

#include <string>
#include<fstream>
#include "exceptions.h"

class Logger{
    public:
        Logger(std::string fileName_){
            fileName="../"+fileName_;
            if(fileName=="")
                throw loggerException("Nome file vuoto.");
            outFile.open(fileName);
            outFile.close();
        }
        ~Logger() {
            if (outFile.is_open()) {
                outFile.close();
            }
        }
        void log(std::string logText){
            outFile.open(fileName, std::ios::app);
            if (!outFile.is_open()) {
                //errore in apertura file
                throw loggerException("Errore in apertura file.");
            }else{
                outFile << logText;
            }
            outFile.close();
        }

    private:
        std::string fileName;
        std::ofstream outFile;
};

#endif //PROVAFINALE_LOGGER_H