/*
** Tic Tac Toe
**	   By
** Thomas McGiverin
**
**
** This is the header file to reference all
** functions used by the tic tac toe game
**
*/

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

int playTTT();
void printBoard(char gameState[]);
int checkWinRow(char gameState[]);
int checkWinCol(char gameState[]);
int checkWinDiag(char gameState[]);
int checkVictory(char gameState[]);
int charInArray(char selectedTile, char used[]);

#endif