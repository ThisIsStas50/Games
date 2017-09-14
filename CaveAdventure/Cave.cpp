/* Cave.cpp
 *
 * Methods of Cave Class Defined Here
 * Also Defined: Friends of Cave Class
 *
 * By Anastas Kanaris
 */

#include "Cave.h"

istream &operator>>(istream &in, Cave &game){
	game.input(in);
	return(in);
}

ostream &operator<<(ostream &out, const Cave &game){
	game.display(out);
	return(out);
}

Cave::Cave(int fakeLocation):advent1(fakeLocation), advent2(fakeLocation), advent3(fakeLocation){
	hero = "Dummy";
}

Cave::~Cave(){
	cout << "Thanks for playing!!" << endl;
}

void Cave::input(istream &in){
	cout << "Brave Knight!!! What is your name? ";
	in >> hero;
}

void Cave::display(ostream &out) const{
	out << "The Brave Knight's name is: " << hero << endl
	    << advent1 << advent2 << advent3 << endl;
}
