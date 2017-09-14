/* BoardGame.h
 *
 * BoardGame Class Definition
 *
 * Member Functions Defined in BoardGame.cpp
 *
 * Note: For Sake of Sanity, I've Defined this Board Game Class
 * to Represent all 2-person Board Games (ie Chess, Checkers, TTT)
 *
 * By Anastas Kanaris
 */

#ifndef BOARDGAME_H
#define BOARDGAME_H

#include "Cell.h"
#include "Player.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class BoardGame {

friend istream &operator>>(istream &, BoardGame &);
friend ostream &operator<<(ostream &, const BoardGame &);

public:

	BoardGame(int = 0);
	~BoardGame();



protected:

	static const int numPlayers = 2;
	const int ROWS, COLS;
	Cell **board;
	Player *players[numPlayers], *winner;
	int currentPlayer, winningPlayer, gamesPlayed;
	Date gameDay;

	virtual void pregame(istream &);
	bool samePlayers(istream &);
	void input(istream &);
	void setOrder(istream &);
	void gameInfo(ostream &) const;
	void display(ostream &) const;
	void initializeBoard();

	virtual void playGame(ostream &);// = 0;
	virtual void instructions();// = 0;
	virtual void move();// = 0;
	virtual bool validMove(int = 0, int = 0);
	virtual void turn();// = 0;
	virtual void updateBoard(int = 0, int = 0);// = 0
	virtual bool winCheck(int = 0);// = 0

	virtual void updateStats();

private:

	// Private Methods:
	// As The Options for determining order are the Same
	// Across all Board Games, 
	// These Methods may be made private.

	void dispOptions() const;
	void coinFlip(istream &);
	bool seniorityRules();
	bool letTheKiddiesPlay();

};


#endif

