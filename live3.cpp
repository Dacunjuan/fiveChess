
#include "head.h"
typedef enum{JBO=12,JBS=17,JWO=22,JWS=27,NoJump=0} JumpThird;
int LB3[200],LW3[200],LJB3[200],LJW3[200];
int LB3Count=0,LW3Count=0,LJB3Count=0,LJW3Count=0;

#define MyLive 600
#define EnemyLive 250
/*.111. .11.1.  */
/*.111.0*/
/*-----------Show----------*/
void ShowL(int L[],int LCount)
{
	int i;
	if(LCount==0)
	{
		printf("None\n");
	}
	for(i=0;i<LCount;i++)
	{
		int o=0,x=0,y=0;
		
		o=L[i];
		x=o/19;
		y=L[i]-x*19;
		PrintLiveBlock(x,y);
		if((i+2)%2==0)printf("-");
		if((i+1)%2==0) printf("\n");
	}
}

void ShowD(int D[],int DCount)
{
	int i;
	if(DCount==0)
	{
		printf("None\n");
	}
	for(i=0;i<DCount;i++)
	{
		int o=0,x=0,y=0;
		o=D[i];
		x=o/19;
		y=D[i]-x*19;
		PrintLiveBlock(x,y);
		printf("\n");
	}
}

void ShowLB3()					
{
	ShowL(LB3,LB3Count);
}

void ShowLW3()
{
	ShowL(LW3,LW3Count);
}

void ShowLJB3()
{
	ShowD(LJB3,LJB3Count);
}
void ShowLJW3()
{
	ShowD(LJW3,LJW3Count);
}
/*-------------show------------------*/

JumpThird  ThirdCheck(int ch[],int b,int w)	//��3�T�{ 
{
	if(ch[2]==0) //.1.11.
	{
		if(b==3)
		{
			return JBO;
		}
			else if(w==3)
			{
				return JWO;
			}
	}
	else if(ch[3]==0)
	{
		if(b==3)
		{
			return JBS;
		}
			else if(w==3)
			{
				return JWS;
			}
	}
	else
		return NoJump;
}

void Jump3BW(int Jump,int localf,int locals)		//��3�}�C 
{
	switch(Jump)
	{
		case JBO:
			LJB3[LJB3Count++]=localf;
			break;
		case JBS:
			LJB3[LJB3Count++]=locals;
			break;
		case JWO:
			LJW3[LJW3Count++]=localf;
			break;
		case JWS:
			LJW3[LJW3Count++]=locals;
			break;
		case NoJump:
			break;
	}
}
/*-------------���3 ----------*/ 
int RightJumpL3Sit(int Jump,int i,int j) //���3����m 
{
	LocalPlace sit;
	sit.localf=19*i+j+2;
	sit.locals=19*i+j+3;
	Jump3BW(Jump,sit.localf,sit.locals);
}

int RightJumpL3Check(char (*p)[6])	//���3���T�{  .1.110
{
	int i,j,Jump=0,b=0,w=0,ch[6];
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			b++;
		}
		else if((*p)[i]==White)
		{
			ch[i]=White;
			w++;
		}
		else ch[i]=None;
	}
	if(ch[0]==None && ch[5]==None)
	{
		if(b==3 || w==3)
		{
			Jump=ThirdCheck(ch,b,w);
			return Jump;
		}
		
	}
	else return None;
}
/*-------------�k�U��3 ----------*/ 
void DownRightJumpL3Sit(int Jump,int i,int j) //�k�U��3����m 
{
	LocalPlace sit;
	sit.localf=19*i+j+19*2+2;
	sit.locals=19*i+j+19*3+3;
	Jump3BW(Jump,sit.localf,sit.locals);
}
int DownRightJumpL3(char (*p)[19])	//���k�U 
{
	int i,j,Jump=0,b=0,w=0,ch[6];
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			b++;
		}
		else if((*p)[i]==White)
		{
			ch[i]=White;
			w++;
		}
		else ch[i]=None;
		p++;
	}
	if(ch[0]==None && ch[5]==None)
	{
		if(b==3 || w==3)
		{
			Jump=ThirdCheck(ch,b,w);
			return Jump;
		}
		
	}
	else return None;
}

/*-------------�U��3 ----------*/ 

void DownJumpL3Sit(int Jump,int i,int j) //�U��3����m 
{
	LocalPlace sit;
	sit.localf=19*i+j+19*2;
	sit.locals=19*i+j+19*3;
	Jump3BW(Jump,sit.localf,sit.locals);
}

int DownJumpL3(char (*p)[19])	
{
	int i,j,Jump=0,b=0,w=0,ch[6];
	for(i=0;i<6;i++)
	{
		if((*p)[0]==Black)
		{
			ch[i]=Black;
			b++;
		}
		else if((*p)[0]==White)
		{
			ch[i]=White;
			w++;
		}
		else ch[i]=None;
		p++;
	}
	if(ch[0]==None && ch[5]==None)
	{
		if(b==3 || w==3)
		{
			Jump=ThirdCheck(ch,b,w);
			return Jump;
		}	
	}
	else return None;
}
/*-------------���U��3 ----------*/ 

void DownLeftJumpL3Sit(int Jump,int i,int j) //�U��3����m 
{
	LocalPlace sit;
	sit.localf=19*i+j-19*2+2;
	sit.locals=19*i+j-19*3+3;
	Jump3BW(Jump,sit.localf,sit.locals);
}

int DownLeftJumpL3(char (*p)[19])	//�����U 
{
	int i,j,Jump=0,b=0,w=0,ch[6];
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			b++;
		}
		else if((*p)[i]==White)
		{
			ch[i]=White;
			w++;
		}
		else ch[i]=None;
		p--;
	}
	if(ch[0]==None && ch[5]==None)
	{
		if(b==3 || w==3)
		{
			Jump=ThirdCheck(ch,b,w);
			return Jump;
		}	
	}
	else return None;
}

/*--------------------------�H�U��3---------------------------- */

Chess RightL3Check(char (*p)[5])	//��T�{ 
{
	int i,j,b=0,w=0;
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black)  b++;
		else if((*p)[i]==White)  w++;
	}
	if((*p)[0]=='.' && (*p)[4]=='.')
	{
		if(b==3)
			return Black;
		else if(w==3)
			return White;
			else
				return None;
	}
	else return None;
}


Chess pickL3BW(int ch[])		//�ˬd��3 
{
	if(ch[0]==None && ch[4]==None)
	{
		if(ch[1]==Black && ch[2]==Black && ch[3]==Black)
		{
			return Black;
		}
		else if(ch[1]==White && ch[2]==White && ch[3]==White)
		{
			return White;
		}
		else return None;
	}
	else return None;
}

void L3BW(int live,int f,int s)		//��3�}�C 
{
	if(live==Black)
	{
		LB3[LB3Count++]=f;
		LB3[LB3Count++]=s;
	}
	else if(live==White)
	{
		LW3[LW3Count++]=f;
		LW3[LW3Count++]=s;
	}
}

int RightL3Sit(int live,int i,int j)	//�Ū����T��m 
{
	LocalPlace sit;
	if(live!=None)
	{
		sit.localf=i*19+j;
		sit.locals=i*19+j+4;
		L3BW(live,sit.localf,sit.locals);
	}
	
}
Chess DownRightL3Check(char(*p)[19])	//�k�U��3 
{
	int i,j;
	int ch[5];
	Chess pd;
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black)  ch[i]=Black;
		else if((*p)[i]==White)  ch[i]=White;
		else ch[i]=None;
		p++;
	}
	pd=pickL3BW(ch);
	if(pd==Black) return Black;
	else if(pd==White) return White;
	else return None;
}

void DownRightL3Sit(int live,int i,int j)	//�k�U���T��m  
{
	LocalPlace sit;
	if(live!=None)
	{
		sit.localf=i*19+j;
		sit.locals=i*19+j+19*4+4;
		L3BW(live,sit.localf,sit.locals);
	}
	
}
Chess DownL3Check(char(*p)[19])	//�U3 
{
	int i,j;
	int ch[5];
	Chess pd;
	for(i=0;i<5;i++)
	{
		if(*p[i]==Black)  ch[i]=Black;
		else if(*p[i]==White)  ch[i]=White;
		else ch[i]=None;
	}
	pd=pickL3BW(ch);
	if(pd==Black) return Black;
	else if(pd==White) return White;
	else return None;
}
int DownL3Sit(int live,int i,int j)	//�U���T��m 
{
	LocalPlace sit;
	if(live!=None)
	{
		sit.localf=i*19+j;
		sit.locals=i*19+j+19*4;
		L3BW(live,sit.localf,sit.locals);					
	}
}
		
Chess DownLeftL3Check(char (*p)[19])	//���U��3 
{
	int i,j;
	int ch[5];
	Chess pd;
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black)  ch[i]=Black;
		else if((*p)[i]==White)  ch[i]=White;
		else ch[i]=None;
		p--;
	}
	pd=pickL3BW(ch);
	if(pd==Black) return Black;
	else if(pd==White) return White;
	else return None;
}

void DownLeftL3Sit(int live,int i,int j)	//���U���T��m 
{
	LocalPlace sit;
	if(live!=None)
	{
		sit.localf=i*19+j;
		sit.locals=(i+4)*19+j-4;
		L3BW(live,sit.localf,sit.locals);
	}
}

void LiveJump3(char board[][19],int i,int j)
{
	int Jump,live;
	if(j<=13)//�� ��3 
	{
		Jump=RightJumpL3Check((char(*)[6]) &board[i][j]);
			RightJumpL3Sit(Jump,i,j);
	}
	
	if(j<=14)//�� ��3 
	{
		live=RightL3Check((char(*)[5]) &board[i][j]);
			RightL3Sit(live,i,j);
	}
	
	if(i<=13 && j<=13)//�ץk�U ��3 
	{
		Jump=DownRightJumpL3((char(*)[19]) &board[i][j]);
					DownRightJumpL3Sit(Jump,i,j);
	}
	
	if(i<=14 && j<=14)//�ץk�U ��3 
	{
		live=DownRightL3Check((char(*)[19]) &board[i][j]);
				DownRightL3Sit(live,i,j);
	}
	
	if(i<=13)
	{
		Jump=DownJumpL3((char(*)[19]) &board[i][j]);
				DownJumpL3Sit(Jump,i,j);
	}
	
	if(i<=14)
	{
		live=DownL3Check((char(*)[19]) &board[i][j]);
		DownL3Sit(live,i,j);
	}
	
	if(i<=13 && j>=5)
	{
		Jump=DownLeftJumpL3((char(*)[19]) &board[i+5][j-5]);
		DownLeftJumpL3Sit(Jump,i+5,j-5);
	}
	
	if(i<=14 && j>=4)	//���U��3 
	{
		live=DownLeftL3Check((char(*)[19]) &board[i+4][j-4]);
		DownLeftL3Sit(live,i,j);
	}
}

void BlackCalculateLD3(int ScoreTable[][19])	//�ܦ��¤��3���p����� 
{
	int i;
	for(i=0;i<LB3Count;i++)						
	{
		int o=0,x=0,y=0;	
		x=LB3[i]/19;
		y=LB3[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
	for(i=0;i<LJB3Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LJB3[i]/19;
		y=LJB3[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
	for(i=0;i<LW3Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LW3[i]/19;
		y=LW3[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
	
	for(i=0;i<LJW3Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LJW3[i]/19;
		y=LJW3[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
}

void WhiteCalculateLD3(int ScoreTable[][19])
{
	int i;
	for(i=0;i<LB3Count;i++)						
	{
		int o=0,x=0,y=0;	
		x=LB3[i]/19;
		y=LB3[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
	
	for(i=0;i<LJB3Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LJB3[i]/19;
		y=LJB3[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
	
	for(i=0;i<LW3Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LW3[i]/19;
		y=LW3[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
	for(i=0;i<LJW3Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LJW3[i]/19;
		y=LJW3[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
}

