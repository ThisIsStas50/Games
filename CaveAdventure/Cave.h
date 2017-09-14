/* Cave.h
 *
 * Cave Class Definition
 * Methods + Friends Defined in Cave.cpp
 *
 */

#ifndef CAVE_H
#define CAVE_H

#include "Adventure.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Cave{

friend istream &operator>>(istream &, Cave &);
friend ostream &operator<<(ostream &, const Cave &);

public:
	Cave(int = -1);
	~Cave();

	string getHero() const;

private:
	string hero;
	Adventure advent1, advent2, advent3;
	int options, fakeLocation;

	void input(istream &);
	void setUp() const;
	void display(ostream &) const;
	void game(ostream &) const;

};

#endif
