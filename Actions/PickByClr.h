#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "PickByBoth.h"

class pickclr : public PickHide
{
private:
	int count;                                                                   //max no. of correct counts
	CFigure* C;
	Point p;
	int correct = 0;                                                            //counter of correct selects
	int incorrect = 0;                                                         //counter of incorrect selects
	//PickHide* ph;                                                            //to access functions in abstract class Pick_Hide
public:
	pickclr(ApplicationManager* pApp);            //constructor
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};