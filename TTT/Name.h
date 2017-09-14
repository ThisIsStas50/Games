/* Name.h
 * Name class definition
 * Methods defined in Name.cpp
 *
 * By Anastas Kanaris
 */

#ifndef NAME_H
#define NAME_H

#include <iostream>
using namespace std;

class Name{
// Friend Functions

	// Operator Overloads
friend istream & operator>>(istream &, Name &); // istream operator
friend ostream & operator<<(ostream &, const Name &); // ostream operator
public:

	//
	//Constructors
	//
	
	Name(); //Default Constructor
	Name(string, string); // Constructor that takes in First and Last Name
	Name(string, char, string); // Constructor that takes in First, Last, and MI
	Name( const Name &); // Copy Constructor

	//
	//Mutator (Set) Methods
	//

	void setFName(string);
	void setMI(char);
	void setLName(string);

	//
	//Accessor (Get) Methods
	//

	string getFName() const;
	char getMI() const;
	string getLName() const;

private:
	string fName, lName;
	char mi;

	// 
	// Private Methods
	// 

	void input(istream &); // input method
	void display(ostream &) const; // display method
};

#endif
