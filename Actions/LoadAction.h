#pragma once
#include "Actions/Action.h"
#include <fstream>
#include <string>
#include <iostream>
#include "Figures/CFigure.h"

class LoadAction : public Action
{
private:
	string name;
	ifstream file;
	ifstream Switch_to_play;
	CFigure* LFig;
	bool readparameters;
public:
	LoadAction(ApplicationManager* pApplication);
	LoadAction(string STP, ApplicationManager* pApplication);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
	//void LoadForPlay();  //only used in Switch To Draw Mode (ToDraw)
};