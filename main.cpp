#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"	//�ǤJ�@�Ӱ}�C �����Y��l�˭p������ �Ǧ^ 

int main(int argc,char *argv[])
{	
	int i,j,first=0;
	int ScoreTable[19][19];
	char sign[]="ABCDEFGHIJKLMNOPQRS";
	char board[19][19];
	char Enemy[20];
	ScoreBest Best[500];
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
			scanf(" %c",&board[i][j]);				//�N�ѽLŪ�J 
			if(board[i][j]!='.')
			{
				ScoreTable[i][j]=0;					//���O�������� 
				first+=1;
			}
			else if(board[i][j]=='.')	
			{
				ScoreTable[i][j]=1;					//���O�������� �Ū��ϰ�+1 
			}
				
		}
	}
	
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
			if(ScoreTable[i][j]!=0)
			{
				if(i>=8 && i<=10 && j>=8 && j<=10)
				{
					ScoreTable[i][j]+=15;
				}
				if(i>=7 && i<=11 && j>=7 && j<=11)
				{
					ScoreTable[i][j]+=10;
				}
			}
		}
	}
	
	
	char my[20];
	
	if(strcmp(argv[1],"Black")==0)
	{
		strcpy(my,"Black");
		strcpy(Enemy,"White");
	}
		
	if(strcmp(argv[1],"White")==0)
	{
		strcpy(my,"White");
		strcpy(Enemy,"Black");
	}
	
	strcpy(my,"Black");
	strcpy(Enemy,"White");
		
		
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
			LiveDead4(board,i,j);	//��X���P��4 ���P��4�O�s�bLIVE4.C�� 
			LiveJump3(board,i,j);
			LiveJump2(board,i,j);
			Attack(board,i,j);
			AllScore(my,ScoreTable,board,i,j);
			EAllScore(Enemy,ScoreTable,board,i,j);
		}
			
	}

	if((strcmp(my,"Black")==0) && first==0)				//�p�G�O�� �S�O�Ĥ@�Ӫ��� 
	{
		printf("J, 10");
		exit(0);
	}
	
	if((strcmp(my,"Black")==0) && first==2)
	{
		if(board[9][10]=='.')
		{
			printf("K, 10");
			exit(0);
		}
			
		if(board[9][8]=='.')
		{
			printf("I, 10");
			exit(0);
		}
			
		if(board[10][9]=='.')
		{
			printf("J, 11");
			exit(0);
		}
	}
	
	if((strcmp(my,"Black")==0) && first>1)		//�¤l���ƭp�� 
	{
		BlackCalculateLD4(ScoreTable);
		BlackCalculateLD3(ScoreTable);
		BlackCalculateLD2(ScoreTable);
		BlackCalculateAttack(ScoreTable);
	}
	
	if((strcmp(my,"White")==0) && first>1)	//�դl���ƭp�� 
	{
		WhiteCalculateLD4(ScoreTable);
		WhiteCalculateLD3(ScoreTable);
		WhiteCalculateLD2(ScoreTable);
		WhiteCalculateAttack(ScoreTable);
	}
	/*
	printf("  %s\n",sign);
	for(i=0;i<19;i++)
	{
		printf("%2d",i+1);
		for(j=0;j<19;j++)
		{
			printf("%6d",ScoreTable[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<19;i++)
	{
		printf("%2d",i+1);
		for(j=0;j<19;j++)
		{
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
	*/
	PrintBest(ScoreTable);
	memset(ScoreTable,'\0',sizeof(ScoreTable));
	exit(0);
}

