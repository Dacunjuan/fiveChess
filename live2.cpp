
#include "head.h"

int LB2[200],LJB2[200],LW2[200],LJW2[200];
int LB2Count=0,LJB2Count=0,LW2Count=0,LJW2Count=0;
#define MyLive 60			
#define EnemyLive 30
void ShowLB2()
{
	ShowL(LB2,LB2Count);
}

void ShowLW2()
{
	ShowL(LW2,LW2Count);
}

void ShowLJB2()
{
	ShowD(LJB2,LJB2Count);
}

void ShowLJW2()
{
	ShowD(LJW2,LJW2Count);
}


/*---------------------直2------------------*/ 

void L2BW(int live,int f,int s)		//活2陣列 
{
	if(live==Black)
	{
		LB2[LB2Count++]=f;
		LB2[LB2Count++]=s;
	}
	else if(live==White)
	{
		LW2[LW2Count++]=f;
		LW2[LW2Count++]=s;
	}
}

Chess pickL2BW(int ch[])		//檢查活2 ..11..
{
	if(ch[0]==None && ch[1]==None && ch[4]==None && ch[5]==None)
	{
		if(ch[2]==Black && ch[3]==Black)
		{
			return Black;
		}
		else if(ch[2]==White && ch[3]==White)
		{
			return White;
		}
		else return None;
	}
	else return None;
}


/*---------------------------橫2--------------*/ 
Chess RightL2Check(char (*p)[6])			//橫 
{
	int i,j,b=0,w=0;
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)  b++;
		else if((*p)[i]==White)  w++;
	}
	if((*p)[0]=='.' && (*p)[1]=='.' && (*p)[4]=='.' && (*p)[5]=='.')
	{
		if(b==2)
			return Black;
		else if(w==2)
			return White;
			
			else
				return None;
	}
	else return None;
} 

int RightL2Sit(int live,int i,int j)
{
	LocalPlace sit;
	if(live!=None)
	{
		sit.localf=i*19+j+1;//.*11..
		sit.locals=i*19+j+4;
		L2BW(live,sit.localf,sit.locals);
		sit.localf=i*19+j;//*.11..
		sit.locals=i*19+j+5;
		L2BW(live,sit.localf,sit.locals);
	}
}

/*---------------------------右下2------------------*/

Chess DownRightL2Check(char(*p)[19])	//右下活2 
{
	int i,j;
	int ch[6];
	Chess pd;
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)  ch[i]=Black;
		else if((*p)[i]==White)  ch[i]=White;
		else ch[i]=None;
		p++;
	}
	pd=pickL2BW(ch);
	if(pd==Black) return Black;
	else if(pd==White) return White;
	else return None;
}

void DownRightL2Sit(int live,int i,int j)	//右下活2位置  
{
	LocalPlace sit;
	if(live!=None)
	{
		sit.localf=i*19+j+19+1;//.*11..
		sit.locals=i*19+j+19*4+4;
		L2BW(live,sit.localf,sit.locals);
		
		sit.localf=i*19+j;//*.11..
		sit.locals=i*19+j+19*5+5;
		L2BW(live,sit.localf,sit.locals);
	}
	
}

/*------------------------下2------------------*/ 

Chess DownL2Check(char(*p)[19])	//下2 
{
	int i,j;
	int ch[6];
	Chess pd;
	for(i=0;i<6;i++)
	{
		if(*p[i]==Black)  ch[i]=Black;
		else if(*p[i]==White)  ch[i]=White;
		else ch[i]=None;
	}
	pd=pickL2BW(ch);
	if(pd==Black) return Black;
	else if(pd==White) return White;
	else return None;
}

int DownL2Sit(int live,int i,int j)	//下活2位置 
{
	LocalPlace sit;
	if(live!=None)
	{
		sit.localf=i*19+j+19;
		sit.locals=i*19+j+19*4;
		L2BW(live,sit.localf,sit.locals);	
		sit.localf=i*19+j;//*.11..
		sit.locals=i*19+j+19*5;
		L2BW(live,sit.localf,sit.locals);						
	}
}
	
/*------------------------左下2------------------*/ 

Chess DownLeftL2Check(char (*p)[19])	//左下活2
{
	int i,j;
	int ch[6];
	Chess pd;
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)  ch[i]=Black;
		else if((*p)[i]==White)  ch[i]=White;
		else ch[i]=None;
		p--;
	}
	pd=pickL2BW(ch);
	if(pd==Black) return Black;
	else if(pd==White) return White;
	else return None;
}

void DownLeftL2Sit(int live,int i,int j)	//左下活2位置  ..11..
{
	LocalPlace sit;
	if(live!=None)
	{
		sit.localf=i*19+j+19-1;
		sit.locals=(i+4)*19+j-4;
		L2BW(live,sit.localf,sit.locals);
		
		sit.localf=i*19+j;//*.11..
		sit.locals=(i+5)*19+j-5;
		L2BW(live,sit.localf,sit.locals);
	}
}

/*-------------------------跳2-------------------*/

void LJ2BW(int live,int f)		//跳2陣列 
{
	if(live==Black)
	{
		LJB2[LJB2Count++]=f;
	}
	else if(live==White)
	{
		LJW2[LJW2Count++]=f;
	}
}

Chess RightLJ2Check(char (*p)[5])
{
	int i,b=0,w=0;
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black) b++;
		if((*p)[i]==White) w++;
	}
	if((*p)[0]=='.' && (*p)[2]=='.' && (*p)[4]=='.') // . 1 . 1 .
	{
		if(b==2)
			return Black;
		if(w==2)
			return White;
	}
	else
		return None;
}

void RightLJ2Sit(int live,int i,int j)	//橫跳2位置 
{
	int sit;
	if(live!=None)
	{
		
		sit=i*19+j+2;
		LJ2BW(live,sit);
		
	}
}

/*---------------右下跳2--------------*/
Chess DownRightLJ2Check(char (*p)[19])
{
	int i,b=0,w=0,ch[5];
	for(i=0;i<5;i++)
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
			else
				ch[i]=None;
		p++;
	}
	if(ch[0]==None && ch[2]==None && ch[4]==None) // . 1 . 1 .
	{
		if(b==2)
			return Black;
		if(w==2)
			return White;
	}
	else
		return None;
}

void DownRightLJ2Sit(int live,int i,int j)	//右下跳2位置 .1.1.
{
	int sit;
	if(live!=None)
	{
	
		sit=i*19+j+19*2+2;
		LJ2BW(live,sit);
		
	}
}

/*-----------------下跳2---------------*/

Chess DownLJ2Check(char (*p)[19])
{
	int i,b=0,w=0,ch[5];
	for(i=0;i<5;i++)
	{
		if(*p[i]==Black)
		{
			ch[i]=Black;
			b++;
		 } 
		else if(*p[i]==White)
		{
			ch[i]=White;
			w++;
		}
			else
				ch[i]=None;
	}
	if(ch[0]==None && ch[2]==None && ch[4]==None) // . 1 . 1 .
	{
		if(b==2)
			return Black;
		if(w==2)
			return White;
	}
	else
		return None;
}

void DownLJ2Sit(int live,int i,int j)	//下跳2 sit
{
	int sit;
	if(live!=None)
	{
		
		sit=i*19+j+19*2;
		LJ2BW(live,sit);
		
	}
}

/*------------------------左下跳2--------------*/

Chess DownLeftLJ2Check(char (*p)[19])
{
	int i,b=0,w=0,ch[5];
	for(i=0;i<5;i++)
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
			else
				ch[i]=None;
		p--;
	}
	if(ch[0]==None && ch[2]==None && ch[4]==None) // . 1 . 1 .
	{
		if(b==2)
			return Black;
		if(w==2)
			return White;
	}
	else
		return None;
}

void DownLeftLJ2Sit(int live,int i,int j)	//左下跳2 sit 
{
	int sit;
	if(live!=None)
	{
		
		sit=i*19+j+19*2-2;
		LJ2BW(live,sit);
		
	}
}


/*-------------統整------------------*/
void LiveJump2(char board[][19],int i,int j)
{
	int live=0;
	/*------------------以下直2------------------*/
	if(j<=13)//橫 
	{
		live=RightL2Check((char(*)[6]) &board[i][j]);
		RightL2Sit(live,i,j);
	}
	if(i<=13 && j<=13)//右下 
	{
		live=DownRightL2Check((char(*)[19]) &board[i][j]);
				DownRightL2Sit(live,i,j);
	}
	if(i<=13)//下 
	{
		live=DownL2Check((char(*)[19]) &board[i][j]);
				DownL2Sit(live,i,j);
	}
	if(i<=13 && j>=5)//左下 
	{
		live=DownLeftL2Check((char(*)[19]) &board[i+5][j-5]);
				DownLeftL2Sit(live,i,j);
	}
	/*------------------以下跳2------------------*/
	if(j<=14)//橫 
	{
		live=RightLJ2Check((char (*)[5]) &board[i][j]);
				RightLJ2Sit(live,i,j);
	}
	if(i<=14 && j<=14)//右下 
	{
		live=DownRightLJ2Check((char (*)[19]) &board[i][j]);
				DownRightLJ2Sit(live,i,j);
	}
	if(i<=14)//下 
	{
		live=DownLJ2Check((char (*)[19]) &board[i][j]);
				DownLJ2Sit(live,i,j);
	}
	if(i<=14 && j>=4)	//左下跳3 
	{
		live=DownLeftLJ2Check((char(*)[19]) &board[i+4][j-4]);
			DownLeftLJ2Sit(live,i,j);
	}
	
}

void BlackCalculateLD2(int ScoreTable[][19])	//變成黑手時2的計算分數 
{
	int i;
	for(i=0;i<LB2Count;i++)						
	{
		int o=0,x=0,y=0;	
		x=LB2[i]/19;
		y=LB2[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
	for(i=0;i<LJB2Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LJB2[i]/19;
		y=LJB2[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
	for(i=0;i<LW2Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LW2[i]/19;
		y=LW2[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
	
	for(i=0;i<LJW2Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LJW2[i]/19;
		y=LJW2[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
}

void WhiteCalculateLD2(int ScoreTable[][19])
{
	int i;
	for(i=0;i<LB2Count;i++)						
	{
		int o=0,x=0,y=0;	
		x=LB2[i]/19;
		y=LB2[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
	
	for(i=0;i<LJB2Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LJB2[i]/19;
		y=LJB2[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
	
	for(i=0;i<LW2Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LW2[i]/19;
		y=LW2[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
	for(i=0;i<LJW2Count;i++)
	{
		int o=0,x=0,y=0;	
		x=LJW2[i]/19;
		y=LJW2[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
}


