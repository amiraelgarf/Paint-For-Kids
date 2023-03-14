#pragma once
#include "Actions/Action.h"

class Addhexagon : public Action
{
private:
	Point Center;
	GfxInfo hexaGfxInfo;
public:
	Addhexagon(ApplicationManager* pApp);

	//Reads sqr parameters
	virtual void ReadActionParameters();

	//Add sqr to the ApplicationManager
	virtual void Execute(bool readparameters = true);
};
