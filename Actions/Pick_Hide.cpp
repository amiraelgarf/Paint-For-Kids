#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "Figures/CRectangle.h"
#include "C_hexa.h"
#include "Ccircle.h"
#include "C_triangle.h"
#include "C_Square.h"
#include "Pick_Hide.h"

// constructor	
PickHide::PickHide(ApplicationManager* pApp)
	:Action(pApp)
{}


///////////////////////////     determining fig type       ////////////////
string PickHide::getFigType(CFigure* C)
{
	string type;
	CRectangle* rect = dynamic_cast<CRectangle*>(C);
	if (rect != NULL)
	{
		type = "Rectangle";                  
	}
	C_Square* sq = dynamic_cast<C_Square*>(C);
	if (sq != NULL)
	{
		type = "Square";
	}
	Ccircle* circ = dynamic_cast<Ccircle*>(C);
	if (circ != NULL)
	{
		type = "Circle";
	}
	C_triangle* tri = dynamic_cast<C_triangle*>(C);
	if (tri != NULL)
	{
		type = "Triangle";
	}
	C_hexa* hex = dynamic_cast<C_hexa*>(C);
	if (hex != NULL)
	{
		type = "Hexagon";
	}
	return type;                                    //getting fig type name for printig it on screen
}
///////////////////////////////////////////////////////////////////////

//////////                get colour name               ////////////
string PickHide::getColourName(CFigure* C)
{
	string clr;
	if (*(C->getColor()) == color(0, 0, 0))
		clr = "black";
	if (*(C->getColor()) == color(255, 255, 0))
		clr = "yellow";
	if (*(C->getColor()) == color(255, 165, 0))
		clr = "orange";
	if (*(C->getColor()) == color(255, 0, 0))
		clr = "red";
	if (*(C->getColor()) == color(0, 255, 0))
		clr = "green";
	if (*(C->getColor()) == color(0, 0, 255))
		clr = "blue";
	if ((C->getColor()) == NULL)
		clr = "NOT FILLED";
	return clr;
}
///////////////////////////////////////////////////////////////////
///////////////////////// Comparing //////////////////////////////

bool PickHide::sameclr(CFigure* C, CFigure* F)
{
	if (C == NULL || F == NULL)
		return false;
	else if (C->getColor() == NULL || F->getColor() == NULL)
		return false;
	else if (*(C->getColor()) == *(F->getColor()))
		return true;
	else
		return false;
}
bool PickHide::sameType(CFigure* C, CFigure* F)
{
	if (getFigType(C) == getFigType(F))
		return true;
	else
		return false;
}
////////////////////////////// GET MAX COUNT ///////////////////
//int PickHide::getCorrectCount(CFigure* C, char criteria)
//{
//	int count = 0;
//	for (int i = 0; i < pManager->getFigCount(); i++)
//	{
//		if ((criteria == 'c') && sameclr(C, pManager->getFigList(i)))              //criteria is colour of CFigure C
//			count++;
//		else if ((criteria == 't') && sameType(C, pManager->getFigList(i)))          //criteria is type of CFigure C
//			count++;
//		else if ((criteria == 'b') && sameclr(C, pManager->getFigList(i)) && sameType(C, pManager->getFigList(i)))    //criteria is both type and colour
//			count++;
//	}
//	return count;
//}
////////////////////////////////////////////////////////////////
////////////////////// OUTPUT MESSAGES /////////////////////////////
void PickHide::PrintResult(int correct, int incorrect)
{
	Point p;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string wrong = to_string(incorrect);
	string right = to_string(correct);
	pOut->PrintMessage("Game Ended, click on the drawing area to see your counts");
	pIn->GetPointClicked(p.x, p.y);
	pOut->PrintMessage("Number of incorrect clicks: " + wrong + " and Number of correct clicks: " + right);
}
////////////////////////////////////////////////////////////////////
