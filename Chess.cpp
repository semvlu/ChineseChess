#include"GameManager.h"
#include"Chess.h"

// ========== Chess class ========== //
void Chess::setType(string input)
{
	if (input == "General") {
		type = 1;
	}
	else if (input == "Advisor") {
		type = 2;
	}
	else if (input == "Elephant") {
		type = 3;
	}
	else if (input == "Chariot") {
		type = 4;
	}
	else if (input == "Horse") {
		type = 5;
	}
	else if (input == "Cannon") {
		type = 6;
	}
	else if (input == "Soldier") {
		type = 7;
	}
}

int Chess::getType()
{
	return type;
}

int Chess::getCurrentPlayer()
{
	return current_player;
}

void Chess::Move(Board& b, position& fromPos, position& toPos)
{
	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
		b.board[fromPos.y][fromPos.x] = "  ";
	}
}

// ========== General class ========== //
void General::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內
	bool canFly = false;			// 王見王 可以直接飛過去吃
	bool chessInMiddle = false;		// 確認中間有沒有隔著棋

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// 王見王
		if (b.board[toPos.y][toPos.x] == "將") {
			for (int i = fromPos.y - 1; i > toPos.y; i--) {
				if (b.board[i][fromPos.x] != "  " || fromPos.x != toPos.x) {
					chessInMiddle = true;
					break;
				}
			}
			if (chessInMiddle == false) {
				canFly = true;
			}
		}
		// 過田
		else if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			cout << "wrong move\n";
		}
		// 田內
		else {
			// 斜著走
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				cout << "wrong move\n";
			}
			// 沒斜著走
			else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) == 1 && (fromPos.x == toPos.x || fromPos.y == toPos.y)) {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// 王見王
		if (b.board[toPos.y][toPos.x] == "帥") {
			for (int i = fromPos.y + 1; i < toPos.y; i++) {
				if (b.board[i][fromPos.x] != "  " || fromPos.x != toPos.x) {
					chessInMiddle = true;
					break;
				}
			}
			if (chessInMiddle == false) {
				canFly = true;
			}
		}
		// 過田
		else if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			cout << "wrong move\n";
		}
		// 田內
		else {
			// 斜著走
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				cout << "wrong move\n";
			}
			// 沒斜著走
			else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) == 1 && (fromPos.x == toPos.x || fromPos.y == toPos.y)) {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}

	if (chessBeyond == true && basicCheck == true || canFly == true) {
		b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
		b.board[fromPos.y][fromPos.x] = "  ";
	}
	else {
		cout << "wrong move\n";
	}

}
bool General::eatable(Board& b, position& fromPos, position& toPos)
{
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內
	bool canFly = false;			// 王見王 可以直接飛過去吃
	bool chessInMiddle = false;		// 確認中間有沒有隔著棋

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// 王見王
		if (b.board[toPos.y][toPos.x] == "將") {
			for (int i = fromPos.y - 1; i > toPos.y; i--) {
				if (b.board[i][fromPos.x] != "  " || fromPos.x != toPos.x) {
					chessInMiddle = true;
					break;
				}
			}
			if (chessInMiddle == false) {
				canFly = true;
			}
		}
		// 過田
		else if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			return false;
		}
		// 田內
		else {
			// 斜著走
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				return false;
			}
			// 沒斜著走
			else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) == 1 && (fromPos.x == toPos.x || fromPos.y == toPos.y)) {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// 王見王
		if (b.board[toPos.y][toPos.x] == "帥") {
			for (int i = fromPos.y + 1; i < toPos.y; i++) {
				if (b.board[i][fromPos.x] != "  " || fromPos.x != toPos.x) {
					chessInMiddle = true;
					break;
				}
			}
			if (chessInMiddle == false) {
				canFly = true;
			}
		}
		// 過田
		else if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			return false;
		}
		// 田內
		else {
			// 斜著走
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				return false;
			}
			// 沒斜著走
			else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) == 1 && (fromPos.x == toPos.x || fromPos.y == toPos.y)) {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}

	if (chessBeyond == true && basicCheck == true || canFly == true) {
		return true;
	}
	else {
		return false;
	}
}

// ========== Advisor class ========== //
void Advisor::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// 過田
		if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			cout << "wrong move\n";
		}
		// 田內
		else {
			// 沒斜著走
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				cout << "wrong move\n";
			}
			// 斜著走
			else if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
			else {
				cout << "wrong move\n";
			}
		}
	}
	// player black
	else {
		// 過田
		if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			cout << "wrong move\n";
		}
		// 田內
		else {
			// 沒斜著走
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				cout << "wrong move\n";
			}
			// 斜著走
			else if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
			else {
				cout << "wrong move\n";
			}
		}
	}

	if (chessBeyond == true && basicCheck == true) {
		b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
		b.board[fromPos.y][fromPos.x] = "  ";
	}
	else {
		cout << "wrong move\n";
	}
}
bool Advisor::eatable(Board& b, position& fromPos, position& toPos)
{
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// 過田
		if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			return false;
		}
		// 田內
		else {
			// 沒斜著走
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				return false;
			}
			// 斜著走
			else if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
			else {
				return false;
			}
		}
	}
	// player black
	else {
		// 過田
		if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			return false;
		}
		// 田內
		else {
			// 沒斜著走
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				return false;
			}
			// 斜著走
			else if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
			else {
				return false;
			}
		}
	}

	if (chessBeyond == true && basicCheck == true) {
		return true;
	}
	else {
		return false;
	}
}

// ========== Elephant class ========== //
void Elephant::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認有沒有擠象眼
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move 
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (沒走田字)
	else if (abs(fromPos.x - toPos.x) != 2 || abs(fromPos.y - toPos.y) != 2) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// player red
		if (getCurrentPlayer() == 1) {
			// 過河 -> wrong
			if (toPos.y < 5) {
				cout << "wrong move\n";
			}
			// 未過河
			else {
				// 向上移動 (左上 右上)
				if (fromPos.y - toPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y - 1][fromPos.x - 1] != "  ") {
						chessInMiddle = true;
					}
				}
				else if (fromPos.y - toPos.y == 2 && toPos.y - fromPos.y == 2) {
					if (b.board[fromPos.y - 1][fromPos.x + 1] != "  ") {
						chessInMiddle = true;
					}
				}
				// 向下移動 (左下 右下)
				if (toPos.y - fromPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x - 1] != "  ") {
						chessInMiddle = true;
					}
				}
				else if (toPos.y - fromPos.y == 2 && toPos.x - fromPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x + 1] != "  ") {
						chessInMiddle = true;
					}
				}

				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// player black
		else {
			// 過河 -> wrong
			if (toPos.y > 4) {
				cout << "wrong move\n";
			}
			// 未過河
			else {
				// 向上移動 (左上 右上)
				if (fromPos.y - toPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y - 1][fromPos.x - 1] != "  ") {
						chessInMiddle = true;
					}
				}
				else if (fromPos.y - toPos.y == 2 && toPos.y - fromPos.y == 2) {
					if (b.board[fromPos.y - 1][fromPos.x + 1] != "  ") {
						chessInMiddle = true;
					}
				}
				// 向下移動 (左下 右下)
				if (toPos.y - fromPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x - 1] != "  ") {
						chessInMiddle = true;
					}
				}
				else if (toPos.y - fromPos.y == 2 && toPos.x - fromPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x + 1] != "  ") {
						chessInMiddle = true;
					}
				}

				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}

		if (chessInMiddle == false && chessBeyond == true && basicCheck == true) {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = "  ";
		}
		else {
			cout << "wrong move\n";
		}
	}

}
bool Elephant::eatable(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認有沒有擠象眼
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move 
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		return false;
	}
	// wrong move (沒走田字)
	else if (abs(fromPos.x - toPos.x) != 2 || abs(fromPos.y - toPos.y) != 2) {
		return false;
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// player red
		if (getCurrentPlayer() == 1) {
			// 過河 -> wrong
			if (toPos.y < 5) {
				return false;
			}
			// 未過河
			else {
				// 向上移動 (左上 右上)
				if (fromPos.y - toPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y - 1][fromPos.x - 1] != "  ") {
						chessInMiddle = true;
					}
				}
				else if (fromPos.y - toPos.y == 2 && toPos.y - fromPos.y == 2) {
					if (b.board[fromPos.y - 1][fromPos.x + 1] != "  ") {
						chessInMiddle = true;
					}
				}
				// 向下移動 (左下 右下)
				if (toPos.y - fromPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x - 1] != "  ") {
						chessInMiddle = true;
					}
				}
				else if (toPos.y - fromPos.y == 2 && toPos.x - fromPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x + 1] != "  ") {
						chessInMiddle = true;
					}
				}

				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// player black
		else {
			// 過河 -> wrong
			if (toPos.y > 4) {
				return false;
			}
			// 未過河
			else {
				// 向上移動 (左上 右上)
				if (fromPos.y - toPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y - 1][fromPos.x - 1] != "  ") {
						chessInMiddle = true;
					}
				}
				else if (fromPos.y - toPos.y == 2 && toPos.y - fromPos.y == 2) {
					if (b.board[fromPos.y - 1][fromPos.x + 1] != "  ") {
						chessInMiddle = true;
					}
				}
				// 向下移動 (左下 右下)
				if (toPos.y - fromPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x - 1] != "  ") {
						chessInMiddle = true;
					}
				}
				else if (toPos.y - fromPos.y == 2 && toPos.x - fromPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x + 1] != "  ") {
						chessInMiddle = true;
					}
				}

				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}

		if (chessInMiddle == false && chessBeyond == true && basicCheck == true) {
			return true;
		}
		else {
			return false;
		}
	}
}

// ========== Chariot class ========== //
void Chariot::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認中間有沒有隔著棋
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move (走斜線)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (不動)
	else if (fromPos.x == toPos.x && fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// vertical move
		if (fromPos.x == toPos.x) {
			if (toPos.y > fromPos.y) {
				for (int i = fromPos.y + 1; i < toPos.y; i++) {
					if (b.board[i][fromPos.x] != "  ") {
						chessInMiddle = true;
						break;
					}
				}
			}
			else {
				for (int i = toPos.y + 1; i < fromPos.y; i++) {
					if (b.board[i][fromPos.x] != "  ") {
						chessInMiddle = true;
						break;
					}
				}
			}
		}
		// horizontal move
		else {
			if (toPos.x > fromPos.x) {
				for (int i = fromPos.x + 1; i < toPos.x; i++) {
					if (b.board[fromPos.y][i] != "  ") {
						chessInMiddle = true;
						break;
					}
				}
			}
			else {
				for (int i = toPos.x + 1; i < fromPos.x; i++) {
					if (b.board[fromPos.y][i] != "  ") {
						chessInMiddle = true;
						break;
					}
				}
			}
		}

		if (b.board[toPos.y][toPos.x] != "  ") {
			if (getCurrentPlayer() == 1 && isBlackChess(b, toPos)) {
				chessBeyond = true;
			}
			else if (getCurrentPlayer() == 0 && isRedChess(b, toPos)) {
				chessBeyond = true;
			}
		}
		else if (b.board[toPos.y][toPos.x] == "  ") {
			chessBeyond = true;
		}

		if (chessBeyond == false || basicCheck == false || chessInMiddle == true) {
			cout << "wrong move\n";
		}
		else {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = "  ";
		}
	}
}
bool Chariot::eatable(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認中間有沒有隔著棋
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move (走斜線)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		return false;
	}
	// wrong move (不動)
	else if (fromPos.x == toPos.x && fromPos.y == toPos.y) {
		return false;
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// vertical move
		if (fromPos.x == toPos.x) {
			if (toPos.y > fromPos.y) {
				for (int i = fromPos.y + 1; i < toPos.y; i++) {
					if (b.board[i][fromPos.x] != "  ") {
						chessInMiddle = true;
						break;
					}
				}
			}
			else {
				for (int i = toPos.y + 1; i < fromPos.y; i++) {
					if (b.board[i][fromPos.x] != "  ") {
						chessInMiddle = true;
						break;
					}
				}
			}
		}
		// horizontal move
		else {
			if (toPos.x > fromPos.x) {
				for (int i = fromPos.x + 1; i < toPos.x; i++) {
					if (b.board[fromPos.y][i] != "  ") {
						chessInMiddle = true;
						break;
					}
				}
			}
			else {
				for (int i = toPos.x + 1; i < fromPos.x; i++) {
					if (b.board[fromPos.y][i] != "  ") {
						chessInMiddle = true;
						break;
					}
				}
			}
		}

		if (b.board[toPos.y][toPos.x] != "  ") {
			if (getCurrentPlayer() == 1 && isBlackChess(b, toPos)) {
				chessBeyond = true;
			}
			else if (getCurrentPlayer() == 0 && isRedChess(b, toPos)) {
				chessBeyond = true;
			}
		}
		else if (b.board[toPos.y][toPos.x] == "  ") {
			chessBeyond = true;
		}

		if (chessBeyond == false || basicCheck == false || chessInMiddle == true) {
			return false;
		}
		else {
			return true;
		}
	}
}

// ========== Horse class ========== //
void Horse::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認有沒有拐馬腳
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (沒走日字)
	else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) != 3) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// 向上移動
		if (fromPos.y - toPos.y == 2) {
			if (b.board[fromPos.y - 1][fromPos.x] != "  ") {
				chessInMiddle = true;
			}
		}
		// 向下移動
		else if (toPos.y - fromPos.y == 2) {
			if (b.board[fromPos.y + 1][fromPos.x] != "  ") {
				chessInMiddle = true;
			}
		}
		// 向左移動
		else if (fromPos.x - toPos.x == 2) {
			if (b.board[fromPos.y][fromPos.y - 1] != "  ") {
				chessInMiddle = true;
			}
		}
		// 向右移動
		else if (toPos.x - fromPos.x == 2) {
			if (b.board[fromPos.y][fromPos.x + 1] != "  ") {
				chessInMiddle = true;
			}
		}

		if (b.board[toPos.y][toPos.x] != "  ") {
			if (getCurrentPlayer() == 1 && isBlackChess(b, toPos)) {
				chessBeyond = true;
			}
			else if (getCurrentPlayer() == 0 && isRedChess(b, toPos)) {
				chessBeyond = true;
			}
		}
		else if (b.board[toPos.y][toPos.x] == "  ") {
			chessBeyond = true;
		}

		if (chessInMiddle == true || chessBeyond == false || basicCheck == false) {
			cout << "wrong move\n";
		}
		else {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = "  ";
		}
	}

}
bool Horse::eatable(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認有沒有拐馬腳
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		return false;
	}
	// wrong move (沒走日字)
	else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) != 3) {
		return false;
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// 向上移動
		if (fromPos.y - toPos.y == 2) {
			if (b.board[fromPos.y - 1][fromPos.x] != "  ") {
				chessInMiddle = true;
			}
		}
		// 向下移動
		else if (toPos.y - fromPos.y == 2) {
			if (b.board[fromPos.y + 1][fromPos.x] != "  ") {
				chessInMiddle = true;
			}
		}
		// 向左移動
		else if (fromPos.x - toPos.x == 2) {
			if (b.board[fromPos.y][fromPos.y - 1] != "  ") {
				chessInMiddle = true;
			}
		}
		// 向右移動
		else if (toPos.x - fromPos.x == 2) {
			if (b.board[fromPos.y][fromPos.x + 1] != "  ") {
				chessInMiddle = true;
			}
		}

		if (b.board[toPos.y][toPos.x] != "  ") {
			if (getCurrentPlayer() == 1 && isBlackChess(b, toPos)) {
				chessBeyond = true;
			}
			else if (getCurrentPlayer() == 0 && isRedChess(b, toPos)) {
				chessBeyond = true;
			}
		}
		else if (b.board[toPos.y][toPos.x] == "  ") {
			chessBeyond = true;
		}

		if (chessInMiddle == true || chessBeyond == false || basicCheck == false) {
			return false;
		}
		else {
			return true;
		}
	}
}

// ========== Cannon class ========== //
void Cannon::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認中間有沒有隔著一棋
	bool chessMoreThanOne = false;	// 確認中間有沒有超過一棋
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move (走斜線)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (不動)
	else if (fromPos.x == toPos.x && fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// vertical move
		if (fromPos.x == toPos.x) {
			if (toPos.y > fromPos.y) {
				for (int i = fromPos.y + 1; i < toPos.y; i++) {
					if (b.board[i][fromPos.x] != "  ") {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessMoreThanOne = true;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
			else {
				for (int i = toPos.y + 1; i < fromPos.y; i++) {
					if (b.board[i][fromPos.x] != "  ") {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessMoreThanOne = true;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
		}
		// horizontal move
		else {
			if (toPos.x > fromPos.x) {
				for (int i = fromPos.x + 1; i < toPos.x; i++) {
					if (b.board[fromPos.y][i] != "  ") {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessMoreThanOne = true;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
			else {
				for (int i = toPos.x + 1; i < fromPos.x; i++) {
					if (b.board[fromPos.y][i] != "  ") {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessMoreThanOne = true;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
		}

		if (b.board[toPos.y][toPos.x] != "  ") {
			if (getCurrentPlayer() == 1 && isBlackChess(b, toPos)) {
				chessBeyond = true;
			}
			else if (getCurrentPlayer() == 0 && isRedChess(b, toPos)) {
				chessBeyond = true;
			}
		}
		else if (b.board[toPos.y][toPos.x] == "  ") {
			chessBeyond = true;
		}

		// 跳吃並移動
		if (chessInMiddle == true && chessBeyond == true && basicCheck == true && b.board[toPos.y][toPos.x] != "  " && chessMoreThanOne == false) {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = "  ";
		}
		// 純移動
		else if (chessInMiddle == false && chessBeyond == true && basicCheck == true && b.board[toPos.y][toPos.x] == "  " && chessMoreThanOne == false) {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = "  ";
		}
		else {
			cout << "wrong move\n";
		}
	}
}
bool Cannon::eatable(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認中間有沒有隔著一棋
	bool chessMoreThanOne = false;	// 確認中間有沒有超過一棋
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move (走斜線)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		return false;
	}
	// wrong move (不動)
	else if (fromPos.x == toPos.x && fromPos.y == toPos.y) {
		return false;
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// vertical move
		if (fromPos.x == toPos.x) {
			if (toPos.y > fromPos.y) {
				for (int i = fromPos.y + 1; i < toPos.y; i++) {
					if (b.board[i][fromPos.x] != "  ") {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessMoreThanOne = true;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
			else {
				for (int i = toPos.y + 1; i < fromPos.y; i++) {
					if (b.board[i][fromPos.x] != "  ") {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessMoreThanOne = true;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
		}
		// horizontal move
		else {
			if (toPos.x > fromPos.x) {
				for (int i = fromPos.x + 1; i < toPos.x; i++) {
					if (b.board[fromPos.y][i] != "  ") {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessMoreThanOne = true;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
			else {
				for (int i = toPos.x + 1; i < fromPos.x; i++) {
					if (b.board[fromPos.y][i] != "  ") {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessMoreThanOne = true;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
		}

		if (b.board[toPos.y][toPos.x] != "  ") {
			if (getCurrentPlayer() == 1 && isBlackChess(b, toPos)) {
				chessBeyond = true;
			}
			else if (getCurrentPlayer() == 0 && isRedChess(b, toPos)) {
				chessBeyond = true;
			}
		}
		else if (b.board[toPos.y][toPos.x] == "  ") {
			chessBeyond = true;
		}

		// 跳吃並移動
		if (chessInMiddle == true && chessBeyond == true && basicCheck == true && b.board[toPos.y][toPos.x] != "  " && chessMoreThanOne == false) {
			return true;
		}
		// 純移動
		else if (chessInMiddle == false && chessBeyond == true && basicCheck == true && b.board[toPos.y][toPos.x] == "  " && chessMoreThanOne == false) {
			return true;
		}
		else {
			return false;
		}
	}
}

// ========== Soldier class ========== //
void Soldier::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessBeyond = false;		//確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// 過河
		if (fromPos.y < 5) {
			// wrong move (後退 斜著走 非走一格)
			if (toPos.y > fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// 未過河
		else {
			// wrong move (後退 左右走 非走一格)
			if (toPos.y > fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// 過河
		if (fromPos.y > 4) {
			// wrong move (後退 斜著走 非走一格)
			if (toPos.y < fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// 未過河
		else {
			// wrong move (後退 左右走 非走一格)
			if (toPos.y < fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}

	if (chessBeyond == true && basicCheck == true) {
		b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
		b.board[fromPos.y][fromPos.x] = "  ";
	}
	else {
		cout << "wrong move\n";
	}
}
bool Soldier::eatable(Board& b, position& fromPos, position& toPos)
{
	bool chessBeyond = false;		//確認toPos為對方的棋或空白
	bool basicCheck = false;		// 確認在版面內

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// 過河
		if (fromPos.y < 5) {
			// wrong move (後退 斜著走 非走一格)
			if (toPos.y > fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				return false;
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// 未過河
		else {
			// wrong move (後退 左右走 非走一格)
			if (toPos.y > fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				return false;
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// 過河
		if (fromPos.y > 4) {
			// wrong move (後退 斜著走 非走一格)
			if (toPos.y < fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				return false;
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// 未過河
		else {
			// wrong move (後退 左右走 非走一格)
			if (toPos.y < fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				return false;
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}

	if (chessBeyond == true && basicCheck == true) {
		return true;
	}
	else {
		return false;
	}
}