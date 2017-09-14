/* Cell.cpp
 *
 * Method Definitions for Cell Class
 * Also Defined: Friends of Class
 *
 * By Anastas Kanaris
 */

#include "Cell.h"

istream &operator>>(istream &in, Cell &C){
	C.input(in);
	return(in);
}

ostream &operator<<(ostream &out, const Cell &C){
	C.display(out);
	return(out);
}

void operator+=(int &n, const Cell &C){
	n += C.iMarker;
}



Cell::Cell(){

	marker = DEFMARKER;
	iMarker = ival;
}


Cell::Cell(const Cell &C){
	marker = C.marker;
	iMarker = C.iMarker;
}


void Cell::initialize(){
	marker = DEFMARKER;
	iMarker = ival;
}

void Cell::setMarker(char c){
	marker = c;
}

void Cell::setIMarker(int im){
	iMarker = im;
}

char Cell::getMarker() const{
	return(marker);
}

int Cell::getIMarker() const{
	return(iMarker);
}


void Cell::operator+=(int im){
	iMarker = im;
}

void Cell::operator+=(char mark){
	marker = mark;
}


void Cell::display(ostream &out) const{
	out << marker;
}

void Cell::input(istream &in){
	iMarker = 3;
}

