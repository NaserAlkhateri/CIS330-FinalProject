//Author: Ahmed Al Ali, Naser Al Khateri, Majed Al Mazrouei
//Main file.

#include <iostream>
#include <string>
#include "manhunt.hpp"
using namespace std;

int main ()
{
	cout << "\033[2J\033[1;1H"; // This is used to clear the console window
	int beginChoice = 0; 
	cout << "Welcome to Manhunt!" << endl;
	cout << "1.New Game\n2.Load Game" << endl;
	cin >> beginChoice;
	if (beginChoice == 1){
  BoardType board;
  //while (board.getIsFinished() == false){}
  board.printBoard();  
	board.changeBoard();
	}if (beginChoice == 2){
		BoardType b(1);
		b.printBoard();
		b.changeBoard();
	}
	
  return 0;
 
}