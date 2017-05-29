//---------------------------------------------------------------------------

#ifndef formEndH
#define formEndH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TEndForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *ButtonExit;
	void __fastcall ButtonExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TEndForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEndForm *EndForm;
//---------------------------------------------------------------------------
#endif
