//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "formEnd.h"
#include "kursova.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEndForm *EndForm;
//---------------------------------------------------------------------------
__fastcall TEndForm::TEndForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEndForm::ButtonExitClick(TObject *Sender)
{
	EndForm->Close();
}
//---------------------------------------------------------------------------
