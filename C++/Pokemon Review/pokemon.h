//DEFINE
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//Define Class
class Pokemon {
    public:
        //Constructor
        Pokemon(std::string data);
        //Destructor
        ~Pokemon();

        std::string getName();
        int getNumber();
        int getAttack();
        int getDefense();
        int getHP();
        bool isAlive();
        std::vector<std::string> listMoves();

    private:
        void fight();
        bool checkAlive();

        std::string name;
        int attack;
        int defense;
        int HP;
        int spAtt;
        int spDef;
        int speed;
        std::vector<std::string>moveset;

};

//END DEFINE
#endif