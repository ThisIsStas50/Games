/* Poem.cpp
 *
 * Methods of Poem Class defined here
 *
 * Also Defined, friends of Poem Class
 *
 * By Anastas Kanaris
 */



#include "Poem.h"

string Poem::initial = "-";

ostream &operator<<(ostream &out, const Poem &P){
	P.display(out);
	return(out);
}

istream &operator>>(istream &in, Poem &P){
	P.input(in);
	return(in);
}

Poem::Poem(int size){

	if (size > 0)
		pSize = size;
	else
		pSize = DEFAULTSIZE;
	// Allocate an array of the specified size
	words = new string[pSize];
	if (!words){
		// If the system can't allocate the memory, exit program
		cerr << "Error: Memory allocation failed, exiting program." << endl;
		pSize = 0;
		exit(1);
	}

	for (int i = 0; i < pSize; i++)
		words[i] = initial;

	numWords = 0;

}

Poem::~Poem(){
	if (words != NULL){
		delete [] words;
		words = NULL;
	}
}

void Poem::input(istream &in){
	string word;
	cout << "Its Time for your Final Challenge: " << endl << endl;

	do{
		cout << "Village Idiot #" << numWords+1 << ", what is your special word? ";
		if (numWords >= 5)
			cout << "If you don't have one, enter \"-\": ";
		in >> word;
		if (word == initial && numWords < 5)
			cout << "Come on... be creative will ya? This poem will not write itself!" << endl;
		else if (word != initial){
			if (!setWord(word))
				cout << word << " has already been given: please create an original special word or you really are a village idiot!" << endl;
		}
	} while(numWords < pSize && (word != initial || numWords < 5));
}

void Poem::display(ostream &out) const{
	string word;
	Randomizer R(words, numWords);

	out << endl << "The Village Idiot Poem that Has Been Generated is: " << endl;
	for (int i = 0; i < numWords; i++){
		word = R.generateName();
		out << word << endl;
	}
	out << endl << "Not a fan? Well you shouldn't have asked the village idiots to be Poets..." << endl;

}

bool Poem::setWord(string word){
	bool valid = true;
	for (int i = 0; i < numWords; i++){
		if (words[i] == word){
			valid = false;
			break;
		}
	}
	if (valid){
		words[numWords] = word;
		numWords++;
	}
	return(valid);
}
