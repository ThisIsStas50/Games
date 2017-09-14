/* Randomizer.cpp
 *
 * Method Definitions for Randomizer Class
 *
 * By Anastas Kanaris
 */

#include "Randomizer.h"

string Randomizer::initial = "-";

Randomizer::Randomizer(const string options[], const int size): max(size){
	items = NULL;
	usedItems = NULL;
	items = new string[max];
	usedItems = new string[max];
	if (items == NULL || usedItems == NULL){
		cerr << "Error. Memory was not allocated." << endl;
		exit(1);
	}

	for (int i = 0; i < max; i++){
		items[i] = options[i];
		usedItems[i] = "-";
	}

	numUsed = 0;
}

Randomizer::~Randomizer(){
	if (items != NULL){
		delete [] items;
		items = NULL;
	}
	if (usedItems != NULL){
		delete [] usedItems;
		usedItems = NULL;
	}
}

string Randomizer::generateName(){
	bool valid;
	string word;
	int num;

	do {
		valid = true;
		num = rand()%max;
		for(int i = 0; i < numUsed; i++)
			if(items[num] == usedItems[i]){
				valid = false;
				break;
			}
		if (valid){
			word = items[num];
			usedItems[numUsed] = word;
			numUsed++;
		}
	} while(!valid);

	return(word);
}

