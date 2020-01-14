//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "SNIRconversions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
void AgrandirFenetre()
{		Form1->Image1->Height=450;
		Form1->Height=450;
}
void RetrecirFenetre()
{		Form1->Image1->Height=737;
		Form1->Height=737;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	// effacer Edit1
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	AnsiString d=DateToStr(Date())+" "+TimeToStr(Time());
	fichier.open("historique.txt",ios_base::app);
	op2=Edit1->Text.ToDouble();
	Edit1->Clear();
	if(operation==1)
	{
		resultat=op1+op2;
		fichier<<d.c_str()<<" "<<op1<<"+"<<op2<<"="<<resultat<<"\n";
	}
	if(operation==2)
	{
		resultat=op1-op2;
		fichier<<d.c_str()<<" "<<op1<<"-"<<op2<<"="<<resultat<<"\n";
	}
	if(operation==3)
	{
		resultat=op1*op2;
		fichier<<d.c_str()<<" "<<op1<<"*"<<op2<<"="<<resultat<<"\n";
	}
	if(operation==4)
	{
		resultat=op1/op2;
		fichier<<d.c_str()<<" "<<op1<<"/"<<op2<<"="<<resultat<<"\n";
	}
	if(operation==7)
	{
		resultat= pow (op1,op2);
		fichier<<d.c_str()<<" "<<op1<<"^"<<op2<<"="<<resultat<<"\n";
	}
	Edit1->Text=FloatToStrF(resultat,ffGeneral,7,0);
	fichier.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=2;
	fichier.close();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=5;
	if(operation==5)
	{
		resultat=1/op1;
		fichier.open("historique.txt",ios_base::app);
		AnsiString d=DateToStr(Date())+" "+TimeToStr(Time());
		fichier<<d.c_str()<<" "<<"1"<<"/"<<op1<<"="<<resultat<<"\n";
		fichier.close();
	}
	Edit1->Text=FloatToStrF(resultat,ffGeneral,7,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=6;
    if(operation==6)
	{
		resultat=op1*op1;
		fichier.open("historique.txt",ios_base::app);
		AnsiString d=DateToStr(Date())+" "+TimeToStr(Time());
		fichier<<d.c_str()<<" "<<op1<<"*"<<op1<<"="<<resultat<<"\n";
		fichier.close();
	}
	Edit1->Text=FloatToStrF(resultat,ffGeneral,7,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=7;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=8;
	if(operation==8)
	{
		resultat=sqrt(op1);
		AnsiString d=DateToStr(Date())+" "+TimeToStr(Time());
		fichier.open("historique.txt",ios_base::app);
		fichier<<d.c_str()<<" "<<"sqrt"<<op1<<"="<<resultat<<"\n";
		fichier.close();
	}
	Edit1->Text=FloatToStrF(resultat,ffGeneral,7,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(Button==mbRight)
		if(Button10->Caption=="log")
			Button10->Caption="ln";
		else Button10->Caption="log";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=9;
	if(operation==9)
	{
		resultat=log(op1);
		AnsiString d=DateToStr(Date())+" "+TimeToStr(Time());
		fichier.open("historique.txt",ios_base::app);
		fichier<<d.c_str()<<" "<<" "<<"log"<<op1<<"="<<resultat<<"\n";
		fichier.close();
	}
	Edit1->Text=FloatToStrF(resultat,ffGeneral,7,0);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=10;
	if(operation==10)
	{
		if(ComboBox1->Text=="Radian")
		{
			resultat= cos(op1);
		}
		else
		{
			resultat= cos((op1*3.14159265359)/180);
		}
		AnsiString d=DateToStr(Date())+" "+TimeToStr(Time());
		fichier.open("historique.txt",ios_base::app);
		fichier<<d.c_str()<<" "<<"cos"<<op1<<"="<<resultat<<"\n";
		fichier.close();
	}
	Edit1->Text=FloatToStrF(resultat,ffGeneral,7,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	operation=11;
	if(operation==11)
	{
		if(ComboBox1->Text=="Radian")
		{
			resultat= sin(op1);
		}
		else
		{
			resultat= sin((op1*3.14159265359)/180);
		}
		AnsiString d=DateToStr(Date())+" "+TimeToStr(Time());
		fichier.open("historique.txt",ios_base::app);
		fichier<<d.c_str()<<" "<<"sin"<<op1<<"="<<resultat<<"\n";
		fichier.close();
	}
	Edit1->Text=FloatToStrF(resultat,ffGeneral,7,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
		if(ComboBox1->Text=="Radian")
		{
			resultat= tan(op1);
		}
		else
		{
			resultat= tan((op1*3.14159265359)/180);
		}
		AnsiString d=DateToStr(Date())+" "+TimeToStr(Time());
		fichier.open("historique.txt",ios_base::app);
		fichier<<d.c_str()<<" "<<"tan"<<op1<<"="<<resultat<<"\n";
		fichier.close();
	Edit1->Text=FloatToStrF(resultat,ffGeneral,7,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	op1=Edit1->Text.ToDouble();
	Edit1->Clear();
	resultat= 3.14159265359*op1;
	AnsiString d=DateToStr(Date())+" "+TimeToStr(Time());
	fichier.open("historique.txt",ios_base::app);
	fichier<<d.c_str()<<" "<<"3.14159265359"<<op1<<"="<<resultat<<"\n";
	fichier.close();
	Edit1->Text=FloatToStrF(resultat,ffGeneral,7,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
	if(grand==true)
	{
		RetrecirFenetre();
		grand=false;
	}
	else
	{
		AgrandirFenetre();
		grand=true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'0';
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button17Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'1';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'2';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'3';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'4';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'5';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'6';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'7';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'8';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'9';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button27Click(TObject *Sender)
{
	WinExec("Notepad.exe historique.txt",1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button28Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'A';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button29Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'B';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button30Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'C';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button31Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'D';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button32Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'E';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button33Click(TObject *Sender)
{
	Edit1->Text=Edit1->Text+'F';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
	if(ComboBox2->Text=="Hexadécimale")
	{
		SNIR s;
		Edit1->Text=s.HexToString(Edit1->Text.ToInt()).c_str();
	}
	else
	{
		if(ComboBox2->Text=="Décimale")
		{
			SNIR s;
			Edit1->Text=s.ChaineHexaVersInt(AnsiString(Edit1->Text).c_str(),Edit1->Text.Length());
		}
		else
		{
		SNIR s;
		Edit1->Text=s.BinToString(Edit1->Text.ToInt()).c_str();
		}
	}
}
//---------------------------------------------------------------------------



