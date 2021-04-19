// SnakeGame - Orig from the Web
// Original code by N. Vitanovic
// Modified Snake Game - Aryaan Athwaal
// 2/1/21
// see his YouTube video here: https://bit.ly/29WZ5Ml
//changelog:
// 2/1/21 
//        - renamed many routines
//        - added the showflow capability
//        - did not change the logic anywhere
//        - cleared and fixed up the white space 
// 2/3/21 
//        - Created void statements to help clear out the Logic Section
//        - Created a restart option for the user to play again
//        - Changed and tried to clean up the logic and draw code
//        - changed up most of the i and the j terms to terms that match its job
//        - Added a restart option
//        - Made the code work to caps sensivity
//        - Made when the snake hits the wall its game over
//        - I added the 5 fruits but i failed to make them work 
//        - My code did used to work but now for some reason it is going straight to game over
//  note section: 
//      fix the duplicate code in Draw (the wall drawing)
//      fix the logic routine, make it less complicated -
//      Make caps A,W,S,D,X have a value too or just say make CapsOn off
//      If snake hits the wall does it wrap around or game over
//      Create a help screen that gives a listing of the rules 

#include <iostream>
#include <conio.h>                 //for cout and cin
#include <windows.h>               //to use the _kbhit and _getch

using namespace std;

bool gameOver;                     //tells if the game is over or not
const int width = 20;              //width of the board
const int height = 20;             //height of the board
int x, y, score;                  //x and y coordinate of snake head, and stores the score of the player's points
int fruitX[5];                    //x coordinates of the fruit
int fruitY[5];                     //y coordinates of the fruit    
int tailX[100], tailY[100];       //to store the x and y coordinate of the snake
int LengthOfTail;                 // to give the length of the tail
string Restart;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN, PAUSE };
eDirecton dir;
const bool doShowFlowDebugging = false;

void showflow(string msg) {       //creating the showflow message
    if (doShowFlowDebugging) {
        cout << "--> " << msg << endl;
        Sleep(100);               //slows down the speed of the snake game
    }
}

void Setup() {
    showflow("Entered Setup");
  
    system("COLOR 17");
    gameOver = false;
    dir = STOP;                    //it stops the snake from moving when the game starts
    x = width / 2;                 //Places the snake in the middle of the board
    y = height / 2;          
    for (int FruitCoordinates = 0; FruitCoordinates < 5; FruitCoordinates++) {
        fruitX[FruitCoordinates] = rand() % width;       //decides a random placement of the fruit's x coordinates
        fruitY[FruitCoordinates] = rand() % height;      //decides a random placement of the fruit's y coordinates
    }
    score = 0;                      //sets the score to 0
    LengthOfTail = 0;
} //Set up
   
void DrawTopAndBottomRow() {
    for (int wall1 = 0; wall1 < width + 2; wall1++) // drawing the top wall
        cout << "#";                    // the border material
    cout << endl;
}
                                       // Draws the game board
void DrawTheBoard() {
   showflow("Entered DrawTheBoard\n");

   cout << "Welcome to the Snake Game!! \nUse the keys 'W', 'A', 'S', and 'D' keys to move around the snake. \nTo grow your snake, eat the Fruits.\n To pause the game press 'P'. \n Don't touch the wall or else... Enjoy!!" << endl;
   system("cls");                      //clears the screen
   
   DrawTopAndBottomRow(); 

    for (int column = 0; column < height; column++){
    for (int row = 0; row < width; row++)     {
       if (row == 0)
          cout << "#";      
       if (column == y && row == x)
          cout << "O";                              //checking for the snake position 
       
       else if (column == fruitY[0] && row == fruitX[0])   //checking for the fruit #1 position 
           cout << "F";  
       else if (column == fruitY[1] && row == fruitX[1])   //checking for the fruit #2 position 
           cout << "F";   
       else if (column == fruitY[2] && row == fruitX[2])   //checking for the fruit #3 position 
           cout << "F";   
       else if (column == fruitY[3] && row == fruitX[3])   //checking for the fruit #4 position 
           cout << "F";   
       else if (column == fruitY[4] && row == fruitX[4])   //checking for the fruit #5 position 
           cout << "F";  

       else {
           bool print = false;
           for (int BodyOfSnake = 0; BodyOfSnake < LengthOfTail; BodyOfSnake++) {
               if (tailX[BodyOfSnake] == row && tailY[BodyOfSnake] == column) {
                   cout << "o";
                   print = true;
               }
           }
           if (!print)
               cout << " ";
       }
       
       if (row == width - 1)               // drawing the bottom wall
                cout << "#";
        }
        cout << endl;
    }

    for (int wall = 0; wall < width + 2; wall++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}               //End Function = Draw The Board
 
void InputFromUser() //Check user input
{
    showflow("Entered InputFromUser\n");
    if (_kbhit())    {
      switch (_getch())   {             //two cases for each letter for case-insensitive. 

      case 'a': 
      case'A':
            dir = LEFT;
            break;
        case 'd':
        case 'D':
            dir = RIGHT;
            break;
        case 'w':
        case 'W':
            dir = UP;
            break;
        case 's':
        case 'S':
            dir = DOWN;
            break;
        case 'x':
        case 'X':
            gameOver = true;
            break;
        case 'p':
        case 'P':
            while (true)
            {
                if (_getch())
                    break;
            }
        }
    }
}               //End Function  = Input

void checkIfHitTail() {
    showflow("checkIfHitTail");
  //check if I hit my own tail
    for (int i = 0; i < LengthOfTail; i++)
        if (tailX[i] == x && tailY[i] == y)
          cout << "You have hit your own tail. GAME OVER" << endl;
            gameOver = true;
}

void checkIfHitWall() {
    showflow("checkIfHitWall");
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;
    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1;
}

void checkIfFruitEaten() {
    showflow("checkIfFruitEaten");
    //check if eating fruit
    for(int FruitCoordinates = 0; FruitCoordinates < 5; FruitCoordinates++)
    if (x == fruitX[FruitCoordinates] && y == fruitY[FruitCoordinates]) {
        showflow("checking if I've eaten any fruits");
        score += 10;
        fruitX[FruitCoordinates] = rand() % width;
        fruitY[FruitCoordinates] = rand() % height;
        LengthOfTail++;
    }
}

//Moves the snake, check if hit tail or wall, check for fruit
void LogicBehindTheGame(){ //figures out what to do
    showflow("Entered LogicBehindTheGame\n");

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int MovementOfTail= 1; MovementOfTail < LengthOfTail; MovementOfTail++)
    {
        prev2X = tailX[MovementOfTail];
        prev2Y = tailY[MovementOfTail];
        tailX[MovementOfTail] = prevX;
        tailY[MovementOfTail] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir){
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    checkIfHitWall();

    checkIfHitTail();

    checkIfFruitEaten();

} // End Function = Logic 

int main()
{ 
    Setup();
    while (!gameOver) {
        DrawTheBoard(); //draws the board
        InputFromUser(); //Ask what the user wants to do and recieves input
        LogicBehindTheGame(); //Executes what the user wants to do
        Sleep(10); //slows down the code for the ease of the user

        if (gameOver) {
            cout << "Would you like to play again? Y or N (Y = Yes, N = No). Press enter when done." << endl;
            cin >> Restart;
            if ((Restart == "Y") || (Restart == "y")) {
                LengthOfTail =0;
                main();
            }
        } 
    } 
            return 0;
 }//Main function ending

