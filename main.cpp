#include <iostream>
#include "GameManager.h"
int main()
{
	GameManager game;
	int status = 1; // 0:end 1:restart 2:read-file
	while (status != 0)
	{
		//game();
		cout << "\ncin 0 to end, 1 to play, 2 to read: ";
		cin >> status;//µ²§ô¶Ü?

		if (status == 1)
			game.play();
		else if (status == 2)
			game.read();

	}
	cout << "game ended.\n";

	return 0;
}