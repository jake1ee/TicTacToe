//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

char currentPlayerSymbol = 'X';

bool TForm1:: checkWinner()
{
	if(!Button1->Caption.IsEmpty() && Button1->Caption == Button2->Caption && Button1->Caption == Button3->Caption)
		return true;
	if(!Button4->Caption.IsEmpty() && Button4->Caption == Button5->Caption && Button4->Caption == Button6->Caption)
		return true;
	if(!Button7->Caption.IsEmpty() && Button7->Caption == Button8->Caption && Button7->Caption == Button9->Caption)
		return true;
	if(!Button1->Caption.IsEmpty() && Button1->Caption == Button4->Caption && Button1->Caption == Button7->Caption)
		return true;
	if(!Button2->Caption.IsEmpty() && Button2->Caption == Button5->Caption && Button2->Caption == Button6->Caption)
		return true;
	if(!Button3->Caption.IsEmpty() && Button3->Caption == Button6->Caption && Button3->Caption == Button9->Caption)
		return true;
	if(!Button1->Caption.IsEmpty() && Button1->Caption == Button5->Caption && Button1->Caption == Button9->Caption)
		return true;
	if(!Button3->Caption.IsEmpty() && Button3->Caption == Button5->Caption && Button3->Caption == Button7->Caption)
		return true;

	return false;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Label2->Caption=currentPlayerSymbol;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	TButton* clickedButton = dynamic_cast<TButton*>(Sender);
	clickedButton->Caption=currentPlayerSymbol;

	if(checkWinner())
	{
		Label3->Caption="You Won";
        return;
    }

	if(currentPlayerSymbol =='X')
		currentPlayerSymbol = 'O';
	else
		currentPlayerSymbol = 'X';

	Label2->Caption = currentPlayerSymbol;
}
//---------------------------------------------------------------------------



