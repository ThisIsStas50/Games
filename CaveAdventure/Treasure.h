/* Treasure.h
 *
 * Definition of the Treasure Class
 *
 * Methods + Friends Defined in Treasure.cpp
 */

#ifndef TREASURE_H
#define TREASURE_H

#include "Randomizer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Treasure{

friend ostream &operator<<(ostream &, const Treasure &);

public:
	Treasure();
	~Treasure();

	void setName();
	string getName() const;





private:
	string name;

	static const int MAX = 3;
	static const string TreasureNames[MAX];
	static Randomizer R;

	void display(ostream &) const;
};

#endif
