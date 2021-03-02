
#include "head.h"


int SPB[200],SPW[200];
int SPBCount=0,SPWCount=0;
#define MyLive 60			
#define EnemyLive 30
void SPBW(int live,int f,int s)		//活2陣列 
{
	if(live==Black)
	{
		SPB[SPBCount++]=f;
		SPB[SPBCount++]=s;
	}
	else if(live==White)
	{
		SPW[SPWCount++]=f;
		SPW[SPWCount++]=s;
	}
}


/*---------------------------特殊直2--------------(..11.0),(0.11..)下第一個或第二個-------*/
/* 	1.  0.11..
	2. 	1.00..
	3.	..11.0
	4.	..00.1*/

int SpecialCheckLB2(int ch[])
{
	if(ch[1]==None && ch[4]==None && ch[5]==None)//*.**..
	{
		if(ch[0]==White && ch[2]==Black && ch[3]==Black)//0.11..
		{
			return 1;
		}
		if(ch[0]==Black && ch[2]==White && ch[3]==White)//1.00..
		{
			return 2;
		}
	}
	
	if(ch[0]==None && ch[1]==None && ch[4]==None)//..**.*
	{
		if(ch[2]==Black && ch[3]==Black && ch[5]==White)//..11.0
		{
			return 3;
		}
		if(ch[2]==White && ch[3]==White && ch[5]==Black)//..00.1
		{
			return 4;
		}
	}
	return 0;	
}

Chess SPRightL2Sit(int State,int i,int j)
{
	/* 	1.  0.11..
		2. 	1.00..
		3.	..11.0
		4.	..00.1*/
	int one=0,two=0;
	switch(State)
	{
		case 1:
			one=i*19+j+4;
			two=i*19+j+5;
			SPBW(Black,one,two);
			break;
		case 2:
			one=i*19+j+4;
			two=i*19+j+5;
			SPBW(White,one,two);
			break;
		case 3:
			one=i*19+j;
			two=i*19+j+1;
			SPBW(Black,one,two);
			break;
		case 4:
			one=i*19+j;
			two=i*19+j+1;
			SPBW(White,one,two);
			break;
		case 0:
			break;
	}
}

Chess SPRightL2Check(char (*p)[6],int x,int y)//衡的 
{
	int i,b=0,w=0,ch[6];
	int State=0;
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
			else
				ch[i]=None;
	}
	State=SpecialCheckLB2(ch);
	SPRightL2Sit(State,x,y);
} 

Chess SPDownRightL2Sit(int State,int i,int j)//DownRight Live 2 sit 
{
	/* 	1.  0.11..
		2. 	1.00..
		3.	..11.0
		4.	..00.1*/
	int one=0,two=0;
	switch(State)
	{
		case 1:
			one=i*19+j+19*4+4;
			two=i*19+j+19*5+5;
			SPBW(Black,one,two);
			break;
		case 2:
			one=i*19+j+19*4+4;
			two=i*19+j+19*5+5;
			SPBW(White,one,two);
			break;
		case 3:
			one=i*19+j;
			two=i*19+j+19+1;
			SPBW(Black,one,two);
			break;
		case 4:
			one=i*19+j;
			two=i*19+j+19+1;
			SPBW(White,one,two);
			break;
		case 0:
			break;
	}
}


Chess SPDownRightL2Check(char (*p)[19],int x,int y)//右下的 
{
	int i,ch[6];
	int State=0;
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
			ch[i]=Black;
		else if((*p)[i]==White)
			ch[i]=White;
			else
				ch[i]=None;
		p++;
	}
	State=SpecialCheckLB2(ch);
	SPDownRightL2Sit(State,x,y);
} 

Chess SPDownL2Sit(int State,int i,int j)//DownRight Live 2 sit 
{
	/* 	1.  0.11..
		2. 	1.00..
		3.	..11.0
		4.	..00.1*/
	int one=0,two=0;
	switch(State)
	{
		case 1:
			one=i*19+j+19*4;
			two=i*19+j+19*5;
			SPBW(Black,one,two);
			break;
		case 2:
			one=i*19+j+19*4;
			two=i*19+j+19*5;
			SPBW(White,one,two);
			break;
		case 3:
			one=i*19+j;
			two=i*19+j+19;
			SPBW(Black,one,two);
			break;
		case 4:
			one=i*19+j;
			two=i*19+j+19;
			SPBW(White,one,two);
			break;
		case 0:
			break;
	}
}


Chess SPDownL2Check(char (*p)[19],int x,int y)//往下的 
{
	int i,b=0,w=0,ch[6];
	int State=0;
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
			else
				ch[i]=None;
		p++;
	}
	State=SpecialCheckLB2(ch);
	SPDownL2Sit(State,x,y);
}

Chess SPDownLeftL2Sit(int State,int i,int j)//DownRight Live 2 sit 
{
	/* 	1.  0.11..
		2. 	1.00..
		3.	..11.0
		4.	..00.1*/
	int one=0,two=0;
	switch(State)
	{
		case 1:
			one=i*19+j;
			two=i*19+j+19-1;
			SPBW(Black,one,two);
			break;
		case 2:
			one=i*19+j;
			two=i*19+j+19-1;
			SPBW(White,one,two);
			break;
		case 3:
			one=i*19+j+19*4-4;
			two=i*19+j+19*5-5;
			SPBW(Black,one,two);
			break;
		case 4:
			one=i*19+j+19*4-4;
			two=i*19+j+19*5-5;
			SPBW(White,one,two);
			break;
		case 0:
			break;
	}
}

Chess SPDownLeftL2Check(char (*p)[19],int x,int y)//左下的 
{
	int i,ch[6];
	int State=0;
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
			ch[i]=Black;
		else if((*p)[i]==White)
			ch[i]=White;
			else
				ch[i]=None;
		p--;
	}
	State=SpecialCheckLB2(ch);
	SPDownLeftL2Sit(State,x,y);
}  

/*-------------------直3------------- 0111.. */ 
/*	1.	0111..
	2.	1000..
	3.	..1110
	4.	..0001
*/
int StraitCheckL3(int ch[])
{
	if(ch[4]==None && ch[5]==None)
	{
		if(ch[0]==White && ch[1]==Black && ch[2]==Black && ch[3]==Black)
			return 1;
		if(ch[0]==Black && ch[1]==White && ch[2]==White && ch[3]==White)
			return 2;
	}
	
	if(ch[0]==None && ch[1]==None)
	{
		if(ch[2]==Black && ch[3]==Black && ch[4]==Black && ch[5]==White)
			return 3;
		if(ch[2]==White && ch[3]==White && ch[4]==White && ch[5]==Black)
			return 4;
	}
}

Chess StraitRightL3(char (*p)[6],int x,int y)
{
	int i,b=0,w=0,ch[6];
	int State=0;
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
			else
				ch[i]=None;
	}
	State=StraitCheckL3(ch);
	SPRightL2Sit(State,x,y);//分數一樣 所以用上面的函式 
}

Chess StraitDownRightL3(char (*p)[19],int x,int y)
{
	int i,ch[6];
	int State=0;
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
			ch[i]=Black;
		else if((*p)[i]==White)
			ch[i]=White;
			else
				ch[i]=None;
		p++;
	}
	State=StraitCheckL3(ch);
	SPDownRightL2Sit(State,x,y);
}

Chess StraitDownL3Check(char (*p)[19],int x,int y)//往下的 
{
	int i,b=0,w=0,ch[6];
	int State=0;
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
			else
				ch[i]=None;
		p++;
	}
	State=StraitCheckL3(ch);
	SPDownL2Sit(State,x,y);
}

Chess StraitDownLeftL3Check(char (*p)[19],int x,int y)//左下的 
{
	int i,ch[6];
	int State=0;
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
			ch[i]=Black;
		else if((*p)[i]==White)
			ch[i]=White;
			else
				ch[i]=None;
		p--;
	}
	State=StraitCheckL3(ch);
	SPDownLeftL2Sit(State,x,y);
}  

void Attack(char board[][19],int i,int j)
{
	if(j<=13)//橫 
	{
		SPRightL2Check((char(*)[6]) &board[i][j],i,j);
		
		StraitRightL3((char(*)[6]) &board[i][j],i,j);
	}
	if(i<=13 && j<=13)//右下 
	{
		SPDownRightL2Check((char (*)[19]) &board[i][j],i,j);
		
		StraitDownRightL3((char (*)[19]) &board[i][j],i,j);
	}
	if(i<=13)//下 
	{
		SPDownL2Check((char (*)[19]) &board[i][j],i,j);
		
		StraitDownL3Check((char (*)[19]) &board[i][j],i,j);
	}
	if(i<=13 && j>=5)//左下 
	{
		SPDownLeftL2Check((char (*)[19]) &board[i+5][j-5],i,j);
		
		StraitDownLeftL3Check((char (*)[19]) &board[i+5][j-5],i,j);
	}
}

void BlackCalculateAttack(int ScoreTable[][19])	//變成黑手時3的計算分數 
{
	int i;
	for(i=0;i<SPBCount;i++)						
	{
		int o=0,x=0,y=0;	
		x=SPB[i]/19;
		y=SPB[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}

	for(i=0;i<SPWCount;i++)
	{
		int o=0,x=0,y=0;	
		x=SPW[i]/19;
		y=SPW[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
}

void WhiteCalculateAttack(int ScoreTable[][19])
{
	int i;
	for(i=0;i<SPBCount;i++)						
	{
		int o=0,x=0,y=0;	
		x=SPB[i]/19;
		y=SPB[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}

	for(i=0;i<SPWCount;i++)
	{
		int o=0,x=0,y=0;	
		x=SPW[i]/19;
		y=SPW[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
}


