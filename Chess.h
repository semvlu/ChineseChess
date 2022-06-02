#pragma once
#include"Board.h"
#include"GameManager.h"
#include"Viewer.h"

typedef struct position {
	int x;
	int y;
}position;


// ========== �򥻴Ѥl�Aabstract class ==========
class Chess
{
private:

public:
	int type;	// �Ngeneral �hadvisor �Helephant ��chariot ��horse ��cannon �Lsoldier
	int current_player;		// 1 red (row > 5 on the board initially) ; 0 black (row < 4 on the board initially)
	//Board bChess;
	Chess(Board b);
	Chess() { type = -1; current_player = -1; };
	Chess(int _player) { type = -1; current_player = _player; };
	Chess(Board b, int _player) { current_player = _player; };

	void setType(std::string input);
	int getType();
	int getCurrentPlayer();
	void setCurrentPlayer(int curr) { current_player = curr; }

	// �i�H��ܪ��Ѥl
	//void availableChess(Board& const board);

	// ��ܰ����@�l -> �g�bmain -> Chess c = new ���O(��type�O����); c.Move(); �Y�i��{�l���O��Move()
	//void chooseChess(Chess current_player);

	// �qfromPos����toPos (�򥻨��k)
	virtual void Move(Board& b, position& fromPos, position& toPos);
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== General ==========
class General : public Chess	// �N : 1.���L�� 2.����ר� (3.�Q�Y���B������ �ҿ鱼�C��)
{
public:
	General();
	General(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Advisor ==========
class Advisor : public Chess	// �h : 1.���L�� 2.�u��ר�
{
public:
	Advisor();
	Advisor(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Elephant ==========
class Elephant : public Chess	// �H : 1.���L�e 2.�Цr�� 3.���H��(�Цr�������i����)
{
public:
	Elephant();
	Elephant(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Chariot ==========
class Chariot : public Chess	// �� : 1.����Ҥ����Z������
{
public:
	Chariot();
	Chariot(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Horse ==========
class Horse : public Chess		// �� : 1.��r�� 2.�䰨�}(�e�i��V ��F������l���i����)
{
public:
	Horse();
	Horse(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Cannon ==========
class Cannon : public Chess		// �� : 1.���Y�Ѯɨ��k�P���ۦP 2.�Y�Ѯɸ��Y
{
public:
	Cannon();
	Cannon(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Soldier ==========
class Soldier : public Chess	// �L : 1.�L�e�e�u��e�� 2.�L�e��u�४�k�e�椣�i��h
{
public:
	Soldier();
	Soldier(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

static bool isBlackChess(Board& b, position toPos)
{
	if (b.board[toPos.y][toPos.x] == "��" || b.board[toPos.y][toPos.x] == "��" || b.board[toPos.y][toPos.x] == "�H" ||
		b.board[toPos.y][toPos.x] == "�h" || b.board[toPos.y][toPos.x] == "�N" || b.board[toPos.y][toPos.x] == "��" ||
		b.board[toPos.y][toPos.x] == "��") {
		return true;
	}
	return false;
}

static bool isRedChess(Board& b, position toPos)
{
	if (b.board[toPos.y][toPos.x] == "��" || b.board[toPos.y][toPos.x] == "�X" || b.board[toPos.y][toPos.x] == "��" ||
		b.board[toPos.y][toPos.x] == "�K" || b.board[toPos.y][toPos.x] == "��" || b.board[toPos.y][toPos.x] == "��" ||
		b.board[toPos.y][toPos.x] == "�L") {
		return true;
	}
	return false;
}