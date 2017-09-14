/* Name.cpp
 * Contains all the method definitions for Name.h
 *
 * By Anastas Kanaris
 */

#include "Name.h"

//
// Friend Functions
//

istream &operator>>(istream &in, Name &N){
	N.input(in);
	return(in); // Allows For Cascading Calls
}

ostream &operator<<(ostream &out, const Name &N){
	N.display(out);
	return(out);
}

// 
// Constructors
//

//
// Default Constructor:
// Sets first Name to "Forename",
// Last Name to "Surname",
// and MI to ' '.
//

Name::Name(){
	fName = "Forename";
	lName = "Surname";
	mi = ' ';
}

//
// Constructor that takes in
// First Name and Last Name
// Sets MI to ' '.
//

Name::Name(string fName, string lName){
	Name::fName = fName;
	Name::lName = lName;
	mi = ' ';
}

//
// Constructor that takes in
// First Name, Last Name
// and Middle Initial
//

Name::Name(string fName, char mi, string lName){
	Name::fName = fName;
	Name::mi = mi;
	Name::lName = lName;
}

//
// Copy Constructor
//

Name::Name(const Name &n){
	fName = n.fName;
	mi = n.mi;
	lName = n.lName;
}

//
// Input Method
//

void Name::input(istream &in){
	char mi = '*';

	cout << "Enter First Name: ";
	in >> fName;
	cout << "Enter Middle Initial or enter \'*\' if none: ";
	in >> mi;
	setMI(mi);
	cout << "Enter Last Name: ";
	in >> lName;
}

//
// Display Method
//

void Name::display(ostream &out) const{
	out << lName << ", " << fName << ' ' << mi << endl;
}

//
// Mutator (Set) Methods
//

void Name::setFName(string name){
	fName = name;
}

void Name::setMI(char mi){
	if (mi = '*')
		Name::mi = ' ';
	else
		Name::mi = mi;
}

void Name::setLName(string name){
	lName = name;
}
//
// Accessor (Get) Methods
//

string Name::getFName() const{
	return(fName);
}

char Name::getMI() const{
	return(mi);
}

string Name::getLName() const{
	return(lName);
}
