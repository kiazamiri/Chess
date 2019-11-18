//Mohammad Kia Zamiri-Jafarian (9312400797) 
//this is the code for chess phase 4.
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
int count = 0;                                                                                              //This is for the strings os saved games.
void gotoxy(int x, int y)                                                                                 //This function helps us move the pointer.
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X = x;
	cursorCoord.Y = y;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}
void clrscr()                                                                                             //This function clears the screen.
{
	system("cls");
}
int getscore(char c)                                                                                      //This function calculates the score.
{
	int point;
	point = 0;
	switch (c) {
	case('P'):
	case('p'):
		point++;
		break;
	case('N'):
	case('n'):
		point += 2;
		break;
	case('B'):
	case('b'):
		point += 3;
		break;
	case('R'):
	case('r'):
		point += 5;
		break;
	case('Q'):
	case('q'):
		point += 10;
		break;
	case('K'):
	case('k'):
		point += 100;
		break;
	}
	return(point);
}
int king(int X, int Y, int x, int y, char c, int turn, char board[][25])                  //This is the function of the king.       
{
	int i, sw;
	sw = 1;
	if (turn == 1) {
		if (c>97 || abs(X - x) != 2 && abs(Y - y) != 1) {                                          //This "if" shows that which places the king can't go or what pieces it can't hit. 
			sw = 0;
			return(sw);
		}
	}//end if
	else if (turn == 0) {
		if (c<90 || abs(X - x) != 2 && abs(Y - y) != 1) {
			sw = 0;
			return(sw);
		}
	}//end if
	return(sw);
}
int queen(int X, int Y, int x, int y, char c, int turn, char board[][25])                   //This is the function of the queen,it is the combination of
{                                                                                     //both rook's move and bishop's move.  
	int i, sw, k;
	sw = 1;
	k = 1;
	if (turn == 1) {                                                                     //This if shows that which places the queen can't go and what pieces it can't hit.
		if (c>97) {
			sw = 0;
			return(sw);
		}
		else if (abs(X - x) != abs(2 * (Y - y)) && x != X&&y != Y) {
			sw = 0;
			return(sw);
		}//end if
		if (x>X) {                                                                     //This is the move of the queen which is like the bishop.
			if (y>Y) {
				k = 1;
				for (i = Y; i<y - 1; i++) {
					if (board[Y + k][X + (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}// end if
					k++;
				}//end for
			}//end if (y>Y)
			else  if (y<Y) {
				k = 1;
				for (i = Y; i>y + 1; i--) {
					if (board[Y - k][X + (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}//end if
					k++;
				}//end for
			}//end if (y<Y)
		}//end if (x>X)
		else if (x<X) {
			if (y>Y) {
				k = 1;
				for (i = Y; i<y - 1; i++) {
					if (board[Y + k][X - (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}//end if
					k++;
				}//end for
			}//end if (y>Y)
			else if (y<Y) {
				k = 1;
				for (i = Y; i>y + 1; i--) {
					if (board[Y - k][X - (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}//end if
					k++;
				}//end for
			}//end if (x<X)
		}//end if turn
		if (x == X) {                                                                    //This is the move of the queen which is like the rook.        
			if (y>Y) {
				for (i = Y; i<y; i++) {
					if (board[i][x] != '_') {
						sw = 0;
						return(sw);
					}//end if
				}//end for
			}//end if (y>Y)
			else if (y<Y) {
				for (i = Y; i>y; i--) {
					if (board[i][x] != '_') {
						sw = 0;
						return(sw);
					}//end if
				}//end for
			}//end if (y<Y)
		}//end if (x==X)
		else if (y == Y) {
			if (x>X) {
				for (i = X; i<x; i += 2) {
					if (board[y][i] != '_') {
						sw = 0;
						return(sw);
					}//end if
				}//end for
			}//end if (x>X)
			else if (x<X) {
				for (i = X; i>x; i -= 2) {
					if (board[y][i] != '_') {
						sw = 0;
						return(sw);
					}//end if
				}//end for
			}//end if (x<X)
		}//end if (y==Y)
	}//end if turn
	else if (turn == 0) {                                                                //This is the same function only it's team 1's turn.      
		if (c<90) {
			sw = 0;
			return(sw);
		}
		else if (abs(X - x) != abs(2 * (Y - y)) && x != X&&y != Y) {
			sw = 0;
			return(sw);
		}
		if (x>X) {
			if (y>Y) {
				k = 1;
				for (i = Y; i<y - 1; i++) {
					if (board[Y + k][X + (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}
					k++;
				}
			}
			else  if (y<Y) {
				k = 1;
				for (i = Y; i>y + 1; i--) {
					if (board[Y - k][X + (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}
					k++;
				}
			}
		}
		else if (x<X) {
			if (y>Y) {
				k = 1;
				for (i = Y; i<y - 1; i++) {
					if (board[Y + k][X - (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}
					k++;
				}
			}
			else if (y<Y) {
				k = 1;
				for (i = Y; i>y + 1; i--) {
					if (board[Y - k][X - (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}
					k++;
				}
			}
		}
		if (x == X) {
			if (y>Y) {
				for (i = Y; i<y; i++) {
					if (board[i][x] != '_') {
						sw = 0;
						return(sw);
					}
				}
			}
			else if (y<Y) {
				for (i = Y; i>y; i--) {
					if (board[i][x] != '_') {
						sw = 0;
						return(sw);
					}
				}
			}
		}
		else if (y == Y) {
			if (x>X) {
				for (i = X; i<x; i += 2) {
					if (board[y][i] != '_') {
						sw = 0;
						return(sw);
					}
				}
			}
			else if (x<X) {
				for (i = X; i>x; i -= 2) {
					if (board[y][i] != '_') {
						sw = 0;
						return(sw);
					}
				}
			}
		}
	}
	return(sw);
}
int rook(int X, int Y, int x, int y, char c, int turn, char board[][25]) {                   //This is the function of rook.
	int sw, i;
	sw = 1;
	if (turn == 1) {                                                                     //Here we find out where the rook can't goes and what pieces it can't hit 
		if (c>97) {
			sw = 0;
			return(sw);
		}
		else if (x != X&&y != Y) {
			sw = 0;
			return(sw);
		}//end id
		if (x == X) {
			if (y>Y) {
				for (i = Y; i<y; i++) {
					if (board[i][x] != '_') {
						sw = 0;
						return(sw);
					}//end if
				}//end for
			}//end if (y>Y)
			else if (y<Y) {
				for (i = Y; i>y; i--) {
					if (board[i][x] != '_') {
						sw = 0;
						return(sw);
					}//end if 
				}//end for
			}//end if (y<Y)
		}//end if (x==X)
		else if (y == Y) {
			if (x>X) {
				for (i = X; i<x; i += 2) {
					if (board[y][i] != '_') {
						sw = 0;
						return(sw);
					}//end if 
				}//end for 
			}//end if (x>X)
			else if (x<X) {
				for (i = X; i>x; i -= 2) {
					if (board[y][i] != '_') {
						sw = 0;
						return(sw);
					}//end if 
				}//end for
			}//end if (x<X)
		}//end if (y==Y)
	}//end if turn
	else if (turn == 0) {                                                                //This is the same function only it's team 1's turn.   
		if (c<90) {
			sw = 0;
			return(sw);
		}
		else if (x != X&&y != Y) {
			sw = 0;
			return(sw);
		}
		if (x == X) {
			if (y>Y) {
				for (i = Y; i<y; i++) {
					if (board[i][x] != '_') {
						sw = 0;
						return(sw);
					}
				}
			}
			else if (y<Y) {
				for (i = Y; i>y; i--) {
					if (board[i][x] != '_') {
						sw = 0;
						return(sw);
					}
				}
			}
		}
		else if (y == Y) {
			if (x>X) {
				for (i = X; i<x; i += 2) {
					if (board[y][i] != '_') {
						sw = 0;
						return(sw);
					}
				}
			}
			else if (x<X) {
				for (i = X; i>x; i -= 2) {
					if (board[y][i] != '_') {
						sw = 0;
						return(sw);
					}
				}
			}
		}
	}
	return(sw);
}
int bishop(int X, int Y, int x, int y, char c, int turn, char board[][25])                  //This is the function of bishop
{
	int i, sw, k;
	sw = 1;
	k = 1;
	if (turn == 1) {                                                                     //Here we find out which places the bishop can't go and what pieces it can't hit. 
		if (c>97) {
			sw = 0;
			return(sw);
		}
		else if (abs(X - x) != abs(2 * (Y - y))) {
			sw = 0;
			return(sw);
		}//end if
		if (x>X) {
			if (y>Y) {
				k = 1;
				for (i = Y; i<y - 1; i++) {
					if (board[Y + k][X + (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}//end if
					k++;
				}//end for
			}//end if (y>Y)
			else  if (y<Y) {
				k = 1;
				for (i = Y; i>y + 1; i--) {
					if (board[Y - k][X + (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}//end if
					k++;
				}//end for
			}//end if (y<Y)
		}//end if (x>X)
		else if (x<X) {
			if (y>Y) {
				k = 1;
				for (i = Y; i<y - 1; i++) {
					if (board[Y + k][X - (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}//end if 
					k++;
				}//end for
			}//end if (y>Y)
			else if (y<Y) {
				k = 1;
				for (i = Y; i>y + 1; i--) {
					if (board[Y - k][X - (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}//end if
					k++;
				}//end for
			}//end if (y<Y)
		}//end if (x<X)
	}//end turn
	else if (turn == 0) {                                                                //This is the same function only it's team 1's turn.          
		if (c<90) {
			sw = 0;
			return(sw);
		}
		else if (abs(X - x) != abs(2 * (Y - y))) {
			sw = 0;
			return(sw);
		}
		if (x>X) {
			if (y>Y) {
				k = 1;
				for (i = Y; i<y - 1; i++) {
					if (board[Y + k][X + (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}
					k++;
				}
			}
			else  if (y<Y) {
				k = 1;
				for (i = Y; i>y + 1; i--) {
					if (board[Y - k][X + (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}
					k++;
				}
			}
		}
		else if (x<X) {
			if (y>Y) {
				k = 1;
				for (i = Y; i<y - 1; i++) {
					if (board[Y + k][X - (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}
					k++;
				}
			}
			else if (y<Y) {
				k = 1;
				for (i = Y; i>y + 1; i--) {
					if (board[Y - k][X - (2 * k)] != '_') {
						sw = 0;
						return(sw);
					}
					k++;
				}
			}
		}
	}
	return (sw);
}
int knight(int X, int Y, int x, int y, char c, int turn)                                                       //This is the function of knight.
{
	int A[8][2] = { { Y + 2,X - 2 },{ Y + 2,X + 2 },{ Y + 1,X + 4 },{ Y + 1,X - 4 },{ Y - 2,X - 2 },{ Y - 2,X + 2 },{ Y - 1,X + 4 },{ Y - 1,X - 4 } };        //This show what places the knight can go,
	int i, sw;
	sw = 0;
	if (turn == 1) {
		for (i = 0; i<8; i++) {
			if (y == A[i][0] && x == A[i][1] && c != 'p'&&c != 'r'&&c != 'b'&&c != 'k'&&c != 'q'&&c != 'n') {
				sw = 1;
				break;
			}//end if
		}//end for
	}//end if turn
	else if (turn == 0) {
		for (i = 0; i<8; i++) {
			if (y == A[i][0] && x == A[i][1] && c != 'P'&&c != 'Q'&&c != 'K'&&c != 'B'&&c != 'R'&&c != 'N') {
				sw = 1;
				break;
			}//end if
		}//end for
	}//end if turn
	return (sw);
}
int Pawn(int X, int Y, int x, int y, char d, char g, char h, char f)                                             //This is the fuction of the pawn of Team 1.                                  
{
	int a[4][2] = { { Y - 1,X },{ Y - 2,X },{ Y - 1,X + 2 },{ Y - 1,X - 2 } };                                                    //This is the places the pawn can go.
	int sw;
	sw = 0;
	if (Y == 6) {                                                                                            //This if is for the first move of the pawn.
		if (y == a[0][0] && x == a[0][1] && h == 95 || y == a[1][0] && x == a[1][1] && h == 95 && f == 95 || y == a[2][0] && x == a[2][1] && d>97 || y == a[3][0] && x == a[3][1] && g>97) {
			sw = 1;
		}//end if
	}
	else {
		if (y == a[0][0] && x == a[0][1] && h == 95 || y == a[2][0] && x == a[2][1] && d>97 || y == a[3][0] && x == a[3][1] && g>97) {   //this if is for the next moves.
			sw = 1;
		}//end if
	}//end if (Y==6)
	return(sw);
}
int pawn(int X, int Y, int x, int y, char d, char g, char h, char f)                                             //this is the fuction of the pawn of Team 2.
{
	int a[4][2] = { { Y + 1,X },{ Y + 2,X },{ Y + 1,X + 2 },{ Y + 1,X - 2 } };                                                    //This shows where the pawn can go.
	int sw;
	sw = 0;
	if (Y == 1) {                                                                                            //This if is for the first move of the pawn. 
		if (y == a[0][0] && x == a[0][1] && h == 95 || y == a[1][0] && x == a[1][1] && h == 95 && f == 95 || y == a[2][0] && x == a[2][1] && d<90 || y == a[3][0] && x == a[3][1] && g<90) {
			sw = 1;
		}//end if
	}
	else {                                                                                                //This if is for the next moves of the pawn.
		if (y == a[0][0] && x == a[0][1] && h == 95 || y == a[2][0] && x == a[2][1] && d<90 || y == a[3][0] && x == a[3][1] && g<90) {
			sw = 1;
		}//end if
	}//end if (Y==1)
	return(sw);
}
void menu()                                                                                               //This is the fuction for printing the menu. 
{
	printf("\n\n\nMENU\n");
	printf("Wellcome To The Game Chess.\n");
	printf("You can move with the arrow keys. To Select a piece, please press P.\n");
	printf("The starter could be either team 1 or team 2.\n");
	printf("The turn of the teams are printed. Please carry out them correctly.\n");
	printf("An invalid move will be notified and the team's turn is finished.\n");
	printf("The game will end by hitting the King.\n");
	printf("Press S to save.\n");
	printf("Here are your Options.\n");
	printf("1. Select A Pawn To move.\n");
	printf("2. Select A Knight To move.\n");
	printf("3. End turn.\n");
	printf("4. QUIT.\n");
}
void highscore(float score, float scores[])                                                                    //This is the function for saving the highscores.    
{
	FILE *score1;                                                                                         //This is the name of the file.
	int i, j, temp;
	scores[3] = score;
	for (i = 1; i<4; i++) {
		temp = scores[i];
		for (j = i - 1; j >= 0 && temp>scores[j]; j--)
			scores[j + 1] = scores[j];
		scores[j + 1] = temp;
	}//end for
	score1 = fopen("highscores", "wb");
	if (!score1) {
		printf("can't open file");
		return;
	}//end if
	for (i = 0; i<3; i++) {
		fwrite(&scores[i], sizeof(float), 1, score1);                                                          //Here we  will save the scores in a file named "highscores".
	}//end for
	fclose(score1);
}
void save(char record[][20], int *count)                                                                   //This is the function for saning the names of the saved files.
{
	FILE *save;                                                                                           //This is the name of the file.
	int i, j, k;
	save = fopen("save", "wb");
	if (!save) {
		printf("can't open file");
		return;
	}//end if
	for (i = 0; i<5; i++) {
		for (j = 0; j<20; j++) {
			fwrite(&record[i][j], sizeof(char), 1, save);
		}
	}//end for
	fwrite(&*count, sizeof(int), 1, save);                                                                   //We should save the count by it's reference.
	fclose(save);
}
void load(char record[][20], int *count)                                                                   //This is the function for loading the saved game's name.
{
	FILE *load;
	int i, j;
	load = fopen("save", "rb");
	if (!load) {
		printf("There is no saved game");
		return;
	}
	while (!feof(load)) {
		for (i = 0; i<5; i++) {
			for (j = 0; j<20; j++) {
				fread(&record[i][j], sizeof(char), 1, load);
			}
		}
		fread(&*count, sizeof(int), 1, load);
	}
	for (i = 0; i<5; i++) {
		for (j = 0; j<20; j++) {
			printf("%c ", record[i][j]);
		}
		printf("\n");
	}
	fclose(load);
}
void loadfromfile(char board[][25], char record[][20], int *turn, float *score1, float *score2)               //This is the fuction for loading and printing the game.
{
	FILE *infile;
	char filename[20];
	int i, j;
	char ch;
	i = 0, j = 0;
	printf("Please enter your saved game's name:\n");
	gets(filename);
	infile = fopen(filename, "rb");
	if (!infile) {
		printf("can't open file");
		return;
	}
	while (!feof(infile)) {
		for (i = 0; i<8; i++) {
			for (j = 0; j<25; j++) {
				fread(&board[i][j], sizeof(char), 1, infile);
			}
		}
		fread(&*score1, sizeof(float), 1, infile);
		fread(&*score2, sizeof(float), 1, infile);
		fread(&*turn, sizeof(int), 1, infile);
	}
	clrscr();
	for (i = 0; i<8; i++) {
		for (j = 0; j<25; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	printf("-----------------");
	printf("\n A B C D E F G H\n");
	if (*turn == 1)
		printf("\n\n  Team 1's Turn!\n");
	else if (*turn == 0)
		printf("\n\n  Team 2's Turn!\n");
	menu();
	fclose(infile);
}
void savetofile(char board[][25], char record[][20], char filename[20], int count, int *turn, float *score1, float *score2)       //This is the function for saving the game.
{
	FILE *outfile;
	int i, j;
	char ch;
	save(record, &count);
	outfile = fopen(filename, "wb");
	if (!outfile) {
		printf("can't open file");
		return;
	}
	for (i = 0; i<8; i++) {
		for (j = 0; j<25; j++) {
			fwrite(&board[i][j], sizeof(char), 1, outfile);
		}
		printf("\n");
	}
	fwrite(&*score1, sizeof(float), 1, outfile);
	fwrite(&*score2, sizeof(float), 1, outfile);
	fwrite(&*turn, sizeof(int), 1, outfile);
	fclose(outfile);
}
void printscores(float scores[])                                                                          //This is the function for printing and loading the highscores.
{
	FILE *highscore;
	int i;
	highscore = fopen("highscores", "rb");
	if (!highscore) {
		printf("There is no high score\n");
		return;
	}
	while (!feof(highscore)) {
		for (i = 0; i<3; i++) {
			fread(&scores[i], sizeof(float), 1, highscore);
		}
	}
	for (i = 0; i<3; i++) {
		printf("%f\n", scores[i]);
	}
}
void main()
{
	char board[8][25] = { { '|','r','|','n','|','b','|','q','|','k','|','b','|','n','|','r','|',' ','8',' ','T','e','a','m','2' },   //this is the board of the game.
	{ '|','p','|','p','|','p','|','p','|','p','|','p','|','p','|','p','|',' ','7',' ',' ',' ' },
	{ '|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|',' ','6',' ',' ',' ' },
	{ '|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|',' ','5',' ',' ',' ' },
	{ '|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|',' ','4',' ',' ',' ' },
	{ '|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|',' ','3',' ',' ',' ' },
	{ '|','P','|','P','|','P','|','P','|','P','|','P','|','P','|','P','|',' ','2',' ',' ',' ' },
	{ '|','R','|','N','|','B','|','Q','|','K','|','B','|','N','|','R','|',' ','1',' ','T','e','a','m','1' } };
	char record[5][20] = { { '_','_','_' },{ '_','_','_' },{ '_','_','_' },{ '_','_','_' },{ '_','_','_' } };
	char filename[20];
	char b, c, d, g, h, f, s;
	int x, y, X, Y;                                         //These are the coordinates of the pointer.
	char ch;
	int t, k, i, j, v;
	int turn;
	double score1, score2;
	float scores[4] = { 0,0,0 };
	clock_t start, end;
	score1 = 0, score2 = 0;
	x = 0, y = 0, k = 0, s = 0, v = 0;
	turn = 0;
	printf("Welcome To The Chess Game!!!\n");
	printf("List Of Options:\n");
	printf("1-Load a game.\n");
	printf("2-New gmae\n");
	printf("The high scores are:\n");
	printscores(scores);
	printf("These are the saved game's name:\n");
	load(record, &count);
	ch = _getch();
	switch (ch) {
	case(49):
		clrscr();
		loadfromfile(board, record, &turn, &score1, &score2);
		menu();
		break;
	case(50):
		clrscr();
		for (i = 0; i<8; i++) {                                    //This is the loop for printing the board.
			for (j = 0; j<25; j++) {
				printf("%c", board[i][j]);
			}//end for
			printf("\n");
		}//end for
		printf("-----------------");
		printf("\n A B C D E F G H\n");
		menu();
		break;
	}
	k = 0;
	gotoxy(0, 0);
	start = clock();
	for (t = 0;; t++) {                                        //Here is the code for moving the pointer and play and it contiues forever unless somebody wins. 
		if (_kbhit() == NULL) {                                 //Here we find out that the keyboard is hitted or not to find out the player made a move or not.
			end = clock() - start;
			if (end>20000) {                                 //If it continues for more than 20 seconds it's the next team's move.
				start = clock();
				gotoxy(2, 12);
				printf("It's the next turn");
			}
		}
		else if (_kbhit() != NULL) {                            //The keyboard is hitted.
			ch = _getch();
			if (ch == -32) {
				ch = _getch();
				if (ch == 80) {                                    //DOWN
					gotoxy(x, y + 1);
					y++;
				}//end if
				else if (ch == 77) {                               //RIGHT
					gotoxy(x + 1, y);
					x++;
				}//end if
				else if (ch == 75) {                               //LEFT
					gotoxy(x - 1, y);
					if (x>0)
						x--;
				}//end if
				else if (ch == 72) {                               //UP
					gotoxy(x, y - 1);
					if (y>0)
						y--;
				}//end if
			}
			else {
				if (ch == 112) {                                   //We now pick the the piece we want to move.
					if (k == 0) {                                   //k is a switch for finding out that we want to pick a piece or putting a piece
						b = board[y][x];
						board[y][x] = '_';
						X = x, Y = y;
						k = 1;
						start = clock();
					}//end if
					else if (k == 1) {
						end = clock() - start;
						if (end>20000) {
							if (b>97) {
								start = clock();
								gotoxy(2, 12);
								board[Y][X] = b;
								printf("It's Team 1's turn");
							}
							else {
								start = clock();
								gotoxy(2, 12);
								board[Y][X] = b;
								printf("It's Team 2's turn");
							}
						}
						else if (end<20000) {
							c = board[y][x];
							if (c != 'k'&&c != 'K') {
								if (b>97)
									turn = 1;
								else
									turn = 0;
								switch (b) {                          //This is where we want to know what piece is chosen.
								case('p'):
									d = board[Y + 1][X + 2];              //These are the places that a pawn could go to hit  
									g = board[Y + 1][X - 2];
									h = board[Y + 1][X];                //This is for moving the pawn one block.
									f = board[Y + 2][X];                //This is for moving the pawn two blocks.
									v = pawn(X, Y, x, y, d, g, h, f);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('P'):
									d = board[Y - 1][X + 2];              //These are the placesthat a pawn can hit.
									g = board[Y - 1][X - 2];
									h = board[Y - 1][X];                //This is for moving the pawn one block.
									f = board[Y - 2][x];                //This is for moving the pawn two blocks.
									v = Pawn(X, Y, x, y, d, g, h, f);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('r'):                           //For both rooks the code is the same.
									v = rook(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('R'):
									v = rook(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('b'):                          //For both bishops the code is the same.
									v = bishop(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('B'):
									v = bishop(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('n'):                          //For both knights the code is the same.
									v = knight(X, Y, x, y, c, turn);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('N'):
									v = knight(X, Y, x, y, c, turn);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case ('q'):                         //For both queens the code is the same.
									v = queen(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case ('Q'):
									v = queen(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('k'):                          //For both kings the code is the same.
									v = king(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case ('K'):
									v = king(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								default:
									board[y][x] = b;
								}//end switch
								clrscr();
								x = 0, y = 0;
								for (i = 0; i<8; i++) {
									for (j = 0; j<25; j++) {
										printf("%c", board[i][j]);
									}//end for
									printf("\n");
								}//end for
								printf("-----------------");
								printf("\n A B C D E F G H\n");
								if (b>97)
									printf("\n\n  Team 1's Turn!\n");
								else
									printf("\n\n  Team 2's Turn!\n");
								if (v == 0)
									printf("\n\n\n Invalid move");
								menu();
								gotoxy(0, 0);
							}//end if (c!='k'&&c!='K')
							else if (c == 'k' || c == 'K') {                       //This is the if of Team's 1 winning.
								if (b>97)
									turn = 1;
								else
									turn = 0;
								switch (b) {                          //This is where we want to know what piece is chosen.
								case('p'):
									d = board[Y + 1][X + 2];              //These are the places that a pawn could go to hit  
									g = board[Y + 1][X - 2];
									h = board[Y + 1][X];                //This is for moving the pawn one block.
									f = board[Y + 2][X];                //This is for moving the pawn two blocks.
									v = pawn(X, Y, x, y, d, g, h, f);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('P'):
									d = board[Y - 1][X + 2];              //These are the placesthat a pawn can hit.
									g = board[Y - 1][X - 2];
									h = board[Y - 1][X];                //This is for moving the pawn one block.
									f = board[Y - 2][x];                //This is for moving the pawn two blocks.
									v = Pawn(X, Y, x, y, d, g, h, f);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('r'):                           //For both rooks the code is the same.
									v = rook(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('R'):
									v = rook(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('b'):                          //For bothe bishops the code is the same.
									v = bishop(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('B'):
									v = bishop(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('n'):                          //For both knights the code is the same.
									v = knight(X, Y, x, y, c, turn);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('N'):
									v = knight(X, Y, x, y, c, turn);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case ('q'):                         //For both queens the code is the same.
									v = queen(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case ('Q'):
									v = queen(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case('k'):                          //For both kings the code is the same.
									v = king(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score2 += s;
										score2 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								case ('K'):
									v = king(X, Y, x, y, c, turn, board);
									if (v == 1 && c == '_') {
										board[y][x] = b;
									}
									else if (v == 1 && c != '_') {
										s = getscore(c);
										score1 += s;
										score1 += (1 / end);
										board[y][x] = b;
									}
									else {
										board[Y][X] = b;
									}//end if
									break;
								default:
									board[y][x] = b;
								}//end switch
								clrscr();
								x = 0, y = 0;
								for (i = 0; i<8; i++) {
									for (j = 0; j<25; j++) {
										printf("%c", board[i][j]);
									}//end for
									printf("\n");
								}//end for
								printf("-----------------");
								printf("\n A B C D E F G H\n");
								if (v == 0) {
									printf("\n\n  invalid move");
								}
								else if (score2>score1) {
									highscore(score2, scores);
									printf("\n\n  Team2 Won!!!\n");
									printf("score=%f\n", score2);
									printf("\a\a");
									break;
								}//end if
								else if (score1>score2) {
									highscore(score1, scores);
									printf("\n\n  Team1 Won!!!\n");
									printf("score=%f\n", score1);
									printf("\a\a");
									break;
								}//end if
								menu();
								gotoxy(0, 0);
							}//end if (c=='k'||c=='K')
						}//end if (k==1)
						k = 0;
						v = 1;
					}//end if (ch==112)
				}
				else if (ch == 115) {
					gotoxy(0, 10);
					printf("please enter your name:\n");
					gets(filename);
					strcpy(record[count], filename);
					count++;
					savetofile(board, record, filename, count, &turn, &score1, &score2);
					return;
				}
			}//end if (ch==-32)
		}//end for
	}
}