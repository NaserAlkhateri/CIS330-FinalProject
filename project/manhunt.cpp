//Author: Ahmed Al Ali, Naser Al Khateri, Majed Al Mazrouei
#include "manhunt.hpp"






BoardType::BoardType(){
	
	int i, j, x, y;
	string **boardArr = nullptr;
	int sizeMax = 20;
	int sizeMin = 5;
	
	// Used to move between user and computer turn
	int player = 1;
	int bot = 0;
	
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
	
	cout << "Investigator coordinates (x y): " << endl;
	cin >> x >> y;
	while ((x > size || x < 0)||(y > size || y < 0)){
		cout << "Invalid input!\nInvestigator coordinates (x y): " << endl;
	cin >> x >> y;
	}
	playerX = x;
	playerY = y;
	array[playerX][playerY] = '*';
	botX = rand() % size;
	botY = rand() % size;
	cout<<"DEBUG: bot x,y "<< botX <<" "<< botY <<endl;
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
	int userInput = 0;
	
	//menu options for the user
	while(userInput != 6){
	cout << 
	"Where would you like to search?\n1. North\n2. East\n3. South\n4. West\n5. See Map\n6. Exit\nEnter 1-6:" <<endl;
	cin >> userInput;
		//move in the direction given after checking if its valid.
		if(userInput == 1 && playerX != 0){
			
			cout<<"DEBUG: North"<<endl;
			array[playerX][playerY] = '-';
			playerX -= 1;
			array[playerX][playerY] = '*';
			printBoard();
		}
		else if(userInput == 2 && playerY != (size-1)){
			cout<<"DEBUG: East"<<endl;
			array[playerX][playerY] = '-';
			playerY += 1;
			array[playerX][playerY] = '*';
			printBoard();
		}
		else if(userInput == 3 && playerX != (size-1)){
			cout<<"DEBUG: South"<<endl;
			array[playerX][playerY] = '-';
			playerX += 1;
			array[playerX][playerY] = '*';
			printBoard();			
		}
		else if(userInput == 4 && playerY != 0){
			cout<<"DEBUG: West"<<endl;
			array[playerX][playerY] = '-';
			playerY -= 1;
			array[playerX][playerY] = '*';
			printBoard();
		}
		else if(userInput == 5){
			printBoard();
		}
		else{
			cout << "Movement is not valid" << endl;
			printBoard();
		}
		
	}
	
	cout << "exited" << endl;
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
