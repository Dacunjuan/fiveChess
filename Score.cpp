#include "head.h"
#include <string.h>
/*
	�`�@��8�Ӥ�V����ܳB�z
	
	�D�ұ����� (��e�O�¤l�Υդl,�p����,�ѽL)
	{
		�C�Ө�ܱ�������(��e�O�¤l�Υդl,�p����,��h�ִѽL����m) 
	} 
	
*/
#define MyLive 10			
#define EnemyLive 6
Chess LeftScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[5])//1111. 0 1 2 3 4 ���� 
{
	int i;
	int Count=0;
	if((*p)[4]=='.')
	{
		if(strcmp(State,"Black")==0)
		{	
			for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
			{
				if((*p)[i]==Black)
				{
					Count++;
					ScoreTable[x][y]+=Count*MyLive;
				}
					
				else if((*p)[i]==White)
					break;
					
				
			}
			
		}
		if(strcmp(State,"White")==0)
		{	
			for(i=3;i>=0;i--)//�p�⦳�h�֥� 
			{
				if((*p)[i]==White)
				{
					Count++;
					ScoreTable[x][y]+=Count*MyLive;
				}
				else if((*p)[i]==Black)
					break;
			}
		}
	}
}

Chess RightScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[5])//.1111 , .00.0  �k�� 
{
	int i;
	int Count=0;
	if(strcmp(State,"Black")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==White)
				break;
		}
			
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�֥� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==Black)
				break;
		}
	}
	
}

Chess TopScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])//�W�� 
{
	int i;
	int Count=0;
	if(strcmp(State,"Black")==0)
	{	
		for(i=0;i<4;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[0]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[0]==White)
				break;
			p++;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=0;i<4;i++)//�p�⦳�h�֥� 
		{
			if((*p)[0]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[0]==Black)
				break;
			p++;
		}
	}
}

Chess DownScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])//�U�� 
{
	int i;
	int Count=0;
	p++;
	if(strcmp(State,"Black")==0)
	{	
		for(i=0;i<4;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[0]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[0]==White)
				break;
			p++;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=1;i<4;i++)//�p�⦳�h�֥� 
		{
			if((*p)[0]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[0]==Black)
				break;
			p++;
		}
	}
}

Chess DownRightScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])//�U�� 
{
	int i;
	int Count=0;
	p++;
	if(strcmp(State,"Black")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==White)
				break;
			p++;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�֥� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==Black)
				break;
			p++;
		}
	}
}

Chess DownLeftScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])//�U�� 
{
	int i;
	int Count=0;
	p++;
	if(strcmp(State,"Black")==0)
	{	
		for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==White)
				break;
			p++;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==Black)
				break;
			p++;
		}
	}
}

Chess TopRightScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])
{
	int i;
	int Count=0;
	p--;
	if(strcmp(State,"Black")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==White)
				break;
			p--;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�֥� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==Black)
				break;
			p--;
		}
	}
}

Chess TopLeftScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])
{
	int i;
	int Count;
	p--;
	if(strcmp(State,"Black")==0)
	{	
		for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==White)
				break;
			p--;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*MyLive;
			}
			else if((*p)[i]==Black)
				break;
			p--;
		}
	}
}
/*---------------------------�Ĥ�----------------------*/

Chess ELeftScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[5])//1111. 0 1 2 3 4 ���� 
{
	int i;
	int Count=0;
	if((*p)[4]=='.')
	{
		if(strcmp(State,"Black")==0)
		{	
			for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
			{
				if((*p)[i]==Black)
				{
					Count++;
					ScoreTable[x][y]+=Count*EnemyLive;
				}
					
				else if((*p)[i]==White)
					break;
					
				
			}
			
		}
		if(strcmp(State,"White")==0)
		{	
			for(i=3;i>=0;i--)//�p�⦳�h�֥� 
			{
				if((*p)[i]==White)
				{
					Count++;
					ScoreTable[x][y]+=Count*EnemyLive;
				}
				else if((*p)[i]==Black)
					break;
			}
		}
	}
}

Chess ERightScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[5])//.1111 , .00.0  �k�� 
{
	int i;
	int Count=0;
	if(strcmp(State,"Black")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==White)
				break;
		}
			
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�֥� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==Black)
				break;
		}
	}
	
}

Chess ETopScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])//�W�� 
{
	int i;
	int Count=0;
	if(strcmp(State,"Black")==0)
	{	
		for(i=0;i<4;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[0]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[0]==White)
				break;
			p++;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=0;i<4;i++)//�p�⦳�h�֥� 
		{
			if((*p)[0]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[0]==Black)
				break;
			p++;
		}
	}
}

Chess EDownScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])//�U�� 
{
	int i;
	int Count=0;
	p++;
	if(strcmp(State,"Black")==0)
	{	
		for(i=0;i<4;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[0]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[0]==White)
				break;
			p++;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=1;i<4;i++)//�p�⦳�h�֥� 
		{
			if((*p)[0]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[0]==Black)
				break;
			p++;
		}
	}
}

Chess EDownRightScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])//�U�� 
{
	int i;
	int Count=0;
	p++;
	if(strcmp(State,"Black")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==White)
				break;
			p++;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�֥� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==Black)
				break;
			p++;
		}
	}
}

Chess EDownLeftScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])//�U�� 
{
	int i;
	int Count=0;
	p++;
	if(strcmp(State,"Black")==0)
	{	
		for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==White)
				break;
			p++;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==Black)
				break;
			p++;
		}
	}
}

Chess ETopRightScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])
{
	int i;
	int Count=0;
	p--;
	if(strcmp(State,"Black")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==White)
				break;
			p--;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=1;i<5;i++)//�p�⦳�h�֥� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==Black)
				break;
			p--;
		}
	}
}

Chess ETopLeftScore(char State[],int ScoreTable[][19],int x,int y,char (*p)[19])
{
	int i;
	int Count;
	p--;
	if(strcmp(State,"Black")==0)
	{	
		for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==Black)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==White)
				break;
			p--;
		}
		
	}
	if(strcmp(State,"White")==0)
	{	
		for(i=3;i>=0;i--)//�p�⦳�h�ֶ� 
		{
			if((*p)[i]==White)
			{
				Count++;
				ScoreTable[x][y]+=Count*EnemyLive;
			}
			else if((*p)[i]==Black)
				break;
			p--;
		}
	}
}
 
void AllScore(char State[],int ScoreTable[][19],char board[][19],int i,int j)
{
	if(board[i][j]=='.')
	{
		if(j>=4)
		{
			LeftScore(State,ScoreTable,i,j,(char(*)[5])&board[i][j-4]);
		}
	
		if(j<=14)
		{
			RightScore(State,ScoreTable,i,j,(char(*)[5])&board[i][j]);
		}	
		
		if(i>=4)
		{
			TopScore(State,ScoreTable,i,j,(char(*)[19])&board[i-4][j]);
		}
		
		if(i<=14)
		{
			DownScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j]);
		}
		
		if(i<=14 && j<=14)
		{
			DownRightScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j]);
		}
		
		if(i<=14 && j>=4)
		{
			DownLeftScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j-4]);
		}
		
		if(i>=4 && j<=14)
		{
			TopRightScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j]);
		}
		
		if(i>=4 && j>=4)
		{
			TopLeftScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j-4]);
		}
	}	
}

void EAllScore(char State[],int ScoreTable[][19],char board[][19],int i,int j)
{
	if(board[i][j]=='.')
	{
		if(j>=4)
		{
			ELeftScore(State,ScoreTable,i,j,(char(*)[5])&board[i][j-4]);
		}
	
		if(j<=14)
		{
			ERightScore(State,ScoreTable,i,j,(char(*)[5])&board[i][j]);
		}	
		
		if(i>=4)
		{
			ETopScore(State,ScoreTable,i,j,(char(*)[19])&board[i-4][j]);
		}
		
		if(i<=14)
		{
			EDownScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j]);
		}
		
		if(i<=14 && j<=14)
		{
			EDownRightScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j]);
		}
		
		if(i<=14 && j>=4)
		{
			EDownLeftScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j-4]);
		}
		
		if(i>=4 && j<=14)
		{
			ETopRightScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j]);
		}
		
		if(i>=4 && j>=4)
		{
			ETopLeftScore(State,ScoreTable,i,j,(char(*)[19])&board[i][j-4]);
		}
	}
		
}

void FindBest(char board[][19],int Count,ScoreBest Best[],char my[])
{
	/*int i,j,k,x=0,y=0;
	char Newboard[19][19];
	char Enemy[20];
	int NewScoreTable[19][19];
	for(i=0;i<19;i++)
		for(j=0;j<19;j++)				//�гy�s���O 
			Newboard[i][j]=board[i][j];
	
	
			
	for(i=0;i<Count;i++)
	{
		x=Best[i].xposit;
		y=Best[i].yposit;
		if(strcmp(my,"Black")==0)
		{
			strcpy(Enemy,"White");
			Newboard[x][y]='1';
		}
			
		if(strcmp(my,"White")==0)
		{
			strcpy(Enemy,"Black");
			Newboard[x][y]='0';
		}
			
		for(j=0;j<19;j++)
		{
			for(k=0;k<19;k++)
			{
				LiveDead4(Newboard,i,j);	//��X���P��4 ���P��4�O�s�bLIVE4.C�� 
				LiveJump3(Newboard,i,j);
				LiveJump2(Newboard,i,j);
				Attack(Newboard,i,j);
				AllScore(my,NewScoreTable,Newboard,i,j);
				EAllScore(Enemy,NewScoreTable,Newboard,i,j);
			}
		}
	}*/
}

void PrintBest(int ScoreTable[][19])
{
	ScoreBest Best[500];
	int max=0;
	int i=0,j=0,k=0,x=0,y=0,Count=0;
	max=ScoreTable[0][0];
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
			if(max<ScoreTable[i][j])
			{
				max=ScoreTable[i][j];
				x=i;
				y=j;
			}
		}
	}
	
		PrintLiveBlock(x,y);
}


