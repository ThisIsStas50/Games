/* Now this is the story all about how
 * this software got flip turned upside down
 * And I'd like to take a minute
 * Just sit right there
 * I'll tell you how I became the all time best tic tac toe game
 * ..
 * ...
 * ...
 * ... Iiinnnn
 * Babbage's mind, I was born and raised
 * A number calculator is how I spent most of my days!
 * Chillin' out multiplyin' primes all cool
 * and all dividing by the square of 29 (that's 841)
 * when a couple of guys who were up to no good
 * starting taking calc 2 in my neighborhood
 * I got them one bad test and they all got scared
 * so then I moved on to being the king of this old school game here
 * ..
 * ...
 * ...
 * .. (I have rhymes for days - the next eminem right hurr.. haha)
 * Anyway, program created by Anastas Kanris
 * on 6/24/15
 * Last edited on 6/26
 *
 */



#include <iostream> //Directories in use
#include <cstdlib>
#include <ctime>
#include <cmath> //To calculate absolute value in determining winner
using namespace std;

const int MAX = 3; //Global Variables
const int ROWS = MAX, COLUMNS = MAX;
int tttBoard[ROWS][COLUMNS] = { {0}, {0} };
bool win = false, p1_win = false;

main()
{
	void initialTTT();//Main functions
	void displayTTT();
	void assignGame(string &, string &);
	void game(int, string);
	bool winner(int);
	string whoWon(string, string);
	void announceResults(string);
	bool contPlay();

	int p1 = 1, p2 = -1, count = 0;//Variables Local to Main
	string p1_name, p2_name, winnerName;

	srand( time(0) ); //Time Randomizer ( for coinflip )

	do
	{
		assignGame(p1_name, p2_name); //Determines who is playing and order
		displayTTT();
		count = 0; //Counter used to track moves in the game
		do
		{
			count++;
			if ( count % 2 == 1 ) //Determines turn
				game(p1, p1_name);
			else
				game(p2, p2_name);
			displayTTT();
		}
		while ( !winner(count) && count < 9 ); //LoopBreaker

		if ( win ) //If win, who won?
			winnerName = whoWon(p1_name, p2_name);
		announceResults(winnerName); //Results announced
		initialTTT(); //Board clears
		win = false; //Resets win to false
	}
	while ( contPlay() ); //Asks for continuation
	cout << "Bye!!" << endl;	

}//End of program

void initialTTT()//Initializes TTT Board
{
	for ( int r = 0; r < ROWS; r++ )
	{
		for ( int c = 0; c < COLUMNS; c++ )
		{
			tttBoard[r][c] = 0;
		}
	}
}

void displayTTT() //Displays TTT Board
{
	for ( int r = 0; r < ROWS; r++ )
	{
		for ( int c = 0; c < COLUMNS; c++ )
		{
			if ( c == 0 )
				cout << ' ';
			switch ( tttBoard[r][c] )
			{
				case 0:
					cout << ' ';
					break;
				case 1:
					cout << 'X';
					break;
				case -1:
					cout << 'O';
					break;
			}
			if ( c < COLUMNS - 1 )
				cout << " | ";
		}
		if ( r < ROWS - 1 )
			cout << "\n---+---+---" << endl;
	}
	cout << endl;
}

void assignGame(string &p1_name, string &p2_name) //Assigns Players
{
	bool checkPlayers(); //Local functions
	string getName(string);
	int callCoin(string);
	bool flipCoin(int);

	static string nm1, nm2; //Static Variables
	static int count = 0;
	int choice, coin;
	bool samePlayers = false;

	count++;
	if ( count > 1 )
		samePlayers = checkPlayers(); //Checks whether or not the same people are playing
	if ( count == 1 || !samePlayers) //If first game or if new people are playing, finds out whose playing
	{
		nm1 = getName("first");
		nm2 = getName("second");
	}

	choice = callCoin(nm1); //Calls coinflip
	if ( flipCoin(choice) ) //Coinflip: Order determined
	{
		p1_name = nm1;
		p2_name = nm2;
	}
	else
	{
		p1_name = nm2;
		p2_name = nm1;
	}

	cout << p1_name << " will go first as the X." << endl;
}

string getName(string number) //Gets name
{
	string name;
	cout << "Will the " << number << " contestant enter a name and press enter: ";
	cin >> name;
	return(name);
}

bool checkPlayers()
{
	char ans;
	bool samePlayers = false;

	cout << "Are the same players playing? ";
	cin >> ans;
	if ( ans == 'Y' || ans == 'y' )
		samePlayers = true;
	else if ( ans != 'N' && ans != 'n' ) //Program is a smartass part 1
		cout << "I guess not!! Follow directions in future." << endl;
	return(samePlayers);
}

int callCoin(string name)
{
	char choice;
	int coin;

	cout << name << ", I will now flip a coin. Please call heads (H) or tails (T): ";
	cin >> choice;
	switch ( choice )
	{
		case 'H':
		case 'h':
			coin = 1;
			break;
		case 'T':
		case 't':
			coin = 0;
			break;
		default: //Program is a smartass part 2!
			cout << "Congratulations, you have forfeited the chance to go first! ";
			break;
	}
	return(coin);
} 

bool flipCoin(int choice)
{
	int coin;
	bool first = true;

	coin = rand() % 2;
	if ( choice != coin )
		first = false;
	return(first);
}

void game(int piece, string player_name) //Plays the game
{
	void instruction(string); //Local Functions
	bool validSpot(int, int);

	int x, y;
	char comma = ',';
	do
	{
		instruction(player_name);
		cin >> x >> comma >> y; 
	} while ( !validSpot(x, y) );
	tttBoard[x][y] = piece;
}

void instruction(string name) //Instructions on how to play
{
	cout << name << ", enter co-ordinates in the format x,y from (0,0) to (" << ROWS - 1 << ',' << COLUMNS - 1 << ") ((" << ROWS / 2 << ", " << COLUMNS / 2 << ") is the center): ";
}

bool validSpot(int x, int y) //Checks if spot is valid
{
	bool valid = true;
	if ( x > ROWS - 1 || x < 0 || y > COLUMNS - 1 || y < 0 )
		valid = false;
	else if ( tttBoard[x][y] != 0 )
		valid = false;
	else
		valid = true;
	return(valid);
}
bool winner(int count) //Checks for winner
{
	bool checkV(int); //Local functions
	bool checkH(int);
	bool checkD(int, int);

	int sumV = 0, sumH = 0, sumLD = 0, sumRD = 0;
	if ( count >= 5 ) //Check 1: If not enough moves were made, it won't check for a winner
	{
		if ( checkV(sumV) )
			win = true;
		else if ( checkH(sumH) )
			win = true;
		else if ( checkD(sumLD, sumRD) )
			win = true;
	}
	return(win);
}

bool checkV(int sumV) //Checks for vertical win
{
	bool gameOver = false;

	for ( int r = 0; r < MAX; r++ )
	{
		for ( int c = 0; c < MAX; c++ )
		{
			sumV += tttBoard[c][r];
		}
		if ( fabs( sumV ) == MAX)
		 //We set a value for each player (player 1's pieces are 1's, player 2's are -1's) so the absolute values for them will be the same
		 //Because of that, we only need to check the absolute value to see if there was a winner
		{
			gameOver = true;
			if ( sumV == MAX ) //This checks for if p1 or p2 won
				p1_win = true;
			break;
		}
		else
			sumV = 0;
	}
		return(gameOver);
}


bool checkH(int sumH ) //Checks for a horizontal win
{
	bool gameOver = false;

	for ( int r = 0; r < MAX; r++ )
	{	
		for ( int c = 0; c < MAX; c++ )
		{
			sumH += tttBoard[r][c];
		}
		if ( fabs( sumH ) == MAX )
		{
			gameOver = true;
			if ( sumH == MAX )
				p1_win = true;
			break;
		}
		else
			sumH = 0;
	}
	return(gameOver);
}

bool checkD(int sumLD, int sumRD)  //Checks for a diagonal winner
{
	bool gameOver = false;

	for ( int r = 0; r < MAX; r++ )
	{
		for ( int c = 0; c < MAX; c++ )
		{
			if ( r == c )
			{
				sumLD += tttBoard[r][c];
			}
			if ( r == MAX - 1 - c )
			{
				sumRD += tttBoard[r][c];
			}
		}	
	}
	if ( fabs( sumLD ) == MAX || fabs( sumRD ) == MAX )
	{
		gameOver = true;
		if ( sumLD == MAX || sumRD == MAX )
			p1_win = true;
	}
	return(gameOver);
}

string whoWon(string p1_name, string p2_name) //Attatches the string variable winnerName to the winner, based on the results of p1_win
{
	string theBigWinner;

	if ( p1_win )
	{
		theBigWinner = p1_name;
		p1_win = false;
	}
	else
		theBigWinner = p2_name;
	return(theBigWinner);
}
void announceResults(string winnerName) //Announces those results
{
	if ( win )
	{
		cout << "We have a winner!! Congrats to " << winnerName << "!!!" << endl;
	}
	else
		cout << "Drat, a draw... Better luck next time!" << endl;
}

bool contPlay() //Checks for continuation
{
	char ans;
	bool play = true;

	do
	{
		cout << "Want to play again? ";
		cin >> ans;
		if ( ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n' )
			cout << "Does Not Compute. ";
	} while ( ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n' );

	if ( ans == 'N' || ans == 'n' )
		play = false;
	return(play);
}
