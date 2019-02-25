//Author: Ahmed Al Ali, Naser Al Khateri, Majed Al Mazrouei
#include "manhunt.hpp"






BoardType::BoardType(){
	
	int i, j;
	string **boardArr = nullptr;
	int sizeMax = 20;
	int sizeMin = 5;

    // asks for user input on board size
	cout << "Please enter the length of the board (5 - 20): ";
	cin >> size;
	// While given int is out of bounds, prompt again
	while (size < sizeMin || size > sizeMax){
			cout << "Please enter a value between 8 and 16 inclusive: ";
			cin >> size;
	}


	//Initializes dynamic array for the board
	boardArr = new string * [size];
	for (i = 0; i < size; i++) {
		boardArr[i] = new string [size];
		// Set values
		for (j = 0; j < size; j++){
			boardArr[i][j] = "-";
		}
	}
  

	// Initialize to player 1, and start of game
	emptySlot = "-";
	size = size;
	array = boardArr;
	isFinished = false;
	
	
	
	
	
}




void BoardType::printBoard(){
	cout << "      ";
	for (int i = 0; i < size; i++)
	{
       cout << i << "  ";
    }

	cout << "\n";

	for (int i = 0; i < size; i++)
    {
		cout << i << "     ";
		for (int j = 0; j < size; j++)
	{
		cout << array[i][j] << "  ";
	}
		cout << "\n";
    }
  cout << "\n";
	
	
	
	
	
	
}

void BoardType::changeBoard(){
	
	
	
	
	
	
	
}

void BoardType::checkWin(){
	
	
	
	
	
	
	
}

bool BoardType::getIsFinished(){
	
	
	
	return isFinished;
	
	
	
}

BoardType::~BoardType(){	
	for (int i = 0; i < size; i++)
		delete [] array[i];
	delete [] array;
}
