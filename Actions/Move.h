#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h" 
#include "GUI/Input.h"
#include "Figures/CFigure.h"

class Move : public Action
{
private:
	Point pmove;  // points of the new place 
public:
	Move(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
	Point getSelectedPoint();
};

