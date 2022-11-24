#include <iostream>
#include <cstring>
#include <ctime>
#include <clocale>

using namespace std;

bool draw, game_exit = false;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}, play_again, player1, player2;
int i, j, choice, row, column, turn = 1, gamemode = 0, temp_int;

void characterChoice() {
	cout << "Choose a character to play as [A-Z]" << endl;
	do {
		cout << "Player one: ";
		cin >> player1;
	} while (player1 < 'A' or player1 > 'Z');
	do {
		cout << "Player two: ";
		cin >> player2;
	} while ((player2 < 'A' or player2 > 'Z') or player1 == player2);
}

void displayBoard() {
	cout << "\t  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "\t ---|---|---" << endl;
	cout << "\t  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "\t ---|---|---" << endl;
	cout << "\t  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << endl;
}

void playerChoice() {
	cout << "Player: " << turn << " Choose a cell: " << endl;
	cin >> choice;

	if (cin.fail()){
			cout << "Thats not a number!\nPlease try again!" << endl;
			// clear error state
			cin.clear();
			// discard 'bad' character(s)
			cin.ignore(1000, '\n');
	}

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
			cout << "Invalid cell!\nPlease try again" << endl;
	};
}

void playerVSplayer() {
	playerChoice();

	if(turn == 1 ) {
		//player one
		if(board[row][column] != player1 and board[row][column] != player2)
		{
			board[row][column] = player1;
			displayBoard();
			turn = 2;
		} else if (board[row][column] == player1 or board[row][column] == player2) {
				cout << "Cell " << board[row][column] << " already occupied \nPlease try again!" << endl; 
				turn = 1;
		}
	} else if(turn == 2 ) {
		//player two
		if(board[row][column] != player1 and board[row][column] != player2)
		{
			board[row][column] = player2;
			displayBoard();
			turn = 1;
		} else if (board[row][column] == player1 or board[row][column] == player2) {
				cout << "Cell " << board[row][column] << " already occupied \nPlease try again!" << endl; 
				turn = 2;
		}
	}

}

//PlayerVSAI
void playerVSAI() {
	//player one
	if(turn == 1 ) {
		playerChoice();

		if(board[row][column] != player1 and board[row][column] != player2)
		{
			board[row][column] = player1;
			displayBoard();
			turn = 2;
		} else if (board[row][column] == player1 or board[row][column] == player2) {
				cout << "Cell " << board[row][column] << " already occupied \nPlease try again!" << endl;
				turn = 1;
		}
	//"AI"
	} else if(turn == 2 ) {
		row = rand() % 3; column = rand() % 3;
		
		if(board[row][column] != player1 and board[row][column] != player2)
		{
			board[row][column] = player2;
			displayBoard();
			turn = 1;
		} else if (board[row][column] == player1 or board[row][column] == player2) {
			turn = 2;
		}
	}
}

bool inGame() {
	//check for complete line(s) 
	for(i = 0; i < 3; i++) {
		//check for rows and columns
		if ((board[i][0] == board[i][1] and board[i][0] == board[i][2]) or (board[0][i] == board[1][i] and board[0][i] == board[2][i])) {
			return false;
		}
		//check for diagonal
		if ((board[0][0] == board[1][1] and board[0][0] == board[2][2]) or (board[0][2] == board[1][1] and board[0][2] == board[2][0])) {
			return false;
		}
	}

    for (int i=0; i<3; i++) {
    	for(int j=0; j<3; j++){
    		if(board[i][j] != player1 && board[i][j] != player2)
   		return true;
		}
	}

	draw = true;
	return false;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "");

	while (game_exit == false) {
		while (gamemode == 0) {
			cout << "Select a gamemode: \n\t1 - Singleplayer against AI \n\t2 - Multiplayer against another person" << endl;
			cin >> gamemode;
			if (cin.fail()){
				cout << "Please try again!" << endl;
				// clear error state
				cin.clear();
				// discard 'bad' character(s)
				cin.ignore(1000, '\n');
			}
			if (gamemode < 1 or gamemode > 2) {gamemode = 0;} else if (gamemode >= 1 and gamemode <= 2) {characterChoice();displayBoard();}
		}

		while (inGame() == true) {
			if(gamemode == 1) {playerVSAI();} else if(gamemode == 2) {playerVSplayer();}
			inGame();
		}
		
		if (turn == 2 and draw == false) {
			cout << "Game Over! \n\t Player 1 won!" << endl;
		} else if (turn == 1 and draw == false) {
			cout << "Game Over! \n\t Player 2 won!" << endl;
		} else {
			cout << "It's a draw! Nobody wins" << endl;
		}

		do {
			cout << "Play again? \nY or N" << endl;
			cin >> play_again;
			if(play_again == 'y' or play_again == 'Y') {
				gamemode = 0; game_exit = false;
				temp_int = 0;
				for(i = 0; i < 3; i++) {
					for (j = 0; j < 3; j++) {
						temp_int++;
						switch (temp_int) {
							case 1: board[i][j] = '1'; break;
							case 2: board[i][j] = '2'; break;
							case 3: board[i][j] = '3'; break;
							case 4: board[i][j] = '4'; break;
							case 5: board[i][j] = '5'; break;
							case 6: board[i][j] = '6'; break;
							case 7: board[i][j] = '7'; break;
							case 8: board[i][j] = '8'; break;
							case 9: board[i][j] = '9'; break;
						}
					}
				}
				turn = 1;
			}
			if(play_again == 'n' or play_again == 'N') {gamemode = 0; game_exit = true;} else {cout << "Invalid choice!" << endl;}
		} while (gamemode != 0);
	}
	return 0;
}
