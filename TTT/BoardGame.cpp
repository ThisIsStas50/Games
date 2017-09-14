/* BoardGame.cpp
 *
 * BoardGame Class Methods + Friend Function Definitions
 *
 * By Anastas Kanaris
 */


#include "BoardGame.h"


istream &operator>>(istream &in, BoardGame &BG){
	BG.pregame(in);
	return(in);
}

ostream &operator<<(ostream &out, const BoardGame &BG){
	BG.gameInfo(out);
	BG.display(out);
	return(out);
}

BoardGame::BoardGame(int size): ROWS(size), COLS(size){
	// Creates an Array of Players
	for ( int i = 0; i < numPlayers; i++ )
		players[i] = NULL;

	board = new Cell*[ROWS];
	for (int i = 0; i < ROWS; i++){
		board[i] = new Cell[COLS];
		for (int j = 0; j < COLS; j++)
			board[i][j].initialize();
	}
	winner = NULL;

	currentPlayer = winningPlayer = gamesPlayed = 0;
}


BoardGame::~BoardGame(){

	// Deallocate the Players
	for (int i = 0; i < numPlayers; i++){
		if (players[i] != NULL){
			delete players[i];
			players[i] = NULL;
		}
	}

	// Deallocate the Board
	for (int i = 0; i < ROWS; i++){
		if (board[i] != NULL){
			delete [] board[i];
			board[i] = NULL;
		}
	}
	if (board != NULL){
		delete [] board;
		board = NULL;
	}
}


// 
// Protected Methods
//

void BoardGame::pregame(istream &in){
	if (!gamesPlayed || !samePlayers(in)){
		input(in);
	}
	setOrder(in);
	initializeBoard();
}

bool BoardGame::samePlayers(istream &in){
	char ans;
	bool same;

	cout << "Same Players? ";
	in >> ans;
	if (ans == 'Y' || ans == 'y')
		same = true;
	else {
		if (ans != 'n' && ans != 'N')
			cout << "Guess Not! Better Follow instructions in the future!" << endl;
		same = false;
	}
	return(same);
}


void BoardGame::input(istream &in){
	for (int i = 0; i < numPlayers; i++){
		if (players[i] == NULL)
			players[i] = new Player;
			// Check that memory was initialized
			
		in >> *players[i];
	}
	if (winner != NULL)
		winner = NULL;
}

void BoardGame::setOrder(istream &in){
	if (!gamesPlayed || winner == NULL){
		int choice = 0;
		bool gameReady = true;
		do {
			dispOptions();
			in >> choice;
			switch (choice) {
				case 1:
					coinFlip(in);
					gameReady = true;
					break;
				case 2:
					if (gameReady)
						gameReady = seniorityRules();
					else
						cout << "Players are the Same Age, this doesn't work!" << endl;
					break;
				case 3:
					if (gameReady)
						gameReady = letTheKiddiesPlay();
					else
						cout << "Players are the Same Age, this doesn't work!" << endl;
					break;
				case 0:
					exit(0);
					break;
				default:
					cout << "Please select a valid option." << endl;
					gameReady = false;
					break;
			}
		} while (!gameReady);	
	}
	else{
		cout << *winner << " will go first." << endl;
//		currentPlayer = winningPlayer;
	}
}

void BoardGame::initializeBoard(){

	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLS; j++)
			board[i][j].initialize();
	}
}


void BoardGame::gameInfo(ostream &out) const{
	out << "Today is: " << gameDay << endl;
	out << "It's TIIIIIMMMMMMEEEEEE!!!!!!" << endl;
	out << "Today's Battle is Between " << numPlayers << " worthy Contestants!" << endl;
	for (int i = 0; i < numPlayers; i++){
		out << *players[i] << endl;
		if (i + 1 != numPlayers)
			out << "AND" << endl;
	}
	
}

void BoardGame::display(ostream &out) const{
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLS; j++){
			if (j == 0)
				out << ' ';
			out << board[i][j];
			if (j+1 != COLS)
				out << " | ";
		}
		if (i+1 != ROWS)
			out << endl << "---+---+---" << endl;
	}
}


void BoardGame::playGame(ostream &out){
	do{
		display(out);
		turn();
		updateBoard();
	} while (!winCheck());	
}

void BoardGame::instructions(){
	// Pure Virtual Function - Instructions Differ
	// In All Board Games
}

void BoardGame::move(){
	// Pure Virtual Function - Implementations Differ
	// In All Board Games
}

bool BoardGame::validMove(int r, int c){
	bool valid = true;
	if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
		valid = false;
	return(valid);
}

void BoardGame::turn(){

	do {
		instructions();
		move();
	} while (!validMove());	
}

void BoardGame::updateBoard(int r, int c){
	// Pure Virtual Function: Each Game has
	// Different Ways to Mark
}

bool BoardGame::winCheck(int c){
	// Pure Virtual Function: Each Game
	// Has Different Win Objective
	// As Such This Function Will Be Called
	// Whenever the winCheck in derived Classes returns False
	currentPlayer++;
	int temp = currentPlayer%2;
	currentPlayer = temp;
	return(true);
}

void BoardGame::updateStats(){

	if (winner != NULL){
		for (int i = 0; i < numPlayers; i++){
			if (players[i] == winner)
				(*players[i])++;
			else
				(*players[i])--;
		}
	}
	else
		for (int i = 0; i < numPlayers; i++)
			players[i]->draw();

	gamesPlayed++;
}



//
// Private Methods
//


void BoardGame::dispOptions() const{
	int count = 1;
	cout << "Please select a method to determine the order:" << endl;
	cout << count++ << ": Flip a Coin." << endl;
	cout << count++ << ": Seniority Rules - Oldest Goes First." << endl;
	cout << count++ << ": Youth Rules - Youngest Goes First." << endl;
	count = 0;
	cout << count << ": Quit." << endl;
}


void BoardGame::coinFlip(istream &in){

	char coinSide;
	string guessSide, flipSide;
	int userChoice, cpuChoice = 0;

	cout << "We shall determine order in the fairest way imaginable - a coin flip!" << endl;
	cout << "I will now flip a coin, " << *players[0] << ", call it (H = Heads, T = Tails): ";
	in >> coinSide;
	switch (coinSide){
		case 'H':
		case 'h':
			userChoice = 0;
			guessSide = "Heads";
			flipSide = "Tails";
			break;
		case 'T':
		case 't':
			userChoice = 1;
			guessSide = "Tails";
			flipSide = "Heads";
			break;
		default:
			cout << "Way to not follow my instructions, " << *players[0] << ", you have successfully forgone your opportunity to go first!" << endl;
			userChoice = -1;
	}
	if (userChoice != -1){
		cout << "The call is " << guessSide << endl;
		cpuChoice = rand()%2;
	}
	if (userChoice == cpuChoice){
		cout << "And " << guessSide << " it is!" << endl;
		cout << *players[0] << "will go first." << endl;
		currentPlayer = 0;
	} else {
		if (userChoice != -1){
			cout << "It is " << flipSide << '!' << endl;
		}
		cout << *players[1] << "will go first." << endl;
		currentPlayer = 1;
	}
}

bool BoardGame::seniorityRules(){
	bool liftoff = true;
	if (*players[0] > *players[1]){
		cout << *players[0] << " will go first." << endl;
		currentPlayer = 0;
	}
	else if (*players[1] > *players[0]){
		cout << *players[1] << " will go first." << endl;
		currentPlayer = 1;
	}
	else{
		cout << "Both Players are the Same Age, please choose a different method." << endl;
		liftoff = false;
	}
	return(liftoff);
}

bool BoardGame::letTheKiddiesPlay(){
	bool liftoff = true;
	if (*players[0] < *players[1]){
		cout << *players[0] << " will go first." << endl;
		currentPlayer = 0;
	}
	else if (*players[1] < *players[0]){
		cout << *players[1] << " will go first." << endl;
		currentPlayer = 1;
	}
	else{
		cout << "Both Players are the Same Age, please choose a different method." << endl;
		liftoff = false;
	}
	return(liftoff);
}


/*
main(){
	BoardGame BG;
	cin >> BG;
	cout << BG;
}
*/


