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