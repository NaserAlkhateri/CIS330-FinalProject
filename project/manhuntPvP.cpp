//Author: Ahmed Al Ali, Naser Al Khateri, Majed Al Mazrouei
#include "manhuntPvP.hpp"


BoardType::BoardType(){
	
  int i, j, x, y;
  string **boardArr = nullptr;
  int sizeMax = 20;
  int sizeMin = 5;
	
  // Used to move between user and enemy turn
  player = 1;
  enemy = 0;
	
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

  cout << "Enemy starting coordinates (x y): " << endl;
  cin >> x >> y;
  while ((x > (size-1) || x < 0)||(y > (size-1) || y < 0)){
    cout << "Invalid input!\nInvestigator coordinates (x y): " << endl;
    cin >> x >> y;
  }
  enemyX = x;
  enemyY = y;
  array[enemyX][enemyY] = 'E';
}

BoardType::BoardType(int x){
	
	loadBoard();
	//array[playerX][playerY] = 'P';
	cout << "LOADED: " <<playerX<<" "<<playerY<<" "<<enemyX<<" "<<enemyY<<" "<<size<<endl;
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
  userInput = 0;
  isFinished = false;
  //printBoard();
  userInput = 0;
  array[playerX][playerY] = 'P';
	array[enemyX][enemyY] = "E";
	
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
	
	int diffX = (playerX - enemyX);
	// This is to ensure absolute value.
	if (diffX < 0){
		diffX = diffX * (-1);
	}
	
	int diffY = (playerY - enemyY);
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
		  cout << "Enemy Turn" << endl;
		  enemyMove();
	  }
		//this if statement is needed after enemy's move
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
	  }else if(userInput == 7){
		  saveBoard();
		  
	  }else if(userInput == 6){
		  //needed when returns from enemy move.
		  cout << "broke loop" << endl;
		  break;
	  }
	  else{
	    cout << "Movement is not valid" << endl;
	    printBoard();
	  }
	  
	}
	
	cout << "Exited" << endl;
}

void BoardType::checkWin(string winner){
	//takes in the string of the current player for output
	
	cout << "checking move" << endl;
	if (array[playerX][playerY] == array[enemyX][enemyY]){
		cout << winner << " won!!!" << endl;
		userInput = 6; //force the loop to stop
	}
  
}

void BoardType::enemyMove(){
	
	//userInput = 0;
	int count = 0;
	
	//menu options for the user
	while(userInput != 6){
		//when player makes 3 moves calls changeBoard and reset counts
	  if(count == 3){
		  count = 0;
		  cout << "Player Turn" << endl;
		  enemyMove();
	  }
		//this if statement is needed after player's move
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
	  if(userInput == 1 && enemyX != 0){
	    
	    cout<<"DEBUG: North"<<endl;
	    array[enemyX][enemyY] = '-';
	    enemyX -= 1;
	    array[enemyX][enemyY] = 'E';
	    printBoard();
		count++;
		checkWin("Enemy");
	  }
	  else if(userInput == 2 && enemyY != (size-1)){
	    cout<<"DEBUG: East"<<endl;
	    array[enemyX][enemyY] = '-';
	    enemyY += 1;
	    array[enemyX][enemyY] = 'E';
	    printBoard();
		count++;
		checkWin("Enemy");
	  }
	  else if(userInput == 3 && enemyX != (size-1)){
	    cout<<"DEBUG: South"<<endl;
	    array[enemyX][enemyY] = '-';
	    enemyX += 1;
	    array[enemyX][enemyY] = 'E';
	    printBoard();
		count++;
		checkWin("Enemy");
	  }
	  else if(userInput == 4 && enemyY != 0){
	    cout<<"DEBUG: West"<<endl;
	    array[enemyX][enemyY] = '-';
	    enemyY -= 1;
	    array[enemyX][enemyY] = 'E';
	    printBoard();
		count++;
		checkWin("Enemy");
	  }
	  else if(userInput == 5){
	    printBoard();
	  }else if(userInput == 7){
		  saveBoard();
		  
	  }else if(userInput == 6){
		  //needed when returns from enemy move.
		  cout << "broke loop" << endl;
		  break;
	  }
	  else{
	    cout << "Movement is not valid" << endl;
	    printBoard();
	  }
	  
	}
	
	cout << "Exited" << endl;
}

