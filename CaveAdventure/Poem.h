/* Poem.h
 *
 * Header file for Class Poem
 * Member Functions and friends of class defined in Poem.cpp
 *
 * By Anastas Kanaris
 */

#ifndef POEM_H
#define POEM_H

#include "Randomizer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



class Poem{

friend istream &operator>>(istream &, Poem &);
friend ostream &operator<<(ostream &, const Poem &);
public:

	Poem(int = 0);
	~Poem();

private:
	string *words;
	int pSize;
	int numWords;
	static const int DEFAULTSIZE = 100;
	static string initial;

	void input(istream &);
	void display(ostream &) const;
	bool setWord(string);
};


#endif
