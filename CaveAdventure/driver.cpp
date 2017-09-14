/* driver.cpp
 *
 * Driver function for the Cave Adventure Program
 * Must be Compiled with Cave.cpp
 *
 * By Anastas Kanaris
 */

#include "Cave.h"
#include "Poem.h"


main(){

	srand( time(0) );
	int location = rand()%3; 
	Cave game(location);
	Poem finalChallenge;

	cin >> game;
	cout << game;
	cin >> finalChallenge;
	cout << finalChallenge;

}
