
/* Cell.h
 *
 * Definition of Cell Class:
 *
 * Member Functions Defined in Cell.cpp
 *
 * By Anastas Kanaris
 */

#ifndef CELL_H
#define CELL_H

// External Directories
#include <iostream>
using namespace std;

// Class Definition
class Cell{
// Friend Functions

friend istream &operator>>(istream &, Cell &);
friend ostream &operator<<(ostream &, const Cell &);
friend void operator+=(int &, const Cell &);

// Public Members
public:

	//
	// Constructors
	//
	Cell();
	Cell(const Cell &);
	void initialize();

	// 
	// Mutator (Set) Methods
	//
	void setMarker(char = DEFMARKER);
	void setIMarker(int = ival);

	//
	// Accessor (Get) Methods
	//
	char getMarker() const;
	int getIMarker() const;


	//
	// Operator Overloads
	//
	void operator+=(char);
	void operator+=(int);

// Private Members
private:

	static const int ival = 0;
	static const char DEFMARKER = ' ';
	char marker;
	int iMarker;

	void input(istream &);
	void display(ostream &) const;

};
// End Class Definition

// End Wrap
#endif

