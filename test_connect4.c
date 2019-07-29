/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */
#include "connect4.h"

/*
This program is designed to let you TEST the functions you have written in connect4.c.
You can test one function at a time, or you can play a complete game of Connect Four,
in which case you will need to have completed all of the functions.  If you want to test
just one of your functions, you should write the appropriate test code in the
MyTestFunction() function.  Initially, this function contains all of the test code from
the project handout.
*/
void MyTestFunction(void);
void PlayConnectFour(void);
int board[MAX_SIZE][MAX_SIZE];



/*
This function is where you can write your own test code, to test the functions that you
have written in the connect.c source file.  Currently, this function contains all of the
examples from the project handout document.  You can make any changes to this function
that you like.
*/
void MyTestFunction(void)
{
	// An example of code that you could use to test Task One.
	// You should write additional tests of your own
	printf("\nTESTING TASK ONE:\n");
	printf("=================\n");
	printf("   Prize = %d\n", SecondPlacePrize(200, 100, 200));
	printf("   Prize = %d\n", SecondPlacePrize(45, 600, 590));
	printf("   Prize = %d\n", SecondPlacePrize(50, 40, 30));
	printf("   Prize = %d\n", SecondPlacePrize(45, 40, 35));
	printf("   Prize = %d\n", SecondPlacePrize(9, 11, 10));
	// An example of code that you could use to test Task Two.
	// You should write additional tests of your own
	printf("\nTESTING TASK TWO:\n");
	printf("=================\n");
	int valuesA[10] = {1,2,1,2,1,1,1,1,2,1};
	int valuesB[15] = {1,2,1,2,1,1,1,2,2,1,1,4,4,4,4};
	int valuesC[15] = {5,6,7,8,8,8,8,8,8,8,8,8,8,8,8};
	int result;
	result = FourInARow(valuesA, 10);
	printf("   Result = %d\n", result);
	result = FourInARow(valuesB, 15);
	printf("   Result = %d\n", result);
	result = FourInARow(valuesC, 15);
	printf("   Result = %d\n", result);
	result = FourInARow(valuesC, 6);
	printf("   Result = %d\n", result);

	// An example of code that you could use to test Task Three.
	// You should write additional tests of your own
	printf("\nTESTING TASK THREE:\n");
	printf("===================\n");
	printf("   Decimal = %d\n", BinaryToDecimal(101));
	printf("   Decimal = %d\n", BinaryToDecimal(1));
	printf("   Decimal = %d\n", BinaryToDecimal(11111111));
	printf("   Decimal = %d\n", BinaryToDecimal(100000000));
	printf("   Decimal = %d\n", BinaryToDecimal(10101));
	printf("   Decimal = %d\n", BinaryToDecimal(110101));

	// An example of code that you could use to test Task Four.
	// You should write additional tests of your own
	printf("\nTESTING TASK FOUR:\n");
	printf("===================\n");
	double grpA[5]={4.3,2.1,6.7,5.0,1.2};
	double grpB[10]={4.3,2.1,6.7,5.0,1.2,9.9,7.0,3.0,6.6,6.5};
	double grpC[12] = { 6.1,1.1,2.3,3.9,4.7,5.6,0.0,10.5,8.8,9.0,7.2,11.6 };
	double medianAbilityA, medianAbilityB, medianAbilityC;
	medianAbilityA = MedianAbility(grpA, 5);
	medianAbilityB = MedianAbility(grpB, 10);
	medianAbilityC = MedianAbility(grpC, 12);
	printf("   Median ability Group A = %.2f\n", medianAbilityA);
	printf("   Median ability Group B = %.2f\n", medianAbilityB);
	printf("   Median ability Group B = %.2f\n", medianAbilityC);

	// An example of code that you could use to test Task Five.
	// You should write additional tests of your own
	printf("\nTESTING TASK FIVE:\n");
	printf("===================\n");
	char nameA[100] = "The       Champ";
	char nameB[100] = "     I    AM      THE     GREATEST    ";
	char nameC[100] = "Therearenospaceshereatall";
	RemoveSpaces(nameA);
	RemoveSpaces(nameB);
	RemoveSpaces(nameC);
	printf("   Name A = [%s]\n", nameA);
	printf("   Name B = [%s]\n", nameB);
	printf("   Name C = [%s]\n", nameC);

	// An example of code that you could use to test Task Six.
	// You should write additional tests of your own
	printf("\nTESTING TASK SIX:\n");
	printf("===================\n");
	int board6[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			board6[i][j] = -1;
		}
	}
	printf("   Board of size 5x5:\n");
	InitialiseBoard(board6, 5);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("   ");
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", board6[i][j]);
		}
		printf("\n");
	}
	printf("   Board of size 8x8:\n");
	InitialiseBoard(board6, 8);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("   ");
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", board6[i][j]);
		}
		printf("\n");
	}
	printf("   Board of size 10x10:\n");
	InitialiseBoard(board6, 10);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("   ");
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", board6[i][j]);
		}
		printf("\n");
	}
	printf("   Board of size 9x9:\n");
	InitialiseBoard(board6, 9);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("   ");
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", board6[i][j]);
		}
		printf("\n");
	}

	// An example of code that you could use to test Task Seven.
	// You should write additional tests of your own
	printf("\nTESTING TASK SEVEN:\n");
	printf("=====================\n");
	int board7[MAX_SIZE][MAX_SIZE];
	int rowPosition, colPosition;
	int size7 = 8;
	InitialiseBoard(board7, size7);
	AddMoveToBoard(board7, size7, 'N', 1, 1, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	AddMoveToBoard(board7, size7, 'E', 4, 2, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	AddMoveToBoard(board7, size7, 'S', 5, 1, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	AddMoveToBoard(board7, size7, 'W', 5, 2, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);

	for (int i = 0; i < size7; i++) {
		printf("   ");
		for (int j = 0; j < size7; j++) {
			printf("%d ", board7[i][j]);
		}
		printf("\n");
	}

	size7 = 10;
	InitialiseBoard(board7, size7);
	AddMoveToBoard(board7, size7, 'S', 6, 2, &rowPosition, &colPosition);
	
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	for (int i = 0; i < size7; i++) {
		printf("   ");
		for (int j = 0; j < size7; j++) {
			printf("%d ", board7[i][j]);
		}
		printf("\n");
	}

	// An example of code that you could use to test Task Eight.
	// You should write additional tests of your own
	printf("\nTESTING TASK EIGHT:\n");
	printf("=====================\n");
	int board8[MAX_SIZE][MAX_SIZE];
	int rowPos, colPos;
	int size8 = 5;
	int hasWon;
	InitialiseBoard(board8, size8);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 2 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 2, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	//AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'E', 4, 1, &rowPos, &colPos);
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);

	// New tester

	int board18[MAX_SIZE][MAX_SIZE];
	int size18 = 8;
	InitialiseBoard(board18, size18);
	AddMoveToBoard(board18, size18, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'W', 3, 1, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'E', 7, 2, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'E', 6, 2, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'E', 6, 2, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'E', 7, 2, &rowPos, &colPos);


	for (int i = 0; i < size18; i++) {
		printf("   ");
		for (int j = 0; j < size18; j++) {
			printf("%d ", board18[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 2 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board18, size18, 2, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	AddMoveToBoard(board18, size18, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board18, size18, 'N', 3, 1, &rowPos, &colPos);

	for (int i = 0; i < size18; i++) {
		printf("   ");
		for (int j = 0; j < size18; j++) {
			printf("%d ", board18[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board18, size18, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);

	// New tester 2

	int board19[MAX_SIZE][MAX_SIZE];
	int size19 = 10;
	InitialiseBoard(board19, size19);
	AddMoveToBoard(board19, size19, 'W', 0, 1, &rowPos, &colPos);

	printf("\n   %d %d\n", rowPos, colPos);

	for (int i = 0; i < size19; i++) {
		printf("   ");
		for (int j = 0; j < size19; j++) {
			printf("%d ", board19[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 2 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board19, size19, 2, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	AddMoveToBoard(board19, size19, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board19, size19, 'N', 3, 1, &rowPos, &colPos);

	for (int i = 0; i < size19; i++) {
		printf("   ");
		for (int j = 0; j < size19; j++) {
			printf("%d ", board19[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board19, size19, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);

	// An example of code that you could use to test Task Nine.
	// You should write additional tests of your own
	printf("\nTESTING TASK NINE:\n");
	printf("====================\n");
	int board9[MAX_SIZE][MAX_SIZE];
	int size9 = 4;
	char boardString[250];
	InitialiseBoard(board9, size9);
	GetDisplayBoardString(board9, size9, boardString);
	printf("   The length of the board string is: %d\n", strlen(boardString));
	printf("%s", boardString);
	size9 = 10;
	InitialiseBoard(board9, size9);
	GetDisplayBoardString(board9, size9, boardString);
	printf("   The length of the board string is: %d\n", strlen(boardString));
	printf("%s", boardString);
	size9 = 9;
	InitialiseBoard(board9, size9);
	GetDisplayBoardString(board9, size9, boardString);
	printf("   The length of the board string is: %d\n", strlen(boardString));
	printf("%s", boardString);

	// An example of code that you could use to test Task Ten.
	printf("\nTESTING TASK TEN:\n");
	printf("===================\n");
	printf("   You can test Task Ten by implementing the two Bot functions in connect.c.\n");
	printf("   If you then play a tournament, of many games, between the two bots, you \n");
	printf("   can see which one is performing the best.  This might help you to refine \n");
	printf("   the strategies that you are using. \n");

	char side = '0';
	int move = 0;
	//Board 1
	int board28[MAX_SIZE][MAX_SIZE];
	//int scoreBoard[MAX_SIZE][MAX_SIZE];
	int size28 = 8;
	InitialiseBoard(board28, size28);
	AddMoveToBoard(board28, size28, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'W', 3, 1, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'E', 7, 2, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'E', 6, 2, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'E', 6, 2, &rowPos, &colPos);
	//AddMoveToBoard(board28, size28, 'E', 7, 2, &rowPos, &colPos);
	AddMoveToBoard(board28, size28, 'N', 0, 1, &rowPos, &colPos);


	// Printing board 1
	for (int i = 0; i < size28; i++) {
		printf("   ");
		for (int j = 0; j < size28; j++) {
			printf("%d ", board28[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 2 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board28, size28, 2, rowPos, colPos);
	printf("   Result = %d\n", hasWon);

	//printf("\n   Number of adjacent pieces: %d\n\n", checkNumAdjacent(board28, size28, 2, 6, 0));
	//Printing scoreboard for board 1
	GetMoveBot1(board28, size28, 2, &side, &move);
	/*printf("\n   Scoreboard: \n");
	for (int i = 0; i < size28; i++) {
		printf("   ");
		for (int j = 0; j < size28; j++) {
			printf("%d ", scoreBoard[i][j]);
		}
		printf("\n");
	}*/
	//char Side = side;
	//char Move = move;
	printf("   Side is %c & move is %d \n", side, move);
	AddMoveToBoard(board28, size28, side, move, 2, &rowPos, &colPos);
	//printing board 1 with the new move
	for (int i = 0; i < size28; i++) {
		printf("   ");
		for (int j = 0; j < size28; j++) {
			printf("%d ", board28[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	// new board & test
	int board29[MAX_SIZE][MAX_SIZE];
	//int scoreBoard2[MAX_SIZE][MAX_SIZE] = { 0 };
	int size29 = 8;
	InitialiseBoard(board29, size29);
	AddMoveToBoard(board29, size29, 'W', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board29, size29, 'W', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board29, size29, 'W', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board29, size29, 'E', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board29, size29, 'E', 3, 1, &rowPos, &colPos);
	AddMoveToBoard(board29, size29, 'E', 3, 1, &rowPos, &colPos);

	//AddMoveToBoard(board29, size29, 'S', 2, 2, &rowPos, &colPos);
	//AddMoveToBoard(board29, size29, 'N', 0, 1, &rowPos, &colPos);
	//AddMoveToBoard(board29, size29, 'N', 3, 2, &rowPos, &colPos);

	//Printing board 2
	for (int i = 0; i < size29; i++) {
		printf("   ");
		for (int j = 0; j < size29; j++) {
			printf("%d ", board29[i][j]);
		}
		printf("\n");
	}
	//printf("\n   Number of adjacent pieces: %d\n", checkNumAdjacent(board29, size29, 2, 6, 0));
	// Board 2 scoreboard
	side = '0';
	move = '-1';
	GetMoveBot1(board29, size29, 2, &side, &move);
	/*printf("\n   Scoreboard: \n");
	for (int i = 0; i < size29; i++) {
		printf("   ");
		for (int j = 0; j < size29; j++) {
			printf("%d ", scoreBoard2[i][j]);
		}
		printf("\n");
	}*/
	//Side = side;
	//Move = move;
	printf("   Side is %c & move is %d \n", side, move);
	AddMoveToBoard(board29, size29, side, move, 2, &rowPos, &colPos);
	// Board 2 final position
	for (int i = 0; i < size29; i++) {
		printf("   ");
		for (int j = 0; j < size29; j++) {
			printf("%d ", board29[i][j]);
		}
		printf("\n");
	}
	printf("   \n Test complete\n");
}

/*********************************************************************************/
/*
The main function for the test program.  The user is asked whether they want to test their
functions or play a game of connect four.  Based on the user's input, the appropriate function
is called.
*/
int main(void)
{
	int input;
	printf("ENGGEN131 Project - Semester Two - 2018\n");
	printf("                                 _      __                 \n");
	printf("                                | |    / _|                \n");
	printf("  ___ ___  _ __  _ __   ___  ___| |_  | |_ ___  _   _ _ __ \n");
	printf(" / __/ _ \\| '_ \\| '_ \\ / _ \\/ __| __| |  _/ _ \\| | | | '__|\n");
	printf("| (_| (_) | | | | | | |  __/ (__| |_  | || (_) | |_| | |   \n");
	printf(" \\___\\___/|_| |_|_| |_|\\___|\\___|\\__| |_| \\___/ \\__,_|_|   \n");
	printf("\nWould you like to:\n\n");
	printf("  0 = Test individual functions in connect.c\n");
	printf("      [you should write your own test code for this in MyTestFunction()]\n");
	printf("  1 = Play Connect Four\n");
	printf("      [this will only work if you to have completed all of the functions)]\n");
	printf("\nPlease enter your choice [0 or 1]:  ");
	scanf("%d", &input);
	if (input == 0) {
		MyTestFunction();
	} else {
		PlayConnectFour();
	}

	return 0;
}

/*********************************************************************************/
/*
This function is called when a human player is asked to enter their move.  The character
(representing the side of the board) and the digit (representing the row/column) are
returned via the pointers *side and *move.
*/
void GetMoveHuman(char *side, int *move, int player)
{
	char a = ' ';
	char b = ' ';
	printf("Player %d: enter move [side/position]: ", player);
	while (!(a == 'N' || a == 'W' || a == 'E' || a == 'S')) {
		scanf("%c", &a);
	}
	while (!(b >= '0' && b <= '9')) {
		scanf("%c", &b);
	}
	*side = a;
	*move = (int)(b - '0');
}

/*********************************************************************************/
/*
This function plays one game of Connect Four.  The starting player (either 1 or 2) is provided
as input.  This function returns the player who won the game.
*/
int PlayOneGame(int startingPlayer, int size, int gameType)
{
	//int board[MAX_SIZE][MAX_SIZE];
	char displayBoardString[(MAX_SIZE+5)*(MAX_SIZE+5)];
	int player, gameOver, move, lastRow, lastCol;
	char side;

	player = startingPlayer;
	gameOver = 0;

	// Initialise the board, and display it if a human is involved in this game
	InitialiseBoard(board, size);
	if (gameType != 3) {
		GetDisplayBoardString(board, size, displayBoardString);
		printf("%s", displayBoardString);
	}

	// Play one move at a time, displaying the board if necessary, until the game is over
	while (!gameOver) {
		if (gameType == 1) {
			GetMoveHuman(&side, &move, player);
		} else if (gameType == 2) {
			if (player == 1) {
				GetMoveHuman(&side, &move, player);
			} else {
				GetMoveBot1(board, size, player, &side, &move);
			}
		} else {
			if (player == 1) {
				GetMoveBot1(board, size, player, &side, &move);
			} else {
				GetMoveBot2(board, size, player, &side, &move);
			}
		}
		AddMoveToBoard(board, size, side, move, player, &lastRow, &lastCol);
		gameOver = CheckGameOver(board, size, player, lastRow, lastCol);
		if (gameType != 3) {
			GetDisplayBoardString(board, size, displayBoardString);
			printf("%s", displayBoardString);
		}
		if (!gameOver) {
			player = 3 - player;
		}
	}
	return player;
}

/*********************************************************************************/
/*
This function plays Connect Four.  The user can choose the size of the board, who the
players will be (human or bot) and how many games will be played (if the bots are competing).
*/
void PlayConnectFour(void)
{
	int size, gameType, numberOfGames, result;
	int i, wins1, wins2, player;

	// Initialise the seed for the random number generator
	srand((unsigned int)time(NULL));

	// Prompt the user for the board size
	printf("\n\n==================");
	printf("\nEnter board size: ");
	scanf("%d", &size);

	// Get play options:
	printf("Options:\n");
	printf(" [1] = Human vs. Human\n");
	printf(" [2] = Human vs. Bot1\n");
	printf(" [3] = Bot1 vs. Bot2\n");
	printf("Choose game type: ");
	scanf("%d", &gameType);
	numberOfGames = 1;
	result = 0;
	// If two bots are playing a tournament, let the user choose how many games
	if (gameType == 3) {
		printf("Number of games: ");
		scanf("%d", &numberOfGames);
	}

	wins1 = 0;
	wins2 = 0;

	// Player 1 will always start the first game
	// If a tournament is played (between two bots), the starting player alternates
	player = 1;

	for (i = 0; i < numberOfGames; i++) {
		result = PlayOneGame(player, size, gameType);
		if (result == 1) {
			wins1++;
		} else {
			wins2++;
		}
		// Switch the starting player for the next game
		player = 3 - player;
	}

	// If a single game was played, show the result of the game, otherwise report the result of the tournament:
	if (numberOfGames == 1) {
		printf("\nGame over! Congratulations! Winner is Player %d\n\n", result);
		for (int k = 0; k < size; k++) {
			printf("   ");
			for (int j = 0; j < size; j++) {
				printf("%d ", board[k][j]);
			}
			printf("\n");
		}
	} else {
		printf("\nTournament over! Games played = %d\nPlayer 1 wins = %d / Player 2 wins = %d\n\n", numberOfGames, wins1, wins2);
	}
}
