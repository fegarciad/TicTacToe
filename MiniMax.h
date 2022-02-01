#pragma once
#include <vector>
#include <tuple>
#include "Game.h"

class MiniMax
{
	public:
		MiniMax();
		
		std::tuple<int, int> find_best_move(Game g, int type);
		std::vector< std::tuple<int, int> > legal_moves(Game g);
		
		int alpha_beta(Game g, std::vector< std::tuple<int, int> > legal_moves, int depth, int alpha, int beta, bool maximizing);
		int basic(Game g, std::vector< std::tuple<int, int> > legal_moves, int depth, bool maximizing);
		std::tuple<int, int> random_move(Game g);
		
		std::tuple<int, int> best_move;
		int calculations;
};

