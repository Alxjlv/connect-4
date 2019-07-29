/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"
#define MAX_ARRAY 1000

/*
Author: Alex Verkerk
UPI: aver551
ID #: 815997675
*/

int testBoard[MAX_SIZE][MAX_SIZE]; // Globally allocating the testBoard array to avoid memory issues
int my_power(int x, int y);
int shifter(char *word, int pos);
void initialiseTestBoard(int board[MAX_SIZE][MAX_SIZE], int size);



int SecondPlacePrize(int prize1, int prize2, int prize3)
{
	/* This function is meant to find the middle value of three values. I used an array containing the three values then sorted them
	 using the bubble sort algorithm from lab 11*/

	int i, j;
	int arr[3] = { 0 };
	// Written this way as opposed to initialising with the values in order to avoid a warning in developer command prompt.
	arr[0] = prize1;
	arr[1] = prize2;
	arr[2] = prize3; 

	for (i = 0; i < 3; i++) // Nested for loop to go through all 9 possibilities the three values could take
	{ 
		for (j = 0; j < 3 - 1; j++) 
		{
			if (arr[j] < arr[j + 1]) 
			{
				// Swaps the values if the value at j is less than the next position
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return arr[1]; // returns the middle value
}

int FourInARow(int values[], int length)
{
	/* This function checks if there are four values in a row using a series of if statements */

	int temp[MAX_ARRAY] = { -1 }; // This array is allocated with -1's
	

	for (int i = 0; i < length; i++) // And is then filled with the values up until the specified length
	{
		temp[i] = values[i];
	}

	for (int i = 0; i < length; i++)
	{
		// If statement to check if there are 4 values in a row and returning the first value when that is true
		if ((temp[i] == temp[i + 1]) && (temp[i] == temp[i + 2]) && (temp[i] == temp[i + 3])) return i;
	}

	return -1;
}

int BinaryToDecimal(int binary)
{
	/* This function converts a binary number to a decimal number by dividing the binary by 10 successively to find
	each digit of the binary number in order to apply 2 to the power of each successive digit to it */

	int quotient = binary; // allocates quotient as the binary number
	int j = 0, total = 0, count = 0;
	int array[MAX_ARRAY] = { 0 };
	
	// This divides the binary number until there is no quotient remaining
	while (quotient != 0)
	{
		quotient = quotient / 10;
		count++;
	} 

	array[count] = -1; // allocates the array at the final binary digit to -1
	quotient = binary; // realocates quotient

	for (int i = 0; i < count; i++)
	{
		/* This allocates the array to hold one digit of the binary number at each position,
		which allows me to address each digit individually. This is done with the least significant 
		bit at the start and most significant bit at the end. */
		array[i] = quotient % 10; 
		quotient /= 10;
	}

	while (array[j] != -1) 
	{
		/* This multiplies each digit of the array by 2^j where j is the position of the binary number. 
		This means that array[0] will be multiplied by 2^0 etc. */
		total += array[j] * my_power(2, j);
		j++;
	}

	return total;
}

double MedianAbility(double abilities[], int length)
{
	/* This function finds the median ability of a series of numbers by using the bubble sort algorithm 
	to order them, and then access the middle number */

	int i,j;
	double temp;

	for (i = 0; i < length; i++) 
	{
		for (j = 0; j < length - 1; j++) 
		{
			if (abilities[j] < abilities[j + 1]) // If statement to sort in descending order
			{ 
				temp = abilities[j];

				abilities[j] = abilities[j + 1];

				abilities[j + 1] = temp; // Swapping values
			}
		}
	}

	if (length % 2 == 0) // Checking if it is an even number of values
	{ 
		// then returning the average of the two middle values
		return (abilities[(length / 2) - 1] + abilities[(length / 2)]) / 2; 
	}
	else 
	{
		return abilities[(length / 2)]; // Returning the middle values
	}
}

void RemoveSpaces(char *name)
{
	/* This function removes the spaces in a character string by finding where two spaces are next to each other
	and then moving the entire string from that point down one position, essentially deleting the duplicate space. */

	int i=0;

	while(name[i] != '\0') // Cycling through to the end of the character string
	{ 
		if ((name[i] == name[i + 1]) && (name[i] == ' ')) 
		{ 
			// if there are two spaces in a row, then the shifter function is called to move them down by one
			i = shifter(name, i);
		}
		i++;
	}
}

void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	/* This function initialises the board by first filling it with zeroes, then placing the midpoints. For odd board sizes,
	the mid point will just be a single 3, and even will have four 3's */

	int mid1 = size / 2; // initialising the first midpoint location
	int mid2 = (size / 2) - 1; // initialising the second midpoint location (only for even boards)

	for (int i = 0; i < size; i++) // Filling board with zeroes
	{ 
		for (int j = 0; j < size; j++) 
		{
			board[i][j] = 0;
		}
	}

	if (size % 2 > 0) // For an odd sized board with a single midpoint
	{ 
		board[mid1][mid1] = 3;
	}
	else if (size % 2 == 0) // For an even sized board & all four midpoints
	{ 
		board[mid1][mid1] = 3;
		board[mid2][mid2] = 3;
		board[mid1][mid2] = 3;
		board[mid2][mid1] = 3;
	}
	
}

void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{
	/* This function will add a move to the board and see how far it goes until it reaches a position that is not a 0 (ie. filled with 
	other values) and returns the final position just prior to where the obstacle is */

	int i = 0, j = 0;
	int check = 1; // Setting a bool

	if ((side == 'N')||(side == 'S')) // For both horizontal movement locations
	{
		if (side == 'S') // If the side 'S' is selected, this sets the bool to 0
		{
			check = 0;
			i = size - 1; // And sets the starting row to the lowest playable row
		}

		while ((board[i][move] == 0) && (i < size) && (i > -1)) // Checking conditions for the move to proceed
		{
			if (check) // if 'N' then adds to i
			{
				i++;
			}
			else i--; // if 'S' then removes from i
		}

		if (check) // This if/else statement sets the position back one in order to get the last valid position
		{
			i--;
		}
		else i++;

		board[i][move] = player; // Setting the last position to the player number
		*lastRow = i;
		*lastCol = move; // Returning row & column indices
	}
	else if ((side == 'E')||(side == 'W')) // For both vertical movement locations
	{
		if (side == 'E') // If the side 'E' is selected, this sets the bool to 0
		{
			check = 0;
			j = size - 1; // And sets the starting column to the furthest playable column
		}

		while ((board[move][j] == 0) && (j < size) && (j > -1))  // Checking conditions for the move to proceed
		{
			if (check) // if 'W' then adds to j
			{
				j++;
			}
			else j--; // if 'E' then adds to j
		}

		if (check) // This if/else statement sets the position back one in order to get the last valid position
		{
			j--;
		}
		else j++;

		board[move][j] = player; // Setting the last position to the player number
		*lastRow = move;
		*lastCol = j; // Returning row & column indices
	}
}

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	/* This function checks if the game is over after a player has placed a move. This is done by checking every position of the board for 
	four in a row in one of four directions: vertical, horizontal, diagonal forward, and diagonal backward. This check starts from the very 
	top corner and sweeps to the bottom corner. It also checks if all spaces a piece may be placed are taken up */

	int pos = board[row][col];
	int i,j;
	int count = 0;

	for (i = 0; i < size; i++)  // Nested for loop to cycle through every value on the board
	{
		if (board[i][0] > 0) count++; // Checks if the entire 'W' column is full

		if (board[i][size - 1] > 0) count++; // Checks if the entire 'E' column is full

		if (board[0][i] > 0) count++; // Checks if the entire 'N' row is full

		if (board[size - 1][i] > 0) count++; // Checks if the entire 'S' row is full
		
		for (j = 0; j < size; j++) 
		{
			pos = board[i][j];
	
			if ((pos == board[i + 1][j]) && (pos == board[i + 2][j]) && (pos == board[i + 3][j]) && (pos == player)) return player; // Checks horizontal four in a row
				
			if ((pos == board[i][j + 1]) && (pos == board[i][j + 2]) && (pos == board[i][j + 3]) && (pos == player)) return player; // Checks vertical four in a row

			if ((pos == board[i + 1][j + 1]) && (pos == board[i + 2][j + 2]) && (pos == board[i + 3][j + 3]) && (pos == player)) return player; // Checks diagonal forward

			if ((pos == board[i - 1][j + 1]) && (pos == board[i - 2][j + 2]) && (pos == board[i - 3][j + 3]) && (pos == player)) return player; // Checks diagonal backward
		}
	}

	if (count == size * 4) return player; // If all four sides are taken up then there is no valid move. Thus the player wins

	return 0; // If there is no win
}

void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{
	/* This function converts the board array into one more visually appealing. It essentially does this by creating the border, then reading each 
	part of the board to fill it in with characters */

	int characters = 0;

	// These nested for loops cycle through every value of the board that was passed in, and also a border with width 2 around the border
	for (char i = 0; i < size + 4; i++) 
	{
		for (char j = 0; j < size + 5; j++) 
		{
			boardString[characters] = '.'; // This populates the entire board with a the fullstop character

			if (j == size + 4)  // Checks if its the end of the row, and inserts a new line character if it is
			{
				boardString[characters] = '\n';

			} else if (((i < 2) && (j < 2)) || ((i > size + 1) && (j < 2)) || ((i < 2) && (j > size + 1)) || ((i > size + 1) && (j > size + 1))) 
			{
				boardString[characters] = '-'; // This else if checks for the corners of the board, and fills them with a '-'
			} 

			/* These four else if statements below check for the borders. If it is the outermost then it will be N, E, S, or W. 
			The innermost border becomes 0 through the size of the board side. This is done by using the ascii character of '.' 
			and adding the index of the row or column. The index is + 2 from the edge so '.' is used as it is (int)46 which is -2 
			from (int)48 which is '0' */

			else if (((i == 0) || (i==1)) && (boardString[characters] == '.')) // else if #1
			{
				if (i == 0) 
				{
					boardString[characters] = 'N';
				} 
				else boardString[characters] = '.' + j;
			} 
			else if (((j == 0) || (j == 1)) && (boardString[characters] == '.')) // else if #2
			{
				if (j == 0) 
				{
					boardString[characters] = 'W';
				} 
				else boardString[characters] = '.' + i;
			} 
			else if (((j == size + 3) || (j == size + 2)) && (boardString[characters] == '.')) // else if #3
			{
				if (j == size + 3) 
				{
					boardString[characters] = 'E';
				} 
				else boardString[characters] = '.' + i;
			} 
			else if (((i == size + 3) || (i == size + 2)) && (boardString[characters] == '.')) // else if #4
			{
				if (i == size + 3) 
				{
					boardString[characters] = 'S';
				} 
				else boardString[characters] = '.' + j;
			} 
			else // This else statement populates the rest of the boardstring with what is actually in the board
			{ 
				if (board[i-2][j-2] == 1) 
				{
					boardString[characters] = 'X';
				} 
				else if (board[i-2][j-2] == 2) 
				{
					boardString[characters] = 'O';
				} 
				else if (board[i-2][j-2] == 3) boardString[characters] = '#';

			} 
			
			characters++; // Advances the character counter to keep track of placed symbols in the boardString
		}
	} 
	boardString[characters] = '\0'; // Adds the Null pointer to the end of the string to terminate it
}

void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE],  int size, int player, char *side, int *move)
{
	/* This is a fairly simple bot, which essentially checks if it can make a winning move by testing every valid move on a test board, and 
	if it can't win, then it will make a random move */

	int i, j;
	int RowPos, ColPos;
	char dir[4] = { 'N','E','S','W' }; // Character array for random selection of a side
	char randSide;
	int randMove;
	int check = 0;

	initialiseTestBoard(board, size); // Initialises the test board (globally defined for more memory)

	for (i = 0; i < 4; i++) // Nested for loop to cycle through each possible side, and number
	{
		for (j = 0; j < size; j++) 
		{
			AddMoveToBoard(testBoard, size, dir[i], j, player, &RowPos, &ColPos); // Adds the move & side to the test board

			if ((CheckGameOver(testBoard, size, player, RowPos, ColPos) > 0)&&(RowPos != -1) && (board[RowPos][ColPos] > -1)) // Checks if that move won
			{
				*side = dir[i];
				*move = j;
				return; // If it wins then thevalues of the pointers are changed to reflect that
			}

			initialiseTestBoard(board, size); // Reinitialises board on commencement of the loop
		}
	}

	do { // Do while loop to cycle through to check for a random valid move

		check = 0;

		randSide = dir[(rand() % 4)]; // Chooses one of the four random sides from the dharacter directory
		randMove = rand() % size; // Chooses a random number between 0 and size-1 for the move

		RowPos = 0;
		ColPos = 0;

		AddMoveToBoard(testBoard, size, randSide, randMove, player, &RowPos,&ColPos); // Adds the move to the test board to test it

		if ((RowPos > -1) && (RowPos < size) && (ColPos > -1) && (ColPos < size)) // Checks to see if it is a valid move
		{
			check++; // End condition for the while loop - not strictly necessary

			*move = randMove;
			*side = randSide; // Sets the pointes to the random move selected
			return;
		}

		initialiseTestBoard(board, size); // Reinitialises board to original state

	} while (check == 0);
}

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	/* This is a fairly simple bot, which essentially checks if it can make a winning move by testing every valid move on a test board, and
if it can't win, then it will make a random move */

	int i, j;
	int RowPos, ColPos;
	char dir[4] = { 'N','E','S','W' }; // Character array for random selection of a side
	char randSide;
	int randMove;
	int check = 0;

	initialiseTestBoard(board, size); // Initialises the test board (globally defined for more memory)

	for (i = 0; i < 4; i++) // Nested for loop to cycle through each possible side, and number
	{
		for (j = 0; j < size; j++)
		{
			AddMoveToBoard(testBoard, size, dir[i], j, player, &RowPos, &ColPos); // Adds the move & side to the test board

			if ((CheckGameOver(testBoard, size, player, RowPos, ColPos) > 0) && (RowPos != -1) && (board[RowPos][ColPos] > -1)) // Checks if that move won
			{
				*side = dir[i];
				*move = j;
				return; // If it wins then thevalues of the pointers are changed to reflect that
			}

			initialiseTestBoard(board, size); // Reinitialises board on commencement of the loop
		}
	}

	do { // Do while loop to cycle through to check for a random valid move

		check = 0;

		randSide = dir[(rand() % 4)]; // Chooses one of the four random sides from the dharacter directory
		randMove = rand() % size; // Chooses a random number between 0 and size-1 for the move

		RowPos = 0;
		ColPos = 0;

		AddMoveToBoard(testBoard, size, randSide, randMove, player, &RowPos, &ColPos); // Adds the move to the test board to test it

		if ((RowPos > -1) && (RowPos < size) && (ColPos > -1) && (ColPos < size)) // Checks to see if it is a valid move
		{
			check++; // End condition for the while loop - not strictly necessary

			*move = randMove;
			*side = randSide; // Sets the pointes to the random move selected
			return;
		}

		initialiseTestBoard(board, size); // Reinitialises board to original state

	} while (check == 0);
}

int my_power(int base, int power)
{
	/* This helper function is used to calculate something to the power of something else as we do not have access to math.h */
	int num = 1;

	for (int i = 0; i < power; i++)
	{
		num *= base; // Just cycles through each value up until the power is reached
	}

	return num;
}

int shifter(char *word, int pos) 
{
	/* This helper function is used to shift all the values of a character string by one to the left */
	int j = pos;

	while (word[j] != '\0') 
	{
		word[j] = word[j + 1];
		j++;
	}

	pos--; // Reducing the position count in order to continue comparing values in the right order as the entire line is shifted back one

	return pos;
}

void initialiseTestBoard(int board[MAX_SIZE][MAX_SIZE], int size) 
{
	/* This helper function is used in the bot to create a fresh board based on the actual board, so that it can test moves without editing th base board */

	for (int i = 0; i < size; i++) // Nested for loop to allocate every value of testBoard to the same value as that of board in the same position
	{
		for (int j = 0; j < size; j++) 
		{
			testBoard[i][j] = board[i][j];
		}
	}
}