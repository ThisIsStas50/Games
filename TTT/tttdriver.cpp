/* tttdriver.cpp
 *
 * Driver Function For Tic-Tac-Toe Class
 * Must Be compiled with TicTacToe.cpp
 *
 * Called newdriver because I left the old one running too long
 * and it wouldnt let me recover it...
 *
 * By Anastas Kanaris
 */

#include "TicTacToe.h"

main(){
	srand( time(0) );

	bool play();
	TicTacToe game;

	
	do{
	cin >> game;
	cout << game;
	} while(play());
}

bool play(){
	char ans = 'y';
	bool again;
	do{
		if (ans != 'y')
			cout << "Please enter a valid response." << endl;
		cout << "Play Again? (y/n): ";
		cin >> ans;
	}while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
	switch (ans) {
		case 'Y':
		case 'y':
			again = true;
			break;
		default:
			again = false;
			break;
	}
	return(again);
}

