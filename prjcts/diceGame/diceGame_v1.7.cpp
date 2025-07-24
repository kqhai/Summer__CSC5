/*
	Author: Manuel M.
	Date: July 23, 2025
	Purpose: Cee-Lo Dice Game Project
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
#include <fstream>
#include <cmath>
#include <string>
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
		rCount = 0; //roll counter
	float pnts = 0,//points
		     pnts2 = 0;//points for other player
	char init;
	bool result = true,//win lose condition for do while loop 
		snglRoll = false; // will be used for for loop in order to keep the diced rolled once
	string initSen = "You're playing a game of Cee-Lo, to start the game type in Y to roll or N to Exit now";
	//Initialize Game
	cout << initSen << endl;
	cin >> init;
	//capitalizes the users lazyness
	if (init == 'y' || init == 'n') { 
		init = init - 32;
	}
	//user input to start game
	if (init == 'Y') {
		result = true;
	}
	else if (init == 'N') {
		result = false;
		return 0;
	}
	else { //incase user decides to input another character
		cout << "Must Enter Y or N." << endl;
		result = false;
		return 0;
	}

	//Game loop
	do
	{
		if (snglRoll != true) {
			//initialize dices
			dice1 = rand() % 6 + 1;
			dice2 = rand() % 6 + 1;
			dice3 = rand() % 6 + 1;

			//roll counter
			cout << "You rolled:" << setw(2) << dice1 << setw(2) << dice2 << setw(2) << dice3 << endl;
			rCount++;
			cout << "Times Rolled: " << rCount << endl; //roll count

			//win conditions
			if ((dice1 == 4 && dice2 == 5 && dice3 == 6) ||//sequintial 456 if statement
				(dice1 == 6 && dice2 == 5 && dice3 == 4) ||
				(dice1 == 5 && dice2 == 6 && dice3 == 4) ||
				(dice1 == 4 && dice2 == 6 && dice3 == 5) ||
				(dice1 == 6 && dice2 == 4 && dice3 == 5) ||
				(dice1 == 5 && dice2 == 4 && dice3 == 6))
			{
				cout << "\x1B[5m" << "Winner! Sequential 4-5-6!!" << "\x1B[25m" << endl;
				result = false;
				return 0;
			}
			else if (dice1 == dice2 && dice2 == dice3)//three of same number 
			{
				cout << "\x1B[5m" << " Winner! Triple Same Number!!" << "\x1B[25m" << endl;
				result = false;
				return 0;
			}
			else if ((dice1 == dice2 && dice3 == 6) || //two of same number and a six
				(dice1 == dice3 && dice2 == 6) ||
				(dice2 == dice3 && dice1 == 6))
					{
						cout << "\x1B[5m" << "Winner! Two alike with a Six High!!" << "\x1B[25m" << endl;
						result = false;
					}

			//loss conditions 
			if ((dice1 == 1 && dice2 == 2 && dice3 == 3) || //sequential 1-2-3
				(dice1 == 3 && dice2 == 2 && dice3 == 1) ||
				(dice1 == 2 && dice2 == 3 && dice3 == 1) ||
				(dice1 == 1 && dice2 == 3 && dice3 == 2) ||
				(dice1 == 3 && dice2 == 1 && dice3 == 2) ||
				(dice1 == 2 && dice2 == 1 && dice3 == 3))
			{
				cout << "\x1B[5m" << "LOSER! Sequential 1-2-3!!" << "\x1B[25m" << endl;
				result = false;
			}
			else if ((dice1 == dice2 && dice3 == 1) || //two of the same with a One
				(dice1 == dice3 && dice2 == 1) ||
				(dice2 == dice3 && dice1 == 1))
					{
						cout << "\x1B[5m" << "YOU LOST! Pair with a One!!" << "\x1B[25m" << endl;
						result = false;
					}
			//point system (4-4-5 = 5 points < 2-2-3 = 3 points)
			if ((dice1 == dice2 && dice3 != dice1 && dice3 != 1 && dice3 != 6) ||
				(dice1 == dice3 && dice2 != dice1 && dice2 != 1 && dice2 != 6) ||
				(dice2 == dice3 && dice1 != dice2 && dice1 != 1 && dice1 != 6))
			{
				if (pnts > 0) {
					pnts2 = dice3;
					if (pnts > pnts2) {
						cout << "\x1B[5m" << "Player One Wins!!" << "\x1B[25m" << endl;
						result = false;
					}
					else if (pnts == pnts2) {
						cout << "\x1B[5m" << "Tie!! Play Again." << "\x1B[25m" << endl;
						result = false;
					}
					else if (pnts < pnts2) {
						cout << "\x1B[5m" << "Player Two Wins!!" << "\x1B[25m" << endl;
						result = false;
					}
				}else pnts = dice3;
				//cout << "Pair with value: " << pnts << " points." << endl; 
				snglRoll = true;
			}
			else cout << "No working combos. Rerolling!" << endl;
			// single roll process
			snglRoll = true;
			if (result == true)
			{
				cout << "Roll again? (Y/N): ";
				cin >> init;

				//capitalize laziness again
				if (init == 'y' || init == 'n') {
					init = init - 32;
				}
				//turnary operator
				snglRoll = (init == 'Y') ? false : snglRoll; // allow next roll
				result = (init != 'Y') ? false : result;// end game
			}
		}
	} while (result == true);
	return 0;
}
//for loop idea: combonation counter to know when theres no combination (Inderterminate(ReRoll)) 
//average roll counter
//switch still needed
//cmath usage needed
//fstream file input output usage needed aswell 