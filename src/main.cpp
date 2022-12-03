#include <iostream>
#include <cstring>
#include <ctime>
#include <clocale>
#include <array>
#include <cctype>

using namespace std;

const int BOARD_SIZE = 9;

bool game_over = false;
array <char, BOARD_SIZE> board;
int i, choice, turn = 1, gamemode = 0;
char play_again, player1, player2;

void characterChoice() {
	cout << "Choose a character to play as [A-Z]" << endl;
	do {
		cout << "Player one: ";
		cin >> player1;
		if (islower(player1)) {
		    player1 = toupper(player1);
		}
	} while (player1 < 'A' or player1 > 'Z');
	do {
		cout << "Player two: ";
		cin >> player2;
		if (islower(player2)) {
		    player2 = toupper(player2);
		}
	} while ((player1 < 'A' or player1 > 'Z') and player1 == player2);
}

void displayBoard() {
	cout << "\t  " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "\t ---|---|---" << endl;
	cout << "\t  " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "\t ---|---|---" << endl;
	cout << "\t  " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << endl;
}

void playerChoice() {
    do {
	    cout << "Player: " << turn << " Choose a cell: " << endl;
	    cin >> choice;


	    if (cin.fail()){
			    cout << "Thats not a number!\nPlease try again!" << endl;
			    // clear error state
			    cin.clear();
			    // discard 'bad' character(s)
			    cin.ignore(1000, '\n');
	    }
    } while (choice < 1 or choice > 9);
    choice --;
}

void playerVSplayer() {
	playerChoice();

	if(turn == 1 ) {
		//player one
		if(board[choice] != player1 and board[choice] != player2)
		{
			board[choice] = player1;
			displayBoard();
			turn = 2;
		} else if (board[choice] == player1 or board[choice] == player2) {
				cout << "Cell " << board[choice] << " already occupied \nPlease try again!" << endl;
				turn = 1;
		}
	} else if(turn == 2 ) {
		//player two
		if(board[choice] != player1 and board[choice] != player2)
		{
			board[choice] = player2;
			displayBoard();
			turn = 1;
		} else if (board[choice] == player1 or board[choice] == player2) {
				cout << "Cell " << board[choice] << " already occupied \nPlease try again!" << endl;
				turn = 2;
		}
	}

}

//PlayerVSAI
void playerVSAI() {
	//player one
	if(turn == 1 ) {
		playerChoice();

		if(board[choice] != player1 and board[choice] != player2)
		{
			board[choice] = player1;
			displayBoard();
			turn = 2;
		} else if (board[choice] == player1 or board[choice] == player2) {
				cout << "Cell " << board[choice] << " already occupied \nPlease try again!" << endl;
				turn = 1;
		}
	//"AI"
	} else if(turn == 2 ) {
		choice = rand() % 9;
		
		if(board[choice] != player1 and board[choice] != player2)
		{
			board[choice] = player2;
			displayBoard();
			turn = 1;
		} else if (board[choice] == player1 or board[choice] == player2) {
			turn = 2;
		}
	}
}

bool checkWin() {
    // Check for horizontal wins
    for (i = 0; i < BOARD_SIZE; i += 3) {
        if (board[i] == board[i + 1] and board[i + 1] == board[i + 2]) {
        return true;
        }
    }

    // Check for vertical wins
    for (i = 0; i < 3; i++) {
        if (board[i] == board[i + 3] and board[i + 3] == board[i + 6]) {
        return true;
        }
    }

    // Check for diagonal wins
    if ((board[0] == board[4] and board[4] == board[8]) or
        (board[2] == board[4] and board[4] == board[6])) {
        return true;
    }

    // No wins found
    return false;
}

bool checkDraw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != 'X' and board[i] != 'O') {
            // There is at least one empty cell, so the game is not a draw
            return false;
        }
    }

    // All cells are occupied, so the game is a draw
    return true;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "");
    // initialize board
	for (i = 0; i < BOARD_SIZE; i++){board[i] = static_cast<char>(i + 49);}

	while (!game_over) {
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
			if (gamemode < 1 or gamemode > 2) {
		        gamemode = 0;
	        } else if (gamemode >= 1 and gamemode <= 2) {
			characterChoice();
			displayBoard();
			}
		}

		while (!checkWin()) {
			if (gamemode == 1) {playerVSAI();} else if (gamemode == 2) {playerVSplayer();}
			checkWin();
			checkDraw();
		}
		

		if (turn == 2 and checkWin() and !checkDraw()) {
			cout << "Game Over! \n\t Player 1 won!" << endl;
			game_over = true;
		} else if (turn == 1 and checkWin() and !checkDraw()) {
			cout << "Game Over! \n\t Player 2 won!" << endl;
			game_over = true;
		} else if (checkDraw()) {
		    cout << "Game Over! \n\t It's a draw!" << endl;
		    game_over = true;
		}

	    do {
	        cout << "Do you want to play again? (Y/N)" << endl;
		    cin >> play_again;

            if(islower(play_again)) {
                play_again = toupper(play_again);
            }

		    if (play_again == 'Y') {
		        // start the game again
			    // reset essential variables
			    gamemode = 0; game_over = false; turn = 1;
			    // reset board
			    for (i = 0; i < BOARD_SIZE; i++){board[i] = static_cast<char>(i + 49);}
		    } else if (play_again == 'N') {
                cout << "Thank you for playing!" << endl;
                return 0;
            }
        } while (gamemode != 0);
    }
    return 0;
}
