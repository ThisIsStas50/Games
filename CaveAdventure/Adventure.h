/* Adventure.h
 *
 * Adventure Class Definition
 *
 * Methods and friend of class functions
 * Defined in Adventure.cpp
 *
 * By Anastas Kanaris
 */
#ifndef ADVENTURE_H
#define ADVENTURE_H

#include "Monster.h"
#include "Treasure.h"
#include "Songs.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Adventure{

friend ostream &operator<<(ostream &, const Adventure &);

public:
	Adventure();
	Adventure(int);
	~Adventure();

	static int getMAX();


private:
	static const int MAX = 3;
	static const string LOCNAMES[MAX];
	static int numAdventures;
	string location;
	string falseTreasure;
	bool fakeTreasure;
	Monster M;
	Treasure T;
	Songs twelveDays, oldMac;

	void display(ostream &) const;
	void game(ostream &) const;
	int selection(ostream &, const bool &, const bool &, const bool &) const;
	bool monster, treasure;
};

#endif
