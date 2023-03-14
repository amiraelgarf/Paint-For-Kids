#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
class PickHide: public Action
{
public:
	PickHide(ApplicationManager* pApp);            //constructor
	string getFigType(CFigure* C);                //return a string of the FigType (rectangle, square, .. etc)
	string getColourName(CFigure* C);                //return a string of the Fig color (red, blue , .. etc)
	void PrintResult(int correct, int incorrect);
	//int getCorrectCount(CFigure* C, char criteria);  //return number of figures  in FigList that matches criteria
	bool sameclr(CFigure* C, CFigure* F);
	bool sameType(CFigure* C, CFigure* F);
};

