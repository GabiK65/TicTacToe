#include <iostream>
#include <cstring>
#include <ctime>
#include <clocale>

using namespace std;

bool draw;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int i, j, choice, row, column, turn = 1, gamemode = 0;

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
bool inGame() {
	//check for win
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
    		if(board[i][j] != 'X' && board[i][j] != 'O')
   		return true;
		}
	}

	draw = true;
	return false;
}

int main() {

	setlocale(LC_ALL, "");

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
	}

	while (inGame() == true) {
		displayBoard();
		if(gamemode == 1) {cout << "SinglePlayer" << endl;} else if(gamemode == 2) {playerVSplayer();}
		
		inGame();
	}
	
	if (turn == 2 and draw == false) {
		cout << "Game Over! \n\t Player 1 won!" << endl;
	} else if (turn == 1 and draw == false) {
		cout << "Game Over! \n\t Player 2 won!" << endl;
	} else {
		cout << "It's a draw! Nobody wins" << endl;
	}

	return 0;
}
