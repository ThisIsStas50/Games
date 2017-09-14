/* TicTacToe.h
 *
 * Class Definition for TicTacToe Class
 *
 * Methods + Friends Defined in TicTacToe.cpp
 *
 * By Anastas Kanaris
 */


#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "TTTPlayer.h"
#include "BoardGame.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class TicTacToe : public BoardGame {

friend istream &operator>>(istream &, TicTacToe &);
friend ostream &operator<<(ostream &, TicTacToe &);
public:

	TicTacToe();
	~TicTacToe();


	virtual void pregame(istream &);


private:
	static const int SIZE = 3;
	int tttGP;


	void setMarkers();

	virtual void playGame(ostream &);
	virtual void instructions();
	virtual bool validMove(int, int);
	virtual void turn();
	virtual void updateBoard(int, int);
	virtual bool winCheck(int);

	bool check3();	

	virtual void updateStats();

};

#endif

