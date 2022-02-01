#pragma once
#include <vector>

class Game 
{
	public:
		void set_players();
		void main_screen();
		void print_board();
		void print_result(bool is_draw);
		bool valid_move(int x, int y);
		void play_move(int x, int y);
		void undo_move();
		bool check_winner();
	
		bool is_x_turn = true;
		bool playerX = true;
		bool playerO = true;
		int turns = 0;
		std::vector<int> row_history;
		std::vector<int> column_history;
		std::string board[3][3] = {
			{ "-","-","-" },
			{ "-","-","-" },
			{ "-","-","-" }
		};
};
