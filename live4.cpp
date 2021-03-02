#include "head.h"

int LBCount=0,LWCount=0,DBCount=0,DWCount=0;
int LB[200],LW[200],DB[200],DW[200];

#define MyLive 5000			
#define EnemyLive 3000
/*.1111. .0000. 01111. 11.11 1.111*/
void PrintLiveBlock(int x,int y)	//�����@�� 
{
	char a[]="ABCDEFGHIJKLMNOPQRS";
	{
		printf("%c, %d\n",a[y],x+1);
	}
	
}

void showeLiveBlack()	//�q�X���� 
{
	int i;
	if(LBCount==0)
	{
		printf("None\n");
	}
	for(i=0;i<LBCount;i++)
	{
		int o=0,x=0,y=0;
		
		o=LB[i];
		x=o/19;
		y=LB[i]-x*19;
		PrintLiveBlock(x,y);
		if((i+2)%2==0)printf("-");
		if((i+1)%2==0) printf("\n");
	}
}

void showeLiveWhite()	//�q�X���� 
{
	int i;
	if(LWCount==0)
	{
		printf("None\n");
	}
	for(i=0;i<LWCount;i++)
	{
		int o=0,x=0,y=0;
		
		o=LW[i];
		x=o/19;
		y=LW[i]-x*19;
		PrintLiveBlock(x,y);
		if((i+2)%2==0)printf("-");
		if((i+1)%2==0) printf("\n");
	}
}

void showeDeadBlack()	//�q�X��
{
	int i;
	if(DBCount==0)
	{
		printf("None\n");
	}
	for(i=0;i<DBCount;i++)
	{
		int o=0,x=0,y=0;
		o=DB[i];
		x=o/19;
		y=DB[i]-x*19;
		PrintLiveBlock(x,y);
		printf("\n");
	}
}

void showeDeadWhite()	//�q�X��
{
	int i;
	if(DWCount==0)
	{
		printf("None\n");
	}
	for(i=0;i<DWCount;i++)
	{
		int o=0,x=0,y=0;
		o=DW[i];
		x=o/19;
		y=DW[i]-x*19;
		PrintLiveBlock(x,y);
		printf("\n");
	}
}


Chess LiveCheckBW(int live,int local)	//�N������J�}�C�� 
{
	if(live==Black)
	{
		LB[LBCount]=local;
		LBCount+=1;
	}
	else if(live==White)
	{
		LW[LWCount]=local;
		LWCount+=1;
	}
}

Chess pickBW(int ch[])				//�ˬd��4 		
{
	if(ch[0]==None && ch[5]==None)
	{
		if(ch[1]==Black && ch[2]==Black && ch[3]==Black && ch[4]==Black)
		{
			return Black;
		}
		else if(ch[1]==White && ch[2]==White && ch[3]==White && ch[4]==White)
		{
			return White;
		}
		else return None;
	}
	else return None;
}
/*------------------------------�H�U�}�l�����P�_--------------------*/ 
Chess RightL4Check(char (*p)[6])	//��T�{ 
{
	int i,j,b=0,w=0;
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)  b++;
		else if((*p)[i]==White)  w++;
	}
	if((*p)[0]=='.' && (*p)[5]=='.')
	{
		if(b==4)
			return Black;
		else if(w==4)
			return White;
			else
				return None;
	}
	else return None;
}

Chess DownRightL4Check(char (*p)[19])	//���k�U 
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
	pd=pickBW(ch);
	if(pd==Black) return Black;
	else if(pd==White) return White;
	else return None;
}

Chess DownL4Check(char (*p)[19])	//���U 
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
	pd=pickBW(ch);
	if(pd==Black) return Black;
	else if(pd==White) return White;
	else return None;
}

Chess DownLeftCheck(char (*p)[19])	//���U 
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
	pd=pickBW(ch);
	if(pd==Black) return Black;
	else if(pd==White) return White;
	else return None;
}

/*-----------------------------------�H�U�}�l�����P�_-------------------------*/ 
DeadChess pickD6BW(int ch[])			//�ˬd��4 	
{
	int No=0,Ns=0;
	if(ch[0]==None) No++;
	if(ch[5]==None) Ns++;
	if((No-Ns)!=0)
	{
		if(ch[1]==Black && ch[2]==Black && ch[3]==Black && ch[4]==Black)
		{
			if(No==1)
			{
				return DBO;
			}
			else if(Ns==1)
			{
				return DBN;
			}
		}
		else if(ch[1]==White && ch[2]==White && ch[3]==White && ch[4]==White)
		{
			if(No==1)
			{
				return DWO;
			}
			else if(Ns==1)
			{
				return DWN;
			}
		}
		else return NoOne;
	}
	else return NoOne;
}

LocalPlace DeadRightCheckBW(int i,int j)  //�p�⩹�k����m 
{
	int localf=0,locals=0;
	LocalPlace sit;
	sit.localf=i*19+j;
	sit.locals=i*19+j+5;
	return sit;
}

LocalPlace SideDeadRightCheckBW(int i,int j)  //�p�⩹�k��Ҫ���m 
{
	int localf=0,locals=0;
	LocalPlace sit;
	sit.localf=i*19+j;
	sit.locals=i*19+j+4;
	return sit;
}

void DeadSw(int dead,LocalPlace sit)		//�N������i�}�C�� 
{
	switch(dead)
	{
		case DBO:
			DB[DBCount]=sit.localf;
			DBCount+=1;
			break;
		case DBN:
			DB[DBCount]=sit.locals;
			DBCount+=1;
			break;
		case DWO:
			DW[DWCount]=sit.localf;
			DWCount+=1;
			break;
		case DWN:
			DW[DWCount]=sit.locals;
			DWCount+=1;
			break;
		case NoOne:
			break;
	}
}


int RightD4Check(char (*p)[6])		//�� �k 
{
	int i,j,B=0,W=0,ans=0;
	int ch[6];
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			B++;
		  }  
		else if((*p)[i]==White)
		{
			ch[i]=White;
			W++;
		  }  
		else ch[i]=None;
	}
	if(B>=5 || W>=5)
	{
		return NoOne;
	}
	ans=pickD6BW(ch);
	return ans;
}

DeadChess FirstRightD4CheckLast(char (*p)[5])	//�� �k �̫� ����	
{
	int i,j,B=0,W=0,ans=0;
	int ch[5];
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			B++;
		  }  
		else if((*p)[i]==White)
		{
			ch[i]=White;
			W++;
		  }  
		else ch[i]=None;
	}
	if(ch[4]==None)
	{
		if(B==4) return DBN;
		else if (W==4) return DWN;
		else return NoOne;
	}
	else
	return NoOne;
}

DeadChess SecondRightD4CheckLast(char (*p)[5])	//�� �k �̫� �k�� 
{
	int i,j,B=0,W=0,ans=0;
	int ch[5];
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			B++;
		  }  
		else if((*p)[i]==White)
		{
			ch[i]=White;
			W++;
		  }  
		else ch[i]=None;
	}
	if(ch[0]==None)
	{
		if(B==4) return DBO;
		else if (W==4) return DWO;
		else return NoOne;
	}
	else
	return NoOne;
}

int DownD4Check(char (*p)[19])		//�� �U 
{
	int i,j,B=0,W=0,ans=0;
	int ch[6];
	for(i=0;i<6;i++)
	{
		if((*p)[0]==Black) 
		{
			ch[i]=Black;
			B++;
		}
		else if((*p)[0]==White)
		{
			ch[i]=White;
			W++;
		}  
		else ch[i]=None;
		p++;
	}
	if(B>=5 || W>=5)
	{
		return NoOne;
	}
	ans=pickD6BW(ch);
	return ans;
}
LocalPlace DeadDownCheckBW(int i,int j) //�p�⩹�U����} 
{
	int localf=0,locals=0;
	LocalPlace sit;
	sit.localf=i*19+j+19-19;
	sit.locals=i*19+j+19*5;
	return sit;
}

LocalPlace SideDeadDownCheckBW(int i,int j) //�p�⩹�U����} 
{
	int localf=0,locals=0;
	LocalPlace sit;
	sit.localf=i*19+j;
	sit.locals=i*19+j+19*4;
	return sit;
}

int FirstDownD4CheckLast(char (*p)[19])	//�� �U �̫� �U�� �^�ǤW�� 
{
	int i,j,B=0,W=0,ans=0;
	int ch[5];
	for(i=0;i<5;i++)
	{
		if((*p)[0]==Black)
		{
			ch[i]=Black;
			B++;
		}  
		else if((*p)[0]==White)
			{
				ch[i]=White;
				W++;
			}  
				else ch[i]=None;
		p++;
	}
	if(ch[0]==None)
	{
		if(B==4) return DBO;
		else if (W==4) return DWO;
		else return NoOne;
	}
	return NoOne;
}

int Num2DownD4CheckLast(char (*p)[19])	//�� �U �̫� �W�� �^�ǤU�� 
{
	int i,j,B=0,W=0,ans=0;
	int ch[5];
	for(i=0;i<5;i++)
	{
		if((*p)[0]==Black)
		{
			ch[i]=Black;
			B++;
		}  
		else if((*p)[0]==White)
			{
				ch[i]=White;
				W++;
			}  
				else ch[i]=None;
		p++;
	}
	if(ch[4]==None)
	{
		if(B==4) return DBN;
		else if (W==4) return DWN;
		else return NoOne;
	}
	return NoOne;
}




int DownRightD4Check(char (*p)[19])		//�� �k�U 
{
	int i,j,B=0,W=0,ans=0;
	int ch[6];
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			B++;
		 } 
		else if((*p)[i]==White)
		{
			ch[i]=White;
			W++;
		  }  
		else ch[i]=None;
		p++;
	}
	if(B>=5 || W>=5)
	{
		return NoOne;
	}
	ans=pickD6BW(ch);
	return ans;
}

int Num2DownRightD4CheckLast(char (*p)[19])		//�� �k�U �̫� 
{
	int i,j,B=0,W=0,ans=0;
	int ch[5];
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			B++;
		}  
		else if((*p)[i]==White)
			{
				ch[i]=White;
				W++;
			}  
				else ch[i]=None;
		p++;
	}
	if(ch[4]==None)
	{
		if(B==4) return DBN;
		else if (W==4) return DWN;
		else return NoOne;
	}
	return NoOne;
}

int OneDownRightD4CheckLast(char (*p)[19])		//�� �k�U �̫� one
{
	int i,j,B=0,W=0,ans=0;
	int ch[5];
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			B++;
		}  
		else if((*p)[i]==White)
			{
				ch[i]=White;
				W++;
			}  
				else ch[i]=None;
		p++;
	}
	if(ch[0]==None)
	{
		if(B==4) return DBO;
		else if (W==4) return DWO;
		else return NoOne;
	}
	return NoOne;
}


LocalPlace DeadDownRightCheckBW(int i,int j) //�p�⩹�k�U����} 
{
	int localf=0,locals=0;
	LocalPlace sit;
	sit.localf=i*19+j;
	sit.locals=i*19+j+19*5+5;
	return sit;
}

LocalPlace DeadDownRightCheckBWLast(int i,int j) //�p�⩹�k�U����}���� 
{
	int localf=0,locals=0;
	LocalPlace sit;
	sit.localf=i*19+j;
	sit.locals=i*19+j+19*4+4;
	return sit;
}

LocalPlace SideDeadDownRightCheckBWLast(int i,int j) //�p�⩹�k�U����}���� 
{
	int localf=0,locals=0;
	LocalPlace sit;
	sit.localf=i*19+j;
	sit.locals=i*19+j+19*4+4;
	return sit;
}


int DownLeftD4Check(char (*p)[19])		//�� ���U 
{
	int i,j,B=0,W=0,ans=0;
	int ch[6];
	for(i=0;i<6;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			B++;
		  }  
		else if((*p)[i]==White)
		{
			ch[i]=White;
			W++;
		  }  
		else ch[i]=None;
		p--;
	}
	if(B>=5 || W>=5)
	{
		return NoOne;
	}
	ans=pickD6BW(ch);
	return ans;
}

LocalPlace DeadDownLeftCheckBW(int i,int j) //�p�⩹���U����} 
{
	int localf=0,locals=0;
	LocalPlace sit;
	sit.localf=(i+5)*19+j-5;
	sit.locals=(i)*19+j;
	return sit;
}

int OneDownLeftD4CheckLast(char (*p)[19])		//�� ���U 
{
	int i,j,B=0,W=0,ans=0;
	int ch[5];
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			B++;
		}  
		else if((*p)[i]==White)
			{
				ch[i]=White;
				W++;
			}  
				else ch[i]=None;
		p--;
	}
	if(ch[0]==None)
	{
		if(B==4) return DBO;
		else if (W==4) return DWO;
		else return NoOne;
	}
	return NoOne;
}

int Num2DownLeftD4CheckLast(char (*p)[19])		//�� ���U 
{
	int i,j,B=0,W=0,ans=0;
	int ch[5];
	for(i=0;i<5;i++)
	{
		if((*p)[i]==Black)
		{
			ch[i]=Black;
			B++;
		}  
		else if((*p)[i]==White)
			{
				ch[i]=White;
				W++;
			}  
				else ch[i]=None;
		p--;
	}
	if(ch[4]==None)
	{
		if(B==4) return DBN;
		else if (W==4) return DWN;
		else return NoOne;
	}
	return NoOne;
}

LocalPlace DeadDownLeftCheckBWLast(int i,int j) //�p�⩹���U����} 
{
	int localf=0,locals=0;
	LocalPlace sit;
	sit.localf=(i+4)*19+j-4;
	sit.locals=(i)*19+j;
	return sit;
}

/*---------------------��4----------- 1.111 111.1 11.11 ----*/
/*	1=	1.111 
	2=	11.11 
	3=	111.1 
	11=	0.000 
	12=	00.00 
	13=	000.0 */

int Special4(int ch[])				//�P�_��4 
{
	if(ch[1]==None)
		return 1;
	if(ch[2]==None)
		return 2;
	if(ch[3]==None)
		return 3;

	else 
		return 0;
}

void Jump4BW(int sit,int b,int w)		//��4�}�C 
{
	if(b==4)
	{
		DB[DBCount]=sit;
		DBCount+=1;
	}
	if(w==4)
	{
		DW[DWCount]=sit;
		DWCount+=1;
	}
}

int SpecialRightSit(int State,int i,int j)	//��4��} 
{
	int sit;
	switch(State)
	{
		case 1:
			sit=i*19+j+1;
			return sit;
			break;
		case 2:
			sit=i*19+j+2;
			return sit;
			break;
		case 3:
			sit=i*19+j+3;
			return sit;
			break;
	}
}

void SpecialRight4(char(*p)[5],int x,int y)	//��4 ������ 
{
	int i,b=0,w=0,n=0,ch[5];
	int sit=0,State=0;
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
		{
			ch[i]=None;
			n++;
		}	
	}
	if(n==1)
		State=Special4(ch);
	if(State!=0)
	{
		sit=SpecialRightSit(State,x,y);
		Jump4BW(sit,b,w);
	}
}

int SpecialDownRightSit(int State,int i,int j)	//��4 �k�U��} 
{
	int sit;
	switch(State)
	{
		case 1:
			sit=(i+1)*19+j+1;
			return sit;
			break;
		case 2:
			sit=(i+2)*19+j+2;
			return sit;
			break;
		case 3:
			sit=(i+3)*19+j+3;
			return sit;
			break;
	}
}

void SpecialDownRight4(char(*p)[19],int x,int y)	//��4 �k�U���� 
{
	int i,b=0,w=0,n=0,ch[5];
	int sit=0,State=0;
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
		{
			ch[i]=None;
			n++;
		}
		p++;
	}
	if(n==1)
		State=Special4(ch);
	if(State!=0)
	{
		sit=SpecialDownRightSit(State,x,y);
		Jump4BW(sit,b,w);
	}
}

int SpecialDownSit(int State,int i,int j)	//��4 �U��} 
{
	int sit;
	switch(State)
	{
		case 1:
			sit=(i+1)*19+j;
			return sit;
			break;
		case 2:
			sit=(i+2)*19+j;
			return sit;
			break;
		case 3:
			sit=(i+3)*19+j;
			return sit;
			break;
	}
}

void SpecialDown4(char(*p)[19],int x,int y)	//��4 �U���� 
{
	int i,b=0,w=0,n=0,ch[5];
	int sit=0,State=0;
	for(i=0;i<5;i++)
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
		{
			ch[i]=None;
			n++;
		}
		p++;
	}
	if(n==1)
		State=Special4(ch);
	if(State!=0)
	{
		sit=SpecialDownSit(State,x,y);
		Jump4BW(sit,b,w);
	}
}

int SpecialDownLeftSit(int State,int i,int j)	//��4 ���U��} 
{
	int sit;
	switch(State)
	{
		case 1:
			sit=(i+3)*19+j-3;
			return sit;
			break;
		case 2:
			sit=(i+2)*19+j-2;
			return sit;
			break;
		case 3:
			sit=(i+1)*19+j-1;
			return sit;
			break;
	}
}

void SpecialDownLeft4(char(*p)[19],int x,int y)	//��4 ���U���� 
{
	int i,b=0,w=0,n=0,ch[5];
	int sit=0,State=0;
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
		{
			ch[i]=None;
			n++;
		}
		p--;
	}
	if(n==1)
		State=Special4(ch);
	if(State!=0)
	{
		sit=SpecialDownLeftSit(State,x,y);
		Jump4BW(sit,b,w);
	}
}

/*---------------�j�ξ�-------------------------*/ 

void LiveDead4(char board[][19],int i,int j)	//�N���P��4�g���@������ 
{
	int live,dead,local;
	int jump;
	LocalPlace sit;
			if(j<=13)//�Ū�  ���X�@�� ���P4 
			{
				dead=RightD4Check((char(*)[6]) &board[i][j]);	//dead4 right
				sit=DeadRightCheckBW(i,j);						//dead4 position
				DeadSw(dead,sit);								//put dead4 in array
				
				live=RightL4Check((char(*)[6]) &board[i][j]);	//live right
					local=i*19+j;								//live local
						LiveCheckBW(live,local);				
					local=i*19+j+5;
						LiveCheckBW(live,local);
			}
			if(j<=14)
			{
				SpecialRight4((char(*)[5]) &board[i][j],i,j);
			}
			if(i<=14 && j<=14)
			{
				SpecialDownRight4((char(*)[19]) &board[i][j],i,j);
			}
			if(i<=13)
			{
				SpecialDown4((char(*)[19]) &board[i][j],i,j);
			}
			if(i<=14 && j>=4)
			{
				SpecialDownLeft4((char(*)[19]) &board[i+4][j-4],i,j);
			}
			if(j==14 || j==0 )//������  
			{
				if(j==0)
				{
					dead=FirstRightD4CheckLast((char(*)[5]) &board[i][j]);
						sit=SideDeadRightCheckBW(i,j);
						DeadSw(dead,sit);
				}
				if(j==14)
				{
					dead=SecondRightD4CheckLast((char(*)[5]) &board[i][j]);
						sit=SideDeadRightCheckBW(i,j);
						DeadSw(dead,sit);
				}									
			}
			//�ץk�U 
			if(i<=13 && j<=13)
			{
				live=DownRightL4Check((char(*)[19]) &board[i][j]);
				local=i*19+j;
					LiveCheckBW(live,local);
				local=i*19+j+19*5+5;
					LiveCheckBW(live,local);
					
			}
			
			if(i<=13 && j<=13)//�ץk�U  �� 
			{
				dead=DownRightD4Check((char(*)[19]) &board[i][j]);
				sit=DeadDownRightCheckBW(i,j);
				DeadSw(dead,sit);
			}
			if((i==0 && j<=14) || (i<=14 && i>=1 && j==0))//�� �ץk�U���� OK
			{
				dead=Num2DownRightD4CheckLast((char(*)[19]) &board[i][j]);
				sit=DeadDownRightCheckBWLast(i,j);
				DeadSw(dead,sit);
			}
			if((j==14 && i<=14) || (i==14 && j<=13))
			{
				dead=OneDownRightD4CheckLast((char(*)[19]) &board[i][j]);
				sit=DeadDownRightCheckBWLast(i,j);
				DeadSw(dead,sit);
			}
			
			//�U 
			if(i<=13)
			{
				dead=DownD4Check((char(*)[19]) &board[i][j]);
				sit=DeadDownCheckBW(i,j);
				DeadSw(dead,sit);
					live=DownL4Check((char(*)[19]) &board[i][j]);
					local=i*19+j;
					LiveCheckBW(live,local);
					local=i*19+j+19*5;
					LiveCheckBW(live,local);
			
			}
			
			if(i==14 || i==0)//�� �U OK
			{
				if(i==0)
				{
					dead=Num2DownD4CheckLast((char(*)[19]) &board[i][j]);
					sit=SideDeadDownCheckBW(i,j);
					DeadSw(dead,sit);
				}
				if(i==14)
				{
					dead=FirstDownD4CheckLast((char(*)[19]) &board[i][j]);
					sit=SideDeadDownCheckBW(i,j);
					DeadSw(dead,sit);
				}
				
			}
			//���U
			if(i<=13 && j>=5)
			{
				dead=DownLeftD4Check((char(*)[19]) &board[i+5][j-5]);
				sit=DeadDownLeftCheckBW(i,j);
				DeadSw(dead,sit);
					live=DownLeftCheck((char(*)[19]) &board[i+5][j-5]);
					local=i*19+j;
						LiveCheckBW(live,local);
					local=(i+5)*19+j-5;
				 		LiveCheckBW(live,local);
				
			}  
			  
			 
			if((i==0 && j>=4) || (i>=1 && i<=14 && j==18))//�� �ץ��U���� 
			{
				
				dead=OneDownLeftD4CheckLast((char(*)[19]) &board[i+4][j-4]);
				sit=DeadDownLeftCheckBWLast(i,j);
				DeadSw(dead,sit);
			}
			if((j==4 && i<=14) || (j>=5 && j<=18 && i==14))
			{
				dead=Num2DownLeftD4CheckLast((char(*)[19]) &board[i+4][j-4]);
				sit=DeadDownLeftCheckBWLast(i,j);
				DeadSw(dead,sit);
			}
}

void BlackCalculateLD4(int ScoreTable[][19])	//�ܦ��¤��4���p����� 
{
	int i;
	
	for(i=0;i<LBCount;i++)
	{
		int o=0,x=0,y=0;	
		x=LB[i]/19;
		y=LB[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
	for(i=0;i<DBCount;i++)
	{
		int o=0,x=0,y=0;	
		x=DB[i]/19;
		y=DB[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
	for(i=0;i<LWCount;i++)
	{
		int o=0,x=0,y=0;	
		x=LW[i]/19;
		y=LW[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
	
	for(i=0;i<DWCount;i++)
	{
		int o=0,x=0,y=0;	
		x=DW[i]/19;
		y=DW[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
}

void WhiteCalculateLD4(int ScoreTable[][19])		//�ܦ��դ��4���p�����  
{
	int i;
	for(i=0;i<LBCount;i++)
	{
		int o=0,x=0,y=0;	
		x=LB[i]/19;
		y=LB[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
	
	for(i=0;i<DBCount;i++)
	{
		int o=0,x=0,y=0;	
		x=DB[i]/19;
		y=DB[i]-x*19;
		ScoreTable[x][y]+=EnemyLive;
	}
	
	for(i=0;i<LWCount;i++)
	{
		int o=0,x=0,y=0;	
		x=LW[i]/19;
		y=LW[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
	for(i=0;i<DWCount;i++)
	{
		int o=0,x=0,y=0;	
		x=DW[i]/19;
		y=DW[i]-x*19;
		ScoreTable[x][y]+=MyLive;
	}
	
}

void PrintAll4()			//�ˬd�}�C������ 
{
	int i,j;
	
	printf("LBarray: ");
	for(i=0;i<LBCount;i++)
	{
		printf("%d ",LB[i]);
	}
	printf("\n");
	
	printf("LWarray: ");
	for(i=0;i<LWCount;i++)
	{
		printf("%d ",LW[i]);
	}
	printf("\n");
	
	printf("DBarray: ");
	for(i=0;i<DBCount;i++)
	{
		printf("%d ",DB[i]);
	}
	printf("\n");
	
	printf("DWarray: ");
	for(i=0;i<DWCount;i++)
	{
		printf("%d ",DW[i]);
	}
	printf("\n");
}

