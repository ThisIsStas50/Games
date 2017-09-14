/* Treasure.cpp
 *
 * Member Functions for Class Treasure Defined here
 * Also Defined: Friends of Treasure Class
 *
 * By Anastas Kanaris
 */

#include "Treasure.h"

const string Treasure::TreasureNames[Treasure::MAX] = {"Golden Sword", "Golden Shield", "Golden Helmet"};
Randomizer Treasure::R(TreasureNames, MAX);


ostream &operator<<(ostream &out, const Treasure &T){
	T.display(out);
	return(out);
}

Treasure::Treasure(){
	setName();
}

Treasure::~Treasure(){
}

void Treasure::display(ostream &out) const{
	out << name;
}

void Treasure::setName(){
	name = R.generateName();
}


string Treasure::getName() const{
	return(name);
}

/*
main(){

	srand( time(0) );

	Treasure T, T1, T2;
	cout << T << T1 << T2;
}
*/



