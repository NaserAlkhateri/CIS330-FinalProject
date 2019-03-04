//Author: Ahmed Al Ali
//Main file.

#include <iostream>
#include <string>
#include "manhunt.hpp"

int main ()
{

  BoardType board;
  //while (board.getIsFinished() == false){}
  board.printBoard();  
	board.changeBoard();
  return 0;
 
}