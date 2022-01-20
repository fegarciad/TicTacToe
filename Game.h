#pragma once

class Game
{
	public:
		void printBoard(std::string board[][3]);
		bool validMove(std::string board[][3], int x, int y);
		void playMove(std::string board[][3], int x, int y, bool turnX);
		bool checkWinner(std::string board[][3]);
		std::string board[3][3] = {
			{ "-","-","-" },
			{ "-","-","-" },
			{ "-","-","-" }
			};
};
