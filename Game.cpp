#include <iostream>
#include "Game.h"

void Game::set_players() {
    bool playerX;
    bool playerO;
    system("CLS");
    std::cout << std::endl << "           TIC-TAC-TOE" << std::endl;
    std::cout << std::endl << std::endl <<"  Player X: human [1] or cpu [0]  ";
    std::cin >> Game::playerX;
    system("CLS");
    std::cout << std::endl << "           TIC-TAC-TOE" << std::endl;
    std::cout << std::endl << std::endl << "  Player O: human [1] or cpu [0]  ";
    std::cin >> Game::playerO;
}

void Game::main_screen() {
    system("CLS");
    std::cout << std::endl << "           TIC-TAC-TOE" << std::endl;
    Game::print_board();
    std::cout << "   Enter row and column separated" << std::endl << "   by a space (0 0 to undo move): ";
}

void Game::print_board() {
    std::cout << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "            ";
        for (int j = 0; j < 3; j++) {
            if (i % 2 == 1) {
                std::cout << "---";
                continue;
            }
            else {
                if (j < 2) {
                    std::cout << Game::board[i/2][j] << " | ";
                }
                else {
                    std::cout << Game::board[i/2][j];
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Game::print_result(bool is_draw) {
    int place_holder;
    system("CLS");
    if (is_draw) {
        std::cout << std::endl << "            No winner" << std::endl;
    }
    else {
        char winner = (not Game::is_x_turn) ? 'X' : 'O';
        std::cout << std::endl << "         " << winner << " is the winner!" << std::endl;
    }
    Game::print_board();
    std::cout << std::endl << "  ";
    system("PAUSE");
}

bool Game::valid_move(int x, int y) {
    if ((x < 4) && (x > 0) && (y < 4) && (y > 0)) {
        if (Game::board[x-1][y-1] == "-") {
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

void Game::play_move(int x, int y) {
    char c = 'x';

    if (is_x_turn) {
        c = 'x';
    }
    else {
        c = 'o';
    }

    Game::board[x - 1][y - 1] = c;
    Game::is_x_turn = not Game::is_x_turn;
    Game::turns++;
    Game::row_history.push_back(x);
    Game::column_history.push_back(y);
}

void Game::undo_move() {
    if (Game::row_history.size() > 0 && Game::column_history.size() > 0) {
        Game::board[Game::row_history.back() - 1][Game::column_history.back() - 1] = "-";
        Game::is_x_turn = not Game::is_x_turn;
        Game::turns--;
        Game::row_history.pop_back();
        Game::column_history.pop_back();
    }
}

bool Game::check_winner() {
    for (int i = 0; i < 3; i++) {
        if ((Game::board[i][0] == Game::board[i][1]) && (Game::board[i][1] == Game::board[i][2]) && ((Game::board[i][0] == "x") || (Game::board[i][0] == "o"))) {
            return true;
        }
        if ((Game::board[0][i] == Game::board[1][i]) && (Game::board[1][i] == board[2][i]) && ((Game::board[0][i] == "x") || (Game::board[0][i] == "o"))) {
            return true;
        }
    }
    if ((Game::board[0][0] == Game::board[1][1]) && (Game::board[1][1] == Game::board[2][2]) && ((Game::board[0][0] == "x") || (Game::board[0][0] == "o"))) {
        return true;
    }
    if ((Game::board[0][2] == Game::board[1][1]) && (Game::board[1][1] == Game::board[2][0]) && ((Game::board[0][2] == "x") || (Game::board[0][2] == "o"))) {
        return true;
    }
    return false;
}
