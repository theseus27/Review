//DEFINE
#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "pokemon.h"

//Define Class
class Trainer {
    public:
        //Constructor
        Trainer(std::string filename);
        //Destructor
        ~Trainer();

        std::string getName();
        Pokemon* getPokemon(int ind);
        Pokemon* activePokemon();

    private:
        std::string name;
        std::vector<Pokemon*>team;
};

//END DEFINE
#endif