// HEADER (File name, purpose, author, etc)
/*
    * Main.cpp
    * Reads in two files and initiates a game
    * Written by Theseus Lim
    * 7/18/22
*/

// INCLUDE LIBRARIES
#include <iostream>
#include <string>

//INCLUDE OTHER .h FILES
#include "game.h"

// USING
using namespace std;

// MAIN FUNCTION
int main(int argc, char *argv[]) {

    //CHECK ARG NUMBER (1 will be the function call)
    if (argc != 3) {
        cerr << "ERROR: Expecting 2 file names." << endl;
        exit(EXIT_FAILURE);
    }

    //CALLING A FUNCTION
    Game newGame(argv[1], argv[2]);
    newGame.play();

    return 0;
}

//--------------------------------------------------------------------------
/*
PARSING COMMAND LINE ARGUMENTS EXAMPLE     (done in main)
    if(argc < 3){
            cerr << "ERROR: Expecting 3 arguments << endl;
            exit(EXIT_FAILURE);
        }
    //Assign/open each arg as args[1], args[2], args[3]
*/
//--------------------------------------------------------------------------
/*
FSTREAM EXAMPLE



    ofstream outfile;
    outfile.open(args);
    outfile << element << endl;
    outfile.close()
*/
//--------------------------------------------------------------------------
/*
SSTREAM EXAMPLE
    stringstream sstream;
    sstream.str(query);
    string query1, arrival, departure;
    sstream >> query1 >> arrival >> departure;
*/
