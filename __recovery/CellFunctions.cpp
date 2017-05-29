#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "CELL.h"
#include <time.h>

using namespace std;

void  infectOneCell(int i, int j, CELL **&skin, int situation)
{
	//situations:
	//0-ліва верхня клітина
	//1-права верхня клітина
	//2-ліва нижня клітина
	//3-права нижня клітина
	//4-верхній ряд
	//5-нижній ряд
	//6-лівий ряд
	//7-правий ряд
	//8-в середині
	//781
	//6c2
	//543
	int n=0;
	if(situation<=8 && situation>=0)
	{

		switch(situation)
		{
			case 0://ліва верхня клітина
			{
				n=3;
				break;
			}
			case 1://права верхня клітина
			{
				n=3;
				break;
			}
			case 2://ліва нижня клітина
			{
				n=3;
				break;
			}
			case 3://права нижня клітина
			{
				n=3;
				break;
			}
			case 4://верхній ряд
			{
				n=5;
				break;
			}
			case 5://нижній ряд
			{
				n=5;
				break;
			}
			case 6://лiвий ряд
			{
				n=5;
				break;
			}
			case 7://правий ряд
			{
				n=5;
				break;
			}
			case 8://в середині
			{
				n=5;
				break;
			}
		}

	}
	else
		return;

	int K[8], maxStep=n;
	 if(skin[i][j].getStatus()==1&&skin[i][j].getTimeOfInfection()>0)
	 {
		 bool infected = false;
		 int step =1;int z=0,k;
		 while (!infected&&step<maxStep)
		 {
			 bool selected = false;
			 while(!selected)
			 {
				bool flag = true;
                switch(situation)
				{
					case 0://ліва верхня клітина
					{
						k=random(3)+2;
						break;
					}
					case 1://права верхня клітина
					{
						k=random(3)+4;
						break;
					}
					case 2://ліва нижня клітина
					{
						int k1[3]={8,1,2};
						int i = random(3);
						k=k1[i];
						break;
					}
					case 3://права нижня клітина
					{
						k=random(3)+6;
						break;
					}
					case 4://верхній ряд
					{
						k=random(5)+2;
						break;
					}
					case 5://нижній ряд
					{
						int k1[5]={6,7,8,1,2};
						int i = random(5);
						k=k1[i];
						break;
					}
					case 6://лiвий ряд
					{
						int k1[5]={8,1,2,3,4};
						int i = random(5);
						k=k1[i];
						break;
					}
					case 7://правий ряд
					{
						k=random(5)+4;
						break;
					}
					case 8://в середині
					{
						k=random(8)+1;
						break;
					}
				}
				for(int s=0; s<z && z<n; s++)
					if(K[s]==k) flag = false;
				if(flag){selected = true; K[z]=k; z++;}
			 }
			 switch (k)
			 {
				case 1:
				{
					if(skin[i-1][j+1].getStatus()==0)
					{
						bool f;
						int f1=random(2);
						if (f1==0) f =false;
						else if(f1==1) f = true;
						if(f)
						{
							skin[i-1][j+1].setStatus(1);
							infected = true;
							break;
						}
						else if (!f) {step++;infected = true; break;}
					}
					else {step++; break;}
				}
				case 2:
				{
					if(skin[i][j+1].getStatus()==0)
					{
						bool f =random(2);
						if(f)
						{
							skin[i][j+1].setStatus(1);
							infected = true;
							break;
						}
						else {step++;infected = true;break;}
					}
					else {step++; break;}
				}
				case 3:
				{
					if(skin[i+1][j+1].getStatus()==0)
					{
						bool f =random(2);
						if(f)
						{
							skin[i+1][j+1].setStatus(1);
							infected = true;
							break;
						}
						else {step++; infected = true;break;}
					}
					else {step++; break;}
				}
				case 4:
				{
					if(skin[i+1][j].getStatus()==0)
					{
						bool f =random(2);
						if(f)
						{
							skin[i+1][j].setStatus(1);
							infected = true;
							break;
						}
						else {step++;infected = true; break;}
					}
					else {step++; break;}
				}
				case 5:
				{
					if(skin[i+1][j-1].getStatus()==0)
					{
						bool f =random(2);
						if(f)
						{
							skin[i+1][j-1].setStatus(1);
							infected = true;
							break;
						}
						else {step++;infected = true; break;}
					}
					else {step++; break;}
				}
				case 6:
				{
					if(skin[i][j-1].getStatus()==0)
					{
						bool f =random(2);
						if(f)
						{
							skin[i][j-1].setStatus(1);
							infected = true;
							break;
						}
						else {step++; infected = true;break;}
					}
					else {step++; break;}
				}
				case 7:
				{
					if(skin[i-1][j-1].getStatus()==0)
					{
						bool f =random(2);
						if(f)
						{
							skin[i-1][j-1].setStatus(1);
							infected = true;
							break;
						}
						else {step++;infected = true;break;}
					}
					else {step++; break;}
				}
				case 8:
				{
					if(skin[i-1][j].getStatus()==0)
					{
						bool f =random(2);
						if(f)
						{
							skin[i-1][j].setStatus(1);
							infected = true;
							break;
						}
						else {step++; infected = true;break;}
					}
					else {step++; break;}
				}
			 }
		 }
	 }
}
void infect(int N, CELL **&skin)
{
	int c =0;
	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j <N; j++)
		{
/**********/if(i==0&&j==0)///ліва верхня клітина************************************************************************
			{
				infectOneCell(i, j, skin, 0);
			}
/**********/else if(i==0&&j==N-1)///права верхня клітина************************************************************************
			{
				infectOneCell(i, j, skin, 1);
			}
/**********/else if(i==N-1&&j==0)///ліва нижня клітина************************************************************************
			{
				infectOneCell(i, j, skin, 2);
			}
/**********/else if(i==N-1&&j==N-1)///права нижня клітина************************************************************************
			{
				infectOneCell(i, j, skin, 3);
			}
/**********/else if(i==0&&j>0&&j<N-1)///верхній ряд************************************************************************
			{
				infectOneCell(i, j, skin, 4);
			}
/**********/else if(i==N-1&&j>0&&j<N-1)///нижній ряд************************************************************************
			{
				infectOneCell(i, j, skin, 5);
			}
/**********/else if(i>0&&i<N-1&&j==0)///лівий ряд************************************************************************
			{
				infectOneCell(i, j, skin, 6);
			}
/**********/else if(i>0&&i<N-1&&j==N-1)///правий ряд************************************************************************
			{
				infectOneCell(i, j, skin, 7);
			}
/**********/else///в середині****************************************************************************************************
			{
				infectOneCell(i, j, skin, 8);
			}
		}
	}
}
///***************************************************************************************************************************
