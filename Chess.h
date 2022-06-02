#pragma once
#include"Board.h"
#include"GameManager.h"
#include"Viewer.h"

typedef struct position {
	int x;
	int y;
}position;


// ========== 基本棋子，abstract class ==========
class Chess
{
private:

public:
	int type;	// 將general 士advisor 象elephant 車chariot 馬horse 炮cannon 兵soldier
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

	// 可以選擇的棋子
	//void availableChess(Board& const board);

	// 選擇執哪一子 -> 寫在main -> Chess c = new 類別(看type是什麼); c.Move(); 即可實現子類別的Move()
	//void chooseChess(Chess current_player);

	// 從fromPos走到toPos (基本走法)
	virtual void Move(Board& b, position& fromPos, position& toPos);
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== General ==========
class General : public Chess	// 將 : 1.不過田 2.不能斜走 (3.被吃掉、王見王 皆輸掉遊戲)
{
public:
	General();
	General(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Advisor ==========
class Advisor : public Chess	// 士 : 1.不過田 2.只能斜走
{
public:
	Advisor();
	Advisor(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Elephant ==========
class Elephant : public Chess	// 象 : 1.不過河 2.田字走 3.擠象眼(田字中間不可有棋)
{
public:
	Elephant();
	Elephant(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Chariot ==========
class Chariot : public Chess	// 車 : 1.直橫皆不受距離移動
{
public:
	Chariot();
	Chariot(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Horse ==========
class Horse : public Chess		// 馬 : 1.日字走 2.拐馬腳(前進方向 緊鄰馬的位子不可有棋)
{
public:
	Horse();
	Horse(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Cannon ==========
class Cannon : public Chess		// 炮 : 1.不吃棋時走法與車相同 2.吃棋時跳吃
{
public:
	Cannon();
	Cannon(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

// ========== Soldier ==========
class Soldier : public Chess	// 兵 : 1.過河前只能前行 2.過河後只能左右前行不可後退
{
public:
	Soldier();
	Soldier(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
	bool eatable(Board& b, position& fromPos, position& toPos);
};

static bool isBlackChess(Board& b, position toPos)
{
	if (b.board[toPos.y][toPos.x] == "車" || b.board[toPos.y][toPos.x] == "馬" || b.board[toPos.y][toPos.x] == "象" ||
		b.board[toPos.y][toPos.x] == "士" || b.board[toPos.y][toPos.x] == "將" || b.board[toPos.y][toPos.x] == "砲" ||
		b.board[toPos.y][toPos.x] == "卒") {
		return true;
	}
	return false;
}

static bool isRedChess(Board& b, position toPos)
{
	if (b.board[toPos.y][toPos.x] == "硨" || b.board[toPos.y][toPos.x] == "傌" || b.board[toPos.y][toPos.x] == "相" ||
		b.board[toPos.y][toPos.x] == "仕" || b.board[toPos.y][toPos.x] == "帥" || b.board[toPos.y][toPos.x] == "炮" ||
		b.board[toPos.y][toPos.x] == "兵") {
		return true;
	}
	return false;
}