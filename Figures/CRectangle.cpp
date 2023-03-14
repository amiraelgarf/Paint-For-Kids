#include "CRectangle.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

CRectangle::CRectangle()
{

}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	iswhat = 1; // default is not moved ,deleted or changed color

}
	
bool  CRectangle::isinside(int x, int y)
{
	//check if point is inside the rectangle 
	if ((x >= Corner1.x && x <= Corner2.x) && (y >= Corner1.y && y <= Corner2.y))
		return true;
	else
		return false;
}

void  CRectangle::printinfo()
{
	 ApplicationManager* pApp;
	 Output* pOut = pApp->GetOutput();
	 Input* pIn = pApp->GetInput();
	 string corner1x = to_string(Corner1.x);
	 string corner1y = to_string(Corner1.y);
	 string corner2x = to_string(Corner2.x);
	 string corner2y = to_string(Corner2.y);

	 pOut->PrintMessage(corner1x + corner1y + corner2x + corner2y);

}
 void CRectangle::movefig(Point des)
 {
	 int x1 = (Corner1.x - Corner2.x) + des.x;
	 int y1 = (Corner1.y - Corner2.y) + des.y;
	 Corner2.x = x1;
	 Corner2.y = y1;
	 Corner1 = des;
	 iswhat = 2;

 }
 void CRectangle::PrintInfo(Output* pOut)
 {
	 string IDNUM = to_string(ID);
	 string Corner1x = to_string(Corner1.x);
	 string Corner1y = to_string(Corner1.y);
	 string Corner2x = to_string(Corner2.x);
	 string Corner2y = to_string(Corner2.y);

	 pOut->PrintMessage("Figure ID is " + IDNUM + " Corner1:( " + Corner1x + " , " + Corner1y + " ) " + " Corner2:( " + Corner2x + " , " + Corner2y + " ) ");

 }

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
string CRectangle:: getFigure() const
{
	return "RECTANGLE";
}
void CRectangle:: Save(ofstream& filename)
{
	filename << "RECTANGLE"<<"  "<<(ID)<<"  "<< this->Corner1.x<<"  "<< this->Corner1.y<<"  "<< this->Corner2.x<<"  "<< this->Corner2.y<<"  ";
	filename<< FigGfxInfo.DrawClr.Color_to_String()<<"  ";
	if(FigGfxInfo.isFilled!= false)
		filename<< FigGfxInfo.FillClr.Color_to_String()<< endl;
	else
		filename<<"NO_FILL"<<endl;
}
void CRectangle::Load(ifstream & filename)
{
	int n;
	filename >>n;
	SetID(n);
	int x1,y1,x2,y2;
	filename >>x1>>y1>>x2>>y2;
	Corner1.x=x1;
	Corner1.y=y1;
	Corner2.x=x2;
	Corner2.y=y2;
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

void CRectangle::resize1(Point des)
{
	Corner2.x = des.x;
	Corner2.y = des.y;
}
void CRectangle::setiswhat(int iw) //sets iswhat
{
	iswhat = iw;
}

int CRectangle::getiswhat()
{
	return iswhat;
}

Point CRectangle::getoriginalpoint()
{
	return Corner1;
}