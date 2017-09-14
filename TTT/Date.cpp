/* Date.cpp
 * Date class method definitions
 *
 * By Anastas Kanaris
 */

#include "Date.h"

istream &operator>>(istream &in, Date &D){
	D.input(in);
	return(in);
}

ostream &operator<<(ostream &out, const Date &D){
	D.display(out);
	return(out);
}

//
//Default Constructor that sets the
//data members to the default date
//of 1/1/1900
//
Date::Date(){
//	cout << "Date(): " << endl;

	month = day = MMD;
	year = 1900;
}

//
//Constructor which takes three arguements
//and sets the data members to the arguements
//passed
//
Date::Date(int month, int day, int year){
//	cout << "Date(" << month << ", " << day << ", " << year << "): " << endl;

	Date::month = month;
	Date::day = day;
	Date::year = year;
}

//
// Copy Constructor which takes
// an existing instance of this class
// and sets the data members from the 
// members of that date object passed.
//
Date::Date( const Date &d){
//	cout << "Date(" << d.month << ", " << d.day << ", " << d.year << ") :" << endl;

	month = d.month;
	day = d.day;
	year = d.year;
}

//
// Input method to allow the user to input the date.
// Method invokes the set methods as necessary to populate
// the members whose values should be validated.
//
void Date::input(istream &in){
	int m, d, y;
	m = d = y = 0;

	do{
		if (!y)
			cout << "Enter Year: ";
		else
			cout << y << " is in the future! Please re-enter: ";
		in >> y;
	} while(!setYear(y));

	do {
		if (!m)
			cout << "Enter Month: ";
		else
			cout << m << " is an invalid month, re-enter: ";
		in >> m;
	} while( !setMonth(m));

	do{
		if (!d)
			cout << "Enter Day: ";
		else
			cout << d << " is an invalid day for " << month << '/' << year << ", re-enter: ";
		in >> d;
	} while (!setDay(month, d, year));
}

//
// Display method to output the date
//

void Date::display(ostream &out) const{
	char dash = '/';
	out << month << dash << day << dash << year << endl;
}
//
// Mutator (Set) Methods
//


bool Date::setDate( int m, int d, int y){
	bool valid = false;

	if (setYear(y) && setMonth(m) && setDay(m, d, y))
		valid = true;
	return(valid);
}

//
// setDay is given a VALID month and a day,
// Validates the Day
// PRIVATE FUNCTION
//

bool Date::setDay(int m, int day, int y){
	bool valid = true;

	if (day < MMD || day > XD)
		valid = false;
	else if (day > XMD && day <= XD){
		switch (m){
			case 4:
			case 6:
			case 9:
			case 11:
				if (day == XD)
					valid = false;
				break;
			case 2:
				if ( day > XMD || (day == 29 && (y%4 != 0 || (y&100 == 0 && y%400 == 0))) )
					valid = false;
				break;
		}
	} else
		Date::day = day;
/*
	int maxDay = getMaxDay();

	if ( day >= 1 <= XD ) {
		int maxDay = XD;

		switch( m ) {

			case 4:
			case 6:
			case 9:
			case 11:
				maxDay = 30;
				break;

			case 2:
				if ( leap year )
					maxDay = 29;
				else
					maxDay = 28;
				break;
		}

		if ( d > maxDay )
			valid = false;

			
	}
*/

	return(valid);
}
	
	
bool Date::setMonth(int month){
	bool valid = true;

	if (month < MMD || month > XM)
		valid = false;
	else
		Date::month = month;
	return(valid);
}

bool Date::setYear(int year){
	bool valid = true;

	if (year > THISYEAR)
		valid = false;
	else
		Date::year = year;
	return(valid);
}

//
// Accessor (Get) Methods
//

int Date::getMonth() const{

	return(month);
}

int Date::getDay() const{

	return(day);
}

int Date::getYear() const{

	return(year);
}


//
// Overloaded Operator Methods
//

bool Date::operator<(const Date &D) const{
	bool lesser;
	if (D.year < year )
		lesser = true;
	else if (year < D.year)
		lesser = false;
	else {
		if ( D.month < month )
			lesser = true;
		else if (month < D.month)
			lesser = false;
		else {
			if (D.day < day)
				lesser = true;
			else
				lesser = false;
		}
	}
	return (lesser);
}

bool Date::operator>(const Date &D) const{
	return (D < *this);
}

bool Date::operator==(const Date &D) const{
	bool isEqual = true;
	if (*this > D || *this < D)
		isEqual = false;
	return(isEqual);
}


/*
main() {
	Date d, bday(3, 2, 1996);
	Date nday(bday);
	int month;

	d.displayDate();
	bday.displayDate();
	nday.displayDate();

	d.inputDate();
	d.displayDate();

	cout << "Enter a new month: ";
	cin >> month;

}
*/
