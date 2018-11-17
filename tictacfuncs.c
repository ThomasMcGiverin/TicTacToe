/*
** Tic Tac Toe
**	   By
** Thomas McGiverin
**
**
** This file contains the functions used
** by the tic tac toe game
**
*/

#include <stdio.h>
#include <TicTacToe.h>

//Prints the current board state given a game state array
void printBoard(char gameState[]){
	printf(" %c | %c | %c\n", gameState[1], gameState[2], gameState[3]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", gameState[4], gameState[5], gameState[6]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", gameState[7], gameState[8], gameState[9]);
}

//Check to see if any of the three rows contains 3 in a row, if so return 1
int checkWinRow(char gameState[]){
	for(int i = 0; i < 3; i++){
		if (gameState[1 + (i * 3)] == gameState[2 + (i * 3)] && gameState[2 + (i * 3)] == gameState[3 + (i * 3)]){
			return 1;
		}
	}
	return 0;
}

//Check to see if any of the three columns contains 3 in a row, if so return 1
int checkWinCol(char gameState[]){
	for(int i = 0; i < 3; i++){
		if (gameState[1 + i] == gameState[4 + i] && gameState[4 + i] == gameState[7 + i]){
			return 1;
		}
	}
	return 0;
}

//Check to see if any of the two Diagonals contains 3 in a row, if so return 1
int checkWinDiag(char gameState[]){
	for(int i = 0; i < 2; i++){
		if (gameState[1 + (i * 6)] == gameState[5] && gameState[5] == gameState[9 - (i * 6)]){
			return 1;
		}
	}
	return 0;
}

//If any row, column, or diagonal contains three in a row of the same piece, return 1 indicating a winner
int checkVictory(char gameState[]){
	if (checkWinRow(gameState) == 1 || checkWinCol(gameState) == 1 || checkWinDiag(gameState) == 1){
		return 1;
	}
	return 0;
}

//Compare current selected tile to an array of tiles that have already been used, if it is already used, return 1
int charInArray(char selectedTile, char used[]){
	for (int i = 0; i < 10; i++){
		if(selectedTile == used[i]){
			return 1;
		}
	}
	return 0;
}