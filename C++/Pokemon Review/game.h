#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "trainer.h"
#include "pokemon.h"

class Game {
    public:
        //Functions
        Game(std::string t1Data, std::string t2Data);
        ~Game();
        void play();

        //Variables
        const int NUM_POKEMON = 6;

    private:
        //Functions
        bool takeTurn();
        bool attack();
        bool switchActive();
        bool useItem();

        //Variables
        Trainer *t1;
        Trainer *t2;
        bool go;
        int turn;
        Trainer *activeTrainer;
        Trainer *inactiveTrainer;

};

#endif