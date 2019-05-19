//Tic Tac Toe Program

#include <stdio.h>

void displayBoard(char board[][3]);
int selectLocation();
void setTurn(char board[][3], char letter, int location);
int checkForWin(char board[][3], int attempts);

void main(){
	char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	int win, attempts=0;
	char choice;
	
	displayBoard(board);
	while (choice != 'N' && choice != 'n'){
		printf("\nEnter the location for X: ");
		setTurn(board, 'X', selectLocation(board));
		++attempts;
		displayBoard(board);
		win = checkForWin(board, attempts);
		if (win == 0){
			break;
		}
		printf("\nEnter the location for O: ");
		setTurn(board, 'O', selectLocation(board));
		++attempts;
		displayBoard(board);
		win = checkForWin(board, attempts);
		if (win == 0){
			break;
		}
	}
		printf("\nWould you like to play again?(Y/N): ");
		scanf("\n%c", &choice);
		while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
			printf("Invalid entry. \nWould you like to play again?(Y/N):");
			scanf("\n%c", &choice);
		}
	}

	


void displayBoard(char board[][3]){
	int x;
	printf("Current Board: \n\n");
	for(x=0; x<3; x++){
		printf("%c\t", board[0][x]);
	}
	printf("\n\n");
	for(x=0; x<3; x++){
		printf("%c\t", board[1][x]);
	}
	printf("\n\n");
	for(x=0; x<3; x++){
		printf("%c\t", board[2][x]);
	}
}

int selectLocation(char board[][3]){
	int location;
	scanf("\n%d", &location);
	while(location < 1 || location > 9){
		printf("Invalid location\nPlease enter a valid location: ");
		scanf("\n%d", &location);
	}
	while(1){
	if(board[0][location - 1] != 'X' && board[0][location - 1] != 'O' && board[1][location - 4] != 'X' && board[1][location - 4] != 'O' && board[2][location - 7] != 'X' && board[2][location - 7] != 'O'){
	return location;
	}
	else{
		printf("Invalid location\nPlease enter a valid location: ");
		scanf("\n%d", &location);
	}
}
}

void setTurn(char board[][3], char letter, int location){
	if (location >= 1 && location <= 3){
		board[0][location - 1] = letter;
	}
	else if (location >= 4 && location <= 6){
		board[1][location - 4] = letter;
	}
	else if (location >= 7 && location <= 9){
		board[2][location - 7] = letter;
	}
}

int checkForWin(char board[][3], int attempts){
	if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){
		printf("Player 1 (X) Wins!");
		return 0;
	}
	else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
		printf("Player 1 (X) Wins!");
		return 0;
	}
	else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
		printf("Player 1 (X) Wins!");
		return 0;
	}
	else if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
		printf("Player 1 (X) Wins!");
		return 0;
	}
	else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
		printf("Player 1 (X) Wins!");
		return 0;
	}
	else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
		printf("Player 1 (X) Wins!");
		return 0;
	}
	else if(board[0][0] == 'X' && board[1][1] == 'X' && board [2][2] == 'X'){
		printf("Player 1 (X) Wins!");
		return 0;
	}
	else if(board[0][2] == 'X' && board [1][1] == 'X' && board[2][0] == 'X'){
		printf("Player 1 (X) Wins!");
		return 0;
	}
	
	else if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
		printf("\nPlayer 2 (Y) Wins!");
		return 0;
	}
	else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
		printf("\nPlayer 2 (Y) Wins!");
		return 0;
	}
	else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
		printf("\nPlayer 2 (Y) Wins!");
		return 0;
	}
	else if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
		printf("\nPlayer 2 (Y) Wins!");
		return 0;
	}
	else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
		printf("\nPlayer 2 (Y) Wins!");
		return 0;
	}
	else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
		printf("\nPlayer 2 (Y) Wins!");
		return 0;
	}
	else if(board[0][0] == 'O' && board[1][1] == 'O' && board [2][2] == 'O'){
		printf("\nPlayer 2 (Y) Wins!");
		return 0;
	}
	else if(board[0][2] == 'O' && board [1][1] == 'O' && board[2][0] == 'O'){
		printf("\nPlayer 2 (Y) Wins!");
		return 0;
	} 
			
}
