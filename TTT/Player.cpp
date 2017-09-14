/* Player.cpp
 *
 * Player Class Methods & Friend Function Definitons
 *
 * By Anastas Kanaris
 */

#include "Player.h"

istream &operator>>(istream &in, Player &P){
	P.input(in);
	return(in);
}

ostream &operator<<(ostream &out, const Player &P){
	P.display(out);
	return(out);
}

Player::Player(){

	username = "dummy";
	totWins = totLosses = totDraws = DEFAULT;
}

void Player::input(istream &in){
	in >> realName >> birthday;
	cout << "Enter username: ";
	in >> username;
}

void Player::display(ostream &out, int type) const{
	if (type){
		out << realName << birthday;
		out << "Username: " << username << endl;
		out << "Total Wins: " << totWins << endl;
		out << "Total Losses: " << totLosses << endl;
		out << "Total Draws: " << totDraws << endl;
	}
	else
		out << username;

}

bool Player::operator<(const Player &P) const{
	return(birthday < P.birthday);
}

bool Player::operator>(const Player &P) const{
	return(birthday > P.birthday);
}

Player Player::operator++(int dummy ){
	Player C = *this;
	totWins++;
	return( C );
}

Player Player::operator--(int dummy){
	Player C = *this;
	totLosses++;
	return(C);
}

void Player::draw(){
	totDraws++;
}


/*
main(){
	Player P;
	cin >> P;
	cout << P;
}
*/
