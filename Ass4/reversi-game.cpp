// Name:       ZHANG ZHIRUI
// Student ID: 1155174021
// Email:      1155174021@link.cuhk.edu.hk

#include <iostream>
#include "reversi.h"

/* You may include more headers here if necessary. */
using namespace std;


// TODO: Write your main function here
int main()
{
	char board[N][N];
	//初始化board
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = '.';
		}
	}

	board[(N / 2) - 1][(N / 2) - 1] = 'X';
	board[(N / 2) - 1][(N / 2)] = 'O';
	board[(N / 2)][(N / 2) - 1] = 'O';
	board[(N / 2)][(N / 2)] = 'X';

	int n_B;
	int num;
	char xo = 0;
	int yo = 0, x = 0, y = 0;


	cout << "Enter number of blocks: ";
	cin >> n_B;
	while (n_B > ((N * N) / 2)) {
		cout << "Too many blocks!\n";
		cout << "Enter number of blocks : ";
		cin >> n_B;
	}

	for (num = 0; num < n_B;) {
		cout << "Enter position for block " << num + 1 << ":";
		cin >> xo >> yo;
		if (xo <= 90 and xo >= 65)
			x = xo - 65;
		if (xo <= 122 and xo >= 97)
			x = xo - 97;
		y = yo - 1;
		if ((x >= N or x < 0) or (y >= N or y < 0) or board[y][x] != '.') {
			cout << "Invalid position!\n";
			continue;
		}
		board[y][x] = '#';
		num++;
	}
	//上面是确认block，下面开始下棋

	char p = 'X';
	int emer = 0;
	int round = 1;
	bool flip = 0;
	while (true) {



		int ec = 0, vm = 0;
		ec = has_empty_cells(board);
		vm = has_valid_moves(board, p);
		if (ec == 0) {
			cout << "Game over:\n";
			print_board(board);

			int score_x = 0, score_o = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (board[i][j] == 'X')
						score_x++;
					if (board[i][j] == 'O')
						score_o++;
				}
			}
			if (score_x > score_o)
				cout << "Player X wins!\n";
			if (score_x < score_o)
				cout << "Player O wins!\n";
			else
				cout << "Draw game!\n";
			break;
		}
		else {

			cout << "Round " << round << ":\n";
			print_board(board);

			if (vm == 0 or ec == 0) {
				cout << "Player " << p << " has no valid moves!Pass!\n";
				if (p == 'X')
					p = 'O';
				else
					p = 'X';
				round++;
				emer++;
				if (emer == 2) {
					cout << "Game over:\n";
					print_board(board);

					int score_x = 0, score_o = 0;
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							if (board[i][j] == 'X')
								score_x++;
							if (board[i][j] == 'O')
								score_o++;
						}
					}
					if (score_x > score_o)
						cout << "Player X wins!\n";
					if (score_x < score_o)
						cout << "Player O wins!\n";
					if (score_x == score_o)
						cout << "Draw game!\n";
					break;
				}
				else
					continue;
			}
			else {
				if (emer == 2) {
					cout << "Game over:\n";
					print_board(board);

					int score_x = 0, score_o = 0;
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							if (board[i][j] == 'X')
								score_x++;
							if (board[i][j] == 'O')
								score_o++;
						}
					}
					if (score_x > score_o)
						cout << "Player X wins!\n";
					if (score_x < score_o)
						cout << "Player O wins!\n";
					else
						cout << "Draw game!\n";
					break;
				}
				else {

					char mxo = 0;
					int myo = 0, mx = 0, my = 0;

					if (p == 'X')
						cout << "Player X's turn: ";
					if (p == 'O')
						cout << "Player O's turn: ";

					cin >> mxo >> myo;
					if (mxo <= 90 and mxo >= 65)
						mx = mxo - 65;
					if (mxo <= 122 and mxo >= 97)
						mx = mxo - 97;
					my = myo - 1;

					//bool deci_v = 0;

					//deci_v = valid_move(board, p, my, mx, flip);
					while (valid_move(board, p, my, mx, flip) == 0) {
						cout << "Invalid move!\n";
						cout << "Player " << p << "'s turn: ";
						cin >> mxo >> myo;
						if (mxo <= 90 and mxo >= 65)
							mx = mxo - 65;
						if (mxo <= 122 and mxo >= 97)
							mx = mxo - 97;
						my = myo - 1;

						//int deci_v = 0;

						//deci_v = valid_move(board, p, my, mx, flip);
					}
					emer = 0;
					if (p == 'X')
						p = 'O';
					else
						p = 'X';
					round++;
				}
			}
		}

	}
	
	

}