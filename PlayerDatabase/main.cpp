#include "Player.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	//Define player count for dynamic array of players
	int playerCount;
	cout << "Please enter number of players" << endl;
	cin >> playerCount;

	Player* players = new Player[playerCount];

	bool windowClose = false;

	while(!windowClose)
	{
		int playerNum;
		cout << "Select a player index number to use that player (starting from 0)" << endl;
		cin >> playerNum; //Select player to use

		//Invalid input check
		while (playerNum > playerCount - 1)
		{
			cout << "Out of bounds, please try again." << endl;
			cin >> playerNum;
		}

		int optionNum = 0;
		while (optionNum != 5 && optionNum != 6)
		{
			//Player options
			cout << "Select option:\n"
				<< "    1) Assign Name\n"
				<< "    2) Defend\n"
				<< "    3) Buy\n"
				<< "    4) Level Up\n"
				<< "    5) Leave\n" 
				<< "    6) Exit game" << endl;
			cin >> optionNum;

			system("CLS");

			//Option function calls
			switch (optionNum)
			{
				case 1: players[playerNum].assignName(players[playerNum], playerNum);
					break;
				case 2: players[playerNum].defend(players[playerNum]);
					break;
				case 3: players[playerNum].buy(players[playerNum]);
					break;
				case 4: players[playerNum].levelUp(players[playerNum]);
					break;
				case 6: windowClose = true;
					break;
			}

			//Remove dead player from array
			if (!players[playerNum].alive)
			{
				optionNum = 5;
				system("CLS");
				cout << players[playerNum].name << " has died, deleting player." << endl;

				for (int i = playerNum; i < playerCount; ++i)
				{
					players[i] = players[i + 1];
				}

				playerCount--;
				break;
			}
		}
	}

	//Deallocate dynamic array memory
	delete[] players;

	return 0;
}
