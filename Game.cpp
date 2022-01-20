#include <iostream>
#include "Game.h"

void Game::printBoard(std::string board[][3])
{
    std::cout << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "    ";
        for (int j = 0; j < 3; j++) {
            if (i % 2 == 1) {
                std::cout << "---";
                continue;
            }
            else {
                if (j < 2) {
                    std::cout << board[i/2][j] << " | ";
                }
                else {
                    std::cout << board[i/2][j];
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Game::validMove(std::string board[][3], int x, int y)
{
    if ((x < 4) && (x > 0) && (y < 4) && (y > 0)) {
        if (board[x-1][y-1] == "-") {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void Game::playMove(std::string board[][3], int x, int y, bool turnX)
{
    char c = 'x';

    if (turnX) {
        c = 'x';
    }
    else {
        c = 'o';
    }
    board[x - 1][y - 1] = c;
}

bool Game::checkWinner(std::string board[][3])
{
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && ((board[i][0] == "x") || (board[i][0] == "o"))) {
            return true;
        }
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && ((board[0][i] == "x") || (board[0][i] == "o"))) {
            return true;
        }
    }
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && ((board[0][0] == "x") || (board[0][0] == "o"))) {
        return true;
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && ((board[0][2] == "x") || (board[0][2] == "o"))) {
        return true;
    }
    return false;
}
