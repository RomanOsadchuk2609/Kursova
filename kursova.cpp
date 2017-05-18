//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Windows.h>
#include "CELL.h"
#include "CellFunctions.h"
#include "kursova.h"
#include "errorform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
///�������
	int N;
	double Pause;
	//Pause = StrToFloat(EditPause->Text);
	Pause = TrackBarDayTime->Position;
	if(Pause == 0) Pause = 10;
	N=StrToInt(EditN->Text);
	if(N>1&&N%2!=0)
	{
		int A = Form1->ClientHeight;
		double X, Y= A/N;
		if(N<6) X = A/(25*N);
		else if(N>=6&&N<10) X = A/(15*N);
		else if(N>=10&&N<30) X = A/(10*N);
		else if(N>=30&&N<70) X= A/(7*N);
		else if(N>=70&&N<100) X = A/(5*N);
		else if(N>=101&&N<200) X = A/(3*N);
		else return;

		int I=N/2, J=N/2;
		CELL **skin = new CELL*[N];
		for (int i=0; i<N; i++)
		skin[i] = new CELL[N];
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
			{
				skin[i][j].setStatus(0);
				skin[i][j].setTimeOfInfection(0);
				skin[i][j].setTimeOfImmunity(0);
			}

		skin[I][J].setStatus(1);
		skin[I][J].setTimeOfInfection(1);
		int infected=1, healthy=N*N-1, healed=0, DaySinceStartOfInfection=1;

		//Canvas->Pen->Color=(TColor)RGB(255,255,255);
		//Canvas->Brush->Color=(TColor)RGB(255,255,255);
		Canvas->Pen->Color=clInactiveBorder;
		Canvas->Brush->Color= clInactiveBorder;
		Canvas->Rectangle(0,0,Form1->ClientHeight,Form1->ClientHeight);
        randomize();
		for(int i=0; i<N; i++)
			for(int j =0; j<N; j++)
				{

					if(skin[i][j].getStatus()==0)
					{
						Canvas->Pen->Color=ColorBoxHealthy->Selected;
						Canvas->Brush->Color=ColorBoxHealthy->Selected;
					}
					else if(skin[i][j].getStatus()==1)
					{
						Canvas->Pen->Color=ColorBoxInfected->Selected;
						Canvas->Brush->Color=ColorBoxInfected->Selected;
					}
					else if(skin[i][j].getStatus()==2)
					{
						Canvas->Pen->Color=ColorBoxHealed->Selected;
						Canvas->Brush->Color=ColorBoxHealed->Selected;
					}
					Canvas->Rectangle(j*A/N,i*A/N,j*A/N+A/N-X,i*A/N+A/N-X);
					/*Memo1->Lines->Clear();
					Memo1->Lines->Append("\nʳ������ �������� �����: "+IntToStr(healthy));
					Memo1->Lines->Append("\nʳ������ ����������� �����: "+IntToStr(infected));
					Memo1->Lines->Append("\nʳ������ ����� �  ����������: "+IntToStr(healed));
					Memo1->Lines->Append("\nʲ������ ���� �� ������� ��������: "+IntToStr(DaySinceStartOfInfection));   */
				}
		Memo1->Lines->Clear();
		Memo1->Lines->Append("\nʳ������ �������� �����: "+IntToStr(healthy));
		Memo1->Lines->Append("\nʳ������ ����������� �����: "+IntToStr(infected));
		Memo1->Lines->Append("\nʳ������ ����� �  ����������: "+IntToStr(healed));
		Memo1->Lines->Append("\nʳ������ ���� �� ������� ��������: "+
		IntToStr(DaySinceStartOfInfection));
		while(healthy!=N*N)
		{
			Sleep(Pause/**1000*/);
			infect (N, skin);
			infected = 0; healthy = 0; healed = 0;
			for (int i=0; i<N; i++)
				for (int j=0; j<N; j++)
				{
					if(skin[i][j].getStatus()==1)//���� ������ �������� - �������� ��� ���������
						skin[i][j].setTimeOfInfection(skin[i][j].getTimeOfInfection()+1);
					if(skin[i][j].getStatus()==1&&skin[i][j].getTimeOfInfection()>6)
						skin[i][j].setStatus(2);//���� ��� ���������>6 - ������ ��������
					if(skin[i][j].getStatus()==2)//���� ������ � ���������� - �������� ��� ���������
						skin[i][j].setTimeOfImmunity(skin[i][j].getTimeOfImmunity()+1);
					if(skin[i][j].getStatus()==2&&skin[i][j].getTimeOfImmunity()>4)
					{   //���� ��� ���������  >4
						skin[i][j].setStatus(0); //������ ��� ��������, �������� �� ���������
						skin[i][j].setTimeOfInfection(0);//��� ��������� = 0
						skin[i][j].setTimeOfImmunity(0);//��� ��������� = 0
					}
					if(skin[i][j].getStatus()==0) healthy++;
					else if(skin[i][j].getStatus()==1) infected++;
					else if(skin[i][j].getStatus()==2) healed++;
				}
			DaySinceStartOfInfection++;
            for(int i=0; i<N; i++)
				for(int j =0; j<N; j++)
				{

					if(skin[i][j].getStatus()==0)
					{
						Canvas->Pen->Color=ColorBoxHealthy->Selected;
						Canvas->Brush->Color=ColorBoxHealthy->Selected;

					}
					else if(skin[i][j].getStatus()==1)
					{
						Canvas->Pen->Color=ColorBoxInfected->Selected;
						Canvas->Brush->Color=ColorBoxInfected->Selected;
					}
					else if(skin[i][j].getStatus()==2)
					{
						Canvas->Pen->Color=ColorBoxHealed->Selected;
						Canvas->Brush->Color=ColorBoxHealed->Selected;
					}
					Canvas->Rectangle(j*A/N,i*A/N,j*A/N+A/N-X,i*A/N+A/N-X);


				}
			Memo1->Lines->Clear();
			Memo1->Lines->Append("\nʳ������ �������� �����: "+IntToStr(healthy));
			Memo1->Lines->Append("\nʳ������ ����������� �����: "+IntToStr(infected));
			Memo1->Lines->Append("\nʳ������ ����� �  ����������: "+IntToStr(healed));
			Memo1->Lines->Append("\nʳ������ ���� �� ������� ��������:"
			+IntToStr(DaySinceStartOfInfection));
		}
	}
	else
	{
		Form2->Show();
	}
}
//---------------------------------------------------------------------------


