/*Name: Jordan Forthman
About this project: This project offers users a menu of options including 3 playable games, an 
option to view their game statistics, an option to reset their game statistics and an option to exit
the program entirely. Guess The Number is where users will have 6 attempts to 
select a randomly generated number between 1 and 100, in a hot or cold format the game tells
the user if their guessed number is higher or lower than the correct number. The game higher or lower 
gives the user a chance to guess wether the next randomly generated number will be higher or lower than
the previous, if they do so correctly 5 times in a row they win. The last game is Collect Pairs where
the user will roll a pair of dice 100 times, they win if they roll a pair of each side of the dice (1-6).
They can view their stats after playing multiple games and will display their total number
of wins, losses and their win percentage. Users can select to reset their statistics if they want to start 
fresh.
Assumptions: User will input integer values when selecting from the menu. User will enter integer values
when playing games this is necessary. User will enter char values when necessary. User will read rules before
playing and understand game objectives.
*/


#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int menu();
bool guessNumber(), highLow(), collectPairs();
void printRules(), viewStats(int wins, int losses);

int main()
{
    srand(time(0));
    int userChoice, wins = 0, losses = 0;
    //Create do/while loop that terminates only when user selects exit from menu
    do
    {
        userChoice = menu();
        if(userChoice == 1)
        {
            if(guessNumber() == true)
                wins++;
            else 
                losses++;
        }
        if(userChoice == 2)
        {
            if(highLow() == true)
                wins++;
            else
                losses++;
        }
        if(userChoice == 3)
        {
            if(collectPairs() == true)
                wins++;
            else
                losses++;
        }
        if(userChoice == 4)
            viewStats(wins, losses);
        if(userChoice == 5)
        {
            wins = 0;
            losses = 0;
            cout << "\nStatistics Reset!";
        }
        if(userChoice == 6)
            printRules();
        if(userChoice == 0)
        {
            viewStats(wins, losses);
            cout << "\n\nThanks for playing!";
        }
    }while(userChoice != 0);
    
    return 0;
}

bool collectPairs()
{
    int dice1, dice2;
    char pairOf1s = 'n', pairOf2s = 'n', pairOf3s = 'n', pairOf4s = 'n', pairOf5s = 'n', pairOf6s = 'n';

    cout << "\nRolling a pair of dice 100 times for pairs!";
    //Creates for loop that iterates 100 times, simulating 100 dice rolls.
    for(int rolls = 0; rolls < 101; rolls++)
    {
        //Generate random roll for each dice, each iteration through loop.
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        //Check if roll is a pair
        if(dice1 == dice2)
        {
            //If roll is a pair, check which pair of numbers it is and record that a pair of that number was found.
            if(dice1 == 1 && pairOf1s == 'n')
            {
                pairOf1s = 'y';
                cout << "\nPAIR OF ONES found";
            }
            else if(dice1 == 2 && pairOf2s == 'n')
            {
                pairOf2s = 'y';
                cout << "\nPAIR OF TWOS found";
            }
            else if(dice1 == 3 && pairOf3s == 'n')
            {
                pairOf3s = 'y';
                cout << "\nPAIR OF THREES found";
            }
            else if(dice1 == 4 && pairOf4s == 'n')
            {
                pairOf4s = 'y';
                cout << "\nPAIR OF FOURS found";
            }
            else if(dice1 == 5 && pairOf5s == 'n')
            {
                pairOf5s = 'y';
                cout << "\nPAIR OF FIVES found";
            }
            else if(dice1 == 6 && pairOf6s == 'n')
            {
                pairOf6s = 'y';
                cout << "\nPAIR OF SIXES found";
            }
        }

    }
    //Check if user won by checking if each pair set was found. If yes, notify user of win and return true to main
    //If all pairs not find, notify user of loss and return false to main.
    if(pairOf1s == 'y' && pairOf2s == 'y' && pairOf3s == 'y' && pairOf4s == 'y' && pairOf5s == 'y' && pairOf6s == 'y')
    {
        cout << "\nYou WIN!";
        return true;
    }
    else
    {
        cout << "\nSorry, you lose.";
        return false;  
    }
}

bool guessNumber()
{
   int correctNum = rand() % 100 + 1;
   int attempt1, attempt2, attempt3, attempt4, attempt5, attempt6;
   char win = 'n';


   /*Game generates a random integer (1-100). Game prompts user to guess what the random number is. Upon each attempt,
   the game checks user attempt against the correctNum and notifies user if their guess was too big, too small, or the correct guess.
   If user input is too big or too small, they are given another attempt up to 6 attempts. If user fails to guess the number in 6 
   attempts, they lose and false is returned to main. If the user does correctly guess the number in 6 tries or less, the game
   imediately terminates upon correct entry, notifies user they have won and returns true back to main.*/
   cout << "\n Guess the Number, 1 --> 100!";

        cout << "\nAttempt 1/6 : ";
        cin >> attempt1;
        if(attempt1 > correctNum)
            cout << "TOO BIG.";
        else if(attempt1 < correctNum)
            cout << "TOO SMALL.";
        else if(attempt1 == correctNum)
        {
            cout << "You WIN!";
            win = 'y';
            return true;
        }

        cout << "\nAttempt 2/6 : ";
        cin >> attempt2;
        if(attempt2 > correctNum)
            cout << "TOO BIG.";
        if(attempt2 < correctNum)
            cout << "TOO SMALL.";
        else if(attempt2 == correctNum)
        {
            cout << "You WIN!";
            win = 'y';
            return true;
        }

        cout << "\nAttempt 3/6 : ";
        cin >> attempt3;
        if(attempt3 > correctNum)
            cout << "TOO BIG.";
        if(attempt3 < correctNum)
            cout << "TOO SMALL.";
        else if(attempt3 == correctNum)
        {
            cout << "You WIN!";
            win = 'y';
            return true;
        }

        cout << "\nAttempt 4/6 : ";
        cin >> attempt4;
        if(attempt4 > correctNum)
            cout << "TOO BIG.";
        if(attempt4 < correctNum)
            cout << "TOO SMALL.";
        else if(attempt4 == correctNum)
        {
            cout << "You WIN!";
            win = 'y';
            return true;
        }

        cout << "\nAttempt 5/6 : ";
        cin >> attempt5;
        if(attempt5 > correctNum)
            cout << "TOO BIG.";
        if(attempt5 < correctNum)
            cout << "TOO SMALL.";
        else if(attempt5 == correctNum)
        {
            cout << "You WIN!";
            win = 'y';
            return true;
        }

        cout << "\nAttempt 6/6 : ";
        cin >> attempt6;
        if(attempt6 > correctNum)
            cout << "TOO BIG.";
        if(attempt6 < correctNum)
            cout << "TOO SMALL.";
        else if(attempt6 == correctNum)
        {
            cout << "You WIN!";
            win = 'y';
            return true;
        }
    
    if(win == 'n')
        cout << "\nSorry, you lose. The number was " << correctNum;
        return false;
}

bool highLow()
{
    int round = 1, currentNum = rand() % 1000 + 1, nextNum;
    char highOrLow;

    cout << "\nHigh or Low! Stay alive for 5 rounds to win! (Numbers range from 1 to 1,000)";
    /*for loop that iterates through each round of game. Game initializes random number (1-1000) and stores it in int currentNum.
    Game then prompts user to guess if the next randomly generated number will be higher or lower than the current one. Game checks
    if users input (H or L) is correct dependent on currentNum against the random integer (1-1000) stored in nextNum. If correct the
    game notifies user and the for loop iterates to the next round. If incorrect the game notifies user and the game terminates, returning
    false value back to main. If user completes all 5 rounds correctly, the game notifies user and returns true back to main.*/
    for(round; round < 6; round++)
    {
        cout << "\nRound " << round << " of 5. The number is " << currentNum;
        
        nextNum = rand() % 1000 + 1;

        cout << "\n\t... is the next number [H]igher or [L]ower?: ";
        cin >> highOrLow;
        while(highOrLow != 'H' && highOrLow != 'L')
        {
            cout << "Enter H or L: ";
            cin >> highOrLow;
        }

        cout << "The next number is: " << nextNum;
        //check if users guess of high or low is correct
        if ((highOrLow == 'H' && nextNum < currentNum) || (highOrLow == 'L' && nextNum > currentNum))
        {
            cout << "\nSorry, you lose.";
            return false;
        }
        else
            cout << "\nCorrect!";
        //replace old current number with new current number for next round
        currentNum = nextNum;    
    }    

    cout << "\nYou WIN!";
    return true;
}

void viewStats(int wins, int losses)
{
    //Calculate users win percentage
    double totalWinPercentage = (static_cast<double>(wins) / (static_cast<double>(wins + losses))) * 100.0;

    if((wins + losses) == 0)
        totalWinPercentage = 0.0;

    //Display user stats
    cout << "\nSTATISTICS:";
    cout << "\n-------------------------";
    cout << "\nWins: " << wins << "\t\tLosses: " << losses;
    cout << fixed << showpoint << setprecision(1);
    cout << "\nTotal Win Percent: " << totalWinPercentage << "%";
}

int menu()
{
    int menuChoice;

    cout << "\n\nGAME MENU:";
    cout << "\n-------------------------";
    cout << "\n1: PLAY Guess the Number";
    cout << "\n2: PLAY High Low";
    cout << "\n3: PLAY Collect Pairs";
    cout << "\n4: VIEW Statistics";
    cout << "\n5: RESET Statistics";
    cout << "\n6: RULES";
    cout << "\n0: QUIT";
    cout << "\n-------------------------";
    cout << "\n>";
    cin >> menuChoice;
    //Error handle invalid menu inputs
    while(menuChoice < 0 || menuChoice > 6)
    {
        cout << "Enter an item on the Menu: ";
        cin >> menuChoice;
    }

    return menuChoice;
}

/*Function definition for PRINTRULES
this function prints the rules of all of the games available to the user in this program
that is all this function is responsible for. DO NOT CHANGE this function.*/
void printRules()
{
    cout << "\nRULES:\n\nGuess the Number Game:\nYou'll only get 6 tries to guess a number between 1 and 100!";
    cout << "\nGuess Wisely!\n\nHigh/Low Game:\nMake it through 5 rounds of guessing whether the next random number\n";
    cout << "between 1 and 1,000 is higher or lower than the previous, and you win!\n\n";
    cout << "Collect the Pairs Game:\nRoll two dice 100 times. If in the 100 times you roll a pair\n";
    cout << "of each type (1's, 2's, 3's, 4's, 5's, 6's) at least once, then YOU WIN!\n\n";
    return;
}
