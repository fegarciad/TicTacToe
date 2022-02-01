#include <iostream>
#include "Game.h"
#include "MiniMax.h"

int main()
{
    Game game;
    MiniMax minimax;

    game.set_players();
    bool humam_turn;

    std::tuple<int, int> engine_move;
    
    int x;
    int y;

    bool playing = true;
    
    while (playing)
    {
        game.main_screen();

        humam_turn = (game.is_x_turn and game.playerX) or (not game.is_x_turn and game.playerO);

        if (humam_turn and not game.check_winner()) {
            std::cin >> x >> y;
        }
        else {
            //Search type, 1: alpha beta, 2: basic, 3: random
            engine_move = minimax.find_best_move(game, 2);
            if (engine_move == std::make_tuple(0, 0)) {
                engine_move = minimax.random_move(game);
            }
            x = std::get<0>(engine_move);
            y = std::get<1>(engine_move);
        }

        if (x == 0 && y == 0) {
            game.undo_move();
            if (!game.playerX or !game.playerO) {
                game.undo_move();
            }
        }

        if (game.valid_move(x, y)) {
            game.play_move(x, y);
        }
        else {
            continue;
        }
        
        if (game.check_winner()) {
            playing = false;
            game.print_result(false);
            main();
        }

        if (game.turns > 8 && not game.check_winner()) {
            playing = false;
            game.print_result(true);
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
