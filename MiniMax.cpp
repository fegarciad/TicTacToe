#include <random>
#include "MiniMax.h"
#include "Game.h"

MiniMax::MiniMax(): calculations(0), best_move(std::make_tuple(0, 0)) {
}

std::tuple<int, int> MiniMax::find_best_move(Game g, int type) {
	MiniMax::calculations = 0;
	MiniMax::best_move = std::make_tuple(0, 0);

	switch (type) {
	case 1:
		MiniMax::alpha_beta(g, MiniMax::legal_moves(g), 0, INT_MIN, INT_MAX, true);
		break;
	case 2:
		MiniMax::basic(g, MiniMax::legal_moves(g), 0, true);
	case 3:
		MiniMax::random_move(g);
	default:
		MiniMax::basic(g, MiniMax::legal_moves(g), 0, true);
	}
	
	return MiniMax::best_move;
}

int MiniMax::alpha_beta(Game g, std::vector< std::tuple<int, int> > legal_moves, int depth, int alpha, int beta, bool maximizing) {
	MiniMax::calculations++;

	if (g.turns > 8 && not g.check_winner()) {
		return 0;
	}
	if (g.check_winner()) {
		return (!maximizing) ? 1 : -1;
	}

	int score;

	if (maximizing) {
		int best_score = INT_MIN;
		for (std::tuple<int, int> move : legal_moves) {
			g.play_move(std::get<0>(move), std::get<1>(move));
			score = MiniMax::alpha_beta(g, MiniMax::legal_moves(g), depth + 1, alpha, beta, false);
			g.undo_move();

			if (depth == 0 && score >= best_score) {
				MiniMax::best_move = move;
			}
			best_score = std::max(score, best_score);

			alpha = std::max(best_score, alpha);
			if (beta <= best_score) {
				break;
			}
		}
		return best_score;
	}
	else {
		int best_score = INT_MAX;
		for (std::tuple<int, int> move : legal_moves) {
			g.play_move(std::get<0>(move), std::get<1>(move));
			score = MiniMax::alpha_beta(g, MiniMax::legal_moves(g), depth + 1, alpha, beta, true);
			g.undo_move();

			best_score = std::min(score, best_score);

			beta = std::min(best_score, beta);
			if (best_score <= alpha) {
				break;
			}
		}
		return best_score;
	}
}

int MiniMax::basic(Game g, std::vector< std::tuple<int, int> > legal_moves, int depth, bool maximizing) {
	MiniMax::calculations++;

	if (g.turns > 8 && not g.check_winner()) {
		return 0;
	}
	if (g.check_winner()) {
		return (!maximizing) ? 1 : -1;
	}

	int score;

	if (maximizing) {
		int best_score = INT_MIN;
		for (std::tuple<int, int> move : legal_moves) {
			g.play_move(std::get<0>(move), std::get<1>(move));
			score = MiniMax::basic(g, MiniMax::legal_moves(g), depth + 1, false);
			g.undo_move();

			if (depth == 0 && score >= best_score) {
				MiniMax::best_move = move;
			}
			best_score = std::max(score, best_score);
		}
		return best_score;
	}
	else {
		int best_score = INT_MAX;
		for (std::tuple<int, int> move : legal_moves) {
			g.play_move(std::get<0>(move), std::get<1>(move));
			score = MiniMax::basic(g, MiniMax::legal_moves(g), depth + 1, true);
			g.undo_move();

			best_score = std::min(score, best_score);
		}
		return best_score;
	}
}

std::tuple<int, int> MiniMax::random_move(Game g) {
	std::vector< std::tuple<int, int> > moves = MiniMax::legal_moves(g);
	std::random_device random_dev;
	std::mt19937 generator(random_dev());
	std::shuffle(moves.begin(), moves.end(), generator);
	MiniMax::best_move = moves[0];
	return moves[0];
}

std::vector< std::tuple<int, int> > MiniMax::legal_moves(Game g) {
	std::vector< std::tuple<int, int> > move_vector;
	std::tuple<int, int> move;

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (g.board[i - 1][j - 1] == "-") {
				move = std::make_tuple(i, j);
				move_vector.push_back(move);
			}
		}
	}
	return move_vector;
}
