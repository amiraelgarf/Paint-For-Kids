#include "C_hexa.h" 
#include "GUI/Output.h"

C_hexa::C_hexa()
{
	l = 100; 
	iswhat = 1;
}
C_hexa::C_hexa(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	l = 100;
	iswhat = 1; // default is not moved ,deleted or changed color

}


void C_hexa::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHexa(Center, FigGfxInfo ,l, Selected);
}

float C_hexa::area(int x, int y, int x1, int y1, int x2, int y2)
{
	float z = abs(((x * (y1 - y2) + x1 * (y2 - y) + x2 * (y - y1))) / 2.0);
	return z;
}


bool C_hexa::isinside(int x, int y)
{
	int* px = new int[6];
	int* py = new int[6];
	px[0] = Center.x;
	px[1] = Center.x + l * 0.866;
	px[2] = px[1];
	px[3] = Center.x;
	px[4] = Center.x - l * 0.866;
	px[5] = px[4];

	py[0] = Center.y - l;
	py[1] = Center.y - l * 0.5;
	py[2] = Center.y + l * 0.5;
	py[3] = Center.y + l;
	py[4] = py[2];
	py[5] = py[1];

	float sum = 0;
	float sum2 = 0;

	for (int i = 0; i < 5; i++)
	{
		float a = area(px[i], py[i], px[i + 1], py[i + 1], x, y);
		sum = sum + a;
	}
	float a1 = area(px[5], py[5], px[0], py[0], x, y);
	sum = sum + a1;


	for (int i = 0; i < 5; i++)
	{
		float a = area(px[i], py[i], px[i + 1], py[i + 1], Center.x, Center.y);
		sum2 = sum2 + a;
	}
	float a2 = area(px[5], py[5], px[0], py[0], Center.x, Center.y);
	sum2 = sum2 + a2;

	if (sum==sum2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void C_hexa::PrintInfo(Output* pOut)
{
	string IDNUM = to_string(ID);
	string centerx = to_string(Center.x);
	string centery = to_string(Center.y);
	pOut->PrintMessage("Figure ID is " + IDNUM + "center:( " + centerx + "  , " + centery + " ) ");

}
string C_hexa:: getFigure() const
{
	return "HEXAGON";
}
void C_hexa:: Save(ofstream &filename)
{
	filename << "HEXAGON"<<"  "<<(ID)<<"  "<< this->Center.x<<"  "<< this->Center.y<<"  ";
	filename<< FigGfxInfo.DrawClr.Color_to_String()<<"  ";
	if(FigGfxInfo.isFilled!= false)
		filename<< FigGfxInfo.FillClr.Color_to_String()<< endl;
	else
		filename<<"NO_FILL"<<endl;
}
void C_hexa:: Load(ifstream &filename)
{
	int n;
	filename >>n;
	SetID(n);
	int x,y;
	filename>>x>>y;
	Center.x=x;
	Center.y=y;
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

void C_hexa::resize1(Point des)
{
	l = 2*(des.y) - 2 * Center.y;
}
void C_hexa::movefig(Point des)
{
	Center = des;
	iswhat = 2;
}

void C_hexa::fillcolour(color c)
{
	ChngFillClr(c);
}

void C_hexa::setiswhat(int iw) //sets iswhat
{
	iswhat = iw;
}

int C_hexa::getiswhat()
{
	return iswhat;
}
Point C_hexa::getoriginalpoint()
{
	return Center;
}