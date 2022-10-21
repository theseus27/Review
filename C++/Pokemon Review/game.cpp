#include "game.h"
using namespace std;

Game::Game(string t1Data, string t2Data) {
    //Create Trainers
    t1 = new Trainer(t1Data);
    t2 = new Trainer(t2Data);
    //Initialize Variables
    go = true;
    turn = 0;
}

Game::~Game() {

}

void Game::play() {
    while(go) {
        if ((turn % 2) == 0) {
            activeTrainer = t1;
            inactiveTrainer = t2;
        } else {
            activeTrainer = t2;
            inactiveTrainer = t1;
        }

        cout << "It is " << activeTrainer->getName() << "'s turn." << endl;
        cout << "On the battlefield is: " << activeTrainer->getName() << "'s " << activeTrainer->activePokemon()->getName() << " versus " << inactiveTrainer->getName() << "'s " << inactiveTrainer->activePokemon()->getName() << "." << endl << endl;

        go = takeTurn();
        turn += 1;
    }
}

bool Game::takeTurn() {
    bool finishTurn = false;
    while (!finishTurn) {
        string action = "";
        cin >> action;
        if (action == "attack") {
            return attack();
        } else if (action == "switch") {
            return switchActive();
        } else if (action == "item") {
            return useItem();
        } else {
            cout << "Invalid Action. Your options are 'attack', 'switch', or 'item'." << endl;
            finishTurn = false;
        }
    }
}

bool Game::attack() {
    vector<string> moves = activeTrainer->activePokemon()->listMoves();

    cout << "Moves" << endl << endl;;
    for (int i = 0; i < moves.size(); i++) {
        cout << moves[i] << endl;
    }

    string move = "";
    while (!(find(moves.begin(), moves.end(), move) != moves.end())) {
        cout << endl << "Which move do you want to use? ";
        cin >> move;
    }

    return true;
}

bool Game::switchActive() {
    return true;
}

bool Game::useItem() {
    return true;
}

/*
bool takeTurn(int turn);

//INITIALIZING VARIABLE
    bool go = true;
    int turn = 0;

    //GAME LOOP
    while (go == true) {
        go = takeTurn(turn);
        turn += 1;
        turn = turn%2;
    }

// OTHER FUNCTIONS
void createTrainers(string t1Data, string t2Data) {

    //Initializing an instance of a class
    Trainer trainer1 = Trainer(t1Data);
    Trainer trainer2 = Trainer(t2Data);

    return;
}

bool takeTurn(int turn) {
    return true;
}
*/