#pragma once

#include "Actions/Action.h"

class Add_sqaure_action : public Action
{
private:
	Point Po1;
	GfxInfo SqrGfxInfo;
public:
	Add_sqaure_action(ApplicationManager* pApp);

	//Reads sqr parameters
	virtual void ReadActionParameters();

	//Add sqr to the ApplicationManager
	virtual void Execute(bool readparameters = true);
};