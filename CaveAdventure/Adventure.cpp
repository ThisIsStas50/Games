/* Adventure.cpp
 *
 * Methods for Class Adventure Defined Here
 * Also Defined: Friends of Class Adventure
 *
 * By Anastas Kanaris
 */

#include "Adventure.h"

int Adventure::numAdventures = 0;
const string Adventure::LOCNAMES[Adventure::MAX] = {"entering the Mouth of the Caves", "venturing deeper into the Cave", "in the Depths of the Cave"};


ostream &operator<<(ostream &out, const Adventure &A){
	A.display(out);
	A.game(out);
	return(out);
}


Adventure::Adventure(){
	location = LOCNAMES[numAdventures];
	numAdventures++;
	twelveDays.setSong(1);
	fakeTreasure = false;
}

Adventure::Adventure(int num):Adventure(){
	if (num+1 == numAdventures){
		falseTreasure = "Silver Tray of Life";
		fakeTreasure = true;
	}
}

Adventure::~Adventure(){
	numAdventures--;
}

int Adventure::getMAX(){
	return(MAX);
}

void Adventure::display(ostream &out) const{

	out << "You are now " << location << endl;

}

void Adventure::game(ostream &out) const{
	int ans;
	bool monster = true, treasure = true, level = true;
	bool fakeTreasure = Adventure::fakeTreasure;

	do{
		ans = selection(out, monster, treasure, fakeTreasure);
		switch (ans){
			case 1:
				if (monster){
					if (!treasure && fakeTreasure){
						out << "Brave Knight, you were not tricked and have slain the " << M << "!!!" << endl;
						fakeTreasure = false;
					}else
						out << "Congratulations!, you have slain the " << M << "!!!" << endl;
					monster = false;
				}
				else if (treasure){
					out << "Congratulations! You have grabbed the " << T << "!!!" << endl;
					treasure = false;
				}
				else
					level = false;
				break;
			case 2:
				if (monster && treasure){
					out << "Congratulations! You have grabbed the " << T << "!!!";
					treasure = false;
					out << "\nWhy don't you take a well deserved rest?" << endl << endl << "Zzzzzzzzzz zzzzzzz..." << endl << endl;
					out << oldMac << endl; 
					out << "Now you are rested and ready to continue with the journey!" << endl;
				}
				else if (fakeTreasure){
					out << "YOU FOOOL!!! YOU GRABBED THE WRONG TREASURE!!! Now you must sing the 12 days of Christmas!!!" << endl << endl;
					out << twelveDays << endl;
					out << "Now that you have paid your pennance, you can continure on the journey." << endl;
				}
				else if (monster)
					out << "NOOOOOOO KNIGHT!!! YOU MUST DEFEAT THE MONSTER!!!! WHAT KIND OF HERO ARE YOU????" << endl;
				else if (treasure)
					out << "NOOOOOOO KNIGHT!!! YOU MUST GRAB THE " << T << "!!! IT BELONGED TO MY MOTHER!!!!" << endl;
				break;
		}
	} while (level);
}



int Adventure::selection(ostream &out, const bool &monster, const bool &treasure, const bool &fakeTreasure) const{
	int ans = 1, count;
	do{
		if (ans == 1)
			out << "What would you like to do?" << endl;
		else
			out << ans << " is invalid. Please select a valid option." << endl;
		count = 1;
		if (monster)
			out << count++ << ": Attack the " << M << endl;
		if (treasure)
			out << count++ << ": Pick up the " << T << endl;
		if (monster && !treasure && fakeTreasure)
			out << count++ << ": Pick up the " << falseTreasure << endl;
		if ((!monster || !treasure) && !fakeTreasure)
			out << count++ << ": Move on to the next adventure." << endl;
		out << "What will it be: ";
		cin >> ans;
	} while (ans != 1 && ans != 2);
	return(ans);
}

