//Include THIS .h file
#include "pokemon.h"
using namespace std;

Pokemon::Pokemon(string data) {
    stringstream sstream;
    sstream.str(data);
    sstream >> name >> attack >> defense >> HP >> spAtt >> spDef >> speed;
    while(!sstream.eof() && moveset.size() < 4) {
        string newMove = "";
        sstream >> newMove;
        moveset.push_back(newMove);
    }
}

Pokemon::~Pokemon() {

}

string Pokemon::getName() {
    return name;
}

vector<string> Pokemon::listMoves() {
    return moveset;
}







