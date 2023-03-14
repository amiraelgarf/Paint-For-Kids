#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "Pick_Hide.h"

class pickfig : public PickHide
{
private:
	int count;                                                                 //max no. of correct counts
	CFigure* C;
	Point p;
	int correct = 0;                                                            //counter of correct selects
	int incorrect = 0;                                                          //counter of incorrect selects
	//PickHide* ph;                                                            //to access functions in abstract class Pick_Hide
public:
	pickfig(ApplicationManager* pApp);            //constructor
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};
