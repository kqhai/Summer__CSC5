/*
	Author: Manuel M.
	Date: July 21, 2025
	Purpose:Cee-Lo Dice Game Project
	------------------------------------------------------
	Cee-Lo:
	Originating from the east coast Cee-Lo was brought over from chinese-american laborers 
	almost like a game of craps the player uses 3 dices instead of 2.
	-----------------------
	Rules:
	-----------------------
	Instant wins:
	Triple Same number
	sequential 4-5-6
	Two Alike Six High // a pair accompanied by a six
	-------------------------------------------------------------------------------
	Pair+Value (point system)
	A pair and a value over one 
	| The value seperate from the pair is the amount of-
	points awarded so if you roll 2-2-5 you get 5 points. |
	so if one gets 5 and the other gets 3 the one who got 5 wins.
	---------------------------------------------------------------------------------
	Instant Loss:
	Sequential 1-2-3
	Pair and a One
	-------------------------
	Inderterminate(ReRoll):
	If the combination of dices does NOT result in a sequential 4-5-6 || 1-2-3
	nor a pair + value.
	REQUIRES REROLL.
*/

//system libs
#include <iostream> //input/output
#include <iomanip>//format lib
#include <cstdlib>  // rand, srand
#include <ctime> //mess with rand lib
using namespace std;

//user libs

//constants - Physics, CHemistry, Conversions, Higher Dimensions

//Function Prototypes

//Executable Begins Here
int main(int argv, char** argc)
{
	//Set the random number seed
	srand(static_cast<unsigned int>(time(0)));
	
	//Declare Variables
	int dice1,//dice1
		  dice2,//dice2
		  dice3,//dice3
		  pnts=0,//points
		  rCount=0; //roll counter
	char init;
	bool result = true; //win lose condition for do while loop 
	//Initialize Game
	cout << "You're playing a game of Cee-Lo, to start the game type in Y to roll or N to Exit now" << endl;
	cin >> init;
	if (init == 'y' || init == 'n') { //capitalizes the users lazyness
		init = init - 32;
	}
	if (init == 'Y') { 
		result = true;
	}
	else if (init == 'N') {
		result = false;
		return 0;
	}
	else { //incase user decides to input another character
		cout << "Must Enter Y or N."<<endl;
		result = false;
		return 0;
	}
	//Game loop
	do {
		//initialize dices
		dice1 = rand() % 6 + 1;
		dice2 = rand() % 6 + 1;
		dice3 = rand() % 6 + 1;
		//display the results
		cout << "You rolled:" << setw(2) << dice1 << setw(2) << dice2 << setw(2) << dice3 << endl;
		rCount++;
		cout << "Times Rolled: \x1B[5m" << rCount << "\x1B[25m" << endl;
		//win conditions
		if ((dice1 == 4 || dice1 == 5 || dice1 == 6) &&
			(dice2 == 4 || dice2 ==5 || dice2 == 6) &&
			(dice3 == 4 || dice3 == 5 || dice3 == 6) 
		{
			cout << "Winner!" << endl;
			result = false;
			return 0;
		}
	} while (result == true);
	
	return 0;
}

