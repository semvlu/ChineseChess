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
//�C���y�{

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

	// ��ܰ����@�l -> �g�bmain -> Chess c = new ���O(��type�O����); c.Move(); �Y�i��{�l���O��Move()
	void chooseChess(int);
	void read();//loop: �I�s�g��
};



/*
//GameManager Example
if (state == MOVE_PIECE)
{
	on_board[...]->OnMove(...);
	//do sth...
	if (cross_river) //�L��L�e��i�H�
	{
		on_board[...]->SetCrossRiver(...);
		//do std...
	}

		1. Display
		2. Check gameover(�N�� ��� �뭰 �ӤH�ɶ��κ�)
		3. Switch player

}
*/