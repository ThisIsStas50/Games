/* Player.h
 *
 * Player Class Definition
 *
 * Methods & Friends Defined in Player.cpp
 * 
 * By Anastas Kanaris
 */


#ifndef PLAYER_H
#define PLAYER_H

#include "Name.h"
#include "Date.h"

#include <iostream>
using namespace std;


class Player {

	friend istream &operator>>(istream &, Player &);
	friend ostream &operator<<(ostream &, const Player &);

public:

	Player();

	virtual void display(ostream &, int = DEFAULT) const;

	bool operator>(const Player &) const;
	bool operator<(const Player &) const;
	Player operator++(int);
	Player operator--(int);

	virtual void draw();



	// I wrote these functions here bc they are just skeletons designed for
	// Derived Classes to Use
	virtual void setMarker(char c){
	}
	virtual void setIMarker(int i){
	}
	virtual int getIMarker() const{
	return(0);
	}
	virtual char getMarker() const{
	return(' ');
	}


protected:
	Name realName;
	Date birthday;

	string username;
	int totWins, totLosses, totDraws;
	static const int DEFAULT = 0;

	void input(istream&);

};



#endif
