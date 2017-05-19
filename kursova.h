//---------------------------------------------------------------------------

#ifndef kursovaH
#define kursovaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditN;
	TButton *Button1;
	TLabel *LabelN1;
	TLabel *LabelN2;
	TLabel *LabelPause;
	TMemo *Memo1;
	TLabel *LabelHealthy;
	TLabel *Labelinfected;
	TLabel *LabelHealed;
	TColorBox *ColorBoxHealthy;
	TColorBox *ColorBoxInfected;
	TColorBox *ColorBoxHealed;
	TTrackBar *TrackBarDayTime;
	TLabel *Label0;
	TLabel *Label5;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label3;
	TLabel *Label1;
	TLabel *Label05;
	TLabel *Label15;
	TLabel *Label25;
	TLabel *Label35;
	TLabel *Label45;
	TImage *Image1;
	TUpDown *UpDownTimeOfInfection;
	TLabel *LabelTimeOfInfection;
	TEdit *EditTimeOfInfection;
	TUpDown *UpDownTimeOfImmunity;
	TEdit *EditTimeOfImmunity;
	TLabel *LabelTimeOfImmunity;
	void __fastcall Button1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
