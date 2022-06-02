#include"Board.h"
#include"Chess.h"
#include <iostream>

void Board::initializeBoard()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = "  ";
		}
	}

	// 放紅棋
	board[9][0] = "俥";
	board[9][1] = "傌";
	board[9][2] = "相";
	board[9][3] = "仕";
	board[9][4] = "帥";
	board[9][5] = "仕";
	board[9][6] = "相";
	board[9][7] = "傌";
	board[9][8] = "俥";
	board[7][1] = "炮";
	board[7][7] = "炮";
	board[6][0] = "兵";
	board[6][2] = "兵";
	board[6][4] = "兵";
	board[6][6] = "兵";
	board[6][8] = "兵";

	// 放黑棋
	board[0][0] = "車";
	board[0][1] = "馬";
	board[0][2] = "象";
	board[0][3] = "士";
	board[0][4] = "將";
	board[0][5] = "士";
	board[0][6] = "象";
	board[0][7] = "馬";
	board[0][8] = "車";
	board[2][1] = "砲";
	board[2][7] = "砲";
	board[3][0] = "卒";
	board[3][2] = "卒";
	board[3][4] = "卒";
	board[3][6] = "卒";
	board[3][8] = "卒";

}

/*
void Board::Print()
{
	system("CLS");

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (j != 8) {
				cout << board[i][j] << "_";
			}
			else {
				if (i != 9) {
					cout << board[i][j] << "\n|  |  |  |  |  |  |  |  |\n";
				}
				else {
					cout << board[i][j] << "\n";
				}
			}
		}
	}
}
*/

string Board::find(int x, int y)
{
	if (board[y][x] == "將" || board[y][x] == "帥") {
		return "General";
	}
	else if (board[y][x] == "士" || board[y][x] == "仕") {
		return "Advisor";
	}
	else if (board[y][x] == "象" || board[y][x] == "相") {
		return "Elephant";
	}
	else if (board[y][x] == "俥" || board[y][x] == "車") {
		return "Chariot";
	}
	else if (board[y][x] == "馬" || board[y][x] == "傌") {
		return "Horse";
	}
	else if (board[y][x] == "砲" || board[y][x] == "炮") {
		return "Cannon";
	}
	else if (board[y][x] == "兵" || board[y][x] == "卒") {
		return "Soldier";
	}
	else {
		return "Error";
	}
}

bool Board::findGeneral(int current_player)
{
	if (current_player == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "帥") {
					return true;	// keep going
				}
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "將") {
					return true;	// keep going
				}
			}
		}
	}

	return false;		// 將死
}

bool Board::whetherCheck(int current_player)
{
	position toPos;	// 將或帥的位置
	position fromPos;	// 要確認的棋的位置

	// 紅的動完要換黑前 (確認紅是否可以吃黑的將)
	if (current_player == 1) {
		// find x y
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "將") {
					toPos.x = j;
					toPos.y = i;
					break;
				}
			}
		}

		// 逐個檢查是否能吃將
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "帥") {
					fromPos.x = j;
					fromPos.y = i;
					General chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "仕") {
					fromPos.x = j;
					fromPos.y = i;
					Advisor chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "相") {
					fromPos.x = j;
					fromPos.y = i;
					Elephant chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "俥") {
					fromPos.x = j;
					fromPos.y = i;
					Chariot chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "傌") {
					fromPos.x = j;
					fromPos.y = i;
					Horse chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "炮") {
					fromPos.x = j;
					fromPos.y = i;
					Cannon chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "兵") {
					fromPos.x = j;
					fromPos.y = i;
					Soldier chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
			}
		}
	}
	// 黑的動完要換紅前 (確認黑是否可以吃紅的帥)
	else {
		// find x y
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "帥") {
					toPos.x = j;
					toPos.y = i;
					break;
				}
			}
		}

		// 逐個檢查是否能吃帥
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "將") {
					fromPos.x = j;
					fromPos.y = i;
					General chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "士") {
					fromPos.x = j;
					fromPos.y = i;
					Advisor chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "象") {
					fromPos.x = j;
					fromPos.y = i;
					Elephant chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "車") {
					fromPos.x = j;
					fromPos.y = i;
					Chariot chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "馬") {
					fromPos.x = j;
					fromPos.y = i;
					Horse chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "砲") {
					fromPos.x = j;
					fromPos.y = i;
					Cannon chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
				else if (board[i][j] == "卒") {
					fromPos.x = j;
					fromPos.y = i;
					Soldier chess(*this, current_player);
					if (chess.eatable(*this, fromPos, toPos)) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Board::whetherStalemate(int current_player)
{
	position fromPos;	// 將或帥
	position toPos;		// 上下左右移動
	bool flag = false;	// 只要有一邊能走就是true
	bool flagOwnChess = true;	// 被己軍包圍就是true
	string bTemp[10][9];

	General chess(*this, current_player);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			bTemp[i][j] = board[i][j];
		}
	}

	// 紅的動完要換黑的前 (確認黑的將是否可以動) (return true if cannot move)
	if (current_player == 0) {
		// find x y
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "將") {
					fromPos.x = j;
					fromPos.y = i;
					toPos.x = j;
					toPos.y = i;
					break;
				}
			}
		}

		// 被己軍包圍
		//case up
		toPos.y--;
		if (chess.eatable(*this, fromPos, toPos) && !isBlackChess(*this, toPos)) {
			flagOwnChess = false;
		}
		//case down
		toPos.y += 2;
		if (chess.eatable(*this, fromPos, toPos) && !isBlackChess(*this, toPos)) {
			flagOwnChess = false;
		}
		toPos.y--;
		//case left
		toPos.x--;
		if (chess.eatable(*this, fromPos, toPos) && !isBlackChess(*this, toPos)) {
			flagOwnChess = false;
		}
		//case right
		toPos.x += 2;
		if (chess.eatable(*this, fromPos, toPos) && !isBlackChess(*this, toPos)) {
			flagOwnChess = false;
		}
		toPos.x--;
	}
	// 黑的動完要換紅的前 (確認紅的帥是否可以動) (return true if cannot move)
	else {
		// find x y
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "帥") {
					fromPos.x = j;
					fromPos.y = i;
					toPos.x = j;
					toPos.y = i;
					break;
				}
			}
		}

		// 被己軍包圍
		//case up
		toPos.y--;
		if (chess.eatable(*this, fromPos, toPos) && !isRedChess(*this, toPos)) {
			flagOwnChess = false;
		}
		//case down
		toPos.y += 2;
		if (chess.eatable(*this, fromPos, toPos) && !isRedChess(*this, toPos)) {
			flagOwnChess = false;
		}
		toPos.y--;
		//case left
		toPos.x--;
		if (chess.eatable(*this, fromPos, toPos) && !isRedChess(*this, toPos)) {
			flagOwnChess = false;
		}
		//case right
		toPos.x += 2;
		if (chess.eatable(*this, fromPos, toPos) && !isRedChess(*this, toPos)) {
			flagOwnChess = false;
		}
		toPos.x--;
	}



	//判斷可以吃且動了之後不會變將軍
	//case up
	toPos.y--;
	if (chess.eatable(*this, fromPos, toPos)) {
		board[toPos.y][toPos.x] = board[fromPos.y][fromPos.x];
		board[fromPos.y][fromPos.x] = "  ";
		if (!whetherCheck(current_player))
			flag = true;
		board[fromPos.y][fromPos.x] = bTemp[fromPos.y][fromPos.x];
		board[toPos.y][toPos.x] = bTemp[toPos.y][toPos.x];
	}

	//case down
	toPos.y += 2;
	if (chess.eatable(*this, fromPos, toPos)) {
		board[toPos.y][toPos.x] = board[fromPos.y][fromPos.x];
		board[fromPos.y][fromPos.x] = "  ";
		if (!whetherCheck(current_player))
			flag = true;
		board[fromPos.y][fromPos.x] = bTemp[fromPos.y][fromPos.x];
		board[toPos.y][toPos.x] = bTemp[toPos.y][toPos.x];
	}
	toPos.y--;
	//case left
	toPos.x--;
	if (chess.eatable(*this, fromPos, toPos)) {
		board[toPos.y][toPos.x] = board[fromPos.y][fromPos.x];
		board[fromPos.y][fromPos.x] = "  ";
		if (!whetherCheck(current_player))
			flag = true;
		board[fromPos.y][fromPos.x] = bTemp[fromPos.y][fromPos.x];
		board[toPos.y][toPos.x] = bTemp[toPos.y][toPos.x];
	}

	//case right
	toPos.x += 2;
	if (chess.eatable(*this, fromPos, toPos)) {
		board[toPos.y][toPos.x] = board[fromPos.y][fromPos.x];
		board[fromPos.y][fromPos.x] = "  ";
		if (!whetherCheck(current_player))
			flag = true;
		board[fromPos.y][fromPos.x] = bTemp[fromPos.y][fromPos.x];
		board[toPos.y][toPos.x] = bTemp[toPos.y][toPos.x];
	}
	toPos.x--;



	if (flag == true || flagOwnChess == true) {		// 只要有一邊能走(走了不會被將軍)或是被己軍包圍就是true -> not stalemate
		return false;
	}
	return true;	// stalemate
}