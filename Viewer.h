#pragma once

#include"Board.h"
#include"GameManager.h"
#include"Chess.h"

//�C������
//GUI API
class Viewer
{
public:
	Board b;
	Viewer(Board bInput) { b = bInput; };
	void printBoard(Board& b);
};