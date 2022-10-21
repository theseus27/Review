#include "trainer.h"
using namespace std;

//Constructor
Trainer::Trainer(string filename) {
    ifstream data(filename);
    if (data.fail()) {
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    getline(data, name);


    while(!data.eof() && team.size() < 6) {
        string info = "";
        getline(data, info);
        Pokemon *nextPokemon = new Pokemon(info);
        team.push_back(nextPokemon);
    }

    data.close();
}

//Destructor
Trainer::~Trainer() {
    team.clear();
}

Pokemon* Trainer::getPokemon(int ind) {
    return team[ind];
}

Pokemon* Trainer::activePokemon() {
    return team[0];
}

string Trainer::getName() {
    return name;
}