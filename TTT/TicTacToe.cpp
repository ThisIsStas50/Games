/* TicTacToe.cpp
 *
 * Methods + Friends of TicTacToe Class Defined Here
 *
 * By Anastas Kanaris
 */


#include "TicTacToe.h"

istream &operator>>(istream &in, TicTacToe &T){
	T.pregame(in);
	return(in);
}

ostream &operator<<(ostream &out, TicTacToe &T){
	T.playGame(out);
	return(out);
}

//
// Constructors
//

	// Default Constructor
TicTacToe::TicTacToe() : BoardGame(SIZE){

	for (int i = 0; i < numPlayers; i++){
		players[i] = new TTTPlayer;
		if (players[i] == NULL){
			cerr << "Error: Memory Allocation Failed, exiting program." << endl;
			exit(1);
		}
	}
	
	tttGP = 0;
}

TicTacToe::~TicTacToe(){
}

void TicTacToe::pregame(istream &in){
	BoardGame::pregame(in);
	setMarkers();
}

void TicTacToe::setMarkers(){
	for (int i = 0; i < numPlayers; i++){
		if (i == currentPlayer){
			players[i]->setMarker('X');
			players[i]->setIMarker(1);
		}
		else{
			players[i]->setMarker('O');
			players[i]->setIMarker(-1);
		}
	}
}


void TicTacToe::playGame(ostream &out) {
	int count = 0;

	gameInfo(out);	

	do {
		count++;	
		display(out);
		turn();
	} while (!winCheck(count) && count < ROWS*COLS);
	if (winner != NULL)
		out << "AND THE WINNER IS: " << *winner << "!!!!!!!" << endl;
	else
		out << "Draw. No Winner." << endl;
	updateStats();
}

void TicTacToe::instructions(){
	cout << endl << *players[currentPlayer] << ", enter co-ordinates in the format x,y from (0,0) to (" << ROWS - 1 << ',' << COLS - 1 << ") ((" << ROWS/2 << ',' << COLS/2 << ") is the center): ";
}

bool TicTacToe::validMove(int r, int c){
	bool valid = false;
	if (BoardGame::validMove(r, c) && !(board[r][c].getIMarker()))
		valid = true;
	return(valid);
}

void TicTacToe::turn(){
	int x = 0, y = 0;
	char comma;
	do{
		if (x || y)
			cout << "Please Enter Valid Co-ordinates." << endl;
		instructions();
		cin >> x >> comma >> y;
	} while (!validMove(x,y));
	updateBoard(x, y);
}

void TicTacToe::updateBoard(int r, int c){

	char mark = players[currentPlayer]->getMarker();
	int im = players[currentPlayer]->getIMarker();
	board[r][c] += im;
	board[r][c] += mark;
}

bool TicTacToe::winCheck(int count){
	bool win;
	if (count < 5)
		win = false;
	else{
		win = check3();

	}
	if (!win && count < ROWS*COLS)
		BoardGame::winCheck();
	else if (win)
		winner = players[currentPlayer];
	return(win);				
}


bool TicTacToe::check3(){
	int sumV = 0, sumH = 0, sumLD = 0, sumRD = 0;
	bool winner = false;

	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			sumV += board[c][r]; // Check Vert
			sumH += board[r][c]; // Check Horiz
			if (r == c)
				sumLD += board[r][c]; // Check LD
			if (r == ROWS - 1 - c)
				sumRD += board[r][c]; // Check RD
		}			
		if (fabs(sumV) == SIZE || fabs(sumH) == SIZE){
			winner = true;
			break;
		}
		else
			sumV = sumH = 0;
	}
	if (!winner){
		if (fabs(sumLD) == SIZE || fabs(sumRD) == SIZE)
			winner = true;
	}	
	return(winner);
}

void TicTacToe::updateStats(){

	BoardGame::updateStats();
//	if (winner != NULL){
//		for (int i = 0; i < numPlayers; i++){
//			if (players[i] == winner)
//				*players[i]++;
//			else
//				*players[i]--;
//		}
//	}
//	else
//		for (int i = 0; i < numPlayers; i++)
//			players[i]->draw();
	tttGP++;
}

