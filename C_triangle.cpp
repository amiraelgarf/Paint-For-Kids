#include "C_triangle.h"
C_triangle::C_triangle()
{
}
C_triangle::C_triangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	iswhat = 1; // default is not moved ,deleted or changed color

}


void C_triangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

float C_triangle::area(int x, int y, int x1, int y1, int x2, int y2)
{
	float z = abs(((x * (y1 - y2) + x1 * (y2 - y) + x2 * (y - y1))) / 2.0);
	return z;
}

//bn2sm el triangle el drawn 3 triangle hasab el point el given fa lw el sum bta3 el areas dy 
//=areas el drawn yba gowa aw 3leh 

bool C_triangle::isinside(int x, int y)
{
	float a, a1, a2, a3;
	//area of triangle drawn
	a = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	//area of triangle 2
	a1 = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	//area of triangle 3 
	a2 = area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	//area of triangle 4 
	a3 = area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);

	if (a == a1 + a2 + a3)
	{
		return true;
	}
	return false;
}

void C_triangle::movefig(Point des)
{
	Corner2.x = (Corner1.x - Corner2.x) + des.x;
	Corner2.y = (Corner1.y - Corner2.y) + des.y;
	Corner3.x = (Corner1.x - Corner3.x) + des.x;
	Corner3.y = (Corner1.y - Corner3.y) + des.y;
	Corner1 = des;
	iswhat = 2;

}
void C_triangle::PrintInfo(Output* pOut)
{
	string IDNUM = to_string(ID);
	string corner1x = to_string(Corner1.x);
	string corner1y = to_string(Corner1.y);
	string corner2x = to_string(Corner2.x);
	string corner2y = to_string(Corner2.y);
	string corner3x = to_string(Corner3.x);
	string corner3y = to_string(Corner3.y);

	pOut->PrintMessage("Figure ID is " + IDNUM + " Point 1:( " + corner1x + " , " + corner1y + " ) " + " Point 2:( " + corner2x + " , " + corner2y + " ) "" Point 3:( " + corner3x + " , " + corner3y + " ) ");
}
string C_triangle:: getFigure() const
{
	 return "TRIANGLE";
}
void C_triangle:: Save(ofstream &filename)
{
	filename << "TRIANGLE"<<"  "<<(ID)<<"  "<<this->Corner1.x<<"  "<< this->Corner1.y<<"  "<< this->Corner2.x<<"  "<< this->Corner2.y<<"  "<<this->Corner3.x<<"  "<<this->Corner3.y<<"  ";
	filename<< FigGfxInfo.DrawClr.Color_to_String()<<"  ";
	if(FigGfxInfo.isFilled!= false)
		filename<< FigGfxInfo.FillClr.Color_to_String()<< endl;
	else
		filename<<"NO_FILL"<<endl;
}
void C_triangle:: Load(ifstream&filename)
{
	int n;
	filename >>n;
	SetID(n);
	int x1,y1,x2,y2,x3,y3;
	filename>> x1>>y1>>x2>>y2>>x3>>y3;
	Corner1.x=x1;
	Corner1.y=y1;
	Corner2.x=x2;
	Corner2.y=y2;
	Corner3.x=x3;
	Corner3.y=y3;
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

void C_triangle::resize1(Point des)
{

	Corner1.x = des.x;
	Corner1.y = des.y;
}

void C_triangle::setiswhat(int iw) //sets iswhat
{
	iswhat = iw;
}

int C_triangle::getiswhat() // gets iswhat 
{
	return iswhat;
}

Point C_triangle::getoriginalpoint()
{
	return Corner1;
}