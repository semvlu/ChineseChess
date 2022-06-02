#include"Viewer.h"

void Viewer::printBoard(Board& b)
{
	//system("CLS");

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (j != 8) {
				cout << b.board[i][j] << "_";
			}
			else {
				if (i != 9) {
					cout << b.board[i][j] << "\n|  |  |  |  |  |  |  |  |\n";
				}
				else {
					cout << b.board[i][j] << "\n";
				}
			}
		}
	}
}