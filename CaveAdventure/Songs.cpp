/* Songs.cpp
 *
 * Member Functions for class Songs defined here
 * Also defined: Friends of Class Functions
 *
 * By Anastas Kanaris
 */


#include "Songs.h"

const string Songs::animals[Songs::SIZE] = {"cow", "sheep", "pig", "chicken"};


ostream &operator<<(ostream &out, const Songs &s){
	switch (s.song){
		case 0:
			s.oldMacDonald(out);
			break;
		case 1:
			s.twelveDays(out);
			break;
	}
	return(out);
}


Songs::Songs(int choice){
	setSong(choice);
}

Songs::~Songs(){

}

bool Songs::setSong(int choice){
	bool valid = false;
	if (choice == 0 || choice == 1){
		valid = true;
		song = choice;
	}
	return (valid);
}

void Songs::oldMacDonald(ostream &out) const{

	Randomizer R(animals, SIZE);
	string noise, animal;

	for (int i = 0; i < SIZE; i++){
		animal = R.generateName();
		noise = animalSounds(animal);
		out << "Old MacDonald had a farm. E-I-E-I-O!" << endl;
		out << "And on his farm he had a " << animal << ". E-I-E-I-O!" << endl;
		out << "With a " << noise << ' ' << noise << " here and a " << noise << ' ' << noise << " there. "
		    << "Here a " << noise << ", there a " << noise << " everywhere a " << noise << ' ' << noise << endl;
		out << "Old MacDonald had a farm. E-I-E-I-O!" << endl;
	}
}

string Songs::animalSounds(string animal) const{
	string noise;
	if (animal == "chicken")
		noise = "cluck";
	else if (animal == "pig")
		noise = "oink";
	else if (animal == "cow")
		noise = "moo";
	else if (animal == "sheep")
		noise = "baaah";
	return(noise);
}

void Songs::twelveDays(ostream &out) const{
	string suffix, msg;

	for (int i = 1; i <= 12; i++){
		switch (i){
			case 1:
				suffix = "st";
				break;
			case 2:
				suffix = "nd";
				break;
			case 3:
				suffix = "rd";
				break;
			default:
				suffix = "th";
				break;
		}
		out << "On the " << i << suffix << " day of Christmas, my true love gave to me: " << endl;
		for (int j = i; j >= 1; j--){
			switch (j){
				case 1:
					msg = "a partridge in a pear tree!";
					break;
				case 2:
					msg = "two turtle doves, and ";
					break;
				case 3:
					msg = "three French hens, ";
					break;
				case 4:
					msg = "four calling birds, ";
					break;
				case 5:
					msg = "FIVE!!! GOL-DEN RINGS!!!!!!! ";
					break;
				case 6:
					msg = "six geese a laying, ";
					break;
				case 7:
					msg = "seven swans a swimming, ";
					break;
				case 8:
					msg = "eight maids a milking, ";
					break;
				case 9:
					msg = "nine ladies dancing, ";
					break;
				case 10:
					msg = "ten lords a leaping, ";
					break;
				case 11:
					msg = "eleven pipers piping, ";
					break;
				case 12:	
					msg = "twelve drummers drumming, ";
					break;
			}
			out << msg;
		}
		out << endl << endl;
	}



}
