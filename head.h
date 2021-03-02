#include <stdio.h>
typedef enum{Black=49,White=48,dead=1,None=0} Chess;
typedef enum{DBO=10,DBN=15,DWO=20,DWN=25,NoOne=11} DeadChess;

typedef struct
{
	int localf;
	int locals;
} LocalPlace;

typedef struct
{
	int xposit;
	int yposit;
	int TotalScore;
} ScoreBest;



/*--------------main.c..................*/

void PrintBest(int ScoreTable[][19]);
/*----------------------live4.c-----------------*/
void LiveDead4(char board[][19],int i,int j);

void PrintLiveBlock(int x,int y);

void showeLiveBlack();
void showeLiveWhite();

void showeDeadBlack();
void showeDeadWhite();

void PrintAll4();

void BlackCalculateLD4(int ScoreTable[][19]);
void WhiteCalculateLD4(int ScoreTable[][19]);
/*----------------------live3.c-----------------*/
void LiveJump3(char board[][19],int i,int j);

void ShowL(int L[],int LCount);
void ShowD(int D[],int DCount);


void ShowLB3();	
void ShowLW3();
void ShowLJB3();
void ShowLJW3();

void BlackCalculateLD3(int ScoreTable[][19]);
void WhiteCalculateLD3(int ScoreTable[][19]);

/*------------------------live2.c---------------*/

void ShowLB2();
void ShowLW2();
void ShowLJB2();
void ShowLJW2();

void LiveJump2(char board[][19],int i,int j);

void BlackCalculateLD2(int ScoreTable[][19]);
void WhiteCalculateLD2(int ScoreTable[][19]);

/*-------------------------Score.c-----------------*/

void AllScore(char State[],int ScoreTable[][19],char board[][19],int i,int j);
void EAllScore(char State[],int ScoreTable[][19],char board[][19],int i,int j);

/*-----------ATTACK----------*/

void Attack(char board[][19],int i,int j);

void BlackCalculateAttack(int ScoreTable[][19]);
void WhiteCalculateAttack(int ScoreTable[][19]);
