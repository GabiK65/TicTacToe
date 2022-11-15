/*
My first try at making a Tic-tac-toe
It has "AI" that will place an X or O on a random cell if it's empty
It has also "Character" selection.
Unfortunetly it can't check who has won, at least for now.
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//Display the board
void displayBoard() {
	
}

//Player one
void player1Step() {

}

//player two 
void player2Step() {

}

//AI
void playerAIStep() {

}

//Win Check
void gameWon() {

}

int main() {

	setlocale(LC_ALL, "");

	char gamemode;
	bool gameEnd = false;

	do {
		cout << "Single or Multi player? \t [S/M]" << gamemode << endl;
		cin >> gamemode;
		gamemode = toupper(gamemode);

		switch (gamemode) {
			case 'S':
				gamemode = 'S';
				break;
			case 'M':
				gamemode = 'M';
				break;
			default:
				gamemode = 'F';
		}

	} while (gamemode == 'F');

	while (gamemode == 'S' and gameEnd == false) {
		displayBoard();
		player1Step();
		playerAIStep();
		gameWon();
	}

	while (gamemode == 'M' and gameEnd == false) {
		displayBoard();
		player1Step();
		player2Step();
		gameWon();
	}

	return 0;
}

//time for a cleanup - leaving this stuff for now
/*
int main() {
	int i, rows, columns, x, temp_y, player_turn, ai_x, ai_y;
	char restart, y, player_char, ai_char;
	char table[3][3] = {};

	srand(time(NULL));
	do {
		do {
			cout << "What do you want to play as? X or O: ";
			cin >> player_char;
			player_char = toupper(player_char);

			switch (player_char) {
			case 'X':
				ai_char = 'O';
				break;
			case 'O':
				ai_char = 'X';
				break;
			default:
				player_char = 'n';
			};
		} while (player_char == 'n');

		//9 turns for a 3x3 array
		for (i = 0; i < 5; i++) {
			//its da players turn
			player_turn = 1;

			//cell selection mechanic for player
			while (player_turn == 1) {

				//player selects a row | prototype no.1
				do {
					cout << "Please select a row (1, 2, 3):" << endl;
					cin >> x;
					cin.clear(); cin.ignore();
					if (x < 1 or x > 3) {
						cout << "Error! " << x << " is not a valid row. Please try again." << endl;
						x = 0;
					};
				} while (x < 1 or x > 3);
				//correct row to make it compatible with the array
				x = x - 1;

				//player selects a column | prototype no.1
				do {
					cout << "Please select a column (A, B, C):" << endl;
					cin >> y;
					y = tolower(y);
					switch (y) {
					case 'a':
						temp_y = 0;
						break;
					case 'b':
						temp_y = 1;
						break;
					case 'c':
						temp_y = 2;
						break;
					default:
						y = 'n';
					};
					if (y == 'n') {
						cout << "Error! " << y << " is not a valid column. \nPlease try again." << endl;
					};
				} while (y == 'n');

				if (table[x][temp_y] == 'X' or table[x][temp_y] == 'O') {
					//Do Nothing but display an error
					player_turn = 1;
					cout << "Error! Cell already occupied" << endl;
				}
				else {
					player_turn = 0;
					//Assing values to array
					table[x][temp_y] = player_char;
					// Display array in form of a table
					for (rows = 0; rows < 3; rows++) {
						for (columns = 0; columns < 3; columns++) {
							cout << "| " << table[rows][columns] << " ";
						}
						cout << "|" << endl;
					}
					cout << endl;
				};
			};

			while (player_turn == 0 and i < 4) {
				//AI choice
				ai_x = rand() % 3; ai_y = rand() % 3;
				//cout << ai_x << " " << ai_y << endl; //debug for random numbers
				if (table[ai_x][ai_y] == 'X' or table[ai_x][ai_y] == 'O') {
					//Do Nothing
					cout << "ai tried to cheat on turn: " << i << endl; //debug turn number for ai
					player_turn = 0;
				}
				else {
					//Assing values to array
					table[ai_x][ai_y] = ai_char;
					// Display array in form of a table
					for (rows = 0; rows < 3; rows++) {
						for (columns = 0; columns < 3; columns++) {
							cout << "| " << table[rows][columns] << " ";
						}
						cout << "|" << endl;
					}
					cout << endl;
					if (i == 4) { player_turn = 0; } else { player_turn = 1; };
				};
			}
		}
		cout << "End of game. \nPlay again? (Y/N)" << endl;
			
		do {
			cin >> restart;
			restart = toupper(restart);
			switch (restart) {
			case 'Y':
				//reset array
				for (rows = 0; rows < 3; rows++) { for (columns = 0; columns < 3; columns++) { table[rows][columns] = ' '; }; };
				//reset turn counter
				player_turn = 1;
				break;
			case 'N':
				break;
			default:
				restart = 'n';
				cout << "Unknown command \nPlease try again!" << endl;
			};
		} while (restart == 'n');

	} while (restart == 'Y');
	return 0;
}
*/

