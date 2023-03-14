#include "CFigure.h"
//constructor 
CFigure::CFigure()
{ 
	Selected = false;
}
/////////////////////// ADDED ////////////////
color* CFigure::getColor()
{
	color* clr;
	if (FigGfxInfo.isFilled == true)
	{
		clr = &FigGfxInfo.FillClr;
	}
	else
	{
		clr = NULL;
	}
	return clr;
}
//////////////////////////////////////////////

//static member 34an el ID
int CFigure:: figureCount=1;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	//set el id w change el count 
	ID=figureCount;
	figureCount++;
}

//setter ll selected
void CFigure::SetSelected(bool s)
{	Selected = s; }

//getter ll selected
bool CFigure::IsSelected() const
{	return Selected; }

//change draw color
void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

//change fill color
void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

//virtual t check ana gowa meen
bool CFigure::isinside(int x, int y)
{
	return false;
}

//virtual 34an t move fig
 void CFigure::movefig(Point des)
 {

 }

 //virtual 34an t print el info 
//print el id bardo 
 void CFigure::PrintInfo(Output* pOut)
 {
	 string IDNUM = to_string(ID);
	 pOut->PrintMessage("Figure ID is" + IDNUM );
}
 //set ll id 
void CFigure::SetID(int id)
{
	if(id>0)
	{
		ID=id;
	}
	else
	{
		ID=1;
	}
}
//get ll id
int CFigure:: GetID()
{
	return ID;
}
//virtual to resize 
 void CFigure::resize1(Point des)
 {

 }



