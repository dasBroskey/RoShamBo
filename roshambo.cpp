#include <iostream>
#include <Time.h>
#include <time.h>
 
// Constant variables
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';
const char EXIT = 'x';
 
using namespace std;
 
char getComputerOption() {

    srand(time(0));
    // Random number
    int num = rand() % 3 + 1;
 
    if(num==1) return 'r';
    if(num==2) return 'p';
    if(num==3) return 's';
}
 
char getUserOption() {
    char c;
    cout << "\nRock, Paper and Scissors Game!" << endl;
    cout << "Choose one of the following options"  << endl;
    cout << "-----------------------------------"  << endl;
    cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl << "(x) to end " << endl;
    cin >> c;
    
    while (c!='r' && c!='p' && c!='s' && c!='x' )
    {
        cout << "Please enter one of the following options only. " << endl;
        cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl;
        cin >> c;
    }
 
    return c;
}
 
void showSelectedOption(char option) {
    if (option == 'r') cout << "Rock" << endl;
    if (option == 'p') cout << "Paper" << endl;
    if (option == 's') cout << "Scissors" << endl;
}
 
int chooseWinner(char uChoice, char cChoice) {
    if (uChoice == ROCK && cChoice == PAPER) {
        cout << "Computer Wins! Paper wraps Rock."<< endl;
        return 2;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS) {
        cout << "Computer Wins! Scissors cut Paper."<< endl;
        return 2;
    }
    else if (uChoice == SCISSORS && cChoice == ROCK) {
        cout << "Computer Wins! Rock smashes Scissors."<< endl;
        return 2;
    }
    else if (uChoice == ROCK && cChoice == SCISSORS) {
        cout << "You Win! Paper wraps Rock."<< endl;
        return 1;
    }
    else if (uChoice == PAPER && cChoice == ROCK) {
        cout << "You Win! Paper wraps Rock."<< endl;
        return 1;
    }
    else if (uChoice == SCISSORS && cChoice == PAPER) {
        cout << "You Win! Scissors cut Paper."<< endl;
        return 1;
    }
    else if (uChoice == EXIT){
        cout << "Thank you for playing." << endl;
        return 0;
    }
    else {
        cout << "Tie. Play again win the Game." << endl;
        return 0;
    }
    
}
 
int main() {
    //User's choice
    char uChoice = 'a'; 
    //Compter's choice
    char cChoice;
    int cWins = 0;
    int pWins = 0;

    while (uChoice!= 'x')
    {
        uChoice = getUserOption();
        cout << "Your choice is: "<< endl;
        showSelectedOption(uChoice);
        
        cout << "Computer's choice is: "<< endl;
        cChoice = getComputerOption();
        showSelectedOption(cChoice);
        int winner = chooseWinner(uChoice, cChoice);
        if (winner == 1){
            pWins ++;
        }
        else if(winner == 2){
            cWins ++;
        }
        cout << "-----------------------------------"  << endl;
        cout << "Score: player: " << pWins << " computer: " << cWins << endl;
        cout << "-----------------------------------"  << endl;
    }
    return 0;
}