/* Donna Ridgeway
CIS215L - Term Project*/

#include <stdio.h>
#include <stdlib.h>

//function to create intro screen
void introScreen ();

void main()
{
  	//declare variables
  	int row=0, column=0, player=0, play=0, line=0, winner=0, counter=0;
  	char gameBoard[3][3]={
                       {'1','2','3'},
                       {'4','5','6'},
                       {'7','8','9'}
                    };
   
	//function is called for intro screen to let user press 1 to play game or 2 for help screen
	introScreen();
    system ("cls");
  
   	//allows players to play for 9 times or until there is a winner
	for(counter = 0; counter<9 && winner==0; counter++)
   	{
   	
    system("cls");
    
    //game board is displayed showing 9 squares
	printf("\t**Tic-Tac-Toe**");
	printf("\n\n");
    printf("\t   %c | %c | %c\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
    printf("\t   ---------\n");
	printf("\t   %c | %c | %c\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("\t   ---------\n");
    printf("\t   %c | %c | %c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
      
    //player is selected
	player = counter%2 + 1;
 
    //players will choose a square to play their X or O
	do
    {
    	if (player ==1){
    		printf("\nPlayer %d, Enter square number "
       		"where you want your %c: ", player,'X');
		}
		else {
			printf("\nPlayer %d, Enter the square number "
       		"where you want your %c: ", player,'O');
		}

        scanf("%d", &play);
		
		//converts the square selected to zero based to find out where to place the X or O on the game board
		play--;
		row = play/3;
        column = play%3;
        
      } while(play<0 || play>9 || gameBoard[row][column]>'9');

      //when user chooses square number, the number is replaced with an X or O
	  if (player == 1){
      	gameBoard[row][column] = 'X';
	  }
	  else {
	  	gameBoard[row][column] = 'O';
	  }

	//checks for winning line based on what square player chose  
      if((gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2]) ||
         (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0]))
        winner = player;
      else
      //checks the rows and columns for a winning line
        for(line = 0; line <= 2; line ++)
          if((gameBoard[line][0] == gameBoard[line][1] && gameBoard[line][0] == gameBoard[line][2])||
             (gameBoard[0][line] == gameBoard[1][line] && gameBoard[0][line] == gameBoard[2][line]))
            winner = player;
      
   	}
	//final board shows where all moves were made and winning line
	system("cls");
	printf("\t**Tic-Tac-Toe**");
	printf("\n\n");
    printf("\t   %c | %c | %c\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
    printf("\t   ---------\n");
	printf("\t   %c | %c | %c\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("\t   ---------\n");
    printf("\t   %c | %c | %c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);

   	//output shows if there is a winner or if the game is a draw
   	if(winner == 0)
      printf("\nThere is no winner. The game is a draw.\n");
   	else
      printf("\nYAY! Player %d, YOU ARE THE WINNER!\n", winner);
}

//function to show intro screen and allowing user to press 1 to play game or 2 to get help and displaying how to play game
void introScreen (int getHelp){
	printf("\n");	
	printf("             Welcome to Tic-Tac-Toe! \n\n");
	printf("Press '1 + Enter' to play game or 'any number + Enter' for help.  \n");
	scanf("%d", &getHelp);
	if (getHelp == 1){
		return;
	}
	else{
		printf("\n");
		system("cls");
	printf("\n");
	printf("             Welcome to Tic-Tac-Toe! \n\n");		
	printf("Goal: Tic-Tac-Toe is a game played between 2 players \n");
	printf("on a 3x3 grid and the goal is to get 3 in a row to win.\n\n");
	printf("Skills Required: Observation and Strategy\n\n");
		
	printf("How to play: Determine who will be player 1 and \n");
	printf("who will be player 2. As a player, you are letter X or letter O. \n");
	printf("X always goes first.\n\n");
	printf("Each player takes a turn placing an X or O \n");
	printf("in a blank space trying to get three letters in a row \n");
	printf("in order to win. The object of the game is to block the \n");
	printf("other player by placing your letter in a blank space.\n");
	printf("When a player has three of their letters in a row, they win. \n");
	printf("If the board is filled and neither player has 3 in a row, \n");
	printf("the game is a draw. \n\n");
	
	printf("References:\n");
	printf("http://boardgames.about.com/od/paperpencil/a/tic_tac_toe.htm\n");

printf("http://www.learnplaywin.net/tictactoe/how-to-play.htm\n\n\n");

	printf("Donna Ridgeway, CIS215L Term Project \n\n\n");
	printf("Press any key to play game.");
	}
	system ("pause>NUL");
	return;
}
