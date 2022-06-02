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
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������
	bool canFly = false;			// ������ �i�H�������L�h�Y
	bool chessInMiddle = false;		// �T�{�������S���j�۴�

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// ������
		if (b.board[toPos.y][toPos.x] == "�N") {
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
		// �L��
		else if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			cout << "wrong move\n";
		}
		// �Ф�
		else {
			// �׵ۨ�
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				cout << "wrong move\n";
			}
			// �S�׵ۨ�
			else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) == 1 && (fromPos.x == toPos.x || fromPos.y == toPos.y)) {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// ������
		if (b.board[toPos.y][toPos.x] == "��") {
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
		// �L��
		else if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			cout << "wrong move\n";
		}
		// �Ф�
		else {
			// �׵ۨ�
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				cout << "wrong move\n";
			}
			// �S�׵ۨ�
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
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������
	bool canFly = false;			// ������ �i�H�������L�h�Y
	bool chessInMiddle = false;		// �T�{�������S���j�۴�

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// ������
		if (b.board[toPos.y][toPos.x] == "�N") {
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
		// �L��
		else if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			return false;
		}
		// �Ф�
		else {
			// �׵ۨ�
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				return false;
			}
			// �S�׵ۨ�
			else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) == 1 && (fromPos.x == toPos.x || fromPos.y == toPos.y)) {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// ������
		if (b.board[toPos.y][toPos.x] == "��") {
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
		// �L��
		else if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			return false;
		}
		// �Ф�
		else {
			// �׵ۨ�
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				return false;
			}
			// �S�׵ۨ�
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
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// �L��
		if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			cout << "wrong move\n";
		}
		// �Ф�
		else {
			// �S�׵ۨ�
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				cout << "wrong move\n";
			}
			// �׵ۨ�
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
		// �L��
		if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			cout << "wrong move\n";
		}
		// �Ф�
		else {
			// �S�׵ۨ�
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				cout << "wrong move\n";
			}
			// �׵ۨ�
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
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// �L��
		if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			return false;
		}
		// �Ф�
		else {
			// �S�׵ۨ�
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				return false;
			}
			// �׵ۨ�
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
		// �L��
		if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			return false;
		}
		// �Ф�
		else {
			// �S�׵ۨ�
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				return false;
			}
			// �׵ۨ�
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
	bool chessInMiddle = false;		// �T�{���S�����H��
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move 
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (�S���Цr)
	else if (abs(fromPos.x - toPos.x) != 2 || abs(fromPos.y - toPos.y) != 2) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// player red
		if (getCurrentPlayer() == 1) {
			// �L�e -> wrong
			if (toPos.y < 5) {
				cout << "wrong move\n";
			}
			// ���L�e
			else {
				// �V�W���� (���W �k�W)
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
				// �V�U���� (���U �k�U)
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
			// �L�e -> wrong
			if (toPos.y > 4) {
				cout << "wrong move\n";
			}
			// ���L�e
			else {
				// �V�W���� (���W �k�W)
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
				// �V�U���� (���U �k�U)
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
	bool chessInMiddle = false;		// �T�{���S�����H��
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move 
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		return false;
	}
	// wrong move (�S���Цr)
	else if (abs(fromPos.x - toPos.x) != 2 || abs(fromPos.y - toPos.y) != 2) {
		return false;
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// player red
		if (getCurrentPlayer() == 1) {
			// �L�e -> wrong
			if (toPos.y < 5) {
				return false;
			}
			// ���L�e
			else {
				// �V�W���� (���W �k�W)
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
				// �V�U���� (���U �k�U)
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
			// �L�e -> wrong
			if (toPos.y > 4) {
				return false;
			}
			// ���L�e
			else {
				// �V�W���� (���W �k�W)
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
				// �V�U���� (���U �k�U)
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
	bool chessInMiddle = false;		// �T�{�������S���j�۴�
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move (���׽u)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (����)
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
	bool chessInMiddle = false;		// �T�{�������S���j�۴�
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move (���׽u)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		return false;
	}
	// wrong move (����)
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
	bool chessInMiddle = false;		// �T�{���S���䰨�}
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (�S����r)
	else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) != 3) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// �V�W����
		if (fromPos.y - toPos.y == 2) {
			if (b.board[fromPos.y - 1][fromPos.x] != "  ") {
				chessInMiddle = true;
			}
		}
		// �V�U����
		else if (toPos.y - fromPos.y == 2) {
			if (b.board[fromPos.y + 1][fromPos.x] != "  ") {
				chessInMiddle = true;
			}
		}
		// �V������
		else if (fromPos.x - toPos.x == 2) {
			if (b.board[fromPos.y][fromPos.y - 1] != "  ") {
				chessInMiddle = true;
			}
		}
		// �V�k����
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
	bool chessInMiddle = false;		// �T�{���S���䰨�}
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		return false;
	}
	// wrong move (�S����r)
	else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) != 3) {
		return false;
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// �V�W����
		if (fromPos.y - toPos.y == 2) {
			if (b.board[fromPos.y - 1][fromPos.x] != "  ") {
				chessInMiddle = true;
			}
		}
		// �V�U����
		else if (toPos.y - fromPos.y == 2) {
			if (b.board[fromPos.y + 1][fromPos.x] != "  ") {
				chessInMiddle = true;
			}
		}
		// �V������
		else if (fromPos.x - toPos.x == 2) {
			if (b.board[fromPos.y][fromPos.y - 1] != "  ") {
				chessInMiddle = true;
			}
		}
		// �V�k����
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
	bool chessInMiddle = false;		// �T�{�������S���j�ۤ@��
	bool chessMoreThanOne = false;	// �T�{�������S���W�L�@��
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move (���׽u)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (����)
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
						if (chessInMiddle == true) {		// �T�O�����j�ۤ��W�L�@��
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
						if (chessInMiddle == true) {		// �T�O�����j�ۤ��W�L�@��
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
						if (chessInMiddle == true) {		// �T�O�����j�ۤ��W�L�@��
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
						if (chessInMiddle == true) {		// �T�O�����j�ۤ��W�L�@��
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

		// ���Y�ò���
		if (chessInMiddle == true && chessBeyond == true && basicCheck == true && b.board[toPos.y][toPos.x] != "  " && chessMoreThanOne == false) {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = "  ";
		}
		// �²���
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
	bool chessInMiddle = false;		// �T�{�������S���j�ۤ@��
	bool chessMoreThanOne = false;	// �T�{�������S���W�L�@��
	bool chessBeyond = false;		// �T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// wrong move (���׽u)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		return false;
	}
	// wrong move (����)
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
						if (chessInMiddle == true) {		// �T�O�����j�ۤ��W�L�@��
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
						if (chessInMiddle == true) {		// �T�O�����j�ۤ��W�L�@��
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
						if (chessInMiddle == true) {		// �T�O�����j�ۤ��W�L�@��
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
						if (chessInMiddle == true) {		// �T�O�����j�ۤ��W�L�@��
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

		// ���Y�ò���
		if (chessInMiddle == true && chessBeyond == true && basicCheck == true && b.board[toPos.y][toPos.x] != "  " && chessMoreThanOne == false) {
			return true;
		}
		// �²���
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
	bool chessBeyond = false;		//�T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// �L�e
		if (fromPos.y < 5) {
			// wrong move (��h �׵ۨ� �D���@��)
			if (toPos.y > fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (�Y�� or ����)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// ���L�e
		else {
			// wrong move (��h ���k�� �D���@��)
			if (toPos.y > fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (�Y�� or ����)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// �L�e
		if (fromPos.y > 4) {
			// wrong move (��h �׵ۨ� �D���@��)
			if (toPos.y < fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (�Y�� or ����)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// ���L�e
		else {
			// wrong move (��h ���k�� �D���@��)
			if (toPos.y < fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (�Y�� or ����)
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
	bool chessBeyond = false;		//�T�{toPos����誺�ѩΪť�
	bool basicCheck = false;		// �T�{�b������

	if (toPos.y < 10 && toPos.x < 9 && fromPos.y < 10 && fromPos.x < 9 && toPos.y >= 0 && toPos.x >= 0 && fromPos.y >= 0 && fromPos.x >= 0) {
		basicCheck = true;
	}

	// player red
	if (getCurrentPlayer() == 1) {
		// �L�e
		if (fromPos.y < 5) {
			// wrong move (��h �׵ۨ� �D���@��)
			if (toPos.y > fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				return false;
			}
			// right move (�Y�� or ����)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// ���L�e
		else {
			// wrong move (��h ���k�� �D���@��)
			if (toPos.y > fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				return false;
			}
			// right move (�Y�� or ����)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isBlackChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// �L�e
		if (fromPos.y > 4) {
			// wrong move (��h �׵ۨ� �D���@��)
			if (toPos.y < fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				return false;
			}
			// right move (�Y�� or ����)
			else {
				if (b.board[toPos.y][toPos.x] == "  " || isRedChess(b, toPos)) {
					chessBeyond = true;
				}
			}
		}
		// ���L�e
		else {
			// wrong move (��h ���k�� �D���@��)
			if (toPos.y < fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				return false;
			}
			// right move (�Y�� or ����)
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