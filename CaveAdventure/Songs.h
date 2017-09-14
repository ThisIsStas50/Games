/* Songs.h
 *
 * Songs Class Definition
 *
 * Member functions and friends of the class defined in Songs.cpp
 *
 */

#ifndef SONGS_H
#define SONGS_H

#include "Randomizer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Songs{

friend ostream& operator<<(ostream &, const Songs &);
public:

	Songs(int = 0);
	~Songs();
	bool setSong(int);



private:

	int song;
 	static const int SIZE = 4;
	static const string animals[SIZE];

	void oldMacDonald(ostream &) const;
	string animalSounds(string) const;
	void twelveDays(ostream &) const;

	
	
};

#endif
