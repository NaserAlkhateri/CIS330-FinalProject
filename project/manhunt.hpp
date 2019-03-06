//Author: Ahmed Al Ali, Naser Al Khateri, Majed Al Mazrouei
//Header file for class BoardType

#ifndef MANHUNT_HPP_
#define MANHUNT_HPP_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Struct for board
class BoardType{
	public:
		//Initializes board
		BoardType();

		//This is where all the movement is supposed to happen.
		void changeBoard();
		
		//computer movements
		void computerMove();
		
		// This is a function that holds score and determines winner
		void checkWin(string winner);

		// Self explanatory, function to print the board.
		void printBoard();

		// This function changes between players after each round
		void changePlayer();

		// Returns boolean isFinished
		bool getIsFinished();

		//Cleans memory
		~BoardType();


	private:
		string **array;
		int size;
		int player;
		int playerX;
		int playerY;
		int botX;
		int botY;
		int bot;
		bool isFinished;
		string emptySlot;

};


#endif
