// Name:       ZHANG ZHIRUI
// Student ID: 1155174021
// Email:      1155174021@link.cuhk.edu.hk
#include <iostream>
#include <iomanip>
#include <string>
#include "TwinKnightsTour.h"
using namespace std;

TwinKnightsTour::TwinKnightsTour(int r1, int c1, int r2, int c2) {
	for (int n = 0; n < N; n++) {//n是行
		for (int m = 0; m < N; m++) {//m是列
			if ((n == r1 && m == c1) || (n == r2 && m == c2)) {
				if (n == r1 && m == c1)
					board[n][m] = ".";//!!!!!!!!!!!!!!!!!!!
				if (n == r2 && m == c2)
					board[n][m] = ".";
			}
			else
				board[n][m] = ".";
		}
	}
	posR1 = r1;//P1现在的位置（行）
	posC1 = c1;//P1现在的位置（列）
	posR2 = r2;//P2现在的位置（行）
	posC2 = c2;//P2现在的位置（列）
	steps1 = 0; 
	steps2 = 0;
	consec1 = 0;
	consec2 = 0;
}

void TwinKnightsTour::print() const {
	cout << "  ";//两个空格
	for (int n = 0; n < N; n++)
		cout << setw(3) << n;
	cout << '\n';
	for (int n = 0; n < N; n++) {
		cout << setw(2) << n;
		for (int m = 0; m < N; m++) {
			//cout << setw(3) << board[n][m];
			if (!((n == posR1 && m == posC1)|| (n == posR2 && m == posC2)))
				cout << setw(3) << board[n][m];
			if(n == posR1 && m == posC1)
				cout << setw(3) << "@";
			if (n == posR2 && m == posC2)
				cout << setw(3) << "#";
			// 
			//if (stoi(board[n][m]) != -1 && stoi(board[n][m]) != -2)
			//	cout << setw(3) << board[n][m];
			//if (stoi(board[n][m]) == -1)
			//	cout << setw(3) << "@";
			//if (stoi(board[n][m]) == -2)
			//	cout << setw(3) << "#";
		}
		cout << '\n';
	}
}

bool TwinKnightsTour::isValid(char knight, int r, int c) const {
	//r & c are the next step
	//posR & posC are where the knight is now(1/2)
	if (knight != '@' && knight != '#')//检查knight是否为@、#之一
		return false;
	else {
		if ((r < 0 || r >= N) || (c < 0 || c >= N))
			return false;
		else {
			if (board[r][c] != "." || (r == posR1 and c == posC1) || (r == posR2 and c == posC2))//!!!!!!!!!!!!!!!!!!!!
				return false;
			else {
				if (knight == '@') {
					if (consec1 >= 2)
						return false;
					else {
						if (((r == posR1 - 1) && (c == posC1 - 2)) || ((r == posR1 - 2) && (c == posC1 - 1)) || ((r == posR1 - 2) && (c == posC1 + 1)) || ((r == posR1 - 1) && (c == posC1 + 2)) || ((r == posR1 + 2) && (c == posC1 + 1)) || ((r == posR1 + 1) && (c == posC1 + 2)) || ((r == posR1 + 2) && (c == posC1 - 1)) || ((r == posR1 + 1) && (c == posC1 - 2)))
							return true;
						else
							return false;
					}
				}
				else {
					if (consec2 >= 2)
						return false;
					else {
						if (((r == posR2 - 1) && (c == posC2 - 2)) || ((r == posR2 - 2) && (c == posC2 - 1)) || ((r == posR2 - 2) && (c == posC2 + 1)) || ((r == posR2 - 1) && (c == posC2 + 2)) || ((r == posR2 + 2) && (c == posC2 + 1)) || ((r == posR2 + 1) && (c == posC2 + 2)) || ((r == posR2 + 2) && (c == posC2 - 1)) || ((r == posR2 + 1) && (c == posC2 - 2)))
							return true;
						else return false;
					}
				}
			}
		}
	}
}

bool TwinKnightsTour::hasMoreMoves() const {
	int vn = 0;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < N; m++) {
			if (isValid('@', n, m) == 1 || isValid('#', n, m) == 1)
				vn = 1;
		}
	}
	if (vn == 0)
		return 0;
	else
		return 1;
}

bool TwinKnightsTour::move(char knight, int r, int c) {
	if (isValid(knight, r, c) == 0)
		return false;
	else {
		if (knight == '@') {//将现在的这一位留下Aa
			if (steps1 < 26)
				board[posR1][posC1] = (char)('A' + steps1);
			if (steps1 == 26)
				board[posR1][posC1] = "AA";
			if (steps1 > 26) {

				int qt;//quotient
				int rd;//remainder
				qt = steps1 / 26;
				rd = steps1 % 26;

				board[posR1][posC1].at(0) = (char)('A' + qt - 1);
				board[posR1][posC1] += (char)('A' + rd);
			}
		}
		if (knight == '#') {
			if (steps2 < 26)
				board[posR2][posC2] = (char)('a' + steps2);
			if (steps2 == 26)
				board[posR2][posC2] = "aa";
			if (steps2 > 26) {
				int qt;//quotient
				int rd;//remainder
				qt = steps2 / 26;
				rd = steps2 % 26;
				board[posR2][posC2].at(0) = (char)('a' + qt - 1);
				board[posR2][posC2] += (char)('a' + rd);
			}
		}
		if (knight == '@') {//将下一位变为@# and change the value of posR(1/2) and posC(1/2)
			//board[r][c] = "@";
			posR1 = r;
			posC1 = c;
		}

		else {
			//board[r][c] = "#";
			posR2 = r;
			posC2 = c;
		}


		if (knight == '@'){ //修改steps1 steps2 consec1 consec2
			steps1++;
			consec1++;
			consec2 = 0;
		}
		else{
			steps2++;
			consec2++;
			consec1 = 0;
		}
		return true;
	}
}
