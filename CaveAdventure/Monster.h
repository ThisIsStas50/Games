/* Monster.h
 *
 * Monster Class Definition
 *
 * Methods and Friend of Class Functions
 * Defined in Monster.cpp
 *
 * By Anastas Kanaris
 */


#ifndef MONSTER_H
#define MONSTER_H

#include "Randomizer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Monster{

friend ostream &operator<<(ostream &, const Monster &);

public:
	Monster();
	~Monster();
	void setName();
	string getName();

private:
	string name;

	static const int MAX = 3;
	static const string MonsterNames[MAX];
	static Randomizer R;

	void display(ostream &) const;
};

#endif
