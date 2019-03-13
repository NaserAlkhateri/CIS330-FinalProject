//Author: Ahmed Al Ali, Naser Al Khateri, Majed Al Mazrouei
#include "manhunt.hpp"



BoardType::BoardType(){
	
  int i, j, x, y;
  string **boardArr = nullptr;
  int sizeMax = 20;
  int sizeMin = 5;
	
  // Used to move between user and computer turn
  player = 1;
  bot = 0;
	
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
  printBoard();
  cout << "Investigator starting coordinates (x y): " << endl;
  cin >> x >> y;
  while ((x > (size-1) || x < 0)||(y > (size-1) || y < 0)){
    cout << "Invalid input!\nInvestigator coordinates (x y): " << endl;
    cin >> x >> y;
  }
  playerX = x;
  playerY = y;
  array[playerX][playerY] = 'P';
  srand(time(0));//to get a different number each time  
  botX = rand() % size;
  //is this needed again??
  //srand(time(0));
  botY = rand() % size;
  array[botX][botY] = "C";
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
	userInput = 0;
	int count = 0;
	//menu options for the user
	while(userInput != 6){
	  if(count == 3){
		  count = 0;
		  cout << "computer finished making 3 moves!" << endl;
		  computerMove();
	  }
	  cout << 
	    "Where would you like to search?\n1. North\n2. East\n3. South\n4. West\n5. See Map\n6. Exit\nEnter 1-6:" <<endl;
	  cin >> userInput;
	  //move in the direction given after checking if its valid.

	  if(userInput == 1 && playerX != 0){
	    
	    cout<<"DEBUG: North"<<endl;
	    array[playerX][playerY] = '-';
	    playerX -= 1;
	    array[playerX][playerY] = 'P';
	    printBoard();
		count++;
		checkWin("Player");
	  }
	  else if(userInput == 2 && playerY != (size-1)){
	    cout<<"DEBUG: East"<<endl;
	    array[playerX][playerY] = '-';
	    playerY += 1;
	    array[playerX][playerY] = 'P';
	    printBoard();
		count++;
		checkWin("Player");
	  }
	  else if(userInput == 3 && playerX != (size-1)){
	    cout<<"DEBUG: South"<<endl;
	    array[playerX][playerY] = '-';
	    playerX += 1;
	    array[playerX][playerY] = 'P';
	    printBoard();
		count++;
		checkWin("Player");
	  }
	  else if(userInput == 4 && playerY != 0){
	    cout<<"DEBUG: West"<<endl;
	    array[playerX][playerY] = '-';
	    playerY -= 1;
	    array[playerX][playerY] = 'P';
	    printBoard();
		count++;
		checkWin("Player");
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

void BoardType::checkWin(string winner){
	cout << "checking move" << endl;
	if (array[playerX][playerY] == array[botX][botY]){
		cout << winner << " won!!!" << endl;
		userInput = 6; //force the loop to stop
	}
  
  
}
void BoardType::computerMove(){
	//like the player options, computer will have a random move 1-4
	int choice = 0;
	srand(time(0));
	int count = 0;
	/*
	srand(time(0));
	choice = (rand() % 4) + 1;
	
	cout << "choice generated for CP: " << choice << endl;
	*/
	//checks if move valid
	array[botX][botY] = '-';
	while(count < 3){
	  //srand(time(0));
	  choice = (rand() % 4) + 1;
	  cout << "choice generated for CP: " << choice << endl;
	if(choice == 1 && botX != 0){
	    
	    cout<<"CP DEBUG: North"<<endl;
	    //array[botX][botY] = '-';
	    botX -= 1;
	   
		count++;
		checkWin("Computer");
	  }
	  else if(choice == 2 && botY != (size-1)){
	    cout<<"CP DEBUG: East"<<endl;
	   
	    botY += 1;
	   
		count++;
		checkWin("Computer");
	  }
	  else if(choice == 3 && botX != (size-1)){
	    cout<<"CP DEBUG: South"<<endl;
	   
	    botX += 1;
	   
		count++;
		checkWin("Computer");
	  }
	  else if(choice == 4 && botY != 0){
	    cout<< "CP DEBUG: West" << endl;
	    
	    botY -= 1;
	   

		count++;
		checkWin("Computer");
	  }else{
	    //gives it a new random choice 
	    //because the one generated is invalid
	    srand(time(0));
	    choice = (rand() % 4) + 1;
		  
		  
	  }
	
	
	}
	array[botX][botY] = "C";
	cout << "CP DEBUG: coordinates" << botX << " " << botY << endl;
	
}

void BoardType::saveBoard(){

  string fileName;
  cout << "What would like to name your fie? (name.txt): ";
  cin >> fileName;
  ofstream myFile;
  myFile.open(fileName);
  myFile << playerX << playerY << botX << botY;
  cout << "Game saved successfully" << endl;
  myFile.close();
  userInput = 6;//forces loop to stop = game ends

}
bool BoardType::getIsFinished(){
  
  
  
  return isFinished;
  
  
	
}

BoardType::~BoardType(){	
  for (int i = 0; i < size; i++)
    delete [] array[i];
  delete [] array;
}
