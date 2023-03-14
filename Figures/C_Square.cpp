#include "C_Square.h"
#include "ApplicationManager.h"
#include <iostream>
using namespace std;

C_Square::C_Square()
{
	length = 100;
	iswhat = 1;
}
C_Square::C_Square(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Po1 = P1;
	length = 100; 
	iswhat = 1; // default is not moved ,deleted or changed color

}


void C_Square::Draw(Output* pOut) const
{
	pOut->DrawSquare(Po1, FigGfxInfo, length , Selected);
}

bool C_Square::isinside(int x, int y)
{
	int l = 2 * length;
	if (x >= Po1.x - l  && x <= Po1.x + l && y >= Po1.y - l && y <= Po1.y + l)
	{
		return true;
	}

}


void C_Square::movefig(Point des)
{
	Po1 = des;
	iswhat = 2;

}


void C_Square::PrintInfo(Output* pOut)
{
	string IDNUM = to_string(ID);
	string Po1x = to_string(Po1.x);
	string Po1y = to_string(Po1.y);
	pOut->PrintMessage("Figure ID is " + IDNUM + " center:( " + Po1x + " , " + Po1y + " ) ");

}

string C_Square::getFigure() const
{
	return "SQUARE";
}
void C_Square:: Save(ofstream &filename)
{

	filename << "SQUARE"<<"  "<<(ID)<<"  "<< this->Po1.x<<"  "<< this->Po1.y<<"  ";
	filename<< FigGfxInfo.DrawClr.Color_to_String()<<"  ";
	if(FigGfxInfo.isFilled!= false)
		filename<< FigGfxInfo.FillClr.Color_to_String()<< endl;
	else
		filename<<"NO_FILL"<<endl;
}
void C_Square:: Load(ifstream &filename)
{
	int n;
	filename >>n;
	SetID(n);
	int x,y;
	filename>>x>>y;
	Po1.x=x;
	Po1.y=y;
	string DrawColor;
	filename>> DrawColor;
	FigGfxInfo.DrawClr.String_to_Color(DrawColor);
	string FillColor;
	filename>> FillColor;
	if(FillColor!= "NO_FILL")
	{
		FigGfxInfo.isFilled=true;
		FigGfxInfo.FillClr.String_to_Color(FillColor);
	}
	else 
		FigGfxInfo.isFilled=false;
}

void C_Square::resize1(Point des)
{
	length = des.x - Po1.x;
}
void C_Square::fillcolour(color c)
{
	ChngFillClr(c);
}
void C_Square::setiswhat(int iw) //sets iswhat
{
	iswhat = iw;
}

int C_Square::getiswhat() // gets iswhat 
{
	return iswhat;
}
Point C_Square::getoriginalpoint()
{
	return Po1;
}
