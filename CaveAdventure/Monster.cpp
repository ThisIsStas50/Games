/* Monster.cpp
 *
 * Member Functions for Monster Class Defined Here
 * Also Defined: Friend of Class Functions
 *
 * By Anastas Kanaris
 */

#include "Monster.h"
 
const string Monster::MonsterNames[Monster::MAX] = {"Evil Goblin", "Evil Wombat", "HobGoblin Lord"};

Randomizer Monster::R(Monster::MonsterNames, Monster::MAX);

ostream &operator<<(ostream &out, const Monster &M){
	M.display(out);
	return(out);
}

Monster::Monster(){
	setName();
}

Monster::~Monster(){
}

void Monster::setName(){
	name = R.generateName();
}

string Monster::getName(){
	return(name);
}

void Monster::display( ostream &out ) const {
	out << name;
}

/*
main(){
	srand( time(0) );
	Monster M1, M2, M3;
	cout << M1 << M2 << M3 << endl;
}
*/
