//Author: Ahmed Al Ali, Naser Al Khateri, Majed Al Mazrouei
#include "manhunt.hpp"



BoardType::BoardType(){
	
  int i, j, x, y;
  string **boardArr = nullptr;
  int sizeMax = 20;
  int sizeMin = 5;
	size = 0;
  // Used to move between user and computer turn
  player = 1;
  bot = 0;
	
  // asks for user input on board size
  //cout << "Please enter the length of the board (5 - 20): ";
  //cin >> size;
  
  // While given int is out of bounds, prompt again
  while (size < sizeMin || size > sizeMax){
    cout << "Please enter the length of the board (5 - 20): ";
	cin >> size;
	/*
	if(!(cin >> size) || size < sizeMin || size > sizeMax){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		size = 0;
    //cin >> size;
	}*/
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
  userInput = 0;
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
  botY = rand() % size;
  //makes sure bot doesnt match the coordinates, p.s user wouldn't notice anyway since there will be a move.
  if (botX == playerX && botY == playerY){
		botX = rand() % size;
		botY = rand() % size;
  }
  array[botX][botY] = "C";
  cout<<"DEBUG: bot x,y "<< botX <<" "<< botY <<endl;
  cout << "\033[2J\033[1;1H"; // This is used to clear the console window
}


BoardType::BoardType(int x){
	
	loadBoard();
	//array[playerX][playerY] = 'P';
	cout << "LOADED: " <<playerX<<" "<<playerY<<" "<<botX<<" "<<botY<<" "<<size<<endl;
  int i, j;
  string **boardArr = nullptr;
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
  //printBoard();
  userInput = 0;
  array[playerX][playerY] = 'P';
	array[botX][botY] = "C";
  cout<<"DEBUG: bot x,y "<< botX <<" "<< botY <<endl;
	
}

void BoardType::printBoard(){
	
	printThreat();
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

// This function prints the threat bar.
void BoardType::printThreat(){
	int threatCount;
	
	int diffX = (playerX - botX);
	// This is to ensure absolute value.
	if (diffX < 0){
		diffX = diffX * (-1);
	}
	
	int diffY = (playerY - botY);
	// This is to ensure absolute value.
	if (diffY < 0){
		diffY = diffY * (-1);
	}
	
	// We check for the greater number, to ensure the
	// right possible area of the opponent.
	if (diffX > diffY){
		// as difference decreases, threat increases.
		// At the same time, the possible area becomes
		// smaller (in terms of strategy).
		if(diffX == 5){
			threatCount = 1;
		}
		else if(diffX == 4){
			threatCount = 2;
		}
		else if(diffX == 3){
			threatCount = 3;
		}
		else if(diffX == 2){
			threatCount = 4;
		}
		else if(diffX == 1){
			threatCount = 5;
		}
		else{
			threatCount = 0;
		}
	}
	
	// We check for the greater number, to ensure the
	// right possible area of the opponent.	
	else if (diffX <= diffY){
		// as difference decreases, threat increases.
		// At the same time, the possible area becomes
		// smaller (in terms of strategy).
		if(diffY == 5){
			threatCount = 1;
		}
		else if(diffY == 4){
			threatCount = 2;
		}
		else if(diffY == 3){
			threatCount = 3;
		}
		else if(diffY == 2){
			threatCount = 4;
		}
		else if(diffY == 1){
			threatCount = 5;
		}
		else{
			threatCount = 0;
		}
	}	
	
	//Printing the bars of threat detector
	//depending on threat count variable calculated above.
	cout << "Threat Count--> ";
	for (int i = 0; i < threatCount; i++){
		cout << "[]";
	}
	cout << endl;
	
	
}


void BoardType::changeBoard(){
	//userInput = 0;
	int count = 0;
	
	//menu options for the user
	while(userInput != 6){
		//when player makes 3 moves calls computerMove and reset counts
	  if(count == 3){
		  count = 0;
		  cout << "computer finished making 3 moves!" << endl;
		  computerMove();
		  cout << "\033[2J\033[1;1H"; // This is used to clear the console window
		  printBoard();
	  }
		//this if statement is needed after computer's move
	  if (userInput != 6){
	  cout << 
	    "Where would you like to search?\n1. North\n2. East\n3. South\n4. West\n5. See Map\n6. Exit\n7. Save Game\nEnter 1-7:" <<endl;
	  cin >> userInput;
	  }
	  //move in the direction given after checking if its valid.

	  /*
		this part will take user's choice, check if its valid
		then make the move on the board, it will check for win
		in each move.
	  */
	  if(userInput == 1 && playerX != 0){
	    
	    cout<<"DEBUG: North"<<endl;
	    array[playerX][playerY] = '-';
	    playerX -= 1;
	    array[playerX][playerY] = 'P';
		cout << "\033[2J\033[1;1H"; // This is used to clear the console window
	    printBoard();
		count++;
		checkWin("Player");
	  }
	  else if(userInput == 2 && playerY != (size-1)){
	    cout<<"DEBUG: East"<<endl;
	    array[playerX][playerY] = '-';
	    playerY += 1;
	    array[playerX][playerY] = 'P';
		cout << "\033[2J\033[1;1H"; // This is used to clear the console window
	    printBoard();
		count++;
		checkWin("Player");
	  }
	  else if(userInput == 3 && playerX != (size-1)){
	    cout<<"DEBUG: South"<<endl;
	    array[playerX][playerY] = '-';
	    playerX += 1;
	    array[playerX][playerY] = 'P';
		cout << "\033[2J\033[1;1H"; // This is used to clear the console window
	    printBoard();
		count++;
		checkWin("Player");
	  }
	  else if(userInput == 4 && playerY != 0){
	    cout<<"DEBUG: West"<<endl;
	    array[playerX][playerY] = '-';
	    playerY -= 1;
	    array[playerX][playerY] = 'P';
		cout << "\033[2J\033[1;1H"; // This is used to clear the console window
		cout << "\033[2J\033[1;1H"; // This is used to clear the console window
	    printBoard();
		count++;
		checkWin("Player");
	  }
	  else if(userInput == 5){
		cout << "\033[2J\033[1;1H"; // This is used to clear the console window
	    printBoard();
	  }else if(userInput == 7){
		  saveBoard();
		  
	  }else if(userInput == 6){
		  //needed when returns from computer move.
		  cout << "broke loop" << endl;
		  break;
	  }
	  else{
	    cout << "Movement is not valid" << endl;
		cout << "\033[2J\033[1;1H"; // This is used to clear the console window
	    printBoard();
	  }
	  
	}
	
	cout << "Exited" << endl;
}

void BoardType::checkWin(string winner){
	//takes in the string of the current player for output
	
	cout << "checking move" << endl;
	if (array[playerX][playerY] == array[botX][botY]){
		cout << winner << " won!!!" << endl;
		userInput = 6; //force the loop to stop
		countBot = 3; //forces computer's move to stop
	}
  
  
}
void BoardType::computerMove(){
	//like the player options, computer will have a random move 1-4
	int choice = 0;
	srand(time(0));
	countBot = 0;
	/*
	srand(time(0));
	choice = (rand() % 4) + 1;
	
	cout << "choice generated for CP: " << choice << endl;
	*/
	//checks if move valid
	array[botX][botY] = '-';
	while(countBot < 3){
	  //srand(time(0));
	  choice = (rand() % 4) + 1;
	  cout << "choice generated for CP: " << choice << endl;
	if(choice == 1 && botX != 0){
	    
	    cout<<"CP DEBUG: North"<<endl;
	    //array[botX][botY] = '-';
	    botX -= 1;
	   
		countBot++;
		checkWin("Computer");
	  }
	  else if(choice == 2 && botY != (size-1)){
	    cout<<"CP DEBUG: East"<<endl;
	   
	    botY += 1;
	   
		countBot++;
		checkWin("Computer");
	  }
	  else if(choice == 3 && botX != (size-1)){
	    cout<<"CP DEBUG: South"<<endl;
	   
	    botX += 1;
	   
		countBot++;
		checkWin("Computer");
	  }
	  else if(choice == 4 && botY != 0){
	    cout<< "CP DEBUG: West" << endl;
	    
	    botY -= 1;
	   

		countBot++;
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
	//saves player's and bot's position and board size in a file
	// the file is just numbers
  string fileName;
  cout << "What would like to name your fie? (name.txt): ";
  cin >> fileName;
  ofstream myFile;
  myFile.open(fileName);
  //this makes it easier to load 
  myFile << playerX << " " << playerY << " " << botX << " " << botY << " " << size;
  cout << "Game saved successfully in file name: " << fileName << endl;
  myFile.close();
  userInput = 6;//forces loop to stop = game ends

}
void BoardType::loadBoard(){
  //load implementation
  int pX,pY,bX,bY,boardSize;
  string fileName;
  cout << "What is the file name that you would like to load?: ";
  cin >> fileName;
	ifstream myFile;
	myFile.open(fileName);
	  if (myFile.is_open()){
		  //saves the numbers from the file
      myFile >> pX >> pY >> bX >> bY >> boardSize;
    }else{ 
	//if file not found tell the user and exit
	cout << fileName <<" file not found, please check the file entered" << endl;
	exit(1);
	} 

	myFile.close();
	//array[playerX][playerY] = 'P';

	cout << "LOADED1: " <<pX<<" "<<pY<<" "<<bX<<" "<<bY<<" "<<boardSize<<endl;
	playerX = pX;
	playerY = pY;
	botX = bX;
	botY = bY;
	size = boardSize;
	
	//return (pX,pY,bX,bY,boardSize);
}
bool BoardType::getIsFinished(){
  
  
  
  return isFinished;
  
  
	
}

BoardType::~BoardType(){	
  for (int i = 0; i < size; i++)
    delete [] array[i];
  delete [] array;
}
