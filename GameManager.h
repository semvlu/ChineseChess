#pragma once

#include <fstream>
#include <sstream>
#include <vector>
#include<iostream>
#include<ctime>
//#include<windows.h>
#include "Board.h"
#include "Chess.h"
#include "Viewer.h"
using namespace std;
//遊戲流程

class GameManager
{
private:
	//vector<Chess*> on_board;
	int current_player; // 1:red, 0:black
	Board board;
	//Viewer viewer;
	//Chess player[2];
	ofstream wFile;

public:
	GameManager() { current_player = 0; }
	int getCurrent_player();
	void play();

	// 選擇執哪一子 -> 寫在main -> Chess c = new 類別(看type是什麼); c.Move(); 即可實現子類別的Move()
	void chooseChess(int);
	void read();//loop: 呼叫寫檔
};



/*
//GameManager Example
if (state == MOVE_PIECE)
{
	on_board[...]->OnMove(...);
	//do sth...
	if (cross_river) //兵卒過河後可以橫移
	{
		on_board[...]->SetCrossRiver(...);
		//do std...
	}

		1. Display
		2. Check gameover(將死 欠行 投降 個人時間用盡)
		3. Switch player

}
*/