/* TTTPlayer.cpp
 *
 * Methods & Friend of TTTPlayer Class Defined Here
 *
 * By Anastas Kanaris
 */


#include "TTTPlayer.h"

const char TTTPlayer::MARKERS[TTTPlayer::NUM_MARKS] = {'X', 'O'};
int TTTPlayer::numPlayers = DEFAULT;

ostream &operator<<(ostream &out, const TTTPlayer &P){
	P.display(out);
	return(out);
}

TTTPlayer::TTTPlayer(){
	marker = MARKERS[numPlayers];
	tttWins = tttLosses = tttDraws = DEFAULT;
	numPlayers++;
}


TTTPlayer::~TTTPlayer(){
	numPlayers--;
}

void TTTPlayer::setIMarker(int i){
	iMarker = i;
}

void TTTPlayer::setMarker(char c){
	marker = c;
}

int TTTPlayer::getIMarker() const{
	return(iMarker);
}

char TTTPlayer::getMarker() const{
	return(marker);
}

void TTTPlayer::display(ostream &out, int type) const{

	Player::display(out, type);
	if (type){
		out << "Tic-Tac-Toe Wins: " << tttWins << endl;
		out << "Tic-Tac-Toe Losses: " << tttLosses << endl;
	}

}


TTTPlayer TTTPlayer::operator++(int d){
	TTTPlayer C = *this;
	totWins++;
	tttWins++;
	return(C);
}

TTTPlayer TTTPlayer::operator--(int dummy){
	TTTPlayer C = *this;
	totLosses++;
	tttLosses++;
	return(C);
}


void TTTPlayer::draw(){
	Player::draw();
	tttDraws++;
}



/*
main(){
	TTTPlayer p1;
	cin >> p1;
	cout << p1;

}
*/

