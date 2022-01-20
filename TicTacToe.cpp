// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Game.h"

int main()
{
    Game game;
    
    int x = 0;
    int y = 0;

    bool playing = true;
    bool turnX = true;
    int turns = 0;
    
    while (playing)
    {
        system("CLS");

        std::cout << std::endl << "   TIC-TAC-TOE" << std::endl;
        game.printBoard(game.board);

        std::cout << "  Enter x and y coordinates (x y): ";
        std::cin >> x >> y;

        if (game.validMove(game.board, x, y)) {
            game.playMove(game.board, x, y, turnX);
            turnX = not turnX;
            turns++;
        }
        else {
            continue;
        }
        
        if (game.checkWinner(game.board)) {
            playing = false;
            system("CLS");
            char winner = (not turnX) ? 'X' : 'O';
            std::cout << std::endl << "  " << winner << " is the winner!" << std::endl;
            game.printBoard(game.board);
            system("pause");
            main();
        }

        if (turns > 8 && not game.checkWinner(game.board)) {
            playing = false;
            system("CLS");
            std::cout << std::endl << "    No winner" << std::endl;
            game.printBoard(game.board);
            system("pause");
            main();
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file