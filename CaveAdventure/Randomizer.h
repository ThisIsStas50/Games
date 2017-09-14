/* Randomizer.h
 *
 * Class Definition for Randomizer
 *
 * Methods + Friends defined in Randomizer.cpp
 *
 * By Anastas Kanaris
 */

#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Randomizer{


// Public Members
public:

	Randomizer(const string [], const int);
	~Randomizer();
	string generateName();

// Private Members
private:
	const int max;
	int numUsed;
	string *usedItems;
	string *items;

	static string initial;
};
// End Class Definition


// End Wrap
#endif
