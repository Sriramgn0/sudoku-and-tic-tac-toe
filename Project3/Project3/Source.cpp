//It's a game you need to add glut plugin in Visual studio to run this code


#include <math.h>
#include<dos.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>


#define maxx 10
#define maxy 10
#define dx 15
#define dy 10
GLfloat x[maxx] = { 0.0 }, y[maxy] = { 0.0 };
GLfloat x0 = 50, yp = 50;
GLint i, j, a, m = 0, n = 0;
static GLuint limit;
static GLuint count = 1;
static GLenum flag = 0;
static char m1[] = { "PUZZLE WORLD" };
static char m4[] = { "WELCOME TO DEMO - MENU" };
static char m5[] = { "PRESS 'c' FOR SUDOKU" };
static char m6[] = { "SUDOKU" };
static char m9[] = { "TIC-TAC-TOE" };
static char m7[] = { "SUDOKU NOT SOLVED YET" };
static char m8[] = { "CONGRATULATION YOU COMPLTED THE SUDOKU " };
static char m21[] = { "sriram" };
int newsudoku1 = 0, sudokuenable = 0,gotanswer=0;
static int ab[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
					   {5, 2, 0, 0, 0, 0, 0, 0, 0},
					  {0, 8, 7, 0, 0, 0, 0, 3, 1},
					  {0, 0, 3, 0, 1, 0, 0, 8, 0},
					  {9, 0, 0, 8, 6, 3, 0, 0, 5},
					  {0, 5, 0, 0, 9, 0, 6, 0, 0},
					  {1, 3, 0, 0, 0, 0, 2, 5, 0},
					  {0, 0, 0, 0, 0, 0, 0, 7, 4},
					  {0, 0, 5, 2, 0, 6, 3, 0, 0} };

static int cd[9][9] = { {4,0,0,2,0,1,0,9,0},
							  {2,7,0,0,9,5,0,0,0},
							  {0,0,5,0,0,3,0,0,0},
							  {0,0,0,0,0,0,9,5,0},
							  {0,0,0,0,5,0,0,4,2},
							  {9,0,0,8,0,2,0,0,7},
							  {7,3,0,0,2,8,0,0,0},
							  {1,0,0,0,0,0,0,0,0},
							  {0,0,9,0,0,0,1,2,0} };

static int ef[9][9] = { {5,3,0,0,7,0,0,0,0},
						  {6,0,0,1,9,5,0,0,0},
						  {0,9,8,0,0,0,0,6,0},
						  {8,0,0,0,6,0,0,0,3},
						  {4,0,0,8,0,3,0,0,1},
						  {7,0,0,0,2,0,0,0,6},
						  {0,6,0,0,0,0,2,8,0},
						  {0,0,0,4,1,9,0,0,5},
						  {0,0,0,0,8,0,0,7,9} };

static int gh[9][9] = { {0,2,0,0,0,4,3,0,0},
						 {9,0,0,0,2,0,0,0,8},
						 {0,0,0,6,0,9,0,5,0},
						 {0,0,0,0,0,0,0,0,1},
						 {0,7,2,5,0,3,6,8,0},
						 {6,0,0,0,0,0,0,0,0},
						 {0,8,0,2,0,5,0,0,0},
						 {1,0,0,0,9,0,0,0,3},
						 {0,0,9,8,0,0,0,6,0} };

static int ij[9][9] = { {1,0,0,0,0,0,0,0,3},
						 {0,0,7,2,6,0,4,8,0},
						 {4,0,0,9,3,5,0,0,6},
						 {0,3,0,4,8,0,2,0,0},
						 {0,4,1,6,0,9,3,0,0},
						 {0,0,6,0,0,0,8,9,0},
						 {5,7,8,0,4,0,0,0,2},
						 {0,0,0,3,0,0,0,7,0},
						 {2,0,0,0,0,0,0,0,5} };

static int kl[9][9] = { {4,0,0,0,0,0,0,6,0},
						 {0,0,0,0,9,7,0,0,0},
						 {0,0,7,2,0,0,0,0,0},
						 {0,0,5,6,0,1,4,7,0},
						 {0,0,1,0,0,8,0,9,0},
						 {0,0,0,5,2,0,0,0,0},
						 {0,1,0,8,0,0,0,0,0},
						 {0,0,6,0,0,0,0,3,0},
						 {0,3,0,9,0,2,7,4,0} };

static int mn[9][9] = { {0,6,0,1,0,4,0,5,0},
						 {0,0,8,3,0,5,6,0,0},
						 {2,0,0,0,0,0,0,0,1},
						 {8,0,0,4,0,7,0,0,6},
						 {0,0,6,0,0,0,3,0,0},
						 {7,0,0,9,0,1,0,0,4},
						 {5,0,0,0,0,0,0,0,2},
						 {0,0,7,2,0,6,9,0,0},
						 {0,4,0,5,0,8,0,7,0} };


static int op[9][9] = { {0,0,0,3,9,0,0,1,6,},
						 {5,0,1,0,0,0,0,4,0,},
						 {9,0,0,7,0,0,5,0,0,},
						 {6,0,2,5,3,0,0,7,0,},
						 {0,0,0,0,7,0,0,0,8,},
						 {7,0,0,8,0,0,9,0,3,},
						 {8,0,3,0,1,0,0,9,0,},
						 {0,9,0,2,0,6,0,0,7,},
						 {4,0,0,0,0,3,0,6,1,} };

static int qr[9][9] = { {9,0,2,0,0,0,0,5,3},
						 {0,8,0,0,0,2,0,0,0},
						 {0,0,0,0,0,4,0,0,7},
						 {2,6,3,1,0,0,0,0,9},
						 {0,0,0,9,0,0,0,6,0},
						 {0,5,0,3,0,6,0,0,2},
						 {0,0,0,0,0,0,4,0,5},
						 {0,2,8,0,0,3,0,0,0},
						 {1,0,0,0,0,0,7,0,0} };



GLfloat vertices[][3] = { {-1.5,-1.5,-1.5},{1.5,-1.5,-1.5},
{1.5,1.5,-1.5}, {-1.5,1.5,-1.5}, {-1.5,-1.5,1.5},
{1.5,-1.5,1.5}, {1.5,1.5,1.5}, {-1.5,1.5,1.5} };
GLfloat normals[][3] = { {-1.5,-1.5,-1.5},{1.5,-1.5,-1.5},
{1.5,1.5,-1.5}, {-1.5,1.5,-1.5}, {-1.5,-1.5,1.5},
{1.5,-1.5,1.5}, {1.5,1.5,1.5}, {-1.5,1.5,1.5} };
GLfloat colors[][3] = { {0.0,0.0,0.0},{1.0,0.0,0.0},
{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0} };

static GLfloat theta[] = { 0.0,0.0,0.0 };
static GLint axis = 1;
int ram = 1, pr = 0, ee = 0, e = 0;
int sudokukey = 0, ramu = 0, selgamekey = 0, tictactoekey = 0, tic = 0;
int sudoku2[9][9], sudoku3[9][9], sudoku1[9][9], red = 0;
static int no, z = 0, r;
int sudokuscore1 = 100, hint = 0;
#define UNASSIGNED 0

//tic-tac-toe variables
int player1, player2,tickname=0,tickname1=0,player1key=0,player2key=0;
static char name1[50], name2[50],empty[50];
int temp1;
static int tic1[3][3];
int f = 0, g = 0, result, gameover;
int sound = 0;

int is_exist_row(int sudoku2[9][9], int row, int num) {
	for (int col = 0; col < 9; col++) {
		if (sudoku2[row][col] == num) {
			return 1;
		}
	}
	return 0;
}

int is_exist_col(int sudoku2[9][9], int col, int num) {
	for (int row = 0; row < 9; row++) {
		if (sudoku2[row][col] == num) {
			return 1;
		}
	}
	return 0;
}

int is_exist_box(int sudoku2[9][9], int startRow, int startCol, int num) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (sudoku2[row + startRow][col + startCol] == num) {
				return 1;
			}
		}
	}
	return 0;
}

int is_safe_num(int sudoku2[9][9], int row, int col, int num) {
	return !is_exist_row(sudoku2, row, num)
		&& !is_exist_col(sudoku2, col, num)
		&& !is_exist_box(sudoku2, row - (row % 3), col - (col % 3), num);
}

int find_unassigned(int sudoku[9][9], int *row, int *col) {
	for (*row = 0; *row < 9; (*row)++) {
		for (*col = 0; *col < 9; (*col)++) {
			if (sudoku[*row][*col] == 0) {
				return 1;
			}
		}
	}
	return 0;
}

int solve(int sudoku2[9][9])
{
	int row = 0;
	int col = 0;

	if (!find_unassigned(sudoku2, &row, &col)) {
		return 1;
	}

	for (int num = 1; num <= 9; num++) {

		if (is_safe_num(sudoku2, row, col, num)) {
			sudoku2[row][col] = num;

			if (solve(sudoku2)) {
				return 1;
			}

			sudoku2[row][col] = UNASSIGNED;
		}
	}

	return 0;
}
void text(char str[])
{
	int i;
	glColor3f(1, 0, 0);
	for (i = 0; i < strlen(str); i++)
	{
		glColor3f(1, 0.4, 0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
}
void text1(int a)
{
	glColor3f(1, 0.4, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 5);

}

void text2(char str[])
{
	int i;
	for (i = 0; i < strlen(str); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}
}

void text3(char str[])
{
	int i;
	for (i = 0; i < strlen(str); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
	}
}

void text4(char str[])
{
	int i;
	for (i = 0; i < strlen(str); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
	}
}

void cover()
{
	glClearColor(0, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	sudokukey = 0;
	selgamekey = 0;
	glColor3f(0, 0, 0);
	glRasterPos3f(-2, 4, -1.0);
	text(m1);


	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-2.3, 1.75, -1.0);
	glVertex3f(0.7, 1.75, -1.0);
	glVertex3f(0.7, 2.4, -1.0);
	glVertex3f(-2.3, 2.4, -1.0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-2.3, 0.75, -1.0);
	glVertex3f(0.7, 0.75, -1.0);
	glVertex3f(0.7, 1.4, -1.0);
	glVertex3f(-2.3, 1.4, -1.0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-2.3, -0.25, -1.0);
	glVertex3f(0.7, -0.25, -1.0);
	glVertex3f(0.7, 0.4, -1.0);
	glVertex3f(-2.3, 0.4, -1.0);
	glEnd();

	if (ramu == 0)
	{
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-2.3, 1.75, -1.0);
		glVertex3f(0.7, 1.75, -1.0);
		glVertex3f(0.7, 2.4, -1.0);
		glVertex3f(-2.3, 2.4, -1.0);
		glEnd();
	}
	else if (ramu == 1)
	{
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-2.3, 0.75, -1.0);
		glVertex3f(0.7, 0.75, -1.0);
		glVertex3f(0.7, 1.4, -1.0);
		glVertex3f(-2.3, 1.4, -1.0);
		glEnd();

	}
	else if (ramu == 2)
	{
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-2.3, -0.25, -1.0);
		glVertex3f(0.7, -0.25, -1.0);
		glVertex3f(0.7, 0.4, -1.0);
		glVertex3f(-2.3, 0.4, -1.0);
		glEnd();
	}
	if (sound == 0)
	{
		static char m110[] = { "SOUND ON" };
		glColor3f(1.0, 0.0, 0);
		glRasterPos3f(5.5, 4, -1.0);
		text(m110);
		static char m113[] = { "PRESS a TO TURN OFF SOUND" };
		glColor3f(0, 0, 0);
		glRasterPos3f(5, 3.7, -1.0);
		text3(m113);
	}
	else if (sound == 1)
	{
		static char m111[] = { "SOUND OFF" };
		glColor3f(1, 0.0, 0);
		glRasterPos3f(5.5, 4, -1.0);
		text(m111);

		static char m112[] = { "PRESS a TO TURN ON SOUND" };
		glColor3f(0, 0, 0);
		glRasterPos3f(5,3.7, -1.0);
		text3(m112);
	}

	static char m11[] = { "GAME INFO" };
	glColor3f(1.0, 0.0, 0);
	glRasterPos3f(-2.0, 0, -1.0);
	text(m11);
	static char m12[] = { "HELP" };
	glColor3f(1.0, 0.0, 0);
	glRasterPos3f(-2.0, 1, -1.0);
	text(m12);
	static char m13[] = { "SELECT GAME" };
	glColor3f(1.0, 0.0, 0);
	glRasterPos3f(-2.0, 2, -1.0);
	text(m13);
	static char m59[] = { "PRESS s TO SELECT" };
	glColor3f(0, 0, 0);
	glRasterPos3f(-2.0, -3.5, -1.0);
	text3(m59);
	static char m19[] = { "PRESS q TO QUIT" };
	glColor3f(0, 0, 0);
	glRasterPos3f(-2.0, -4, -1.0);
	text3(m19);
	glFlush();
	glutSwapBuffers();
}
void demo()
{
	glClearColor(0, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glColor3f(0, 0, 0);
	glRasterPos3f(-2, 4, -1.0);
	text(m1);

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-2.3, 0.75, -1.0);
	glVertex3f(0.7, 0.75, -1.0);
	glVertex3f(0.7, 1.4, -1.0);
	glVertex3f(-2.3, 1.4, -1.0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-2.3, -0.25, -1.0);
	glVertex3f(0.7, -0.25, -1.0);
	glVertex3f(0.7, 0.4, -1.0);
	glVertex3f(-2.3, 0.4, -1.0);
	glEnd();


	if (ramu == 0)
	{
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-2.3, 0.75, -1.0);
		glVertex3f(0.7, 0.75, -1.0);
		glVertex3f(0.7, 1.4, -1.0);
		glVertex3f(-2.3, 1.4, -1.0);
		glEnd();

	}
	else if (ramu == 1)
	{
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-2.3, -0.25, -1.0);
		glVertex3f(0.7, -0.25, -1.0);
		glVertex3f(0.7, 0.4, -1.0);
		glVertex3f(-2.3, 0.4, -1.0);
		glEnd();
	}

	glColor3f(1.0, 0.0, 0);
	glRasterPos3f(-2.0, 0, -1.0);
	text(m9);

	glColor3f(1.0, 0.0, 0);
	glRasterPos3f(-2.0, 1, -1.0);
	text(m6);

	static char m59[] = { "PRESS s TO SELECT" };
	glColor3f(0, 0, 0);
	glRasterPos3f(-2.0, -3.5, -1.0);
	text3(m59);
	static char m19[] = { "PRESS q TO QUIT" };
	glColor3f(0, 0, 0);
	glRasterPos3f(-2.0, -4, -1.0);
	text3(m19);

	glFlush();
	glutSwapBuffers();
}
void info()
{
	glClearColor(0, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	sudokukey = 0;
	if (sound == 0)
	PlaySound(TEXT("infosound.wav"), NULL, SND_ASYNC | SND_FILENAME);
	static char m23[] = { "DEVELOPED BY:-" };
	glColor3f(1.0, 0.0, 0);
	glRasterPos3f(-2, 4, -1.0);
	text(m23);

	static char m22[] = { "SRIRAM G N" };
	glColor3f(0,0,0);
	glRasterPos3f(-2.0, 1, -1.0);
	text(m22);
	static char m24[] = { "1CG16CS097" };
	glColor3f(0, 0, 1);
	glRasterPos3f(-2.0, 0.5, -1.0);
	text2(m24);

	static char m21[] = { "and" };
	glColor3f(1.0, 0.0, 0);
	glRasterPos3f(-1.5, -0.25, -1.0);
	text2(m21);

	static char m20[] = { "PRAVEEN G" };
	glColor3f(0,0,0);
	glRasterPos3f(-2.0, -1, -1.0);
	text(m20);
	static char m25[] = { "1CG16CS072" };
	glColor3f(0, 0, 1);
	glRasterPos3f(-2.0, -1.5, -1.0);
	text2(m25);

	static char m19[] = { "press n to go back" };
	glColor3f(0, 0, 0);
	glRasterPos3f(-2.0, -4, -1.0);
	text3(m19);
	glFlush();
	glutSwapBuffers();
}
void help()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	sudokukey = 0;
	glColor3f(0, 0, 0);
	glRasterPos3f(-1.5, 4, -1.0);
	text(m1);


	static char m23[] = { "RULES OF SUDOKU" };
	glColor3f(1.0, 0.0, 0);
	glRasterPos3f(-6.5, 3, -1.0);
	text(m23);


	static char m24[] = { " Fill in the empty cells!" };
	glColor3f(0, 0, 0);
	glRasterPos3f(-8.5, 1, -1.0);
	text2(m24);

	static char m21[] = { "No repeats are allowed in any row, column, or block." };
	glColor3f(0, 0, 0);
	glRasterPos3f(-8.5, 0, -1.0);
	text2(m21);

	static char m20[] = { "You must use all nine numbers in each row, column, and block." };
	glColor3f(0, 0, 0);
	glRasterPos3f(-8.5, -1, -1.0);
	text2(m20);


	static char m33[] = { "RULES OF TIC-TAC-TOE " };
	glColor3f(1.0, 0.0, 0);
	glRasterPos3f(2, 3, -1.0);
	text(m33);


	static char m34[] = { "The object of Tic Tac Toe is to get three in a row." };
	glColor3f(0, 0, 0);
	glRasterPos3f(1.5, 1, -1.0);
	text2(m34);

	static char m31[] = { "You play on a three by three game board." };
	glColor3f(0, 0, 0);
	glRasterPos3f(1.5, 0, -1.0);
	text2(m31);

	static char m30[] = { "The first player is known as X and the second is O." };
	glColor3f(0, 0, 0);
	glRasterPos3f(1.5, -1, -1.0);
	text2(m30);


	static char m37[] = { "Players alternate placing Xs and Os on the game board " };
	glColor3f(0, 0, 0);
	glRasterPos3f(1.5, -2, -1.0);
	text2(m37);

	static char m38[] = { "Until either oppent has three in a row or all nine squares are filled. " };
	glColor3f(0, 0, 0);
	glRasterPos3f(1.5, -3, -1.0);
	text2(m38);

	static char m39[] = { "press n to go back" };
	glColor3f(0, 0, 0);
	glRasterPos3f(-2.0, -4, -1.0);
	text3(m39);

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, 3.5);
	glVertex2f(0, -3);

	glEnd();

	glFlush();
	glutSwapBuffers();
}
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
	glutPostRedisplay(); // request redisplay
}







int gameover1 = 0;
void soltictac()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 0);

	glRasterPos3f(-2, 4, -1.0);
	text(m9);

	glBegin(GL_LINES);
	glVertex2f(-2.5, 3.3);
	glVertex2f(-2.5, -3.3);
	glVertex2f(1.5, 3.3);
	glVertex2f(1.5, -3.3);

	glVertex2f(-4.5, 1);
	glVertex2f(3.5, 1);
	glVertex2f(-4.5, -1.5);
	glVertex2f(3.5, -1.5);
	glEnd();

	if (f == 0 && g == 0)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(-4.3, 1.2);
		glVertex2f(-4.3, 3);
		glVertex2f(-2.8, 3);
		glVertex2f(-2.8, 1.2);
		glEnd();
	}
	else if (f == 0 && g == 1)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(-2.3, 1.2);
		glVertex2f(-2.3, 3);
		glVertex2f(1.3, 3);
		glVertex2f(1.3, 1.2);
		glEnd();
	}
	else if (f == 0 && g == 2)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(1.7, 1.2);
		glVertex2f(1.7, 3);
		glVertex2f(3.3, 3);
		glVertex2f(3.3, 1.2);
		glEnd();
	}
	else if (f == 1 && g == 0)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(-4.3, -1.3);
		glVertex2f(-4.3, 0.8);
		glVertex2f(-2.8, 0.8);
		glVertex2f(-2.8, -1.3);
		glEnd();
	}
	else if (f == 1 && g == 1)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(-2.3, -1.3);
		glVertex2f(-2.3, 0.8);
		glVertex2f(1.3, 0.8);
		glVertex2f(1.3, -1.3);
		glEnd();
	}
	else if (f == 1 && g == 2)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(1.7, -1.3);
		glVertex2f(1.7, 0.8);
		glVertex2f(3.3, 0.8);
		glVertex2f(3.3, -1.3);
		glEnd();
	}
	else if (f == 2 && g == 0)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(-4.3, -3.1);
		glVertex2f(-4.3, -1.7);
		glVertex2f(-2.8, -1.7);
		glVertex2f(-2.8, -3.1);
		glEnd();
	}
	else if (f == 2 && g == 1)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(-2.3, -3.1);
		glVertex2f(-2.3, -1.7);
		glVertex2f(1.3, -1.7);
		glVertex2f(1.3, -3.1);
		glEnd();
	}
	else if (f == 2 && g == 2)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(1.7, -3.1);
		glVertex2f(1.7, -1.7);
		glVertex2f(3.3, -1.7);
		glVertex2f(3.3, -3.1);
		glEnd();
	}

	//player1 o print 
	if (player1 == 1 && tic == 1 && tic1[f][g] == 0)
	{
		if (sound == 0)
		{

			PlaySound(TEXT("tic2sel.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		player2 = 1; player1 = 0;
		glLineWidth(1);
		if (f == 0 && g == 0)
		{
			glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslated(-3.55, 2, -1.0);
			glutWireTorus(0.05, 0.8, 5, 50);
			glPopMatrix();
		}
		else if (f == 0 && g == 1)
		{
			glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslated(-0.5, 2, -1.0);
			glutWireTorus(0.05, 0.8, 5, 50);
			glPopMatrix();
		}
		else if (f == 0 && g == 2)
		{
			glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslated(3, 2, -1.0);
			glutWireTorus(0.05, 0.8, 5, 50);
			glPopMatrix();
		}
		else if (f == 1 && g == 0)
		{
			glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslated(-3.55, -0.3, -1.0);
			glutWireTorus(0.05, 0.8, 5, 50);
			glPopMatrix();
		}
		else if (f == 1 && g == 1)
		{
			glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslated(-0.5, -0.3, -1.0);
			glutWireTorus(0.05, 0.8, 5, 50);
			glPopMatrix();
		}
		else if (f == 1 && g == 2)
		{
			glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslated(3, -0.3, -1.0);
			glutWireTorus(0.05, 0.8, 5, 50);
			glPopMatrix();
		}
		else if (f == 2 && g == 0)
		{
			glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslated(-3.55, -2.7, -1.0);
			glutWireTorus(0.05, 0.8, 5, 50);
			glPopMatrix();
		}
		else if (f == 2 && g == 1)
		{
			glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslated(-0.5, -2.7, -1.0);
			glutWireTorus(0.05, 0.8, 5, 50);
			glPopMatrix();
		}
		else if (f == 2 && g == 2)
		{
			glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslated(3, -2.7, -1.0);
			glutWireTorus(0.05, 0.8, 5, 50);
			glPopMatrix();
		}
		tic1[f][g] = 1;
		tic = 0;
	}














	if (player2 == 1 && tic == 1 && tic1[f][g] == 0)
	{
		if (sound == 0)
		{
			PlaySound(TEXT("tic1sel.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		player2 = 0; player1 = 1;
		glLineWidth(5);
		if (f == 0 && g == 0)
		{
			glColor3f(1, 0, 0);
			glBegin(GL_LINES);
			glVertex2f(-4.3, 1.2);
			glVertex2f(-2.8, 3);
			glVertex2f(-4.3, 3);
			glVertex2f(-2.8, 1.2);
			glEnd();
		}
		else if (f == 0 && g == 1)
		{
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex2f(-1.3, 1.2);
			glVertex2f(0.3, 3);
			glVertex2f(-1.3, 3);

			glVertex2f(0.3, 1.2);
			glEnd();
		}
		else if (f == 0 && g == 2)
		{
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex2f(1.7, 1.2);
			glVertex2f(3.3, 3);
			glVertex2f(1.7, 3);

			glVertex2f(3.3, 1.2);
			glEnd();
		}
		else if (f == 1 && g == 0)
		{
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex2f(-4.3, -1.3);
			glVertex2f(-2.8, 0.8);
			glVertex2f(-4.3, 0.8);

			glVertex2f(-2.8, -1.3);
			glEnd();
		}
		else if (f == 1 && g == 1)
		{
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex2f(-1.3, -1.3);
			glVertex2f(0.3, 0.8);
			glVertex2f(-1.3, 0.8);

			glVertex2f(0.3, -1.3);
			glEnd();
		}
		else if (f == 1 && g == 2)
		{
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex2f(1.7, -1.3);
			glVertex2f(3.3, 0.8);
			glVertex2f(1.7, 0.8);

			glVertex2f(3.3, -1.3);
			glEnd();
		}
		else if (f == 2 && g == 0)
		{
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex2f(-4.3, -3.5);
			glVertex2f(-2.8, -1.7);
			glVertex2f(-4.3, -1.7);

			glVertex2f(-2.8, -3.5);
			glEnd();
		}
		else if (f == 2 && g == 1)
		{
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex2f(-1.3, -3.5);
			glVertex2f(0.3, -1.7);
			glVertex2f(-1.3, -1.7);

			glVertex2f(0.3, -3.5);
			glEnd();
		}
		else if (f == 2 && g == 2)
		{
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex2f(1.7, -3.5);
			glVertex2f(3.3, -1.7);
			glVertex2f(1.7, -1.7);
			glVertex2f(3.3, -3.5);
			glEnd();
		}
		tic1[f][g] = 2;
		tic = 0;
		glLineWidth(1);

	}




















	static char m19[] = { "press n to go back" };
	glColor3f(0, 0, 0);
	glRasterPos3f(-2.0, -4, -1.0);
	text3(m19);

	if((player1!=0 || player2!=0 ) && gameover1==9)
	{
		if (sound == 0)
		{
			PlaySound(TEXT("ticgameover.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
	glColor3f(1, 1,0);
	static char m42[] = { "GAME OVER!!!" };
	glRasterPos3f(6, 3, -1.0);
	text(m42);
	}

	else	if (player1 == 1 && gameover1<10)
	{
	
		if (player1key == 1)
		{
			char name1f[50];
			strcpy_s(name1f, name1);
			strcat_s(name1f, " 'S TURN ");
			glColor3f(1, 0, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name1f);
		}
		else
		{
			glColor3f(1, 0, 0);
			static char m41[] = { " TURN:  PLAYER 1 " };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	else if (player2 == 1 && gameover1<10)
	{
	
		if (player2key == 1)
		{
			char name2f[50];
			strcpy_s(name2f, name2);
			strcat_s(name2f, " 'S TURN ");
			glColor3f(0, 0, 1);
			glRasterPos3f(6, 3, -1.0);
			text(name2f);
		}
		else
		{
			glColor3f(0, 0, 1);
			static char m42[] = { "TURN:  PLAYER 2" };
			glRasterPos3f(6, 3, -1.0);
			text(m42);
		}

	}
	


	//O for already in 
	if (tic1[0][0] == 1)
	{
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(-3.55, 2, -1.0);
		glutWireTorus(0.05, 0.8, 5, 50);
		glPopMatrix();
	}
	if (tic1[0][1] == 1)
	{
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(-0.5, 2, -1.0);
		glutWireTorus(0.05, 0.8, 5, 50);
		glPopMatrix();
	}
	if (tic1[0][2] == 1)
	{
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(3, 2, -1.0);
		glutWireTorus(0.05, 0.8, 5, 50);
		glPopMatrix();
	}
	if (tic1[1][0] == 1)
	{
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(-3.55, -0.3, -1.0);
		glutWireTorus(0.05, 0.8, 5, 50);
		glPopMatrix();
	}
	if (tic1[1][1] == 1)
	{
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(-0.5, -0.3, -1.0);
		glutWireTorus(0.05, 0.8, 5, 50);
		glPopMatrix();
	}
	if (tic1[1][2] == 1)
	{
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(3, -0.3, -1.0);
		glutWireTorus(0.05, 0.8, 5, 50);
		glPopMatrix();
	}
	if (tic1[2][0] == 1)
	{
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(-3.55, -2.7, -1.0);
		glutWireTorus(0.05, 0.8, 5, 50);
		glPopMatrix();
	}
	if (tic1[2][1] == 1)
	{
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(-0.5, -2.7, -1.0);
		glutWireTorus(0.05, 0.8, 5, 50);
		glPopMatrix();
	}
	if (tic1[2][2] == 1)
	{
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(3, -2.7, -1.0);
		glutWireTorus(0.05, 0.8, 5, 50);
		glPopMatrix();
	}


	// Xfor already 
	glLineWidth(5);
	if (tic1[0][0] == 2)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-4.3, 1.2);
		glVertex2f(-2.8, 3);
		glVertex2f(-4.3, 3);
		glVertex2f(-2.8, 1.2);
		glEnd();
	}
	if (tic1[0][1] == 2)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-1.3, 1.2);
		glVertex2f(0.3, 3);
		glVertex2f(-1.3, 3);

		glVertex2f(0.3, 1.2);
		glEnd();
	}
	if (tic1[0][2] == 2)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(1.7, 1.2);
		glVertex2f(3.3, 3);
		glVertex2f(1.7, 3);

		glVertex2f(3.3, 1.2);
		glEnd();
	}
	if (tic1[1][0] == 2)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-4.3, -1.3);
		glVertex2f(-2.8, 0.8);
		glVertex2f(-4.3, 0.8);

		glVertex2f(-2.8, -1.3);
		glEnd();
	}
	if (tic1[1][1] == 2)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-1.3, -1.3);
		glVertex2f(0.3, 0.8);
		glVertex2f(-1.3, 0.8);

		glVertex2f(0.3, -1.3);
		glEnd();
	}
	if (tic1[1][2] == 2)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(1.7, -1.3);
		glVertex2f(3.3, 0.8);
		glVertex2f(1.7, 0.8);

		glVertex2f(3.3, -1.3);
		glEnd();
	}
	if (tic1[2][0] == 2)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-4.3, -3.5);
		glVertex2f(-2.8, -1.7);
		glVertex2f(-4.3, -1.7);

		glVertex2f(-2.8, -3.5);
		glEnd();
	}
	if (tic1[2][1] == 2)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-1.3, -3.5);
		glVertex2f(0.3, -1.7);
		glVertex2f(-1.3, -1.7);

		glVertex2f(0.3, -3.5);
		glEnd();
	}
	if (tic1[2][2] == 2)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(1.7, -3.5);
		glVertex2f(3.3, -1.7);
		glVertex2f(1.7, -1.7);
		glVertex2f(3.3, -3.5);
		glEnd();
	}



	if (tic1[0][0] == 1 && tic1[0][1] == 1 && tic1[0][2] == 1)
	{
		if (sound == 0)
		{
			PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name1f[50];
			strcpy_s(name1f, name1);
			strcat_s(name1f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name1f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 1 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	if (tic1[1][0] == 1 && tic1[1][1] == 1 && tic1[1][2] == 1)
	{
		if (sound == 0)
		{
			PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name1f[50];
			strcpy_s(name1f, name1);
			strcat_s(name1f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name1f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 1 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	if (tic1[2][0] == 1 && tic1[2][1] == 1 && tic1[2][2] == 1)
	{
		if (sound == 0)
		{
			PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name1f[50];
			strcpy_s(name1f, name1);
			strcat_s(name1f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name1f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 1 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}//rows 1st player


	if (tic1[0][0] == 1 && tic1[1][0] == 1 && tic1[2][0] == 1)
	{
		if(sound==0)
			PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name1f[50];
			strcpy_s(name1f, name1);
			strcat_s(name1f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name1f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 1 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	if (tic1[0][1] == 1 && tic1[1][1] == 1 && tic1[2][1] == 1)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name1f[50];
			strcpy_s(name1f, name1);
			strcat_s(name1f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name1f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 1 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	if (tic1[0][2] == 1 && tic1[1][2] == 1 && tic1[2][2] == 1)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name1f[50];
			strcpy_s(name1f, name1);
			strcat_s(name1f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name1f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 1 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	//coloms player 1 completed






	if (tic1[0][0] == 2 && tic1[0][1] == 2 && tic1[0][2] == 2)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name2f[50];
			strcpy_s(name2f, name2);
			strcat_s(name2f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name2f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 2 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}

	if (tic1[1][0] == 2 && tic1[1][1] == 2 && tic1[1][2] == 2)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name2f[50];
			strcpy_s(name2f, name2);
			strcat_s(name2f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name2f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 2 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	if (tic1[2][0] == 2 && tic1[2][1] == 2 && tic1[2][2] == 2)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name2f[50];
			strcpy_s(name2f, name2);
			strcat_s(name2f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name2f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 2 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	//player 2 rows


	if (tic1[0][0] == 2 && tic1[1][0] == 2 && tic1[2][0] == 2)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name2f[50];
			strcpy_s(name2f, name2);
			strcat_s(name2f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name2f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 2 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	if (tic1[0][1] == 2 && tic1[1][1] == 2 && tic1[2][1] == 2)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name2f[50];
			strcpy_s(name2f, name2);
			strcat_s(name2f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name2f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 2 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	if (tic1[0][2] == 2 && tic1[1][2] == 2 && tic1[2][2] == 2)
	{
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name2f[50];
			strcpy_s(name2f, name2);
			strcat_s(name2f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name2f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 2 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	//player 2 columns


	if (tic1[0][0] == 2 && tic1[1][1] == 2 && tic1[2][2] == 2)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name2f[50];
			strcpy_s(name2f, name2);
			strcat_s(name2f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name2f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 2 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	//dia player 2
	if (tic1[0][0] == 1 && tic1[1][1] == 1 && tic1[2][2] == 1)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name1f[50];
			strcpy_s(name1f, name1);
			strcat_s(name1f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name1f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 1 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}
	//dia player 1


	if (tic1[0][2] == 1 && tic1[1][1] == 1 && tic1[2][0] == 1)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name1f[50];
			strcpy_s(name1f, name1);
			strcat_s(name1f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name1f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 1 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}

	if (tic1[0][2] == 2 && tic1[1][1] == 2 && tic1[2][0] == 2)
	{
		if (sound == 0)
		PlaySound(TEXT("ticwin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		player1 = 0; player2 = 0;
		if (player1key == 1)
		{
			char name2f[50];
			strcpy_s(name2f, name2);
			strcat_s(name2f, " WINS  ");
			glColor3f(1, 1, 0);
			glRasterPos3f(6, 3, -1.0);
			text(name2f);
		}
		else
		{
			glColor3f(1, 1, 0);
			static char m41[] = { "PLAYER 2 WINS" };
			glRasterPos3f(6, 3, -1.0);
			text(m41);
		}
	}

	static char m79[] = { "PRESS n TO GO BACK" };
	glColor3f(1, 1, 1);
	glRasterPos3f(6, 0, -1.0);
	text3(m19);
	static char m18[] = { "PRESS m TO RESET TIC TAC TOE" };
	glColor3f(1, 1, 1);
	glRasterPos3f(6, 0.5, -1.0);
	text3(m18);
	glLineWidth(1);
	glFlush();
	glutSwapBuffers();
}















void tictac()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sudokukey = 0;
	tictactoekey = 1;
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 0);

	glRasterPos3f(-2, 4, -1.0);
	text(m9);

	glBegin(GL_LINES);
	glVertex2f(-2.5, 3.3);
	glVertex2f(-2.5, -3.3);
	glVertex2f(1.5, 3.3);
	glVertex2f(1.5, -3.3);

	glVertex2f(-4.5, 1);
	glVertex2f(3.5, 1);
	glVertex2f(-4.5, -1.5);
	glVertex2f(3.5, -1.5);
	glEnd();
	player1 = 1;
	player2 = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			tic1[i][j] = 0;
		}
	}
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(-4.3, 1.2);
	glVertex2f(-4.3, 3);
	glVertex2f(-2.8, 3);
	glVertex2f(-2.8, 1.2);
	glEnd();
	f = 0, g = 0;
	if (tickname == 0)
	{
		static char m79[] = { "PRESS n TO GO BACK" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, 0, -1.0);
		text3(m79);
		static char m18[] = { "PRESS m TO RESET TIC TAC TOE" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, 0.5, -1.0);
		text3(m18);
		static char m21[] = { "PRESS y TO GIVE PLAYERS NAME" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, -0.5, -1.0);
		text3(m21);
	
		glColor3f(1, 0, 0);
		static char m41[] = { " TURN:  PLAYER 1 " };
		glRasterPos3f(6, 3, -1.0);
		text(m41);
	}


	else if (tickname1 == 1)
	{
		static char m118[] = { "ENTER THE PLAYER 2 NAME " };
		glColor3f(1, 0, 0);
		glRasterPos3f(6, 4, -1.0);
		text2(m118);
		if (temp1 == 1)
		{
			strcat_s(name2, "A");

		}
		else if (temp1 == 2)
		{
			strcat_s(name2, "B");
		}
		else if (temp1 == 3)
		{
			strcat_s(name2, "C");
		}
		else if (temp1 == 4)
		{
			strcat_s(name2, "D");
		}
		else if (temp1 == 5)
		{
			strcat_s(name2, "E");
		}
		else if (temp1 == 6)
		{
			strcat_s(name2, "F");
		}
		else if (temp1 == 7)
		{
			strcat_s(name2, "G");
		}
		else if (temp1 == 8)
		{
			strcat_s(name2, "H");
		}
		else if (temp1 == 9)
		{
			strcat_s(name2, "I");
		}
		else if (temp1 == 10)
		{
			strcat_s(name2, "J");
		}
		else if (temp1 == 11)
		{
			strcat_s(name2, "K");
		}
		else if (temp1 == 12)
		{
			strcat_s(name2, "L");
		}
		else if (temp1 == 13)
		{
			strcat_s(name2, "M");
		}
		else if (temp1 == 14)
		{
			strcat_s(name2, "N");
		}
		else if (temp1 == 15)
		{
			strcat_s(name2, "O");
		}
		else if (temp1 == 16)
		{
			strcat_s(name2, "P");
		}
		else if (temp1 == 17)
		{
			strcat_s(name2, "Q");
		}
		else if (temp1 == 18)
		{
			strcat_s(name2, "R");
		}
		else if (temp1 == 19)
		{
			strcat_s(name2, "S");
		}
		else if (temp1 == 20)
		{
			strcat_s(name2, "T");
		}
		else if (temp1 == 21)
		{
			strcat_s(name2, "U");
		}
		else if (temp1 == 22)
		{
			strcat_s(name2, "V");
		}
		else if (temp1 == 23)
		{
			strcat_s(name2, "W");
		}
		else if (temp1 == 24)
		{
			strcat_s(name2, "X");
		}
		else if (temp1 == 25)
		{
			strcat_s(name2, "Y");
		}
		else if (temp1 == 26)
		{
			strcat_s(name2, "Z");
		}
		glColor3f(1, 1, 0);
		glRasterPos3f(6, 3, -1.0);
		text(name2);
		temp1 = 0;
		static char m79[] = {"PRESS 1 TO GO BACK"};
		glColor3f(1, 1, 1);
		glRasterPos3f(6, 0, -1.0);
		text3(m79);

		static char m18[] = { "PRESS 9 TO START GAME" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, -0.5, -1.0);
		text3(m18);
	}


	else if (tickname == 1)
	{
		static char m118[] = { "ENTER THE PLAYER 1 NAME" };
		glColor3f(1, 0, 0);
		glRasterPos3f(6, 4, -1.0);
		text2(m118);
		if (temp1 == 1)
		{
			strcat_s(name1,"A");
			
		}
		else if(temp1 == 2)
		{
			strcat_s(name1, "B");
		}
		else if (temp1 == 3)
		{
			strcat_s(name1, "C");
		}
		else if (temp1 == 4)
		{
			strcat_s(name1, "D");
		}
		else if (temp1 == 5)
		{
			strcat_s(name1, "E");
		}
		else if (temp1 == 6)
		{
			strcat_s(name1, "F");
		}
		else if (temp1 == 7)
		{
			strcat_s(name1, "G");
		}
		else if (temp1 == 8)
		{
			strcat_s(name1, "H");
		}
		else if (temp1 == 9)
		{
			strcat_s(name1, "I");
		}
		else if (temp1 == 10)
		{
			strcat_s(name1,"J");
		}
		else if (temp1 == 11)
		{
			strcat_s(name1, "K");
		}
		else if (temp1 == 12)
		{
			strcat_s(name1, "L");
		}
		else if (temp1 == 13)
		{
			strcat_s(name1, "M");
		}
		else if (temp1 == 14)
		{
			strcat_s(name1, "N");
		}
		else if (temp1 == 15)
		{
			strcat_s(name1, "O");
		}
		else if (temp1 == 16)
		{
			strcat_s(name1, "P");
		}
		else if (temp1 == 17)
		{
			strcat_s(name1, "Q");
		}
		else if (temp1 == 18)
		{
			strcat_s(name1, "R");
		}
		else if (temp1 == 19)
		{
			strcat_s(name1, "S");
		}
		else if (temp1 == 20)
		{
			strcat_s(name1, "T");
		}
		else if (temp1 == 21)
		{
			strcat_s(name1, "U");
		}
		else if (temp1 == 22)
		{
			strcat_s(name1, "V");
		}
		else if (temp1 == 23)
		{
			strcat_s(name1, "W");
		}
		else if (temp1 == 24)
		{
			strcat_s(name1, "X");
		}
		else if (temp1 == 25)
		{
			strcat_s(name1, "Y");
		}
		else if (temp1 == 26)
		{
			strcat_s(name1,"Z");
		}
		glColor3f(1, 1, 0);
		glRasterPos3f(6, 3, -1.0);
		text(name1);
		temp1 = 0;
		static char m79[] = { "PRESS 1 TO GO BACK" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, 0, -1.0);
		text3(m79);
		
		static char m18[] = { "PRESS 9 TO GIVE PLAYER 2 NAME" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, -0.5, -1.0);
		text3(m18);
	}


	glFlush();
	glutSwapBuffers();
}













































//user given sudoku 
void newsudoku()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glRasterPos3f(-0.8, 4.5, -1.0);
	text(m6);
	glColor3f(1.0, 0.0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-4.5, 3);
	glVertex2f(-4.5, -3.3);
	glVertex2f(4.5, -3.3);
	glVertex2f(4.5, 3);
	glColor3f(0.0, 0.0, 1.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-4.5, 2.3);
	glVertex2f(4.5, 2.3);
	glVertex2f(-4.5, 1.6);
	glVertex2f(4.5, 1.6);
	glColor3f(1, 0.0, 0);
	glVertex2f(-4.5, 0.9);
	glVertex2f(4.5, 0.9);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-4.5, 0.2);
	glVertex2f(4.5, 0.2);
	glVertex2f(-4.5, -0.5);
	glVertex2f(4.5, -0.5);
	glColor3f(1, 0.0, 0);
	glVertex2f(-4.5, -1.2);
	glVertex2f(4.5, -1.2);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-4.5, -1.9);
	glVertex2f(4.5, -1.9);
	glVertex2f(-4.5, -2.6);
	glVertex2f(4.5, -2.6);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-3.5, 3);
	glVertex2f(-3.5, -3.3);
	glVertex2f(-2.5, 3);
	glVertex2f(-2.5, -3.3);
	glColor3f(1.0, 0.0, 0);
	glVertex2f(-1.5, 3);
	glVertex2f(-1.5, -3.3);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.5, 3);
	glVertex2f(-0.5, -3.3);
	glVertex2f(0.5, 3);
	glVertex2f(0.5, -3.3);
	glColor3f(1.0, 0.0, 0);
	glVertex2f(1.5, 3);
	glVertex2f(1.5, -3.3);
	glColor3f(0, 0.0, 1.0);
	glVertex2f(2.5, 3);
	glVertex2f(2.5, -3.3);
	glVertex2f(3.5, 3);
	glVertex2f(3.5, -3.3);
	glEnd();


	if (gotanswer == 1)
	{
		solve(sudoku1);
		glColor3f(0.0, 0.5, 0.1);
		char message[] = { "cv" };
		int  len;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				glRasterPos2f(-4 + i, 2.5 - j + (j*0.3));
				sprintf_s(message, "%d", sudoku1[j][i]);
				len = (int)strlen(message);
				for (int i = 0; i < len; i++)
				{
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
				}
			}
		}
		static char m16[] = { "ANSWER FOR YOUR SUDOKU" };
		glColor3f(1.0, 1.0, 0.0);
		glRasterPos3f(-4.35, -4, -1.0);
		text(m16);
		static char m48[] = { "FILL THE BOXES WITH APPROPRIATE NUMBERS" };
		glColor3f(1, 1, 1);
		glRasterPos3f(5.2, 0.5, -1.0);
		text3(m48);
	}

	else if(sudokuenable==0)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				sudoku1[i][j] = 0;
			}
		}
		char message[] = { "cv" };
		int  len;
		glRasterPos2f(3.5, -3.3);
		glColor3f(0.0, 0.5, 0.1);
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				glRasterPos2f(-4 + i, 2.5 - j + (j*0.3));
				sprintf_s(message, "%d", sudoku1[j][i]);
				len = (int)strlen(message);
				for (int i = 0; i < len; i++)
					{
						glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
					}
			}
		}
		sudokuenable = 1;
		static char m19[] = { "PRESS n TO GO BACK" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, 0, -1.0);
		text3(m19);
		static char m18[] = { "PRESS s TO GET ANSWER" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, 0.5, -1.0);
		text3(m18);
		static char m48[] = { "FILL THE BOXES WITH APPROPRIATE NUMBERS" };
		glColor3f(1, 1, 1);
		glRasterPos3f(5.2, 1, -1.0);
		text3(m48);
		
	}

	else if (sudokuenable == 1)
	{
		char message[] = { "cv" };
		int  len;
		if (red == 1)
		{
			sudoku1[m][n] = no;
		}
		red = 0;
		glRasterPos2f(3.5, -3.3);
		glColor3f(0.0, 0.5, 0.1);
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				glRasterPos2f(-4 + i, 2.5 - j + (j*0.3));
				sprintf_s(message, "%d", sudoku1[j][i]);
				len = (int)strlen(message);
				for (int i = 0; i < len; i++)
				{
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
				}
			}
		}
		static char m19[] = { "PRESS n TO GO BACK" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, 0, -1.0);
		text3(m19);
		static char m18[] = { "PRESS s TO GET ANSWER" };
		glColor3f(1, 1, 1);
		glRasterPos3f(6, 0.5, -1.0);
		text3(m18);
		static char m48[] = { "FILL THE BOXES WITH APPROPRIATE NUMBERS" };
		glColor3f(1, 1, 1);
		glRasterPos3f(5.2, 1, -1.0);
		text3(m48);
	}


	char message[] = { "cv" };
	int  len;
	int r[5];
	r[1] =sudoku1[m][n];
	glRasterPos2f(-4, 2.5);
	sprintf_s(message, "%d", r[1]);
	len = (int)strlen(message);
	for (int i = 0; i < len; i++)
	{
		glColor3f(1.0, 0, 0.0);
		glRasterPos2f(-4 + n, 2.5 - m + (m*0.3));
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
	}

	glFlush();
	glutSwapBuffers();
}







void solvesudoku()
{
	if (sound == 0)
	PlaySound(TEXT("sudoku _clock.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glRasterPos3f(-0.8, 4.5, -1.0);
	text(m6);
	glColor3f(1.0, 0.0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-4.5, 3);
	glVertex2f(-4.5, -3.3);
	glVertex2f(4.5, -3.3);
	glVertex2f(4.5, 3);
	glColor3f(0.0, 0.0, 1.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-4.5, 2.3);
	glVertex2f(4.5, 2.3);
	glVertex2f(-4.5, 1.6);
	glVertex2f(4.5, 1.6);
	glColor3f(1, 0.0, 0);
	glVertex2f(-4.5, 0.9);
	glVertex2f(4.5, 0.9);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-4.5, 0.2);
	glVertex2f(4.5, 0.2);
	glVertex2f(-4.5, -0.5);
	glVertex2f(4.5, -0.5);
	glColor3f(1, 0.0, 0);
	glVertex2f(-4.5, -1.2);
	glVertex2f(4.5, -1.2);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-4.5, -1.9);
	glVertex2f(4.5, -1.9);
	glVertex2f(-4.5, -2.6);
	glVertex2f(4.5, -2.6);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-3.5, 3);
	glVertex2f(-3.5, -3.3);
	glVertex2f(-2.5, 3);
	glVertex2f(-2.5, -3.3);
	glColor3f(1.0, 0.0, 0);
	glVertex2f(-1.5, 3);
	glVertex2f(-1.5, -3.3);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.5, 3);
	glVertex2f(-0.5, -3.3);
	glVertex2f(0.5, 3);
	glVertex2f(0.5, -3.3);
	glColor3f(1.0, 0.0, 0);
	glVertex2f(1.5, 3);
	glVertex2f(1.5, -3.3);
	glColor3f(0, 0.0, 1.0);
	glVertex2f(2.5, 3);
	glVertex2f(2.5, -3.3);
	glVertex2f(3.5, 3);
	glVertex2f(3.5, -3.3);
	glEnd();
	char message[] = { "cv" };
	int  len;
	if (hint == 1)
	{
		sudoku2[m][n] = sudoku3[m][n];
		sudokuscore1 = sudokuscore1 - 5;
	}
	else if (red == 1)
	{
		sudoku2[m][n] = no;
	}

	red = 0;
	glRasterPos2f(3.5, -3.3);
	glColor3f(0.0, 0.5, 0.1);
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			glRasterPos2f(-4 + i, 2.5 - j + (j*0.3));
			sprintf_s(message, "%d", sudoku2[j][i]);
			len = (int)strlen(message);
			for (int i = 0; i < len; i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
			}
		}
	}

	z = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (sudoku2[j][i] != sudoku3[j][i])
			{
				z = 100;
				break;
			}
		}
	}
	if (z != 100)
	{
		PlaySound(NULL, 0, 0);
		if (sound == 0)
		PlaySound(TEXT("sudoku_success.wav"), NULL, SND_ASYNC | SND_FILENAME);
		glColor3f(1.0, 1.0, 0.0);
		glRasterPos3f(-4.35, -4, -1.0);
		text(m8);
	
	}
	else
	{
		glColor3f(1.0, 1.0, 0.0);
		glRasterPos3f(-2.5, -4, -1.0);
		text(m7);
	}

	glColor3f(1, 0, 0);
	glRasterPos2f(-4 + n, 2.5 - m + (m*0.3));
	sprintf_s(message, "%d", sudoku2[m][n]);
	len = (int)strlen(message);
	for (int i = 0; i < len; i++)
	{
		glColor3f(1, 0, 0);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
	}



	if (sudokuscore1 <= 0)
	{
		sudokuscore1 = 0;
	}
	if (sudokuscore1 == 100)
	{
		glColor3f(1, 0, 0);
		glRasterPos3f(6, 2, -1);
		static char m15[] = { "100" };
		text(m15);
	}
	else
	{
		glColor3f(1, 0, 0);
		glRasterPos3f(6, 2, -1);
		sprintf_s(message, "%d", sudokuscore1);
		len = (int)strlen(message);
		for (int i = 0; i < len; i++)
		{
			glColor3f(1, 0, 0);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
		}
	}



	static char m19[] = { "PRESS n TO GO BACK" };
	glColor3f(1, 1, 1);
	glRasterPos3f(6, 0, -1.0);
	text3(m19);
	static char m18[] = { "PRESS m TO RESET SUDOKU" };
	glColor3f(1, 1, 1);
	glRasterPos3f(6, 0.5, -1.0);
	text3(m18);
	static char m17[] = { "PRESS h TO GET HINT" };
	glColor3f(1, 1, 1);
	glRasterPos3f(6, 1, -1.0);
	text3(m17);

	static char m16[] = { "SCORE:" };
	glColor3f(1, 0, 0);
	glRasterPos3f(6, 3, -1.0);
	text(m16);
	hint = 0;
	glFlush();
	glutSwapBuffers();
}





void sudoku()
{
	
	sudokukey = 1;
	tictactoekey = 0;
	sudokuscore1 = 100;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int ri, am, sr, tn;
	srand(time(0));
	am = rand();
	tn = rand() % 9;
	sr = (am + tn) % 9;
	if (sr == 0)
	{
		for (i = 0; i < 9; i++) { for (j = 0; j < 9; j++) { sudoku1[i][j] = ab[i][j]; } }
	}
	else if (sr == 1)
	{
		for (i = 0; i < 9; i++) { for (j = 0; j < 9; j++) { sudoku1[i][j] = cd[i][j]; } }
	}
	else if (sr == 2)
	{
		for (i = 0; i < 9; i++) { for (j = 0; j < 9; j++) { sudoku1[i][j] = ef[i][j]; } }
	}
	else if (sr == 3)
	{
		for (i = 0; i < 9; i++) { for (j = 0; j < 9; j++) { sudoku1[i][j] = gh[i][j]; } }
	}
	else if (sr == 4)
	{
		for (i = 0; i < 9; i++) { for (j = 0; j < 9; j++) { sudoku1[i][j] = ij[i][j]; } }
	}
	else if (sr == 5)
	{
		for (i = 0; i < 9; i++) { for (j = 0; j < 9; j++) { sudoku1[i][j] = kl[i][j]; } }
	}
	else if (sr == 6)
	{
		for (i = 0; i < 9; i++) { for (j = 0; j < 9; j++) { sudoku1[i][j] = mn[i][j]; } }
	}
	else if (sr == 7)
	{
		for (i = 0; i < 9; i++) { for (j = 0; j < 9; j++) { sudoku1[i][j] = op[i][j]; } }
	}
	else
	{
		for (i = 0; i < 9; i++) { for (j = 0; j < 9; j++) { sudoku1[i][j] = qr[i][j]; } }
	}

	glColor3f(1.0, 1.0, 0.0);
	glRasterPos3f(-0.8, 4.5, -1.0);
	text(m6);
	glColor3f(1.0, 0.0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-4.5, 3);
	glVertex2f(-4.5, -3.3);
	glVertex2f(4.5, -3.3);
	glVertex2f(4.5, 3);
	glColor3f(0.0, 0.0, 1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-4.5, 2.3);
	glVertex2f(4.5, 2.3);
	glVertex2f(-4.5, 1.6);
	glVertex2f(4.5, 1.6);
	glColor3f(1, 0.0, 0);
	glVertex2f(-4.5, 0.9);
	glVertex2f(4.5, 0.9);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-4.5, 0.2);
	glVertex2f(4.5, 0.2);
	glVertex2f(-4.5, -0.5);
	glVertex2f(4.5, -0.5);
	glColor3f(1, 0.0, 0);
	glVertex2f(-4.5, -1.2);
	glVertex2f(4.5, -1.2);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-4.5, -1.9);
	glVertex2f(4.5, -1.9);
	glVertex2f(-4.5, -2.6);
	glVertex2f(4.5, -2.6);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-3.5, 3);
	glVertex2f(-3.5, -3.3);
	glVertex2f(-2.5, 3);
	glVertex2f(-2.5, -3.3);
	glColor3f(1.0, 0.0, 0);
	glVertex2f(-1.5, 3);
	glVertex2f(-1.5, -3.3);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.5, 3);
	glVertex2f(-0.5, -3.3);
	glVertex2f(0.5, 3);
	glVertex2f(0.5, -3.3);
	glColor3f(1.0, 0.0, 0);
	glVertex2f(1.5, 3);
	glVertex2f(1.5, -3.3);
	glColor3f(0, 0.0, 1.0);
	glVertex2f(2.5, 3);
	glVertex2f(2.5, -3.3);
	glVertex2f(3.5, 3);
	glVertex2f(3.5, -3.3);
	glEnd();
	char message[] = { "cv" };
	int  len;
	glRasterPos2f(3.5, -3.3);
	glColor3f(0.0, 0.5, 0.1);
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
		{
			glRasterPos2f(-4 + i, 2.5 - j + (j*0.3));
			sprintf_s(message, "%d", sudoku1[j][i]);
			len = (int)strlen(message);
			for (int i = 0; i < len; i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
			}
		}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sudoku2[i][j] = sudoku1[i][j];
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sudoku3[i][j] = sudoku1[i][j];
		}
	}
	solve(sudoku3);


	int s[5];
	s[1] = sudoku1[0][0];
	glRasterPos2f(-4, 2.5);
	sprintf_s(message, "%d", s[1]);
	len = (int)strlen(message);
	for (int i = 0; i < len; i++)
	{
		glColor3f(1.0, 0, 0.0);
		glRasterPos2f(-4, 2.5);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
	}
	static char m19[] = { "PRESS n TO GO BACK" };
	glColor3f(1, 1, 1);
	glRasterPos3f(6, 0, -1.0);
	text3(m19);
	static char m18[] = { "PRESS m TO RESET SUDOKU" };
	glColor3f(1, 1, 1);
	glRasterPos3f(6, 0.5, -1.0);
	text3(m18);
	static char m17[] = { "PRESS h TO GET HINT" };
	glColor3f(1, 1, 1);
	glRasterPos3f(6, 1, -1.0);
	text3(m17);
	static char m74[] = { "PRESS j TO GIVE YOUR SUDOKU TO SOLVE " };
	glColor3f(1, 1, 1);
	glRasterPos3f(6, -0.5, -1.0);
	text3(m74);
	static char m16[] = { "SCORE:" };
	glColor3f(1, 0, 0);
	glRasterPos3f(6, 3, -1.0);
	text(m16);

	glColor3f(1, 0, 0);
	glRasterPos3f(6, 2, -1);
	static char m15[] = { "100" };
	text(m15);
	glFlush();
}




void ans()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glRasterPos3f(-0.8, 4.5, -1.0);
	text(m6);
	glColor3f(1.0, 0.0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-4.5, 3);
	glVertex2f(-4.5, -3.3);
	glVertex2f(4.5, -3.3);
	glVertex2f(4.5, 3);
	glColor3f(0.0, 0.0, 1.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-4.5, 2.3);
	glVertex2f(4.5, 2.3);
	glVertex2f(-4.5, 1.6);
	glVertex2f(4.5, 1.6);
	glColor3f(1, 0.0, 0);
	glVertex2f(-4.5, 0.9);
	glVertex2f(4.5, 0.9);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-4.5, 0.2);
	glVertex2f(4.5, 0.2);
	glVertex2f(-4.5, -0.5);
	glVertex2f(4.5, -0.5);
	glColor3f(1, 0.0, 0);
	glVertex2f(-4.5, -1.2);
	glVertex2f(4.5, -1.2);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-4.5, -1.9);
	glVertex2f(4.5, -1.9);
	glVertex2f(-4.5, -2.6);
	glVertex2f(4.5, -2.6);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-3.5, 3);
	glVertex2f(-3.5, -3.3);
	glVertex2f(-2.5, 3);
	glVertex2f(-2.5, -3.3);
	glColor3f(1.0, 0.0, 0);
	glVertex2f(-1.5, 3);
	glVertex2f(-1.5, -3.3);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.5, 3);
	glVertex2f(-0.5, -3.3);
	glVertex2f(0.5, 3);
	glVertex2f(0.5, -3.3);
	glColor3f(1.0, 0.0, 0);
	glVertex2f(1.5, 3);
	glVertex2f(1.5, -3.3);
	glColor3f(0, 0.0, 1.0);
	glVertex2f(2.5, 3);
	glVertex2f(2.5, -3.3);
	glVertex2f(3.5, 3);
	glVertex2f(3.5, -3.3);
	glEnd();
	char message[] = { "cv" };
	int  len;
	glRasterPos2f(3.5, -3.3);
	glColor3f(0.0, 0.5, 0.1);
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
		{
			glRasterPos2f(-4 + i, 2.5 - j + (j*0.3));
			sprintf_s(message, "%d", sudoku3[j][i]);
			len = (int)strlen(message);
			for (int i = 0; i < len; i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
			}
		}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sudoku2[i][j] = sudoku3[i][j];
		}
	}
	m = 0; n = 0;
	glFlush();
	glutSwapBuffers();
}



void wdaw()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	sudoku();
	glutSwapBuffers();
}



float righthandx =- 7.6;
float lefthandx = -8.4;
float righthandy = -1.5;
float lefthandy = -1.3;

float handbase = -1.1;

float stickx = -8;
float stickyb = -1.7;
float stickyt = -0.5;
float stickxlleg = -8.2;
float stickxrleg = -7.8;
float stickybase = -2;
float facecircley = 0;
float facecirclex= -8.1;
float dx1=0;
int countq = 0;
void delay()
{
	for (int i = 0; i < 70000000; i++)
	{
		int z;
	}
}
void stickman()
{
    
	delay();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	countq = countq + 1;
	glBegin(GL_LINES);
	glVertex2f(-10, -2);
	glVertex2f(10, -2);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(stickx + dx1, stickyt);
	glVertex2f(stickx + dx1, stickyb);

	glVertex2f(stickxlleg + dx1, stickybase);
	glVertex2f(stickx + dx1, stickyb);

	glVertex2f(stickxrleg + dx1, stickybase);
	glVertex2f(stickx + dx1, stickyb);

	glVertex2f(lefthandx+dx1, lefthandy);
	glVertex2f(stickx+dx1,handbase);

	glVertex2f(stickx+dx1, handbase);
	glVertex2f(righthandx +dx1,righthandy);
	glEnd();

	glColor3f(0.556863, 0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-1, -2);
	glVertex2f(-1, -0.5);
	glVertex2f(1, -0.5);
	glVertex2f(1, -2);
	glEnd();

	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-1.1, -0.5);
	glVertex2f(-1.1, -0.3);
	glVertex2f(1.1, -0.3);
	glVertex2f(1.1, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0,-0.3);
	glVertex2f(-0.2,-0.1);
	glVertex2f(-0.05,0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0, -0.3);
	glVertex2f(0.05, 0);
	glVertex2f(0.2, -0.1);
	glEnd();
	glColor3f(1, 1, 1);

	








	glPushMatrix();
	glTranslated(facecirclex + dx1, facecircley, -1.0);
	glutWireTorus(0.05, 0.5, 2, 50);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	delay();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	countq = countq + 1;
	glBegin(GL_LINES);
	glVertex2f(-10, -2);
	glVertex2f(10, -2);
	glEnd();
	dx1 = dx1 + 0.2;

	glBegin(GL_LINES);
	glVertex2f(stickx + dx1, stickyt);
	glVertex2f(stickx + dx1, stickyb);

	glVertex2f(stickxlleg + dx1, stickybase);
	glVertex2f(stickx + dx1, stickyb);

	glVertex2f(stickxrleg + dx1, stickybase);
	glVertex2f(stickx + dx1, stickyb);

	glVertex2f(lefthandx + dx1, righthandy);
	glVertex2f(stickx + dx1, handbase);

	glVertex2f(stickx + dx1, handbase);
	glVertex2f(righthandx + dx1, lefthandy);
	glEnd();

	glColor3f(0.556863, 0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-1, -2);
	glVertex2f(-1, -0.5);
	glVertex2f(1, -0.5);
	glVertex2f(1, -2);
	glEnd();

	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-1.1, -0.5);
	glVertex2f(-1.1, -0.3);
	glVertex2f(1.1, -0.3);
	glVertex2f(1.1, -0.5);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(0, -0.3);
	glVertex2f(-0.2, -0.1);
	glVertex2f(-0.05, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0, -0.3);
	glVertex2f(0.05, 0);
	glVertex2f(0.2, -0.1);
	glEnd();
	glColor3f(1, 1, 1);










	glPushMatrix();
	glTranslated(facecirclex + dx1, facecircley, -1.0);
	glutWireTorus(0.05, 0.5, 2, 50);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	
	if ((stickx+dx1) <= -1.8)
	{
		stickman();
	}
	
	
	
	else
	{
		delay();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		countq = countq + 1;
		glBegin(GL_LINES);
		glVertex2f(-10, -2);
		glVertex2f(10, -2);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(stickx + dx1, stickyt);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxlleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxrleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(lefthandx + dx1, lefthandy);
		glVertex2f(stickx + dx1, handbase);

		glVertex2f(stickx + dx1, handbase);
		glVertex2f(righthandx + dx1, righthandy);
		glEnd();

		glColor3f(0.556863, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(-1, -2);
		glVertex2f(-1, -0.5);
		glVertex2f(1, -0.5);
		glVertex2f(1, -2);
		glEnd();


	  //box cap flip
	    glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex2f(0.8, 1.7);
		glVertex2f(1, 2);
		glVertex2f(1.6, 0);
		glVertex2f(1.4, -0.3);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(1.3, 1);
		glVertex2f(1.5, 1.1);
		glVertex2f(1.4, 0.9);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(1.3, 1);
		glVertex2f(1.3, 1.2);
		glVertex2f(1.5,1.2 );
		glEnd();
		glColor3f(1, 1, 1);

		//box cap flip over
		glBegin(GL_POINTS);
		glColor3f(1, 0,0);
		glVertex2i(-1.1,-0.4);
		glColor3f(0,0,1);
		glVertex2i(-0.4, -0.7);
		glColor3f(0, 1, 1);
		glVertex2i(1, -0.4);
		glEnd();

		glPushMatrix();
		glTranslated(facecirclex + dx1, facecircley, -1.0);
		glutWireTorus(0.05, 0.5, 2, 50);
		glPopMatrix();
		glFlush();
		glutSwapBuffers();
		delay();
		delay();
		



		//puzzle world name in small
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		countq = countq + 1;
		glBegin(GL_LINES);
		glVertex2f(-10, -2);
		glVertex2f(10, -2);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(stickx + dx1, stickyt);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxlleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxrleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(lefthandx + dx1, lefthandy);
		glVertex2f(stickx + dx1, handbase);

		glVertex2f(stickx + dx1, handbase);
		glVertex2f(righthandx + dx1, righthandy);
		glEnd();

		glColor3f(0.556863, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(-1, -2);
		glVertex2f(-1, -0.5);
		glVertex2f(1, -0.5);
		glVertex2f(1, -2);
		glEnd();

		static char m37[] = { "PUZZLE WORLD" };
		glColor3f(1, 1, 1);
		glRasterPos3f(-0.8,0.5, -1.0);
		text3(m37);

		//box cap flip
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex2f(0.8, 1.7);
		glVertex2f(1, 2);
		glVertex2f(1.6, 0);
		glVertex2f(1.4, -0.3);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(1.3, 1);
		glVertex2f(1.5, 1.1);
		glVertex2f(1.4, 0.9);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(1.3, 1);
		glVertex2f(1.3, 1.2);
		glVertex2f(1.5, 1.2);
		glEnd();
		glColor3f(1, 1, 1);

		//box cap flip over

		glPushMatrix();
		glTranslated(facecirclex + dx1, facecircley, -1.0);
		glutWireTorus(0.05, 0.5, 2, 50);
		glPopMatrix();
		glFlush();
		glutSwapBuffers();
		delay();
		delay();
		delay();
		delay();


		//puzzle world name in medium
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		countq = countq + 1;
		glBegin(GL_LINES);
		glVertex2f(-10, -2);
		glVertex2f(10, -2);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(stickx + dx1, stickyt);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxlleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxrleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(lefthandx + dx1, lefthandy);
		glVertex2f(stickx + dx1, handbase);

		glVertex2f(stickx + dx1, handbase);
		glVertex2f(righthandx + dx1, righthandy);
		glEnd();

		glColor3f(0.556863, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(-1, -2);
		glVertex2f(-1, -0.5);
		glVertex2f(1, -0.5);
		glVertex2f(1, -2);
		glEnd();

		static char m80[] = { "PUZZLE WORLD" };
		glColor3f(0, 0,1);
		glRasterPos3f(-1, 1, -1.0);
		text2(m80);


		//box cap flip
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex2f(1, 1.7);
		glVertex2f(1.2, 2);
		glVertex2f(1.6, 0);
		glVertex2f(1.4, -0.3);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(1.5, 1);
		glVertex2f(1.7, 1.1);
		glVertex2f(1.6, 0.9);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(1.5, 1);
		glVertex2f(1.5, 1.2);
		glVertex2f(1.7, 1.2);
		glEnd();
		glColor3f(1, 1, 1);

		//box cap flip over

		glPushMatrix();
		glTranslated(facecirclex + dx1, facecircley, -1.0);
		glutWireTorus(0.05, 0.5, 2, 50);
		glPopMatrix();
		glFlush();
		glutSwapBuffers();
		delay();
		delay();
		delay();
		delay();



		//puzzle world name in large
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		countq = countq + 1;
		glBegin(GL_LINES);
		glVertex2f(-10, -2);
		glVertex2f(10, -2);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(stickx + dx1, stickyt);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxlleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxrleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(lefthandx + dx1, lefthandy);
		glVertex2f(stickx + dx1, handbase);

		glVertex2f(stickx + dx1, handbase);
		glVertex2f(righthandx + dx1, righthandy);
		glEnd();

		glColor3f(0.556863, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(-1, -2);
		glVertex2f(-1, -0.5);
		glVertex2f(1, -0.5);
		glVertex2f(1, -2);
		glEnd();

		static char m84[] = { "PUZZLE WORLD" };
		glColor3f(1, 1,0);
		glRasterPos3f(-1.5, 3, -1.0);
		text(m84);


		//box cap flip
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex2f(1.2, 1.7);
		glVertex2f(1.4, 2);
		glVertex2f(2, 0);
		glVertex2f(1.8, -0.3);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(1.7, 1);
		glVertex2f(1.9, 1.1);
		glVertex2f(1.8, 0.9);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(1.7, 1);
		glVertex2f(1.7, 1.2);
		glVertex2f(1.9, 1.2);
		glEnd();
		glColor3f(1, 1, 1);

		//box cap flip over

		glPushMatrix();
		glTranslated(facecirclex + dx1, facecircley, -1.0);
		glutWireTorus(0.05, 0.5, 2, 50);
		glPopMatrix();
		glFlush();
		glutSwapBuffers();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();

		//by sriram name in large
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		countq = countq + 1;
		glBegin(GL_LINES);
		glVertex2f(-10, -2);
		glVertex2f(10, -2);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(stickx + dx1, stickyt);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxlleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxrleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(lefthandx + dx1, lefthandy);
		glVertex2f(stickx + dx1, handbase);

		glVertex2f(stickx + dx1, handbase);
		glVertex2f(righthandx + dx1, righthandy);
		glEnd();

		glColor3f(0.556863, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(-1, -2);
		glVertex2f(-1, -0.5);
		glVertex2f(1, -0.5);
		glVertex2f(1, -2);
		glEnd();

		static char m89[] = { "PUZZLE WORLD" };
		glColor3f(1, 1, 0);
		glRasterPos3f(-1.5, 3, -1.0);
		text(m89);

		//box cap flip
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex2f(1.2, 1.7);
		glVertex2f(1.4, 2);
		glVertex2f(2, 0);
		glVertex2f(1.8, -0.3);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(1.7, 1);
		glVertex2f(1.9, 1.1);
		glVertex2f(1.8, 0.9);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(1.7, 1);
		glVertex2f(1.7, 1.2);
		glVertex2f(1.9, 1.2);
		glEnd();
		glColor3f(1, 1, 1);

		//box cap flip over
	
		glPushMatrix();
		glTranslated(facecirclex + dx1, facecircley, -1.0);
		glutWireTorus(0.05, 0.5, 2, 50);
		glPopMatrix();
	
		/*static char m85[] = { "BY:" };
		glColor3f(1, 0, 0);
		glRasterPos3f(4, 3, -1.0);
		text(m85);
		glFlush();
		
		static char m86[] = { "SRIRAM GN" };
		glColor3f(0, 0, 1);
		glRasterPos3f(4, 2, -1.0);
		text(m86);*/
		glColor3f(1, 1, 1);
		glFlush();
		glutSwapBuffers();
		delay();
		delay();
		delay();

		//by praveen name in large
		PlaySound(NULL, 0, 0);
		if (sound == 0)
		PlaySound(TEXT("thunder.wav"), NULL, SND_ASYNC | SND_FILENAME);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		countq = countq + 1;
		glBegin(GL_LINES);
		glVertex2f(-10, -2);
		glVertex2f(10, -2);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(stickx + dx1, stickyt);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxlleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(stickxrleg + dx1, stickybase);
		glVertex2f(stickx + dx1, stickyb);

		glVertex2f(lefthandx + dx1, lefthandy);
		glVertex2f(stickx + dx1, handbase);

		glVertex2f(stickx + dx1, handbase);
		glVertex2f(righthandx + dx1, righthandy);
		glEnd();

		glColor3f(0.556863, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(-1, -2);
		glVertex2f(-1, -0.5);
		glVertex2f(1, -0.5);
		glVertex2f(1, -2);
		glEnd();

		static char m99[] = { "PUZZLE WORLD" };
		glColor3f(1, 1, 0);
		glRasterPos3f(-1.5, 3, -1.0);
		text(m99);
		//box cap flip
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex2f(1.2, 1.7);
		glVertex2f(1.4, 2);
		glVertex2f(2, 0);
		glVertex2f(1.8, -0.3);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex2f(1.7, 1);
		glVertex2f(1.9, 1.1);
		glVertex2f(1.8, 0.9);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(1.7, 1);
		glVertex2f(1.7, 1.2);
		glVertex2f(1.9, 1.2);
		glEnd();
		glColor3f(1, 1, 1);
		//box cap flip over


		glPushMatrix();
		glTranslated(facecirclex + dx1, facecircley, -1.0);
		glutWireTorus(0.05, 0.5, 2, 50);
		glPopMatrix();

		static char m95[] = { "BY:" };
		glColor3f(1, 1, 0);
		glRasterPos3f(4, 3, -1.0);
		text(m95);
		glFlush();

		static char m96[] = { "SRIRAM GN" };
		glColor3f(1, 1, 1);
		glRasterPos3f(4, 2, -1.0);
		text(m96);
		glFlush();

		static char m97[] = { "and" };
		glColor3f(1, 1, 0);
		glRasterPos3f(4.5, 1, -1.0);
		text2(m97);
		glFlush();
		

		static char m88[] = { "PRAVEEN G" };
		glColor3f(1, 1, 1);
		glRasterPos3f(4, 0, -1.0);
		text(m88);
		glColor3f(1, 1, 1);
		glFlush();
		glutSwapBuffers();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		flag = 9;

	}
}



















void draw(void)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	if (flag == 1)
	{
		ram = 0;
		demo();
	}
	if (flag == 9)
	{

		cover();
	}
	else if (flag == 2)
	{
		selgamekey = 0;
		help();
	}
	else if (flag == 3)
	{
		selgamekey = 0;
		info();
	}
	else if (flag == 4 && pr == 0)
	{
		if (sound == 0)
		PlaySound(TEXT("sudoku_clock.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		pr = 1;
		wdaw();
		PlaySound(NULL, 0, 0);

	}
	else if (flag == 5)
	{
		ram = 0;
		solvesudoku();
	}
	else if (flag == 6)
	{
		tictac();
	}
	else if (flag == 7)
	{
		soltictac();
	}
	else if (flag == 0 & e == 0)
	{
		if (sound == 0)
		PlaySound(TEXT("ball.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		stickman();
		PlaySound(NULL, 0, 0);
		
	}
	else if (flag == 10)
	{
		newsudoku();

	}
	//glutSwapBuffers();
   //glFlush();
   //glutPostRedisplay();
}


/******** change view angle, exit upon pressing any key **********//* ARGSUSED1 */


/******* new window size or exposure ********/
static void reshape(int width, int height)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat h = (GLfloat)height / (GLfloat)width;
	glViewport(0, 0, (GLint)width, (GLint)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -h, h, 5.0, 60.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -50.0);
}


static void key(unsigned char k, int x, int y)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	if (tickname1 == 1)
	{
		switch (k)
		{
			//case '9': exit(0);
		case '1':flag = 1; tictactoekey = 0; sudokukey = 0; gameover1 = 0; tickname1 = 0; strcpy_s(name1, empty); strcpy_s(name2, empty); tickname = 0, player1key = 0; player2key = 0; draw(); break;
		case '9': player2key = 1; tickname1 = 0; tickname = 0; flag = 7; draw(); break;
		case 'a':temp1 = 1; flag = 6; draw(); break;
		case 'b':temp1 = 2; flag = 6; draw(); break;
		case 'c':temp1 = 3; flag = 6; draw(); break;
		case 'd':temp1 = 4; flag = 6; draw(); break;
		case 'e':temp1 = 5; flag = 6; draw(); break;
		case 'f':temp1 = 6; flag = 6; draw(); break;
		case 'g':temp1 = 7; flag = 6; draw(); break;
		case 'h':temp1 = 8; flag = 6; draw(); break;
		case 'i':temp1 = 9; flag = 6; draw(); break;
		case 'j':temp1 = 10; flag = 6; draw(); break;
		case 'k':temp1 = 11; flag = 6; draw(); break;
		case 'l':temp1 = 12; flag = 6; draw(); break;
		case 'm':temp1 = 13; flag = 6; draw(); break;
		case 'n':temp1 = 14; flag = 6; draw(); break;
		case 'o':temp1 = 15; flag = 6; draw(); break;
		case 'p':temp1 = 16; flag = 6; draw(); break;
		case 'q':temp1 = 17; flag = 6; draw(); break;
		case 'r':temp1 = 18; flag = 6; draw(); break;
		case 's':temp1 = 19; flag = 6; draw(); break;
		case 't':temp1 = 20; flag = 6; draw(); break;
		case 'u':temp1 = 21; flag = 6; draw(); break;
		case 'v':temp1 = 22; flag = 6; draw(); break;
		case 'w':temp1 = 23; flag = 6; draw(); break;
		case 'x':temp1 = 24; flag = 6; draw(); break;
		case 'y':temp1 = 25; flag = 6; draw(); break;
		case 'z':temp1 = 26; flag = 6; draw(); break;
		}
	}
	else if (tickname == 1)
	{
		switch (k)
		{
		//case '9': exit(0);
		case '1':flag = 1; tictactoekey = 0; sudokukey = 0; gameover1 = 0; strcpy_s(name1, empty); strcpy_s(name2, empty); tickname1 = 0; tickname = 0, player1key = 0; player2key = 0; draw(); break;
		case'9': player2key = 1; tickname1 = 1; flag = 6; gameover1 = 0;  draw(); break;
		case 'a':temp1 = 1; flag = 6; draw(); break;
		case 'b':temp1 = 2; flag = 6; draw(); break;
		case 'c':temp1 = 3; flag = 6; draw(); break;
		case 'd':temp1 = 4; flag = 6; draw(); break;
		case 'e':temp1 = 5; flag = 6; draw(); break;
		case 'f':temp1 = 6; flag = 6; draw(); break;
		case 'g':temp1 = 7; flag = 6; draw(); break;
		case 'h':temp1 = 8; flag = 6; draw(); break;
		case 'i':temp1 = 9; flag = 6; draw(); break;
		case 'j':temp1 = 10; flag = 6; draw(); break;
		case 'k':temp1 = 11; flag = 6; draw(); break;
		case 'l':temp1 = 12; flag = 6; draw(); break;
		case 'm':temp1 = 13; flag = 6; draw(); break;
		case 'n':temp1 = 14; flag = 6; draw(); break;
		case 'o':temp1 = 15; flag = 6; draw(); break;
		case 'p':temp1 = 16; flag = 6; draw(); break;
		case 'q':temp1 = 17; flag = 6; draw(); break;
		case 'r':temp1 = 18; flag = 6; draw(); break;
		case 's':temp1 = 19; flag = 6; draw(); break;
		case 't':temp1 = 20; flag = 6; draw(); break;
		case 'u':temp1 = 21; flag = 6; draw(); break;
		case 'v':temp1 = 22; flag = 6; draw(); break;
		case 'w':temp1 = 23; flag = 6; draw(); break;
		case 'x':temp1 = 24; flag = 6; draw(); break;
		case 'y':temp1 = 25; flag = 6; draw(); break;
		case 'z':temp1 = 26; flag = 6; draw(); break;
		}
	}
	else if (tictactoekey == 1)
	{
		switch (k)
		{
		case 'q': exit(0);
		case 'n':flag = 1; tictactoekey = 0; gameover1 = 0; sudokukey = 0;
			strcpy_s(name1, empty); strcpy_s(name2, empty); player1key = 0; player2key = 0;
				draw(); break;
		case 'y':tickname = 1; player1key = 1; flag = 6;  draw(); break;
		case 's':tic = 1; gameover1 = gameover1 + 1; flag = 7; draw(); break;
		case 'm':flag = 6; strcpy_s(name1, empty); strcpy_s(name2, empty); player2key = 0; player1key = 0; gameover1 = 0; draw(); break;
		}
	}


	else if (newsudoku1 == 1)
	{
		switch (k)
		{
		case 'q': exit(0);
		case 'n': flag = 1; sudokukey = 0; newsudoku1 = 0; PlaySound(NULL, 0, 0); gotanswer = 0; sudokuenable = 0; no = 0; tictactoekey = 0; draw(); break;
		case '0':no = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case 's':gotanswer = 1; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '1':no = 1; hint = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '2':no = 2; hint = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '3':no = 3; hint = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '4':no = 4; hint = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '5':no = 5; hint = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '6':no = 6; hint = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '7':no = 7; hint = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '8':no = 8; hint = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '9':no = 9; hint = 0; flag = 10; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		}
	}






	else if (sudokukey == 1)
	{
		switch (k)
		{
		case 'q': exit(0);
		case 'n': flag = 1; sudokukey = 0; tictactoekey = 0; PlaySound(NULL, 0, 0); draw(); break;
		case 'h': hint = 1; flag = 5; red = 1; draw(); break;
		case 'm':flag = 4; pr = 0; m = 0; n = 0; draw(); break;
		case 'j':flag = 10; /*pr = 0;*/newsudoku1 = 1; m = 0; n = 0; draw(); break;
		case '0':no = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '1':no = 1; hint = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '2':no = 2; hint = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '3':no = 3; hint = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '4':no = 4; hint = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '5':no = 5; hint = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '6':no = 6; hint = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '7':no = 7; hint = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '8':no = 8; hint = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		case '9':no = 9; hint = 0; flag = 5; red = 1; glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); draw(); break;
		}
	}
	else if (selgamekey == 0)
	{
		switch (k)
		{
		case 'q': exit(0);
		case 's': selgamekey = 1; if (ramu == 0)flag = 1; else if (ramu == 1)flag = 2; else if (ramu == 2)flag = 3; draw(); break;
		case 'n':flag = 9; selgamekey = 0; sudokukey = 0; tictactoekey = 0; ramu = 0; PlaySound(NULL, 0, 0); draw(); break;
		case 'a':if (sound == 0)sound = 1; else if (sound == 1) sound = 0; flag = 9; draw();  break;
		}

	}
	else
	{
		switch (k)
		{
		case 'q': exit(0);
		case's':glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); if (ramu == 0) { flag = 4; pr = 0; m = 0; n = 0; }
				else flag = 6; draw(); break;
		case 'n':cover(); ramu = 0; PlaySound(NULL, 0, 0); break;
		}
	}
	glutPostRedisplay();
}

void specialkey(int key, int x, int y)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	if (sudokukey == 1)
	{
		switch (key)
		{
		case GLUT_KEY_LEFT: if (n == 0) { n = 8; }
							else  n = n - 1; 
							if (newsudoku1 == 1) { flag = 10; }
							else flag = 5; hint = 0; draw(); break;
		case GLUT_KEY_DOWN:if (m == 8) { m = 0; }
							 else  m = m + 1; 
							if (newsudoku1 == 1) { flag = 10; }
							else flag = 5; hint = 0; draw(); break;
		case GLUT_KEY_UP: if (m == 0) { m = 8; }
						  else m = m - 1;	
							if (newsudoku1 == 1) { flag = 10; }
						  else  flag = 5; hint = 0; draw(); break;
		case GLUT_KEY_RIGHT:if (n == 8) { n = 0; }
							else n = n + 1; 	
							if (newsudoku1 == 1) { flag = 10; }
							else flag = 5; hint = 0; draw(); break;
		case GLUT_KEY_F1:if (solve(sudoku3)) { ans(); }
		}
	}
	else if (tictactoekey == 1)
	{
		switch (key)
		{
		case GLUT_KEY_LEFT: if (g == 0) { g = 2; }
							else if (g == 1) { g = 0; }
							else if (g == 2) { g = 1; }flag = 7; hint = 0; tic = 0; draw(); break;
		case GLUT_KEY_DOWN:if (f == 2) { f = 0; }
						   else if (f == 1) { f = 2; }
						   else if (f == 0) { f = 1; }  flag = 7; hint = 0; tic = 0; draw(); break;
		case GLUT_KEY_UP:if (f == 2) { f = 1; }
						 else if (f == 1) { f = 0; }
						 else if (f == 0) { f = 2; }  flag = 7; hint = 0; tic = 0; draw(); break;
		case GLUT_KEY_RIGHT:if (g == 0) { g = 1; }
							else if (g == 1) { g = 2; }
							else if (g == 2) { g = 0; }flag = 7; hint = 0; tic = 0; draw(); break;
		}
	}
	else if (selgamekey == 0)
	{
		switch (key)
		{
		case GLUT_KEY_DOWN:ramu = (ramu + 1) % 3; cover(); break;
		case GLUT_KEY_UP: if (ramu == 0)ramu = 2; else if (ramu == 1)ramu = 0; else ramu = 1; cover(); break;
		}
	}
	else
	{
		switch (key)
		{
		case GLUT_KEY_DOWN:if (ramu == 0)ramu = 1; else ramu = 0; demo(); break;
		case GLUT_KEY_UP:if (ramu == 0)ramu = 1; else ramu = 0; demo(); break;
		}
	}
}
void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1600, 800);
	glutCreateWindow("puzzle world");
	glClearColor(0, 0, 0, 0);
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutSpecialFunc(specialkey);
	glutMainLoop();
}
