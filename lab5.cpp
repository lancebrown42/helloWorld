//*************************************************
//
// Title: Dice Game
// Author: Lance Brown
// CS1021-001 February 10, 2014
// Lab 05
//
// *************************************************
//
// Description: The program is a dice game, where the user has a starting balance of $100.
//     The user is asked for a wager, and then for a guess for a number. The program then
//     "rolls" up to 3 times, finding a random number between 1 and 6, and if one of the
//     three matches the users guess, the user wins, and the value of their wager is added
//     to their account. If none of the three match the user's guess, they lsoe and the
//     wager is deducted from the account. The game exits when the user enters 0 wager
//     or runs out of money in the account.
//
// Input: User provided integer wager, user provided integer guess
//
// Output: the value of each roll, the win/loss result, and the account balance
//
// Procedure: The program initializes the users account to $100, displays it, and asks for
//     a wager. It checks to ensure the wager is neither below zero or greater than the
//     balance. If the input is invalid, an error is displayed and the user is prompted
//     again. If the wager is 0, the program displays remaining balance and exits. The
//     user is then prompted for their guess. The input is verified between 1 and 6, 
//     an invalid input prompting an error message, and fed to the game function, 
//     playOneGame. The game function generates a random int between 1 and 6 and checks
//     the user guess against it. If it matches, it returns true. If it doesn't it rolls
//     again and checks again. If none of the 3 possible rolls equals the user guess, the
//     game function returns false. If the return was true, the program displays the winning
//     message and adds the user's wager to their account. If the return was false, the 
//     losing message is displayed and the wager is deducted from the account. As long as 
//     the account is in the black it loops. If the wager is 0 or the account hits 0, the 
//     game ends, the final account balance is displayed, and the program terminates.
//
// Constraints: Wager input must be greater than 0 (or == 0 to exit) and less than or equal
//     to the remaining account balance
//
// *****************Begin Program********************
//
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int rollDie() { //function to generate random int 1-6 (die roll)
  return rand() % 6 + 1;
}

bool playOneGame() { //game logic, calls rollDie and compares result to user input
  bool win = 0; //return variable, true if win, false if lose
  cout << endl << "Enter your point value (1 - 6): ";
  int point = 0;
  cin >> point;
  while (!(point <= 6 && point > 0)) { // check for invalid input
    cout << "Error: Enter your point value, must be between 1 and 6: ";
    cin >> point;
  }
  int attempt = 0;
  int roll = 0;
  while (point != roll && attempt < 3) {
    roll = rollDie();
    cout << "Roll #" << ++attempt << " is " << roll << endl;
  }
  if (point == roll){
    win = 1;
  }else {
    win = 0;}
  return win;
}

void display(int balance) {
  cout << "Account balance $" << balance << endl;
}

int main() {
  int balance = 100;//total account balance, goes up or down with win and loss
  int wager = -1;//player bet, initialiazed to -1 because 0 is exit condition
  int point = 0; //player guess
  int attempt = 0; //which roll it is per round
  int roll = 0; //value of roll
  int winCount = 0; //how many wins the player has
  bool win = 0; //if the game was won or lost

  srand (time(NULL)); //seed the random number
  while (balance > 0) {
    display(balance);
    cout << "Enter wager (0 to exit): ";
    cin >> wager;
    if (wager == 0) { //check for exit value
      break;
    }else if( wager > balance || wager < 0) { //check for invalid input
      while (wager > balance || wager < 0){
      cout << "Error: You must enter a wager between $1 and $" << balance << " (type 0 to exit): ";
      cin >> wager; //accept a new input
      }
    
      if (wager == 0) { //check for exit value
        break;
      }
    }
    //next block was moved to the logic function
   /* cout << endl << "Enter your point value (1-6): ";
    cin >> point;
    while (!(point < 6 && point > 0)) { //check for invalid input
      cout << "Error: Enter your point value, must be between 1 and 6: ";
      cin >> point;
    }*/
    win = playOneGame(); //play the game, and return win or loss
                                          
    if (win){//winning condition
      cout << " ** You win! **" << endl;
      winCount++;
      balance += wager;
    }else {//losing condition
      cout << " ** You Lose **" << endl;
      balance -= wager;
    }
  }
  if (balance == 0) { //if bankrupt
    cout << "Game over, you are out of money!" << endl;
  }
//end result
  cout << "Your final account balance is $" << balance << endl;

}
