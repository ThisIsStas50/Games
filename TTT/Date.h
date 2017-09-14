
/* Date.h
 * Date class definition
 * Methods defined in Date.cpp
 *
 * By Anastas Kanaris
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{

	friend ostream &operator<<(ostream &, const Date &);
	friend istream &operator>>(istream &, Date &);

public:
	//
	//Class Constructors
	//
	Date(); // Default Constructor
	Date(int, int, int); // Constructor that takes three arguements (month, day and year)
	Date ( const Date& ); // Copy constructor

	//
	// Class level external input/output
	//
	void input(istream &);
	void display(ostream &) const;

	//
	//Set Methods
	//
	bool setMonth(int);
	bool setDate(int, int, int);
	bool setYear(int);

	//
	//Get Methods
	//
	int getMonth() const;
	int getDay() const;
	int getYear() const;

	// 
	// Operator Overloads
	//
	bool operator<(const Date &) const;
	bool operator==(const Date &) const;
	bool operator>(const Date &) const;

private:
	int month, day, year;
	static const int MMD = 1, XMD = 28, XM = 12, XD = 31, THISYEAR = 2016;

	bool setDay(int, int, int);

};

#endif
