#include "Ccircle.h"
#include<cmath>
Ccircle::Ccircle()
{
}

Ccircle::Ccircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
	iswhat = 1; // default is not moved ,deleted or changed color

}


void Ccircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCircle(Center, Radius, FigGfxInfo, Selected);
}

bool Ccircle::isinside(int x, int y)
{
	int z1 = x - Center.x;
	int z2 = y - Center.y;
	int z = sqrt((z1 * z1) + (z2 * z2));
	int r1 = Radius.x - Center.x;
	int r2 = Radius.y - Center.y;

	int r = sqrt((r1 * r1) + (r2 * r2));
	if (z <= r)
	{
		return true;
	}
	else
		return false;
}

Point Ccircle::getRadius()
{
	return Radius;
}
void Ccircle::movefig(Point des)
{
	int x1 = (Radius.x - Center.x) + des.x;
	int y1 = (Radius.y - Center.y) + des.y;
	Center = des;
	Radius.x = x1;
	Radius.y = y1;
	iswhat = 2;

}
void Ccircle::PrintInfo(Output* pOut)
{
	string IDNUM = to_string(ID);
	string centerx = to_string(Center.x);
	string centery = to_string(Center.y);
	int r1 = Radius.x - Center.x;
	int r2 = Radius.y - Center.y;
	int r = sqrt((r1 * r1) + (r2 * r2));
	string radius = to_string(r);

	pOut->PrintMessage("Figure ID is " + IDNUM + " center:(  " + centerx  + " , " + centery + " ) Radius " + radius);

}
string Ccircle::getFigure() const
{
	return "CIRCLE";
}

void Ccircle:: Save(ofstream &filename)
{
	filename << "CIRCLE"<<"  "<<(ID)<<"  "<<this->Center.x<<"  "<< this->Center.y<<"  "<< this->Radius.x<<"  "<<this->Radius.y<<"  ";
	filename<< FigGfxInfo.DrawClr.Color_to_String()<<"  ";
	if(FigGfxInfo.isFilled!= false)
		filename<< FigGfxInfo.FillClr.Color_to_String()<< endl;
	else
		filename<<"NO_FILL"<<endl;
}
void Ccircle:: Load(ifstream &filename)
{
	int n;
	filename >>n;
	SetID(n);
	int x,y,z,w;
	filename>> x>> y>> z>>w;
	Center.x=x;
	Center.y=y;
	Radius.x=z;
	Radius.y=w;
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
void Ccircle::resize1(Point des)
{
	Radius.x = des.x;
	Radius.y = des.y;
}

void Ccircle::setiswhat(int iw) //sets iswhat
{
	iswhat = iw;
}

int Ccircle::getiswhat()
{
	return iswhat;
}

Point Ccircle::getoriginalpoint()
{
	return Center;
}