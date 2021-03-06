/**
 * Copyright 2019 Umich EECS 183
 *
 * battleship.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * Project 4: Battleship
 *
 * Drive of the Battleship game.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <utility>
#include <limits>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


int main() {
    print_initial_header();
    
    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName);
    
    Player p1(playerName);
    Player p2("CPU");
    
    char gridChoice1 = ' ';
    char gridChoice2 = ' ';
    cout << "Read your grid from file grid1.txt? (y or n): ";
    cin >> gridChoice1;
    cout << "Read CPU grid from file grid2.txt? (y or n): ";
    cin >> gridChoice2;
    
    Game game;
    
    if (gridChoice1 == 'y' && gridChoice2 == 'y') {
        game = Game(p1, "grid1.txt", p2, "grid2.txt");
    }
    else if (gridChoice1 == 'y' && gridChoice2 == 'n') {
        game = Game(p1, "grid1.txt", p2, "");
    }
    else if (gridChoice1 == 'n' && gridChoice2 == 'y') {
        game = Game(p1, "", p2, "grid2.txt");
    }
    else {
        game = Game(p1, "", p2, "");
    }
    
    int menuChoice = get_menu_choice();
    while (menuChoice == 2) {
        cout << "Under Construction" <<endl;
        menuChoice = get_menu_choice();
    }
    if (menuChoice == 4) {
        print_closer();
        return 0;
    }
    game.start(EASY, MAX_ROUNDS);
    
    print_closer();

/* 
    TODO: implement the following steps. 
    
    (Note: some menus and prompts should be printed using 
       functions utility.cpp, see sample runs.)

    1. You must enter your name.

        Prompt: "Enter your name:"

    2. Print prompt and get user input from keyboard to specify whether 
    not to read your grid from a file. The input must be the chracter 'y' or 'n'.

        Prompt: "Read your grid from file grid1.txt? (y or n):"
        Note: You may assume that a user will enter correct, valid input. 

    3. Print prompt and get user input from keyboard to specify whether 
    not to read the CPU's grid from a file. The input must be the chracter 'y' or 'n'.

        Prompt: "Read CPU grid from file grid2.txt? (y or n):"
        Note: You may assume that a user will enter correct, valid input. 
    
    4. Print menu and get the menu choice from keyboard to select the 
    difficulty of the AI or quit the game. Make use of get_menu_choice in utility.cpp. 
        
        Prompts: "Starting game with EASY AI"
                 "Starting game with MEDIUM AI"
                 "Starting game with CPU EMULATION"
        Note 1: the medium AI is not available unless you implement S'more. 
        Note 2: CPU emulation is for debugging purposes and will NOT be autograder tested.

    5. Start the game with given difficulty and MAX_ROUNDS number of rounds.

    (Note: you will only play one instance of the game, i.e., after the game ends, 
       the program ends.)
*/
    return 0;
}
