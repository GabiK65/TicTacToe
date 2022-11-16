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

bool valid_choice;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice, row, column, turn = 1;

//Display the board
void displayBoard() {
	cout << "\t  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "\t ---|---|---" << endl;
	cout << "\t  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "\t ---|---|---" << endl;
	cout << "\t  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

//Player one
void playerVSplayer() {
	cout << "Player: " << turn << " Choose a cell: " << endl;
	cin >> choice;
	cin.clear(); cin.ignore();

	switch(choice) {
		case 1: row = 0; column = 0; break;
		case 2: row = 0; column = 1; break;
		case 3: row = 0; column = 2; break;
		case 4: row = 1; column = 0; break;
		case 5: row = 1; column = 1; break;
		case 6: row = 1; column = 2; break;
		case 7: row = 2; column = 0; break;
		case 8: row = 2; column = 1; break;
		case 9: row = 2; column = 2; break;
		default:
			cout << "Invalid cell! Please try again" << endl;
	};

	if(turn == 1 ) {
		//player one
		if(board[row][column] != 'X' and board[row][column] != 'O')
		{
			board[row][column] = 'X';
			turn = 2;
		} else {
				cout << "Cell " << board[row][column] << " already occupied \nPlease try again!" << endl; 
				//cout << "Player ONE debug" << endl;
				turn = 1;
		}
	} else {
		//player two
		if(board[row][column] != 'X' and board[row][column] != 'O')
		{
			board[row][column] = 'O';
			turn = 1;
		} else {
				cout << "Cell " << board[row][column] << " already occupied \nPlease try again!" << endl; 
				//cout << "Player TWO debug" << endl;
				turn = 2;
		}
	}

}

//Win Check
void gameWon() {

}

int main() {

	setlocale(LC_ALL, "");

	bool gameEnd = false;

	while (gameEnd == false) {
		displayBoard();
		playerVSplayer();
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

