/*
    Author: Manuel M.
    Date: July 24, 2025
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
#include <iomanip>  //format lib
#include <cstdlib>  //rand, srand
#include <ctime>    //time for rand seed
#include <fstream>  //file stream
#include <cmath>    //math functions
#include <string>   //string lib
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
    int dice1, dice2, dice3, rCount, combo;
    const int rndSeed = pow(2, 3) - 1; //2^3-1 = 7
    float pnts, pnts2;
    char init, pAgn;
    bool result, snglRoll, plyAgn = true;
    string initSen = "You're playing a game of Cee-Lo, to start the game type in Y to roll or N to Exit now";

    //file setup
    ofstream fName;
    fName.open("diceGame_Results.txt"); //opens and writes in file

    //play again loop
    while (plyAgn == true)
    {
        //reinitialize
        result = true;
        snglRoll = false;
        rCount = 0;
        combo = 0;
        pnts = 0;
        pnts2 = 0;

        //Initialize Game
        cout << initSen << endl;
        fName << initSen << endl;
        cin >> init;

        //capitalizes the users lazyness
        if (init == 'y' || init == 'n') {
            init = init - 32;
        }

        //switch case to check yes or no
        switch (init)
        {
        case 'Y': result = true; break;
        case 'N': result = false; break;
        default:
            cout << "Must Enter Y or N." << endl;
            fName << "Must Enter Y or N." << endl;
            result = false;
        }

        //Game loop
        do {
            if (!snglRoll) {
                //initialize dices
                dice1 = rand() % rndSeed;
                dice2 = rand() % rndSeed;
                dice3 = rand() % rndSeed;

                //roll counter
                cout << "You rolled:" << setw(2) << dice1 << setw(2) << dice2 << setw(2) << dice3 << endl;
                fName << "You rolled:" << setw(2) << dice1 << setw(2) << dice2 << setw(2) << dice3 << endl;

                rCount++;
                cout << "Times Rolled: " << rCount << endl;
                fName << "Times Rolled: " << rCount << endl;

                //win conditions
                if ((dice1 == 4 && dice2 == 5 && dice3 == 6) || //sequential 456
                    (dice1 == 6 && dice2 == 5 && dice3 == 4) ||
                    (dice1 == 5 && dice2 == 6 && dice3 == 4) ||
                    (dice1 == 4 && dice2 == 6 && dice3 == 5) ||
                    (dice1 == 6 && dice2 == 4 && dice3 == 5) ||
                    (dice1 == 5 && dice2 == 4 && dice3 == 6)) {
                    cout << "Winner! Sequential 4-5-6!!" << endl;
                    fName << "Winner! Sequential 4-5-6!!" << endl;
                    combo++; result = false;
                }
                else if (dice1 == dice2 && dice2 == dice3) { //triple same number
                    cout << "Winner! Triple Same Number!!" << endl;
                    fName << "Winner! Triple Same Number!!" << endl;
                    combo++; result = false;
                }
                else if ((dice1 == dice2 && dice3 == 6) || //two alike with six high
                    (dice1 == dice3 && dice2 == 6) ||
                    (dice2 == dice3 && dice1 == 6)) {
                    cout << "Winner! Two alike with a Six High!!" << endl;
                    fName << "Winner! Two alike with a Six High!!" << endl;
                    combo++; result = false;
                }

                //loss conditions
                if ((dice1 == 1 && dice2 == 2 && dice3 == 3) || //sequential 123
                    (dice1 == 3 && dice2 == 2 && dice3 == 1) ||
                    (dice1 == 2 && dice2 == 3 && dice3 == 1) ||
                    (dice1 == 1 && dice2 == 3 && dice3 == 2) ||
                    (dice1 == 3 && dice2 == 1 && dice3 == 2) ||
                    (dice1 == 2 && dice2 == 1 && dice3 == 3)) {
                    cout << "LOSER! Sequential 1-2-3!!" << endl;
                    fName << "LOSER! Sequential 1-2-3!!" << endl;
                    combo++; result = false;
                }
                else if ((dice1 == dice2 && dice3 == 1) || //pair with a one
                    (dice1 == dice3 && dice2 == 1) ||
                    (dice2 == dice3 && dice1 == 1)) {
                    cout << "YOU LOST! Pair with a One!!" << endl;
                    fName << "YOU LOST! Pair with a One!!" << endl;
                    combo++; result = false;
                }

                //point system (pair + value)
                if ((dice1 == dice2 && dice3 != dice1 && dice3 != 1 && dice3 != 6) ||
                    (dice1 == dice3 && dice2 != dice1 && dice2 != 1 && dice2 != 6) ||
                    (dice2 == dice3 && dice1 != dice2 && dice1 != 1 && dice1 != 6)) {
                    if (pnts > 0) {
                        pnts2 = dice3;
                        if (pnts > pnts2) {
                            cout << "Player One Wins!!" << endl;
                            fName << "Player One Wins!!" << endl;
                        }
                        else if (pnts == pnts2) {
                            cout << "Tie!! Play Again." << endl;
                            fName << "Tie!! Play Again." << endl;
                        }
                        else {
                            cout << "Player Two Wins!!" << endl;
                            fName << "Player Two Wins!!" << endl;
                        }
                        combo++; result = false;
                    }
                    else {
                        pnts = dice3;
                    }
                    combo++;
                    snglRoll = true;
                }

                //indeterminate (reroll)
                if (combo == 0) {
                    cout << "Indeterminate! (ReRoll)" << endl;
                    fName << "Indeterminate! (ReRoll)" << endl;
                    snglRoll = false;
                }

                //ask to roll again
                if (result == true) {
                    cout << "Roll again? (Y/N): " << endl;
                    fName << "Roll again? (Y/N): " << endl;
                    cin >> init;

                    if (init == 'y' || init == 'n') init = init - 32;

                    snglRoll = (init == 'Y') ? false : snglRoll;
                    result = (init != 'Y') ? false : result;
                }
            }
        } while (result == true);

        //ask to play again
        cout << "Do you want to play again? (Y/N): " << endl;
        fName << "Do you want to play again? (Y/N): " << endl;
        cin >> pAgn;

        if (pAgn == 'y' || pAgn == 'n') pAgn = pAgn - 32;

        switch (pAgn)
        {
        case 'Y': plyAgn = true; break;
        case 'N': plyAgn = false; break;
        default:
            cout << "Must Enter Y or N." << endl;
            fName << "Must Enter Y or N." << endl;
            plyAgn = false;
        }
    }

    fName.close(); //close the file
    return 0;
}