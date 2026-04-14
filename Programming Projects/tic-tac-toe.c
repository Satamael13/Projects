#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()

{
	
// Ask user for 2-player of 1-player

char gameMode;
printf("2-player (a) or 1-player (b): ");
scanf(" %c", &gameMode);

// Variables
	
int i, j;
int row, col;
int moves = 0;
int win = 0;

int player = 1;
char symbol;

// Initialize an empty 3x3 array

char board[3][3];

for (i = 0; i < 3; i++)
{
	for (j = 0; j < 3; j++)
	{
		board[i][j] = '-';
	}
}

// 2-player, gameMode = a

if (gameMode == 'a')
{

	// Set win and move conditions 
	
	while (moves < 9 && win == 0)
	{
		
		// Print the board
		
		printf("\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%c ", board[i][j]);
			}
			printf("\n");
		}
		
		// Choose symbol
		
		if (player == 1)
		{
			symbol = 'X';
		}
		else
		{
			symbol = 'O';
		}
		
		// Player input
		
		printf("Player %d (%c), enter row and column (0-2): ", player, symbol);
		scanf("%d %d", &row, &col);
		
		// Check for valid move
		
		if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-')
		{
			printf("Invalid move! Try again!\n");
			continue; 
		}
		
		// Place symbol
		
		board[row][col] = symbol;
		moves++;
		
		// Checking win conditions
			
			// Rows
			for (i = 0; i < 3; i++)
			{
				if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
				{
					win = 1;
				}
			}
			
			// Columns
			for (i = 0; i < 3; i++)
			{
				if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
				{
					win = 1;
				}
			}
			
			// Diagonals
			if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
			{
				win = 1;
			}
			if (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol)
			{
				win = 1;
			}
			
		// Switch players
		
		if (player == 1)
		{
			player = 2;
		}
		else
		{
			player = 1;
		}
			
	}
	
	// Final board
	
	printf("\nFinal Board\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	
	// Result 
	
	if (win == 1)
	{
		if (player == 1)
		{
			printf("Player 2 wins!\n");
		}
		else 
		{
			printf("Player 1 wins!\n");
		}
	}
	else 
	{
		printf("It's a draw!\n");
	}

return 0; // End of game
}
else if (gameMode == 'b')
{
	
// Set win and move conditions 
	
	while (moves < 9 && win == 0)
	{
		
		// Print the board
		
		printf("\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%c ", board[i][j]);
			}
			printf("\n");
		}
		
		// -- Player turn -- 
		
		symbol = 'X';
		printf("Your move (X). Enter row and column (0-2): ");
		scanf("%d %d", &row, &col);
		
			// Check for  valid move
			
			if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-')
			{
				printf("Invalid move! Try again!\n");
				continue; 
			}
			
			// Place symbol
			
			board[row][col] = symbol;
			moves++;
			
			// Check win conditions
			
				// Rows
				for (i = 0; i < 3; i++)
				{
					if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
					{
						win = 1;
					}
				}
			
				// Columns
				for (i = 0; i < 3; i++)
				{
					if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
					{
						win = 1;
					}
				}
				
				// Diagonals
				if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
				{
					win = 1;
				}
				if (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol)
				{
					win = 1;
				}
			
			if (win == 1)
			{
				break;
			}
		
		// -- Computer turn -- 
		
		symbol = 'O';
		printf("Computer's turn.\n");
		
			// Place symbol
		
			int Cmove = 0;
			for (i = 0; i < 3 && Cmove == 0; i++)
			{
				for (j = 0; j < 3 && Cmove == 0; j++)
				{
					if (board[i][j] == '-')
					{
						board[i][j] = symbol;
						Cmove = 1;
					}
				}
			}
			
			moves++;
			
			// Check win conditions
			
				// Rows
				for (i = 0; i < 3; i++)
				{
					if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
					{
						win = 1;
					}
				}
			
				// Columns
				for (i = 0; i < 3; i++)
				{
					if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
					{
						win = 1;
					}
				}
				
				// Diagonals
				if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
				{
					win = 1;
				}
				if (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol)
				{
					win = 1;
				}
			
	}
	
	// Final board
	
	printf("\nFinal Board\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	
	// Result
	
	if (win == 1)
	{
		if (symbol == 'X')
		{
			printf("You win!\n");
		}
		else
		{
			printf("Computer wins!\n");
		}
	}
	else 
	{
		printf("It's a draw!\n");
	}
	
	
return 0; // End of game
}
	


}
