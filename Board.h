//盤面
#pragma once
#include<string>
#include<iostream>


using namespace std;

class Board
{
public:
	string board[10][9];

	Board() { initializeBoard(); }
	void initializeBoard();
	//初始化盤面(沒棋的地方為空格)
	//邊界
	//楚河漢界
	//現在的AB
	void Print();

	string find(int x, int y);
	bool findGeneral(int current_player);
	bool whetherCheck(int current_player);	// 確認目前棋局是否將軍	-> 是 表示將死 ; 不是 表示可能為欠行
	bool whetherStalemate(int current_player);	// 沒有被將軍的情況下確認是否行止
};

