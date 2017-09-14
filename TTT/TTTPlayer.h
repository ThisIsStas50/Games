/* TTTPlayer.h
 *
 * Derived From Player Class
 *
 */

#ifndef TTTPLAYER_H
#define TTTPLAYER_H

#include "Player.h"
#include <iostream>
using namespace std;

class TTTPlayer : public Player {

friend ostream &operator<<(ostream &, const TTTPlayer &);

public:

	TTTPlayer();
	~TTTPlayer();

	void setMarker(char);
	void setIMarker(int);

	int getIMarker() const;
	char getMarker() const;

	TTTPlayer operator++(int);
	TTTPlayer operator--(int);

	virtual void draw();


private:
	char marker;
	int iMarker;
	int tttWins, tttLosses, tttDraws;

	static const int NUM_MARKS = 2;
	static const char MARKERS[NUM_MARKS];
	static int numPlayers;

	virtual void display(ostream &, int = DEFAULT) const;

};


#endif
