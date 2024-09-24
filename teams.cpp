/*Name: Jordan Forthman
Date: 7/28/24
Assignment: HW 8
Due Date: 7/30/24
About this project: Program prompts user for file containing team data. Program then offers user a menu of options that will
display information about teams including their records, playoff status, win/loss differentials, filter teams by number of wins
as well as sorting teams based on their win/loss records.
Assumptions: Program assumes files will be correctly formatted for data gathering.

All work below was performed by Jordan Forthman*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

struct teamInfo
{
    string teamName;
    int wins;
    int losses;
    bool playoffs;
    int winLossDifferential;
};
string menu();
void showRecords(teamInfo * teams, int numOfRecords);
void showXwins(teamInfo * teams, int numOfRecords);
void madePlayoffs(teamInfo * teams, int numOfRecords);
void wlDiff(teamInfo * teams, int numOfRecords);
void sort(teamInfo * teams, int numOfRecords);

int main()
{
    teamInfo * tiPtr;
    string userFilename, userMenuChoice;
    ifstream fileInputs;
    int numOfRecords;
    //error handling: loop until user inputs valid file name
    do
    {
        cout << "\nPlease enter the name of the input file.\nFilename: ";
        cin >> userFilename;

        fileInputs.open(userFilename);
        if(!fileInputs)
            cout << "\nThat is not a valid file. Try again!";
    
    }while(!fileInputs);

    fileInputs >> numOfRecords;
    //dynamic teams array allocating array size based on number of records present in file (initial int read)
    teamInfo * teams = new teamInfo[numOfRecords];
    tiPtr = teams;
    //read through file and input proper information into teamInfo array slots
    for(int i = 0; i < numOfRecords; i++)
    {
        fileInputs.ignore();
        getline(fileInputs, tiPtr[i].teamName, ',');
        fileInputs >> tiPtr[i].wins;
        fileInputs.ignore();
        fileInputs >> tiPtr[i].losses;
        fileInputs.ignore();
        fileInputs >> tiPtr[i].playoffs;
    }
    //loop menu until "exit"
    do    
    {
    userMenuChoice = menu();

    if(userMenuChoice == "record")
        showRecords(tiPtr, numOfRecords);
    if(userMenuChoice == "xwins")
        showXwins(tiPtr, numOfRecords);
    if(userMenuChoice == "playoffs")
        madePlayoffs(tiPtr, numOfRecords);
    if(userMenuChoice == "wldiff")
        wlDiff(tiPtr, numOfRecords);
    if(userMenuChoice == "sort")
        sort(tiPtr, numOfRecords);
    }while(userMenuChoice != "exit");
    //clear dynamically allocated space and close input stream
    fileInputs.close();
    delete [] teams;

    return 0;
}
//display menu and prompt user for input that will be returned back to main
string menu()
{
    const int numberOfChoices = 6;
    bool validChoice;
    string userMenuChoice;
    string validMenuOptions[numberOfChoices] = {"record", "xwins", "playoffs", "wldiff", "sort", "exit"};
    
    do
    {    
    cout << "\nrecord - Show W-L records"; 
    cout << "\nxwins - Show teams with at least x wins";
    cout << "\nplayoffs - Show teams that made the playoffs"; 
    cout << "\nwldiff - Show teams win/loss differentials";
    cout << "\nsort - Sort teams by Win/Loss differential";
    cout << "\nexit - Exit program";
    cout << "\nSelection: ";
    cin >> userMenuChoice;
    cout << endl;
    //error handling: check user input against valid menu options
    for(int i = 0; i < numberOfChoices; i++)
        if(validMenuOptions[i] == userMenuChoice)
            validChoice = true;
    
    if(!validChoice)
        cout << "\n\"" << userMenuChoice << "\" is not a supported command.\n";

    }while(validChoice == false);

    return userMenuChoice;
}
//display team records
void showRecords(teamInfo * teams, int numOfRecords)
{
    cout << "\nTeam W-L:" << endl;
    for(int i = 0; i < numOfRecords; i++)
        cout << teams[i].teamName << " " << teams[i].wins << "-" << teams[i].losses << endl;

}
//allow user to display teams based on if they have as many or more wins than their input value
void showXwins(teamInfo * teams, int numOfRecords)
{
    int userWinLimit;

    cout << "\nShow teams with at least how many wins? --> ";
    cin >> userWinLimit;

    for(int i = 0; i < numOfRecords; i++)
    {
        if(teams[i].wins >= userWinLimit)
            cout << endl << teams[i].teamName;
    }
    cout << endl;
}
//display teams that made the playoffs
void madePlayoffs(teamInfo * teams, int numOfRecords)
{
    bool firstTeam = true;

    cout << "Playoff teams:" << endl;

    for(int i = 0; i < numOfRecords; i++)
    {
        if(teams[i].playoffs)
        {    
            if(!firstTeam)
                cout << ", ";
            cout << teams[i].teamName;
            firstTeam = false;
        }
    }
    cout << endl;
}
//display teams win/loss record
void wlDiff(teamInfo * teams, int numOfRecords)
{   
    for(int i = 0; i < numOfRecords; i++)
    {
        int winLossDiff = teams[i].wins - teams[i].losses;
        if(winLossDiff > 0)
            cout << endl << teams[i].teamName << " +" << winLossDiff;
        else
            cout << endl << teams[i].teamName << " " << winLossDiff;
    }
    cout << endl;
}
//bubble sort teams
void sort(teamInfo * teams, int numOfRecords)
{
    for(int i = 0; i < numOfRecords - 1; ++i)
    {
        for(int k = 0; k < numOfRecords - i - 1; ++k)
        {
            int diff1 = teams[k].wins - teams[k].losses;
            int diff2 = teams[k + 1].wins - teams[k + 1].losses;

            if(diff1 < diff2)
            {
                //swap teams
                teamInfo temp = teams[k];
                teams[k] = teams[k + 1];
                teams[k + 1] = temp;
            }
        }
    }
    cout << "\nTeams have been sorted" << endl;
}

