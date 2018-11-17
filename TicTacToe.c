/*
** Tic Tac Toe
**	   By
** Thomas McGiverin
**
**
** This file contains the main application
** itself to run the tic tac toe game
**
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <TicTacToe.h>

int main(void){
	playTTT();
}

int playTTT(){
	char gameState[10] = {" 123456789"}; //Char array to represent each tile
	char invalidMoves[10] = {"          "}; //Char array to keep track of chosen tiles
	bool player2Turn = false; //Boolean that determines whos turn it is
	char pieceToPlay; //char that is either 'X' or 'O' depending on whos turn it is
	int selectedTile; //Stores tile number selected by user

	for(int i = 0; i < 9; i++){
		printBoard(gameState); //Print board with updated tiles

		//If it is player 2s turn, place a 'O', otherwise place 'X' for player 1
		if (player2Turn){
			pieceToPlay = 'O';
		} else {
			pieceToPlay = 'X';
		}

		//Do while loop to validate input for the selected tile.
		//Checks to make sure the selected tile is between 1 and 9 inclusive,
		//Then checks to make sure the selected tile does not already have a game piece on it
		do {
			printf("Player %d, input tile number to place '%c': ", player2Turn + 1, pieceToPlay);
			scanf("%d", &selectedTile);
		} while ((selectedTile < 1 || selectedTile > 9) || (charInArray(selectedTile, invalidMoves) == 1));

		invalidMoves[i] = selectedTile; //Add the current selected tile to the invalidMoves array for later input validation
		gameState[selectedTile] = pieceToPlay; //Change the selected tile to the current game piece depending on player

		//Once there have been at least 5 turns (minimum number to win a game),
		//start checking to see if either player has won 
		if (i >= 4 && checkVictory(gameState) == 1){
			printBoard(gameState); //Print final board state
			printf("Player %d Wins!\n", player2Turn + 1);
			return 1;
		}

		player2Turn = !player2Turn; //Alternate player 1 and player 2 turns by negating player2turn (swap from false -> true, and vice versa)
	}
}