//�L��
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
	//��l�ƽL��(�S�Ѫ��a�謰�Ů�)
	//���
	//���e�~��
	//�{�b��AB
	void Print();

	string find(int x, int y);
	bool findGeneral(int current_player);
	bool whetherCheck(int current_player);	// �T�{�ثe�ѧ��O�_�N�x	-> �O ��ܱN�� ; ���O ��ܥi�ର���
	bool whetherStalemate(int current_player);	// �S���Q�N�x�����p�U�T�{�O�_���
};

